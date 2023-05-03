/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:08:58 by mmuesser          #+#    #+#             */
/*   Updated: 2023/05/03 15:17:31 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_pile *pile_a)
{
	int	len_a;
	int	nb;
	int	i;
	int	j;

	len_a = pile_len(pile_a);
	i = 0;
	while (i < len_a)
	{
		nb = pile_a->data;
		pile_a = pile_a->next;
		j = 1;
		while (j < len_a)
		{
			if (nb == pile_a->data)
				return (1);
			pile_a = pile_a->next;
			j++;
		}
		pile_a = pile_a->next;
		i++;
	}
	return (0);
}

int	verif_nbr(char *str, int nb)
{
	int				len;
	unsigned int	nbr;

	if (((nb < 0 && str[0] != '-') || (nb > 0 && str[0] == '-')))
		return (1);
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	len = ft_strlen(str) - 1;
	while (len >= 0 && str[len] == ' ')
		len--;
	while (len >= 0)
	{
		if (str[len] != (nbr % 10 + 48) && (nbr != 0 && str[0] != '-'))
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
		if (av[i][0] == '-' && av[i][1] == '\0')
			return (1);
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
