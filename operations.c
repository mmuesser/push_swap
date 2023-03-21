/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:39 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/01 21:12:09 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*swap(t_pile *pile)
{
	int tmp;

	tmp = pile->data;
	pile->data = pile->next->data;
	pile->next->data = tmp;
	return (pile);
}

void	push_a(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_b)
	{
		if (!(*pile_a))
			*pile_a = lstnew((*pile_b)->data);
		else
			*pile_a = lstadd_front(*pile_a, lstnew((*pile_b)->data));
		lst_del(pile_b);
	}
}

void	push_b(t_pile **pile_b, t_pile **pile_a)
{
	if (*pile_a)
	{
		if (!(*pile_b))
			*pile_b = lstnew((*pile_a)->data);
		else
			*pile_b = lstadd_front(*pile_b, lstnew((*pile_a)->data));
		lst_del(pile_a);
	}
}

t_pile	*rotate(t_pile *pile)
{
	pile = pile->next;
	return (pile);
}

t_pile	*reverse_rotate(t_pile *pile)
{
	pile = pile->prev;
	return (pile);
}
