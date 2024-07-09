/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:43:26 by tbabou            #+#    #+#             */
/*   Updated: 2024/07/10 00:44:44 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>

void	send_bit(int pid, char *str)
{
	while (*str)
	{
		usleep(200);
		if (*str == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		str++;
	}
}

char	*int_to_binary(int decimal_num)
{
	char	*bit;
	int		i;
	int		remainder;

	i = 7;
	bit = malloc(sizeof(char) * 8);
	if (!bit)
		return (NULL);
	ft_memset(bit, '0', 8);
	while (decimal_num != 0)
	{
		remainder = decimal_num % 2;
		decimal_num /= 2;
		bit[i] = remainder + '0';
		i--;
	}
	return (bit);
}

void	send_message(char *str, int pid)
{
	char	*current_char;

	while (*str)
	{
		current_char = int_to_binary(*str);
		if (!current_char)
			return ;
		send_bit(pid, current_char);
		free(current_char);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1)
		return (ft_printf("%sBad usage - Invalid pid%s", RED, RESET), -1);
	if (argc != 3)
		return (ft_printf("%sBad usage - Too much args%s", RED, RESET),
			-1);
	send_message(argv[2], ft_atoi(argv[1]));
	send_bit(ft_atoi(argv[1]), "00000000");
	return (0);
}
