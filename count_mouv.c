/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:14:01 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/29 15:30:55 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_max_or_min(t_pile *pile_a, t_pile *pile_b, int ib)
{
	int	lowest;
	int	count;

	lowest = calcul_lowest(pile_a);
	count = 0;
	while (pile_a->data != lowest)
	{
		pile_a = pile_a->next;
		count++;
	}
	if (count > pile_len(pile_a) / 2)
		count = pile_len(pile_a) - count;
	if (ib > pile_len(pile_b) / 2)
		ib = pile_len(pile_b) - ib;
	return (count + ib);
}

int	count_mouv_2(t_pile *pile_a, t_pile *pile_b, int ib)
{
	int	count;
	int	len_a;
	int	i;

	if (pile_b->data < calcul_lowest(pile_a)
		|| pile_b->data > calcul_highest(pile_a))
		return (count_max_or_min(pile_a, pile_b, ib));
	len_a = pile_len(pile_a);
	i = 0;
	while (i < len_a)
	{
		if (pile_b->data > pile_a->prev->data && pile_b->data < pile_a->data)
			break ;
		pile_a = pile_a->next;
		i++;
	}
	count = i;
	if (count > len_a / 2)
		count = len_a - count;
	if (ib > pile_len(pile_b) / 2)
		ib = pile_len(pile_b) - ib;
	return (count + ib);
}

int	count_mouv(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	elem;
	int	count;
	int	count_elem;

	elem = pile_b->data;
	count = count_mouv_2(pile_a, pile_b, 0);
	i = 0;
	while (i < pile_len(pile_b))
	{
		count_elem = count_mouv_2(pile_a, pile_b, i);
		if (count_elem < count)
		{
			elem = pile_b->data;
			count = count_elem;
		}
		pile_b = pile_b->next;
		i++;
	}
	return (elem);
}
