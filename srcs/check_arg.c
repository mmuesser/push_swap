/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:08:58 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/03 18:11:19 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verif_nbr(char *str, int nb)
{
	int				len;
	unsigned int	nbr;
	
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		if (str[len] != nbr % 10 + 48 && (nbr != 0 && str[len] != '-'))
			return (1);
		nbr /= 10;
		len--;
	}
	return (0);
}

int	check_nbr(int ac, char **av)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (verif_nbr(av[i], nbr) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_char(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+'
				&& (av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing_arg(int ac, char **av)
{
	if (check_char(ac, av) == 1)
		return (1);
	if (check_nbr(ac, av) == 1)
		return (1);
	return (0);
}
