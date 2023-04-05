/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:06:42 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 20:47:37 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*push_swap(t_pile *pile_a, t_pile *pile_b)
{
	t_data	*data;
	char	**str;

	str = NULL;
	if (check_double(pile_a) == 1)
	{
		free_pile(&pile_a);
		write(2, "Error\n", 6);
		return (NULL);
	}
	data = mediane(pile_a);
	if (pile_len(pile_a) <= 3)
		sort_3(&pile_a);
	else
	{
		// printf("test\n");
		pretri(&pile_a, &pile_b, data, str);
		tri_a(&pile_a, &pile_b, data, str);
	}
	set_a_final(&pile_a, data);
	free(data);
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
		return (0);
	pile_a = init_pile(ac, av);
	if (!pile_a)
		return (0);
	pile_b = NULL;
	pile_a = push_swap(pile_a, pile_b);
	if (!pile_a)
		return (0);
	free_pile(&pile_a);
	return (0);
}
