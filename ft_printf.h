/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:28:29 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/13 11:51:25 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *src, ...);
int				ft_putchar_pf(int c);
int				ft_pustr_pf(char *src);
int				ft_fork(char *src, va_list ap);
int				ft_putnbr_pf(int src);
int				ft_putnbr_u(unsigned int nb, int i);
int				ft_putnbr_x(long unsigned int nb, int i, char *base);
int				ft_putvoid(long unsigned int nbr, char *base);
int				ft_printf(const char *src, ...);
unsigned int	ft_strlen_pf(const char *src);
void			ft_putnbr_fd(int nb, int fd);

#endif