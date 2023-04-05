/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:06:42 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 11:31:46 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (parsing_arg(ac, av) == 1 || ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_order(ac, av) == 1)
		return (0);
	pile_a = init_pile(ac, av);
	pile_b = NULL;
	pile_a = push_swap(pile_a, pile_b);
	free_pile(&pile_a);
	return (0);
}
