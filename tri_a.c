/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/23 20:56:25 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_pile	*tri_a(t_pile *pile_a, t_pile *pile_b, int *nb_mouv)
// {
// 	int	lowest;
// 	int	len_a;
// 	int	len_b;
// 	int	count;
// 	int	i;
// 	int	save;

// 	lowest = pile_a->data;
// 	len_b = pile_len(pile_b);
// 	while (len_b > 0)
// 	{
// 		// display_pile(pile_a);
// 		if (pile_b->data < lowest)
// 			lowest = pile_b->data;
// 		// printf("elem de b à push : %d\n", pile_b->data);
// 		len_a = pile_len(pile_a);
// 		// printf("len_a : %d - len_b : %d\n", len_a, pile_len(pile_b));
// 		save = 2147483647;
// 		count = len_a;
// 		i = 0;
// 		while (i < len_a)
// 		{
// 			if (pile_b->data < pile_a->data)
// 			{
// 				// printf("%d > %d\n", save - pile_b->data, pile_a->data - pile_b->data);
// 				if ((save - pile_b->data) > (pile_a->data - pile_b->data))
// 				{
// 					save = pile_a->data;
// 					count = i;
// 				}
// 			}
// 			pile_a = pile_a->next;
// 			i++;
// 		}
// 		// printf("save : %d - count : %d\n", save, count);
// 		if (count == len_a)
// 		{
// 			while (pile_a->data != lowest)
// 			{
// 				pile_a = rotate(pile_a);
// 				*nb_mouv += 1;
// 			}
// 		}
// 		else if (count <= len_a / 2)
// 		{
// 			while (count > 0)
// 			{
// 				pile_a = rotate(pile_a);
// 				*nb_mouv += 1;
// 				count--;
// 			}
// 		}
// 		else if (count > len_a / 2)
// 		{
// 			while (count < len_a)
// 			{
// 				pile_a = reverse_rotate(pile_a);
// 				*nb_mouv += 1;
// 				count++;
// 			}
// 		}
// 		push_a(&pile_a, &pile_b);
// 		*nb_mouv += 1;
// 		len_b--;
// 		// display_pile(pile_a);
// 		// printf("b_mouv [%d] : %d\n\n", len_a, *nb_mouv);
// 		// printf("pile_a où push elem : %d\n\n", pile_a->data);
// 	}
// 	while (pile_a->data != lowest)
// 	{
// 		pile_a = reverse_rotate(pile_a);
// 		*nb_mouv += 1;
// 	}
// 	// printf("nb_mouv après : %d\n", *nb_mouv);
// 	return (pile_a);
// }

void	check_a(t_pile **pile_a, int *nb_mouv)
{
	int	lowest;
	int	highest;

	lowest = calcul_lowest(*pile_a);
	highest = calcul_highest(*pile_a);
	if ((*pile_a)->data == lowest)
	{
		if ((*pile_a)->next->data > (*pile_a)->prev->data)
		{
			*pile_a = swap(*pile_a);
			*nb_mouv += 1;
		}
	}
	else if ((*pile_a)->data == highest)
	{
		if ((*pile_a)->next->data > (*pile_a)->prev->data)
		{
			*pile_a = swap(*pile_a);
			*nb_mouv += 1;
		}
	}
	else
	{
		if ((*pile_a)->data > (*pile_a)->next->data)
		{
			*pile_a = swap(*pile_a);
			*nb_mouv += 1;
		}
	}
}

int	count_mouv(t_pile *pile_a, t_pile *pile_b)
{
	int	count;
	int	save;
	int	i;
	int	len_a;

	save = 2147483647;
	count = 0;
	len_a = pile_len(pile_a);
	i = 0;
	while (i < len_a)
	{
		if ((pile_a->data > pile_b->data) && (save > (pile_a->data - pile_b->data)))
		{
			save = pile_a->data - pile_b->data;
			count = i;
		}
		pile_a = pile_a->next;
		i++;
	}
	if (pile_b->data > calcul_highest(pile_a))
	{
		i = 0;
		while (i < len_a)
		{
			if (pile_a->data == calcul_lowest(pile_a))
				count = i;
			pile_a = pile_a->next;
			i++;
		}
	}
	return (count);
}

void	tri_a(t_pile **pile_a, t_pile **pile_b, int *nb_mouv)
{
	int	i;
	int	count_b;
	int	count_a;
	int	count_total;
	int	len_b;

	check_a(pile_a, nb_mouv);
	printf("nb_mouv après sep : %d\n", *nb_mouv);
	// display_pile(*pile_a);
	// printf("\n");
	len_b = pile_len(*pile_b);
	while (len_b > 0)
	{
		count_a = 0;
		count_b = 0;
		count_total = 2147483647;
		i = 0;
		while (i < pile_len(*pile_b))
		{
			if ((count_mouv(*pile_a, *pile_b) + i) < count_total)
			{
				count_a = count_mouv(*pile_a, *pile_b);
				count_b = i;
				count_total = count_a + count_b;
			}
			*pile_b = (*pile_b)->next;
			i++;
		}
		if (count_a > (pile_len(*pile_a) / 2) && count_b > (pile_len(*pile_b) / 2))
			*nb_mouv += rrr(pile_a, pile_b, count_a, count_b);
		else if (count_a <= (pile_len(*pile_a) / 2) && count_b <= (pile_len(*pile_b) / 2))
			*nb_mouv += rr(pile_a, pile_b, count_a, count_b);
		else
			*nb_mouv += r_and_rr(pile_a, pile_b, count_a, count_b);
		push_a(pile_a, pile_b);
		*nb_mouv += 1;
		len_b--;
	}
	printf("\n");
}