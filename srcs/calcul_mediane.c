/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_mediane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:41:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/27 12:19:42 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_mediane(t_data *data, t_pile **tmp, int len)
{
	int	i;

	if (len % 2 == 0)
		len /= 2;
	else
	{
		len /= 2;
		len++;
	}
	i = 1;
	while (i < len)
	{
		*tmp = (*tmp)->next;
		i++;
	}
	data->mediane = (*tmp)->data;
	return (len);
}

void	calcul_t_quartile(t_data *data, t_pile **tmp, int len)
{
	int	i;

	i = 0;
	while (i < (len / 2))
	{
		*tmp = (*tmp)->next;
		i++;
	}
	data->t_quartile = (*tmp)->data;
}

void	calcul_f_quartile(t_data *data, t_pile **tmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*tmp = (*tmp)->next;
		i++;
	}
	data->f_quartile = (*tmp)->data;
}

t_pile	*set_tmp(t_pile *pile, int len)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;

	tmp = lstnew(pile->data);
	i = -1;
	while (++i < len)
	{
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
	}
	return (tmp);
}

t_data	mediane(t_pile *pile)
{
	t_data	data;
	t_pile	*tmp;
	int		len;	

	len = pile_len(pile);
	tmp = set_tmp(pile, len);
	len = calcul_mediane(&data, &tmp, len);
	calcul_t_quartile(&data, &tmp, len);
	calcul_f_quartile(&data, &tmp, len);
	free_pile(&tmp);
	return (data);
}
