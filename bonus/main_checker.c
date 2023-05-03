/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:01:11 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/06 12:10:01 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_pile	*checker(t_pile *pile_a, t_pile *pile_b, int ac)
{
	char	**list_op;

	if (check_double(pile_a) == 1)
	{
		free_pile(&pile_a);
		write(2, "Error\n", 6);
		return (NULL);
	}
	list_op = create_list_op();
	if (!list_op)
	{
		write(2, "Error\n", 6);
		return (pile_a);
	}
	do_op(&pile_a, &pile_b, list_op);
	if (check_pile(pile_a, ac) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_str(list_op);
	if (pile_b)
		free_pile(&pile_b);
	return (pile_a);
}

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
	if (!pile_a)
		return (0);
	free_pile(&pile_a);
	return (0);
}
