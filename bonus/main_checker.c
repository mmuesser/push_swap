/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:01:11 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 11:39:15 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac == 1)
		return (0);
	if (parsing_arg(ac, av) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_order(ac, av) == 1)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	pile_a = init_pile(ac, av);
	if (!pile_a)
		return (0);
	pile_b = NULL;
	pile_a = checker(pile_a, pile_b, ac);
	free_pile(&pile_a);
	return (0);
}
