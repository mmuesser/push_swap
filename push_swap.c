/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/27 15:14:45 by mmuesser         ###   ########.fr       */
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

void	free_pile(t_pile **pile)
{
	int	len;
	int	i;

	len = pile_len(*pile);
	i = 0;
	while (i < len)
	{
		lst_del(pile);
		i++;
	}
}

t_pile	*push_swap(t_pile *pile_a, t_pile *pile_b)
{
	t_data	data;
	int		nb_mouv;

	nb_mouv = 0;
	data = mediane(pile_a);
	nb_mouv += pretri(&pile_a, &pile_b, data);
	tri_a(&pile_a, &pile_b, &nb_mouv);
	while (pile_a->data != calcul_lowest(pile_a))
	{
		pile_a = reverse_rotate(pile_a);
		write(1, "rra\n", 4);
		nb_mouv++;
	}
	printf("nb_mouv : %d\n", nb_mouv);
	return (pile_a);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (parsing_arg(ac, av) == 1 || ac == 1)
		return (0);
	if (check_order(ac, av) == 1)
	{
		write(1, "Les éléments sont déjà dans l'ordre.\n", 41);
		return (0);
	}
	pile_a = init_pile(ac, av);
	pile_b = NULL;
	if ()
	pile_a = push_swap(pile_a, pile_b);
	free_pile(&pile_a);
	return (0);
}
