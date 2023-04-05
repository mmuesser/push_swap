/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_mediane2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:00:47 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 19:58:07 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*set_tmp_min_max(t_pile *pile, t_pile *tmp)
{
	int	lowest;

	lowest = calcul_lowest(tmp);
	while (tmp->data != lowest)
		tmp = tmp->next;
	tmp = lstadd_front(tmp, lstnew(pile->data));
	return (tmp);
}

t_pile	*set_tmp2(t_pile *pile, t_pile *tmp, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (pile->data > calcul_highest(tmp)
			|| pile->data < calcul_lowest(tmp))
			tmp = set_tmp_min_max(pile, tmp);
		j = -1;
		while (++j < pile_len(tmp))
		{
			if (pile->data > tmp->prev->data && pile->data < tmp->data)
			{
				tmp = lstadd_front(tmp, lstnew(pile->data));
				if (!tmp)
					return (NULL);
			}
			tmp = tmp->next;
		}
		pile = pile->next;
		i++;
	}
	return (tmp);
}

t_pile	*set_tmp(t_pile *pile, int len)
{
	t_pile	*tmp;

	tmp = lstnew(pile->data);
	if (!tmp)
		return (NULL);
	tmp = set_tmp2(pile, tmp, len);
	if (!tmp)
		return (NULL);
	while (tmp->data != calcul_lowest(tmp))
		tmp = tmp->next;
	return (tmp);
}
