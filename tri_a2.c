/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:10:50 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/02 18:12:09 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a(t_pile *pile_a, int nb)
{
	while (pile_a->data != nb)
			pile_a = rotate(pile_a);
	while (pile_a->data < pile_a->next->data)
		pile_a = pile_a->next;
	pile_a = pile_a->next;
	if (pile_a->data == nb)
	{
		return (1);
	}
	else
		return (0);
}

int	calcul_lowest(t_pile *pile_a)
{
	int		lowest;
	t_pile	*tmp;

	lowest = pile_a->data;
	tmp = pile_a;
	pile_a = pile_a->next;
	while (pile_a->data != tmp->data)
	{	
		if (pile_a->data < lowest)
			lowest = pile_a->data;
		pile_a = pile_a->next;
	}
	return (lowest);
}

int	is_trie(t_pile *pile_a, int lowest)
{
	t_pile	*tmp;

	tmp = pile_a;
	pile_a = pile_a->next;
	while (1)
	{
		if (check_a(pile_a, lowest) == 1)
			return (1);
		while (pile_a->data != tmp->data)
		{
			if (tmp->data > pile_a->prev->data && tmp->data < pile_a->data)
				return (0);
			pile_a = pile_a->next;
		}
		pile_a = pile_a->next;
		tmp = pile_a;
		pile_a = pile_a->next;
	}
}