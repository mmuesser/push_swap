/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:10:38 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/24 22:51:06 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sep(t_pile **pile_a, t_pile **pile_b, t_data data)
{
	int	i;
	int	len_a;
	int	nb_mouv;

	nb_mouv = 0;
	len_a = pile_len(*pile_a);
	i = 0;
	while (i < len_a)
	{
		if ((*pile_a)->data <= data.f_quartile
			|| (*pile_a)->data > data.t_quartile)
		{
			*pile_a = rotate(*pile_a);
			write(1, "ra\n", 3);
			nb_mouv++;
		}
		else
		{
			push_b(pile_b, pile_a);
			write(1, "pb\n", 3);
			nb_mouv++;
			if ((*pile_b)->data <= data.mediane)
			{
				*pile_b = rotate(*pile_b);
				write(1, "rb\n", 3);
				nb_mouv++;
			}
		}
		i++;
	}
	while (pile_len(*pile_a) > 3)
	{
		push_b(pile_b, pile_a);
		nb_mouv++;
		if ((*pile_b)->data <= data.f_quartile)
		{
			*pile_b = rotate(*pile_b);
			write(1, "rb\n", 3);
			nb_mouv++;
		}
	}
	return (nb_mouv);
}
