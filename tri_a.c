/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/02/21 15:29:27 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	is_trie(t_pile *pile_a, int lowest, int *count)
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
			*count += 1;
		}
		pile_a = pile_a->next;
		tmp = pile_a;
		pile_a = pile_a->next;
	}
}

static t_pile	*mouve(t_pile *pile_a, int count, int *nb_mouv, int j)
{
	while (count > 0 && count < j)
		{
			pile_a = swap(pile_a);
			printf("sa\n");
			*nb_mouv += 1;
			pile_a = rotate(pile_a);
			printf("ra\n");
			*nb_mouv += 1;
			count--;
		}
	pile_a = rotate(pile_a);
	printf("ra\n");
	*nb_mouv += 1;
	return (pile_a);
}

t_pile  *tri_a(t_pile *pile_a, int *nb_mouv, int nb_b, int ac)
{
	t_pile	*tmp;
	int     lowest;
	int		count;
	int		i;
	int     j;

	lowest = calcul_lowest(pile_a);
	j = ac - 1 - nb_b;
	i = 1;
	while (i)
	{
		count = 0;
		tmp = pile_a;
		if (is_trie(pile_a, lowest, &count) == 1)
			break ;
		while (pile_a->data != tmp->data)
			pile_a = pile_a->next;
		pile_a = mouve(pile_a, count, nb_mouv, j);
	}
	while (pile_a->data != lowest)
	{
		pile_a = rotate(pile_a);
		printf("ra\n");
		*nb_mouv += 1;
	}
	return (pile_a);
}