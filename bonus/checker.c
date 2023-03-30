/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:11:09 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/30 20:53:50 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_pile	*checker(t_pile *pile_a, t_pile *pile_b, int ac)
{
	char	**list_op;

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
	free_list_op(list_op);
	return (pile_a);
}

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
	{
		write(1, "OK\n", 3);
		return (0);
	}
	pile_a = init_pile(ac, av);
	pile_b = NULL;
	pile_a = checker(pile_a, pile_b, ac);
	free_pile(&pile_a);
	return (0);
}