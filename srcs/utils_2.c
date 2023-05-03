/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:09:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/06 12:08:49 by mmuesser         ###   ########.fr       */
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
		free_str(str);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}
