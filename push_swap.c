/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/26 19:19:52 by mmuesser         ###   ########.fr       */
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

	tmp = pile;
	pile = pile->next;
	i = 1;
	while (pile->data != tmp->data)
	{
		pile = pile->next;
		i++;
	}
	return (i);
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

void	push_swap(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_data	data;
	int		nb_mouv;

	pile_a = init_pile(ac, av);
	pile_b = NULL;
	data = mediane(pile_a, data, ac);
	nb_mouv = 0;
	nb_mouv += sep(&pile_a, &pile_b, data);	tri_a(&pile_a, &pile_b, &nb_mouv);
	while (pile_a->data != calcul_lowest(pile_a))
	{
		pile_a = reverse_rotate(pile_a);
		write(1, "rra\n", 4);
		nb_mouv++;
	}
	// display_pile(pile_a);
	printf("nb_mouv : %d\n", nb_mouv);
	free_pile(&pile_a);
}

int	main(int ac, char **av)
{
	if (parsing_arg(ac, av) == 0 || ac == 1)
		return (0);
	if (check_order(ac, av) == 1)
	{
		write(1, "Les éléments sont déjà dans l'ordre.\n", 37);
		return (0);
	}
	push_swap(ac, av);
	return (0);
}
