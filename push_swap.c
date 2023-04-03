/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/03 12:02:31 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_a_final(t_pile **pile_a, t_data data)
{
	int	lowest;

	lowest = calcul_lowest(*pile_a);
	while ((*pile_a)->data != lowest)
	{
		if ((*pile_a)->data <= data.mediane)
		{
			*pile_a = reverse_rotate(*pile_a);
			write(1, "rra\n", 4);
		}
		else
		{
			*pile_a = rotate(*pile_a);
			write(1, "ra\n", 3);
		}
	}
}

t_pile	*push_swap(t_pile *pile_a, t_pile *pile_b)
{
	t_data	data;

	data = mediane(pile_a);
	if (pile_len(pile_a) <= 3)
		sort_3(&pile_a);
	else
	{
		pretri(&pile_a, &pile_b, data);
		tri_a(&pile_a, &pile_b);
	}
	set_a_final(&pile_a, data);
	return (pile_a);
}
