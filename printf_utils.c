/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:14:45 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/10 16:57:49 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_pustr_pf(char *src)
{
	unsigned int	len;

	if (!src)
		return (ft_pustr_pf("(null)"));
	if (!ft_strlen_pf(src))
		return (0);
	len = ft_strlen_pf(src);
	write (1, src, len);
	return (len);
}

int	ft_putvoid(long unsigned int nbr, char *base)
{
	unsigned int	len;

	if (nbr == 0)
		return (ft_pustr_pf("(nil)"));
	len = ft_pustr_pf("0x");
	len += ft_putnbr_x(nbr, 1, base);
	return (len);
}

unsigned int	ft_strlen_pf(const char *src)
{
	unsigned int	len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int				res;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write (fd, "-", 1);
	}
	if (nb > 9)
	{
		res = nb % 10 + '0';
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		write (fd, &res, 1);
	}
	else
	{
		nb += '0';
		write (fd, &nb, 1);
	}
}
