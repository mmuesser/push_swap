/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/21 22:46:39 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*tri_a(t_pile *pile_a, t_pile *pile_b, int *nb_mouv)
{
	int	lowest;
	int	len_a;
	int	len_b;
	int	count;
	int	i;
	int	save;

	lowest = pile_a->data;
	len_b = pile_len(pile_b);
	while (len_b > 0)
	{
		// display_pile(pile_a);
		if (pile_b->data < lowest)
			lowest = pile_b->data;
		// printf("elem de b à push : %d\n", pile_b->data);
		len_a = pile_len(pile_a);
		// printf("len_a : %d - len_b : %d\n", len_a, pile_len(pile_b));
		save = 2147483647;
		count = len_a;
		i = 0;
		while (i < len_a)
		{
			if (pile_b->data < pile_a->data)
			{
				// printf("%d > %d\n", save - pile_b->data, pile_a->data - pile_b->data);
				if ((save - pile_b->data) > (pile_a->data - pile_b->data))
				{
					save = pile_a->data;
					count = i;
				}
			}
			pile_a = pile_a->next;
			i++;
		}
		// printf("save : %d - count : %d\n", save, count);
		if (count == len_a)
		{
			while (pile_a->data != lowest)
			{
				pile_a = rotate(pile_a);
				*nb_mouv += 1;
			}
		}
		else if (count <= len_a / 2)
		{
			while (count > 0)
			{
				pile_a = rotate(pile_a);
				*nb_mouv += 1;
				count--;
			}
		}
		else if (count > len_a / 2)
		{
			while (count < len_a)
			{
				pile_a = reverse_rotate(pile_a);
				*nb_mouv += 1;
				count++;
			}
		}
		push_a(&pile_a, &pile_b);
		*nb_mouv += 1;
		len_b--;
		// display_pile(pile_a);
		// printf("b_mouv [%d] : %d\n\n", len_a, *nb_mouv);
		// printf("pile_a où push elem : %d\n\n", pile_a->data);
	}
	// printf("nb_mouv avant : %d\n", *nb_mouv);
	// i = 0;
	// while (i < len_a)
	// {
	// 	if (pile_a->data == lowest)
	// 		count = i;
	// 	i++;
	// }
	// count++;
	// if (count > len_a / 2)
	// {
	// 	while (pile_a->data != lowest)
	// 	{
	// 		pile_a = reverse_rotate(pile_a);
	// 		*nb_mouv += 1;
	// 	}
	// }
	// else if (count <= len_a / 2)
	// {
	// 	while (pile_a->data != lowest)
	// 	{
	// 		pile_a = rotate(pile_a);
	// 		*nb_mouv += 1;
	// 	}
	// }
	while (pile_a->data != lowest)
	{
		pile_a = reverse_rotate(pile_a);
		*nb_mouv += 1;
	}
	// printf("nb_mouv après : %d\n", *nb_mouv);
	return (pile_a);
}

// int	set_count(t_pile *pile_a)
// {
// 	t_pile	*tmp;
// 	int		count;
// 	int		len_pile;
// 	int		i;

// 	tmp = pile_a;
// 	count = 0;
// 	len_pile = pile_len(pile_a);
// 	i = 0;
// 	while (i < len_pile)
// 	{
// 		if (tmp->data < pile_a->data)
// 		{
// 			if (count == 0)
// 				count = i;
// 		}
// 		pile_a = pile_a->next;
// 		i++;
// 	}
// 	count--;
// 	return (count);
// }

// t_pile	*mouv(t_pile *pile_a, t_pile *pile_b, int count, int *nb_mouv)
// {
// 	int	len_pile;

// 	len_pile = pile_len(pile_a);
// 	if (count != 0)
// 	{
// 		push_b(&pile_b, &pile_a);
// 		*nb_mouv += 1;
// 		if (count < (len_pile / 2))
// 		{
// 			while (count > 0)
// 			{
// 				pile_a = rotate(pile_a);
// 				*nb_mouv += 1;
// 				count--;
// 			}
// 		}
// 		else
// 		{
// 			while (count < len_pile)
// 			{
// 				pile_a = reverse_rotate(pile_a);
// 				*nb_mouv += 1;
// 				count++;
// 			}
// 		}
// 		push_a(&pile_a, &pile_b);
// 	}
// 	return (pile_a);
// }

// t_pile	*blabla(t_pile *pile_a, t_pile *pile_b, int *nb_mouv, int lowest)
// {
// 	int	count;
// 	while (is_trie(pile_a, lowest) != 1)
// 	{
// 		count = set_count(pile_a);
// 		pile_a = mouv(pile_a, pile_b, count, nb_mouv);
// 		pile_a = rotate(pile_a);
// 		*nb_mouv += 1;
// 	}
// 	return (pile_a);
// }

// t_pile	*tri_a(t_pile *pile_a, t_pile *pile_b, int *nb_mouv)
// {
// 	int		lowest;

// 	lowest = calcul_lowest(pile_a);
// 	if (is_trie(pile_a, lowest) == 1)
// 		return (pile_a);
// 	pile_a = blabla(pile_a, pile_b, nb_mouv, lowest);
// 	while (pile_a->data != lowest)
// 	{
// 		pile_a = rotate(pile_a);
// 		*nb_mouv += 1;
// 	}
// 	return (pile_a);
// }