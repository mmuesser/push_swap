/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:42:44 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/31 16:23:19 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_pile(t_pile *pile_a, int ac)
{
	int	len_a;
	int	i;

	len_a = pile_len(pile_a);
	if (len_a != ac - 1)
		return (1);
	pile_a = pile_a->next;
	i = 1;
	while (i < len_a)
	{
		if (pile_a->data < pile_a->prev->data)
			return (1);
		pile_a = pile_a->next;
		i++;
	}
	return (0);
}
