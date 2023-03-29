/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:34:11 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/29 15:30:29 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_len(t_pile *pile)
{
	int		i;
	t_pile	*tmp;

	tmp = pile;
	pile = pile->next;
	i = 1;
	while (pile->data != tmp->data)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void	free_pile(t_pile **pile)
{
	int	len;
	int	i;

	len = pile_len(*pile);
	i = 0;
	while (i < len)
	{
		lst_del(pile);
		i++;
	}
}

int	calcul_lowest(t_pile *pile)
{
	int	lowest;
	int	len;
	int	i;

	len = pile_len(pile);
	lowest = pile->data;
	i = 0;
	while (i < len)
	{	
		if (pile->data < lowest)
			lowest = pile->data;
		pile = pile->next;
		i++;
	}
	return (lowest);
}

int	calcul_highest(t_pile *pile)
{
	int	highest;
	int	len;
	int	i;

	len = pile_len(pile);
	highest = pile->data;
	i = 0;
	while (i < len)
	{
		if (pile->data > highest)
			highest = pile->data;
		pile = pile->next;
		i++;
	}
	return (highest);
}

void	set_a_final(t_pile **pile_a, t_data data)
{
	int	lowest;

	lowest = calcul_lowest(*pile_a);
	while ((*pile_a)->data != lowest)
	{
		if ((*pile_a)->data <= data.mediane)
		{
			*pile_a = reverse_rotate(*pile_a);
			write(1, "rra\n", 4);
		}
		else
		{
			*pile_a = rotate(*pile_a);
			write(1, "ra\n", 3);
		}
	}
}
