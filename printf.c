/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:33:29 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/10 16:58:19 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *src, ...)
{
	va_list		ap;
	int			cnt;
	int			res;

	va_start (ap, src);
	cnt = 0;
	res = 0;
	while (src[cnt])
	{
		if (src[cnt] != '%')
			write (1, &src[cnt], 1);
		else
		{
			res += ft_fork ((char *)src + cnt, ap) - 2;
			cnt++;
		}
		cnt++;
	}
	va_end(ap);
	return (cnt + res);
}

int	ft_fork(char *src, va_list ap)
{
	int		res;
	char	*hexa;
	char	*hexam;

	hexa = "0123456789abcdef";
	hexam = "0123456789ABCDEF";
	if (src[1] == 'c')
		res = ft_putchar_pf((int)va_arg(ap, int));
	else if (src[1] == 's')
		res = ft_pustr_pf((char *)va_arg(ap, char *));
	else if (src[1] == 'd' || src[1] == 'i')
		res = ft_putnbr_pf((int)va_arg(ap, int));
	else if (src[1] == 'u')
		res = ft_putnbr_u((unsigned int)va_arg(ap, unsigned int), 1);
	else if (src[1] == 'x')
		res = ft_putnbr_x((unsigned int)va_arg(ap, unsigned int), 1, hexa);
	else if (src[1] == 'X')
		res = ft_putnbr_x((unsigned int)va_arg(ap, unsigned int), 1, hexam);
	else if (src[1] == 'p')
		res = ft_putvoid((long unsigned int)va_arg(ap, void *), hexa);
	else if (src[1] == '%')
		res = ft_putchar_pf('%');
	return (res);
}

int	ft_putnbr_pf(int src)
{
	int	cnt;

	cnt = 0;
	ft_putnbr_fd(src, 1);
	if (src <= 0)
		cnt++;
	while (src != 0)
	{
		src /= 10;
		cnt ++;
	}
	return (cnt);
}

int	ft_putnbr_u(unsigned int nb, int i)
{
	unsigned int	res;

	if (nb > 9)
	{
		res = nb % 10 + '0';
		nb = nb / 10;
		i += ft_putnbr_u(nb, 1);
		write (1, &res, 1);
	}
	else
	{
		nb += '0';
		write (1, &nb, 1);
	}
	return (i);
}

int	ft_putnbr_x(long unsigned int nb, int i, char *base)
{
	unsigned int	res;
	unsigned int	len;

	len = ft_strlen_pf(base);
	if (nb > len - 1)
	{
		res = nb % len;
		nb = nb / len;
		i += ft_putnbr_x(nb, 1, base);
		write (1, &base[res], 1);
	}
	else
		write (1, &base[nb], 1);
	return (i);
}
