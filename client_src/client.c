/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:43:26 by tbabou            #+#    #+#             */
/*   Updated: 2024/06/13 14:54:47 by tbabou           ###   ########.fr       */
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
		if (*str == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		str++;
		usleep(300);
	}
}

char	*int_to_binary(int decimal_num, t_m_free *m_free)
{
	char	*bit;
	int		i;
	int		remainder;

	i = 7;
	bit = ft_malloc(sizeof(char) * 8, m_free);
	if (!bit)
		return (ft_free_all(m_free), NULL);
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

int	main(int argc, char **argv)
{
	t_m_free	m_free;
	int			i;
	int			j;

	if (argc < 3)
		return (printf("%sBad usage => ./client <pid> <message>%s", RED,
				RESET), 0);
	if (ft_atoi(argv[1]) < 1)
		return (printf("%sBad usage => PID INVALID.%s", RED,
				RESET), 0);
	m_free.list = NULL;
	i = -1;
	j = 1;
	while (argv[++j])
	{
		while (argv[j][++i])
			send_bit(ft_atoi(argv[1]), int_to_binary(argv[j][i], &m_free));
		if (argv[j + 1])
			send_bit(ft_atoi(argv[1]), int_to_binary(' ', &m_free));
		i = -1;
	}
	send_bit(ft_atoi(argv[1]), "00000000");
	ft_free_all(&m_free);
	return (0);
}
