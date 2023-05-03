/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:39 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/06 11:42:21 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*swap(t_pile *pile)
{
	int	tmp;

	if (!pile)
		return (NULL);
	tmp = pile->data;
	pile->data = pile->next->data;
	pile->next->data = tmp;
	return (pile);
}

void	push_a(t_pile **pile_a, t_pile **pile_b, t_data *data, char **str)
{
	t_pile	*tmp;

	if (*pile_b)
	{
		tmp = (*pile_a);
		if (!tmp)
			tmp = lstnew((*pile_b)->data);
		else
			tmp = lstadd_front(*pile_a, lstnew((*pile_b)->data));
		lst_del(pile_b);
		if (!tmp)
			exit(error(pile_a, pile_b, data, str));
		*pile_a = tmp;
	}
}

void	push_b(t_pile **pile_b, t_pile **pile_a, t_data *data, char **str)
{
	t_pile	*tmp;

	if (*pile_a)
	{
		tmp = (*pile_b);
		if (!tmp)
			tmp = lstnew((*pile_a)->data);
		else
			tmp = lstadd_front(*pile_b, lstnew((*pile_a)->data));
		lst_del(pile_a);
		if (!tmp)
			exit(error(pile_a, pile_b, data, str));
		*pile_b = tmp;
	}
}

t_pile	*rotate(t_pile *pile)
{
	if (!pile)
		return (NULL);
	pile = pile->next;
	return (pile);
}

t_pile	*reverse_rotate(t_pile *pile)
{
	if (!pile)
		return (NULL);
	pile = pile->prev;
	return (pile);
}
