/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/28 23:55:52 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	count_mouv_2_old(t_pile *pile_a, t_pile *pile_b, int pb)
// {
// 	int	i;
// 	int	count;
// 	int	diff;

// 	if (pb > (pile_len(pile_b) / 2))
// 		count = pile_len(pile_b) - pb;
// 	else
// 		count = pb;
// 	// printf("count pb : %d\n", count);
// 	diff = 2147483647;
// 	i = -1;
// 	while (++i < pile_len(pile_a))
// 	{
// 		if (pile_a->data > pile_b->data && diff > (pile_a->data - pile_b->data)
// 			|| (pile_b->data > calcul_highest(pile_a)
// 				&& pile_a->data == calcul_lowest(pile_a)))
// 		{
// 			// printf("old : pile_b : %d - pile_a prev : %d - pile_a : %d\n", pile_b->data, pile_a->prev->data, pile_a->data);
// 			diff = pile_a->data - pile_b->data;
// 			if (i > (pile_len(pile_a) / 2))
// 				count += pile_len(pile_a) - i;
// 			else
// 				count += i;
// 		}
// 		pile_a = pile_a->next;
// 	}
// 	// printf("count final : %d\n", count);
// 	return (count);
// }

// int	count_mouv_old(t_pile *pile_a, t_pile *pile_b)
// {
// 	int	i;
// 	int	elem;
// 	int	count;
// 	int count_elem;

// 	elem = pile_b->data;
// 	count = count_mouv_2_old(pile_a, pile_b, 0);
// 	i = 1;
// 	while (i < pile_len(pile_b))
// 	{
// 		count_elem = count_mouv_2_old(pile_a, pile_b, i);
// 		if (count_elem < count)
// 		{
// 			elem = pile_b->data;
// 			count = count_elem;
// 		}
// 		pile_b = pile_b->next;
// 		i++;
// 	}
// 	// printf("count old : %d\n", count);
// 	return (elem);
// }

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

// int	count_a_old(t_pile *pile_a, int elem)
// {
// 	int	i;
// 	int	len_a;
// 	int	diff;
// 	int	count;

// 	len_a = pile_len(pile_a);
// 	diff = 2147483647;
// 	count = 0;
// 	i = 0;
// 	while (i < len_a)
// 	{
// 		if ((pile_a->data > elem && diff > (pile_a->data - elem))
// 			|| (elem > calcul_highest(pile_a)
// 				&& pile_a->data == calcul_lowest(pile_a)))
// 		{
// 			diff = pile_a->data - elem;
// 			count = i;
// 		}
// 		pile_a = pile_a->next;
// 		i++;
// 	}
// 	return (count);
// }

int    count_a(t_pile *pile_a, int elem)
{
	int    lowest;
	int    count;
	int    len_a;
	int    i;

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

void	set_a(t_pile **pile_a)
{
	int	len_a;
	int	i;
	int	count;

	len_a = pile_len(*pile_a);
	i = 0;
	while (i < len_a)
	{
		if ((*pile_a)->data == calcul_lowest(*pile_a))
			count = i;
		*pile_a = (*pile_a)->next;
		i++;
	}
	if (count > len_a / 2)
	{
		while ((*pile_a)->data != calcul_lowest(*pile_a))
		{
			*pile_a = reverse_rotate(*pile_a);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while ((*pile_a)->data != calcul_lowest(*pile_a))
		{
			*pile_a = rotate(*pile_a);
			write(1, "ra\n", 3);
		}
	}
}

void	tri_a(t_pile **pile_a, t_pile **pile_b)
{
	int	i;
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
		push_a(pile_a, pile_b);
		write(1, "pa\n", 3);
		len_b--;
	}
	set_a(pile_a);
}
