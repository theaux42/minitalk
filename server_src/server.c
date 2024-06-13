/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:13:44 by tbabou            #+#    #+#             */
/*   Updated: 2024/06/13 15:10:12 by tbabou           ###   ########.fr       */
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
	if (result == 0)
		ft_printf("%s%s%s", GREEN, "Message received: ", RESET);
	ft_putchar(result);
}

char binary_to_char(char *str)
{
	int	i;
	int	result;

	i = 128;
	result = 0;
	while (*str)
	{
		if (*str == '1')
			result += i;
		i /= 2;
		str++;
	}
	return (result);
}

int ft_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ftstrjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char*)malloc(sizeof(*s1) * (ft_ft_strlen((char *)s1) + ft_ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

void	bit_handler(int sig)
{
	static char	current_char[8];
	static char *string;
	
	if (!string)
		string = NULL;
	if (sig == SIGINT)
	{
		exit(0);
	}
	if (sig == SIGUSR1)
		current_char[ft_ft_strlen(current_char)] = '1';
	else if (sig == SIGUSR2)
		current_char[ft_ft_strlen(current_char)] = '0';
	if (ft_ft_strlen(current_char) == 8)
	{		
		if (binary_to_char(current_char) == 0)
		{
			ft_printf("%s%s%s", GREEN, string, RESET);
		}
		else
			string = ftstrjoin(string, current_char);
		ft_memset(current_char, '\0', 8);
	}
}

int	main(void)
{
	ft_printf("Welcome on my %sminitalk%s\n", GREEN, RESET);
	ft_printf("PID is %s%d%s\n", BLUE, getpid(), RESET);
	ft_printf("=== %sWaiting for text%s ===\n", BLUEBG, RESET);
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	while (1)
		;
	return (0);
}
