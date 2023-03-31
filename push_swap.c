/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/31 16:28:41 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac - 1)
	{
		j = ft_atoi(av[i]);
		k = ft_atoi(av[i + 1]);
		if (k < j)
			return (0);
		i++;
	}
	return (1);
}

t_pile	*push_swap(t_pile *pile_a, t_pile *pile_b)
{
	t_data	data;

	data = mediane(pile_a);
	if (pile_len(pile_a) <= 3)
		sort_3(&pile_a);
	else
	{
		pretri(&pile_a, &pile_b, data);
		tri_a(&pile_a, &pile_b);
	}
	set_a_final(&pile_a, data);
	return (pile_a);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (parsing_arg(ac, av) == 1 || ac == 1)
		return (0);
	if (check_order(ac, av) == 1)
		return (0);
	pile_a = init_pile(ac, av);
	pile_b = NULL;
	pile_a = push_swap(pile_a, pile_b);
	free_pile(&pile_a);
	return (0);
}
