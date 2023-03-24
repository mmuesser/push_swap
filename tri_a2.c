/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:10:50 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/23 20:34:24 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	rrr(t_pile **pile_a, t_pile **pile_b, int count_a, int count_b)
{
	int	len_a;
	int	len_b;
	int	nb_mouv;

	nb_mouv = 0;
	len_a = pile_len(*pile_a);
	len_b = pile_len(*pile_b);
	while (count_a < len_a && count_b < len_b)
	{
		*pile_a = reverse_rotate(*pile_a);
		count_a++;
		*pile_b = reverse_rotate(*pile_b);
		count_b++;
		// printf("rrr\n");
		nb_mouv++;
	}
	while (count_a < len_a)
	{
		*pile_a = reverse_rotate(*pile_a);
		count_a++;
		// printf("rra\n");
		nb_mouv++;
	}
	while (count_b < len_b)
	{
		*pile_b = reverse_rotate(*pile_b);
		count_b++;
		// printf("rrb\n");
		nb_mouv++;
	}
	return (nb_mouv);
}

int	rr(t_pile **pile_a, t_pile **pile_b, int count_a, int count_b)
{
	int	nb_mouv;

	nb_mouv = 0;
	while (count_a > 0 && count_b > 0)
	{
		*pile_a = rotate(*pile_a);
		count_a--;
		*pile_b = rotate(*pile_b);
		count_b--;
		// printf("rr\n");
		nb_mouv++;
	}
	while (count_a > 0)
	{
		*pile_a = rotate(*pile_a);
		count_a--;
		// printf("ra\n");
		nb_mouv++;
	}
	while (count_b > 0)
	{
		*pile_b = rotate(*pile_b);
		count_b--;
		// printf("rb\n");
		nb_mouv++;
	}
	return (nb_mouv);
}

int	r_and_rr(t_pile **pile_a, t_pile **pile_b, int count_a, int count_b)
{
	int	nb_mouv;

	nb_mouv = 0;
	if (count_a > (pile_len(*pile_a) / 2))
	{
		while (count_a < pile_len(*pile_a))
		{
			*pile_a = reverse_rotate(*pile_a);
			nb_mouv++;
			// printf("rra\n");
			count_a++;
		}
		while (count_b > 0)
		{
			*pile_b = rotate(*pile_b);
			nb_mouv++;
			// printf("rb\n");
			count_b--;
		}
	}
	else
	{
		while (count_b < pile_len(*pile_b))
		{
			*pile_b = reverse_rotate(*pile_b);
			nb_mouv++;
			// printf("rrb\n");
			count_b++;
		}
		while (count_a > 0)
		{
			*pile_a = rotate(*pile_a);
			nb_mouv++;
			// printf("ra\n");
			count_a--;
		}
	}
	return (nb_mouv);
}