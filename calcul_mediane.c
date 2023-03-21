/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_mediane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:41:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/01 20:18:40 by mmuesser         ###   ########.fr       */
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
	while(i < (ac / 2))
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

// t_data	calcul(t_data data, t_pile *pile_a, int ac)
// {
// 	t_pile	*tmp;
// 	t_pile	*tmp2;
// 	int		i;
// 	int		nb_tmp;

// 	tmp2 = pile_a;
// 	tmp = NULL;
// 	// printf("ac 1 : %d\n", ac);
// 	data.mediane = mediane(tmp2, ac);
// 	// printf("med : %d\n", data.mediane);
// 	nb_tmp = 0;
// 	i = 0;
// 	// display_pile(tmp2);
// 	while (i < ac)
// 	{
// 		if (tmp2->data >= data.mediane)
// 		{
// 			// printf("tmp2 : %d - med : %d\n", tmp2->data, data.mediane);
// 			push_b(&tmp2, &tmp);
// 			nb_tmp++;
// 		}
// 		tmp2 = tmp2->next;
// 		// printf("tmp2 : %d\n", tmp2->data);
// 		i++;
// 	}
// 	// printf("nb_tmp : %d\n", nb_tmp);
// 	data.f_quartile = mediane(tmp2, ac - nb_tmp);
// 	data.t_quartile = mediane(tmp, nb_tmp - 1);
// 	return (data);
// }