/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:10:38 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/28 21:44:19 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pretri_2(t_pile **pile_a, t_pile **pile_b, t_data data)
{
	while (pile_len(*pile_a) > 3)
	{
		push_b(pile_b, pile_a);
		write(1, "pb\n", 3);
		if ((*pile_b)->data <= data.f_quartile)
		{
			*pile_b = rotate(*pile_b);
			write(1, "rb\n", 3);
		}
	}
}

void	inf_fquartile_and_sup_tquartile(t_pile **pile_a, t_pile **pile_b)
{
	*pile_a = rotate(*pile_a);
	write(1, "ra\n", 3);
}

void	sup_fq_and_inf_tq(t_pile **pile_a, t_pile **pile_b, t_data data)
{
	push_b(pile_b, pile_a);
	write(1, "pb\n", 3);
	if ((*pile_b)->data <= data.mediane)
	{
		*pile_b = rotate(*pile_b);
		write(1, "rb\n", 3);
	}
}

void	pretri(t_pile **pile_a, t_pile **pile_b, t_data data)
{
	int	i;
	int	len_a;

	len_a = pile_len(*pile_a);
	i = 0;
	while (i < len_a)
	{
		if ((*pile_a)->data <= data.f_quartile
			|| (*pile_a)->data > data.t_quartile)
			inf_fquartile_and_sup_tquartile(pile_a, pile_b);
		else
			sup_fq_and_inf_tq(pile_a, pile_b, data);
		i++;
	}
	pretri_2(pile_a, pile_b, data);
}
