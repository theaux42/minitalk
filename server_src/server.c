/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:13:44 by tbabou            #+#    #+#             */
/*   Updated: 2024/06/21 14:24:36 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	binary_to_char(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result <<= 1;
		if (*str == '1')
			result |= 1;
		str++;
	}
	return ((char)result);
}

void	bit_handler(int sig)
{
	static char	current_char[8];
	static char	*string;

	if (!string)
		string = ft_strdup("");
	if (sig == SIGUSR1)
		current_char[ft_strlen(current_char)] = '1';
	else if (sig == SIGUSR2)
		current_char[ft_strlen(current_char)] = '0';
	if (ft_strlen(current_char) == 8)
	{
		if (binary_to_char(current_char) == 0)
		{
			ft_printf("%s", string);
			free(string);
			string = NULL;
		}
		else
			string = ft_addchar(string, binary_to_char(current_char));
		ft_memset(current_char, '\0', 8);
	}
}

int	main(void)
{
	ft_printf("Welcome on my %sminitalk%s\n", MAGENTA, RESET);
	ft_printf("PID is %s%d%s\n", MAGENTA, getpid(), RESET);
	ft_printf("=== %sWaiting for text%s ===\n", MAGENTABG, RESET);
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	while (1)
		;
	return (0);
}
