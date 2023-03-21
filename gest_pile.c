/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:59:06 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/21 20:47:53 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*lstnew(int content)
{
	t_pile	*elem;

	elem = malloc(sizeof(t_pile));
	if (!elem)
		return (NULL);
	elem->next = elem;
	elem->data = content;
	elem->prev = elem;
	return (elem);
}

t_pile	*init_pile(int ac, char **av)
{
	int		i;
	t_pile	*pile;
	t_pile	*tmp;

	pile = lstnew(ft_atoi(av[1]));
	if (!pile)
		return (NULL);
	tmp = pile;
	i = 2;
	while (i < ac)
	{
		pile->next = lstnew(ft_atoi(av[i]));
		if (!pile->next)
			return (NULL);
		pile->next->prev = pile;
		pile = pile->next;
		i++;
	}
	pile->next = tmp;
	tmp->prev = pile;
	return (tmp);
}

t_pile	*lstadd_back(t_pile *pile, t_pile *new)
{
	t_pile	*tmp;

	if (!pile)
		return (new);
	tmp = pile;
	tmp->prev = new;
	while (tmp->next != pile)
		tmp = tmp->next;
	tmp->next = new;
	new->next = pile;
	new->prev = tmp;
	return (tmp);
}

t_pile	*lstadd_front(t_pile *pile, t_pile *new)
{
	t_pile	*tmp;

	// if (!pile->data)
	// 	return (lstnew(new->data));
	tmp = pile;
	while (tmp->next != pile)
		tmp = tmp->next;
	tmp->next = new;
	pile->prev = new;
	new->next = pile;
	new->prev = tmp; 
	pile = new;
	return (pile);
}

void	lst_del(t_pile **pile)
{
	t_pile	*tmp;

	if (*pile) 
	{
		tmp = (*pile)->next;
		(*pile)->prev->next = (*pile)->next;
		(*pile)->next->prev = (*pile)->prev;
		free(*pile);
		*pile = tmp;
	}
}