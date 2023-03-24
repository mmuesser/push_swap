/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_mediane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:41:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/24 17:16:40 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	mediane(t_pile *pile, t_data data, int ac)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;

	tmp = NULL;
	ac -= 1;
	i = 0;
	while (i < ac)
	{
		if (!tmp)
			tmp = lstnew(pile->data);
		if (pile->data > tmp->data)
		{
			tmp2 = tmp;
			while (pile->data < tmp->prev->data)
				tmp = tmp->prev;
			lstadd_back(tmp, lstnew(pile->data));
			tmp = tmp2;
		}
		if (pile->data < tmp->data)
		{
			lstadd_front(tmp, lstnew(pile->data));
			tmp = tmp->prev;
		}
		pile = pile->next;
		i++;
	}
	ac -= 1;
	if (ac % 2 == 0)
		ac /= 2;
	else
	{
		ac /= 2;
		ac++;
	}
	i = 0;
	while (i < ac)
	{
		tmp = tmp->next;
		i++;
	}
	data.mediane = tmp->data;
	i = 0;
	while (i < (ac / 2))
	{
		tmp = tmp->next;
		i++;
	}
	data.t_quartile = tmp->data;
	i = 0;
	while (i < ac)
	{
		tmp = tmp->next;
		i++;
	}
	data.f_quartile = tmp->data;
	return (data);
}
