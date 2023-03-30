/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:24:59 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/30 20:57:16 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_op2(t_pile **pile_a, t_pile **pile_b, char **list_op, int i)
{
	if (ft_strcmp(list_op[i], "rr") == 0)
	{
		*pile_a = rotate(*pile_a);
		*pile_b = rotate(*pile_b);
	}
	else if (ft_strcmp(list_op[i], "rra") == 0)
		*pile_a = reverse_rotate(*pile_a);
	else if (ft_strcmp(list_op[i], "rrb") == 0)
		*pile_b = reverse_rotate(*pile_b);
	else if (ft_strcmp(list_op[i], "rrr") == 0)
	{
		*pile_a = reverse_rotate(*pile_a);
		*pile_b = reverse_rotate(*pile_b);
	}
}

void	do_op(t_pile **pile_a, t_pile **pile_b, char **list_op)
{
	int	i;
	
	i = 0;
	while (list_op[i])
	{
		if (ft_strcmp(list_op[i], "sa") == 0)
			*pile_a = swap(*pile_a);
		else if (ft_strcmp(list_op[i], "sb") == 0)
			*pile_b = swap(*pile_b);
		else if (ft_strcmp(list_op[i], "pa") == 0)
			push_a(pile_a, pile_b);
		else if (ft_strcmp(list_op[i], "pb") == 0)
			push_b(pile_b, pile_a);
		else if (ft_strcmp(list_op[i], "ra") == 0)
			*pile_a = rotate(*pile_a);
		else if (ft_strcmp(list_op[i], "rb") == 0)
			*pile_b = rotate(*pile_b);
		do_op2(pile_a, pile_b, list_op, i);
		i++;
	}
}