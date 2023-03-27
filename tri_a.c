/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/27 15:15:33 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_mouv_2(t_pile *pile_a, t_pile *pile_b, int pb)
{
	int	i;
	int	count;
	int	diff;

	if (pb > (pile_len(pile_b) / 2))
		count = pile_len(pile_b) - pb;
	else
		count = pb;
	diff = pile_a->data - pile_b->data;
	i = -1;
	while (++i < pile_len(pile_a))
	{
		if (pile_a->data > pile_b->data && diff > (pile_a->data - pile_b->data)
			|| (pile_b->data > calcul_highest(pile_a)
				&& pile_a->data == calcul_lowest(pile_a)))
		{
			diff = pile_a->data - pile_b->data;
			if (i > (pile_len(pile_a) / 2))
				count += pile_len(pile_a) - i;
			else
				count += i;
		}
		pile_a = pile_a->next;
	}
	return (count);
}

int	count_mouv(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	elem;
	int	count;

	elem = pile_b->data;
	count = count_mouv_2(pile_a, pile_b, 0);
	i = 1;
	while (i < pile_len(pile_b))
	{
		if (count_mouv_2(pile_a, pile_b, i) < count)
		{
			elem = pile_b->data;
			count = count_mouv_2(pile_a, pile_b, i);
		}
		pile_b = pile_b->next;
		i++;
	}
	return (elem);
}

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

int	count_a(t_pile *pile_a, int elem)
{
	int	i;
	int	len_a;
	int	diff;
	int	count;

	len_a = pile_len(pile_a);
	diff = 2147483647;
	count = 0;
	i = 0;
	while (i < len_a)
	{
		if ((pile_a->data > elem && diff > (pile_a->data - elem))
			|| (elem > calcul_highest(pile_a)
				&& pile_a->data == calcul_lowest(pile_a)))
		{
			diff = pile_a->data - elem;
			count = i;
		}
		pile_a = pile_a->next;
		i++;
	}
	return (count);
}

void	tri_a(t_pile **pile_a, t_pile **pile_b, int *nb_mouv)
{
	int	i;
	int	elem;
	int	cb;
	int	ca;
	int	len_b;

	sort_3(pile_a, nb_mouv);
	len_b = pile_len(*pile_b);
	while (len_b > 0)
	{
		cb = 0;
		ca = 0;
		elem = count_mouv(*pile_a, *pile_b);
		cb = count_b(*pile_b, elem);
		ca = count_a(*pile_a, elem);
		*nb_mouv += rotate_a_and_b(pile_a, pile_b, ca, cb);
		push_a(pile_a, pile_b);
		write(1, "pa\n", 3);
		*nb_mouv += 1;
		len_b--;
	}
}
