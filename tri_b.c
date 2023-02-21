/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:43:59 by mmuesser          #+#    #+#             */
/*   Updated: 2023/02/21 15:28:11 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_highest(t_pile *pile_b)
{
	int		highest;
	t_pile	*tmp;

	highest = pile_b->data;
	tmp = pile_b;
	pile_b = pile_b->next;
	while (pile_b->data != tmp->data)
	{	
		if (pile_b->data > highest)
			highest = pile_b->data;
		pile_b = pile_b->next;
	}
	return (highest);
}

static int	is_trie(t_pile *pile_b, int highest, int *count)
{
	t_pile	*tmp;

	tmp = pile_b;
	pile_b = pile_b->next;
	while (1)
	{
		if (check_b(pile_b, highest) == 1)
			return (1);
		while (pile_b->data != tmp->data)
		{
			if (tmp->data < pile_b->prev->data && tmp->data > pile_b->data)
				return (0);
			pile_b = pile_b->next;
			*count += 1;
		}
		pile_b = pile_b->next;
		tmp = pile_b;
		pile_b = pile_b->next;
	}
}

static t_pile	*mouve(t_pile *pile_b, int count, int *nb_mouv, int nb_b)
{
	while (count > 0 && count < nb_b - 1)
		{
			pile_b = swap(pile_b);
			printf("sb\n");
			*nb_mouv += 1;
			pile_b = rotate(pile_b);
			printf("rb\n");
			*nb_mouv += 1;
			count--;
		}
	pile_b = rotate(pile_b);
	printf("rb\n");
	*nb_mouv += 1;
	return (pile_b);
}

t_pile  *tri_b(t_pile *pile_b, int *nb_mouv, int nb_b)
{
	t_pile	*tmp;
	int     highest;
	int		count;
	int		i;
	
	highest = calcul_highest(pile_b);
	i = 1;
	while (i)
	{
		count = 0;
		tmp = pile_b;
		if (is_trie(pile_b, highest, &count) == 1)
			break ;
		while (pile_b->data != tmp->data)
			pile_b = pile_b->next;
		pile_b = mouve(pile_b, count, nb_mouv, nb_b);
	}
	while (pile_b->data != highest)
	{
		pile_b = rotate(pile_b);
		printf("rb\n");
		*nb_mouv += 1;
	}
	return (pile_b);
}