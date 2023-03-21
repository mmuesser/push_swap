/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:08:58 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/02 17:09:28 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test(char *str, int nb, int j)
{
	while (j >= 0)
	{
		if (str[j] != nb % 10 + 48)
			return (1);
		nb /= 10;
		j--;
	}
	return (0);
}

int	parsing_arg(int ac, char **av)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != 32)
			{
				printf("error_1\n");
				return (0);
			}
			j++;
		}
		nb = ft_atoi(av[i]);
		if (test(av[i], nb, j - 1) == 1)
		{
			printf("error_2\n");
			return (0);
		}
		i++;
	}
	return (1);
}