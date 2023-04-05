/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_mediane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:41:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 19:23:08 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_mediane(t_data **data, t_pile **tmp, int len)
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
	(*data)->mediane = (*tmp)->data;
	return (len);
}

void	calcul_t_quartile(t_data **data, t_pile **tmp, int len)
{
	int	i;

	i = 0;
	while (i < (len / 2))
	{
		*tmp = (*tmp)->next;
		i++;
	}
	(*data)->t_quartile = (*tmp)->data;
}

void	calcul_f_quartile(t_data **data, t_pile **tmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*tmp = (*tmp)->next;
		i++;
	}
	(*data)->f_quartile = (*tmp)->data;
}

t_data	*mediane(t_pile *pile)
{
	t_data	*data;
	t_pile	*tmp;
	int		len;	

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	len = pile_len(pile);
	tmp = set_tmp(pile, len);
	if (!tmp)
		return (NULL);
	len = calcul_mediane(&data, &tmp, len);
	calcul_t_quartile(&data, &tmp, len);
	calcul_f_quartile(&data, &tmp, len);
	free_pile(&tmp);
	return (data);
}
