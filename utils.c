/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:34:11 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/27 15:14:56 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	display_pile(t_pile *pile)
// {
// 	int	len;
// 	int	i;

// 	len = pile_len(pile);
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("pile : %d\n", pile->data);
// 		pile = pile->next;
// 		i++;
// 	}
// }

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

void	sort_3(t_pile **pile, int *nb_mouv)
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
		*nb_mouv += 1;
	}
}
