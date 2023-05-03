/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/06 14:44:17 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_b(t_pile *pile_b, int elem)
{
	int	i;
	int	len_b;
	int	count;

	len_b = pile_len(pile_b);
	i = 0;
	while (i < len_b)
	{
		if (pile_b->data == elem)
			count = i;
		pile_b = pile_b->next;
		i++;
	}
	return (count);
}

int	count_a(t_pile *pile_a, int elem)
{
	int	lowest;
	int	count;
	int	len_a;
	int	i;

	lowest = calcul_lowest(pile_a);
	count = 0;
	if (elem > calcul_highest(pile_a) || elem < lowest)
	{
		while (pile_a->data != lowest)
		{
			pile_a = pile_a->next;
			count++;
		}
		return (count);
	}
	len_a = pile_len(pile_a);
	i = -1;
	while (++i < len_a)
	{
		if (elem > pile_a->prev->data && elem < pile_a->data)
			count = i;
		pile_a = pile_a->next;
	}
	return (count);
}

void	sort_3(t_pile **pile)
{
	int	lowest;
	int	highest;
	int	len;
	int	i;

	i = 0;
	len = pile_len(*pile);
	lowest = calcul_lowest(*pile);
	highest = calcul_highest(*pile);
	while (len > 0)
	{
		if ((*pile)->data == lowest && (*pile)->next->data == highest)
			i = 1;
		*pile = (*pile)->next;
		len--;
	}
	if (i == 1)
	{
		*pile = swap(*pile);
		write(1, "sa\n", 3);
	}
}

void	tri_a(t_pile **pile_a, t_pile **pile_b, t_data *data)
{
	int	elem;
	int	cb;
	int	ca;
	int	len_b;

	sort_3(pile_a);
	len_b = pile_len(*pile_b);
	while (len_b > 0)
	{
		cb = 0;
		ca = 0;
		elem = count_mouv(*pile_a, *pile_b);
		cb = count_b(*pile_b, elem);
		ca = count_a(*pile_a, elem);
		rotate_a_and_b(pile_a, pile_b, ca, cb);
		push_a(pile_a, pile_b, data, NULL);
		write(1, "pa\n", 3);
		len_b--;
	}
}
