/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/21 22:47:54 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac - 1)
	{
		j = ft_atoi(av[i]);
		k = ft_atoi(av[i + 1]);
		if (k < j)
			return (0);
		i++;
	}
	return (1);
}

void	display_pile(t_pile *pile)
{
	int	len;
	int	i;

	len = pile_len(pile);
	i = 0;
	while (i < len)
	{
		printf("pile : %d\n", pile->data);
		pile = pile->next;
		i++;
	}

}

int	pile_len(t_pile *pile)
{
	int		i;
	t_pile	*tmp;

	if (pile->next->data == pile->data)
		return (1);
	tmp = pile;
	pile = pile->next;
	i = 1;
	while (pile != tmp)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int		nb_mouv;
	t_data	data;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (parsing_arg(ac, av) == 0)
		return (0);
	pile_a = init_pile(ac, av);
	nb_mouv = 0;
	if (check_order(ac, av) == 1)
	{
		display_pile(pile_a);
		printf("nb_mouv : %d\n", nb_mouv);
		return (0);
	}
	pile_b = NULL;
	data = mediane(pile_a, data, ac);
	nb_mouv += sep(&pile_a, &pile_b, data);
	// display_pile(pile_b);
	printf("nb_mouv après sep : %d\n", nb_mouv);
	pile_a = tri_a(pile_a, pile_b, &nb_mouv);
	// printf("\n");
	// printf("pile a :\n");
	// display_pile(pile_a);
	// printf("\nlen_a : %d\n", pile_len(pile_a));
	printf("nb_mouv : %d\n", nb_mouv);
	return (0);
}