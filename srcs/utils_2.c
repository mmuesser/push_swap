/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:09:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 20:41:13 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_pile **pile_a, t_pile **pile_b, t_data *data, char **str)
{
	if (*pile_a)
		free_pile(pile_a);
	if (*pile_b)
		free_pile(pile_b);
	if (data)
		free(data);
	if (str)
		free_all(str);
	return (0);
}

int	check_double(t_pile *pile_a)
{
	int	len_a;
	int	nb;
	int	i;
	int	j;

	len_a = pile_len(pile_a);
	i = 0;
	while (i < len_a)
	{
		nb = pile_a->data;
		pile_a = pile_a->next;
		j = 1;
		while (j < len_a)
		{
			if (nb == pile_a->data)
				return (1);
			pile_a = pile_a->next;
			j++;
		}
		pile_a = pile_a->next;
		i++;
	}
	return (0);
}

void	set_a_final(t_pile **pile_a, t_data *data)
{
	int	lowest;

	lowest = calcul_lowest(*pile_a);
	while ((*pile_a)->data != lowest)
	{
		if ((*pile_a)->data <= data->mediane)
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
