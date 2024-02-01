/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 07:08:38 by tbabou            #+#    #+#             */
/*   Updated: 2024/01/29 16:23:54 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
int		ft_printf(const char *format, ...);
int		ft_intlen(int nbr);
int		ft_uintlen(unsigned int nbr);
int		ft_hexalen(uintptr_t ptr);
int		ft_putchar(int c);
char	*ft_uitoa(unsigned int n);
int		ft_puthexa(unsigned int num, int isUpper);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putptr(unsigned long long ptr);

#endif
