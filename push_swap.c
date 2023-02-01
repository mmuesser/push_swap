/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/02/01 19:30:32 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str);

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
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("error1\n");
				return (0);
			}
			j++;
		}
		nb = ft_atoi(av[i]);
		if (test(av[i], nb, j - 1) == 1)
		{
			printf("error2\n");
			return (0);
		}
		i++;
	}
	return (nb);
}

int	main(int ac, char **av)
{
	int nb;

	nb = parsing_arg(ac, av);
	return (0);
}