/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:13:44 by tbabou            #+#    #+#             */
/*   Updated: 2024/02/01 12:07:59 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	display_binary(char *octet)
{
	int	i;
	int	result;

	i = 128;
	result = 0;
	while (*octet)
	{
		if (*octet == '1')
			result += i;
		i /= 2;
		octet++;
	}
	if (result > 127 || result < 0)
	{
		ft_printf("%sSomething went wrong...%s\n", RED, RESET);
		exit(0);
	}
		
	ft_putchar(result);
}

int ft_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	bit_handler(int sig)
{
	static char	str[8];

	if (sig == SIGINT)
	{
		exit(0);
	}
	if (sig == SIGUSR1)
		str[ft_ft_strlen(str)] = '1';
	else if (sig == SIGUSR2)
		str[ft_ft_strlen(str)] = '0';
	if (ft_ft_strlen(str) == 8)
	{
		display_binary(str);
		ft_memset(str, '\0', 8);
	}
}

int	main(void)
{
	ft_printf("Welcome on my %sminitalk%s\n", GREEN, RESET);
	ft_printf("PID is %s%d%s\n", BLUE, getpid(), RESET);
	ft_printf("=== %sWaiting for text%s ===\n", BLUEBG, RESET);
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	signal(SIGINT, bit_handler);
	while (1)
		;
	return (0);
}
