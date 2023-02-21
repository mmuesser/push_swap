/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:46:31 by mmuesser          #+#    #+#             */
/*   Updated: 2023/02/21 15:34:02 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test(char *str, int nb, int j)
{
	while (j >= 0)
	{
		if (str[j] != nb % 10 + 48)
			return (1);
		nb /= 10;
		j--;
	}
	return (0);
}

int	parsing_arg(int ac, char **av)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("error_1\n");
				return (0);
			}
			j++;
		}
		nb = ft_atoi(av[i]);
		if (test(av[i], nb, j - 1) == 1)
		{
			printf("error_2\n");
			return (0);
		}
		i++;
	}
	return (1);
}

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

int	check_b(t_pile *pile_b, int nb)
{
	while (pile_b->data != nb)
			pile_b = rotate(pile_b);
	while (pile_b->data > pile_b->next->data)
		pile_b = pile_b->next;
	pile_b = pile_b->next;
	if (pile_b->data == nb)
	{
		return (1);
	}
	else
		return (0);
}

int	check_a(t_pile *pile_a, int nb)
{
	while (pile_a->data != nb)
			pile_a = rotate(pile_a);
	while (pile_a->data < pile_a->next->data)
		pile_a = pile_a->next;
	pile_a = pile_a->next;
	if (pile_a->data == nb)
	{
		return (1);
	}
	else
		return (0);
}

void	display_pile(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile->prev;
	while (pile->data != tmp->data)
	{
		printf("pile : %d\n", pile->data);
		pile = pile->next;
	}
	printf("pile : %d\n", pile->data);

}

int	sep_mediane(t_pile **pile_a, t_pile **pile_b, int *nb_mouv, int ac)
{
	int	nb_b;
	int	i;
	int	med;

	med = mediane(*pile_a, ac);
	nb_b = 0;
	i = 0;
	while (i < ac - 1)
	{
		if ((*pile_a)->data >= med)
		{
			push_b(pile_a, pile_b);
			nb_b++;
			printf("pb\n");
			*nb_mouv += 1;
		}
		else
		{
			*pile_a = rotate(*pile_a);
			printf("ra\n");
			*nb_mouv += 1;
		}
		i++;
	}
	return (nb_b);
}

int	main(int ac, char **av)
{
	int 	i;
	int		lowest;
	int		nb_b;
	int		nb_mouv;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (parsing_arg(ac, av) == 0)
		return (0);
	nb_mouv = 0;
	pile_a = init_pile(pile_a, ac, av);
	if (check_order(ac, av) == 1)
	{
		display_pile(pile_a);
		return (0);
	}
	pile_b = NULL;
	i = 0;
	lowest = pile_a->data;
	while (i < ac - 1)
	{
		if (pile_a->data < lowest)
			lowest = pile_a->data;
		pile_a = pile_a->next;
		i++;
	}
	nb_b = 0;
	nb_b = sep_mediane(&pile_a, &pile_b, &nb_mouv, ac);
	pile_b = tri_b(pile_b, &nb_mouv, nb_b);
	pile_a = tri_a(pile_a, &nb_mouv, nb_b, ac);
	i = 0;
	while (i < nb_b)
	{
		push_a(&pile_a, &pile_b);
		printf("pb\n");
		nb_mouv++;
		i++;
	}
	while(pile_a->data != lowest)
	{
		pile_a = rotate(pile_a);
		printf("ra\n");
		nb_mouv++;
	}
	display_pile(pile_a);
	printf("nb_mouv : %d\n", nb_mouv);
	return (0);
}