/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:10:50 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/27 15:01:45 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	nb_mouv;

	nb_mouv = 0;
	while (ca < pile_len(*pile_a) || cb < pile_len(*pile_b))
	{
		if (ca < pile_len(*pile_a))
		{
			*pile_a = reverse_rotate(*pile_a);
			if (cb >= pile_len(*pile_b))
				write(1, "rra\n", 4);
		}
		if (cb < pile_len(*pile_b))
		{
			*pile_b = reverse_rotate(*pile_b);
			if (ca > pile_len(*pile_a))
				write(1, "rrb\n", 4);
		}
		if (ca < pile_len(*pile_a) && cb < pile_len(*pile_b))
			write(1, "rrr\n", 4);
		ca++;
		cb++;
		nb_mouv++;
	}
	return (nb_mouv);
}

int	rr(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	nb_mouv;

	nb_mouv = 0;
	while (ca > 0 || cb > 0)
	{
		if (ca > 0)
		{
			*pile_a = rotate(*pile_a);
			if (cb <= 0)
				write(1, "ra\n", 3);
		}
		if (cb > 0)
		{
			*pile_b = rotate(*pile_b);
			if (ca <= 0)
				write(1, "rb\n", 3);
		}
		if (ca > 0 && cb > 0)
			write(1, "rr\n", 3);
		ca--;
		cb--;
		nb_mouv++;
	}
	return (nb_mouv);
}

int	rr_and_r(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	nb_mouv;

	nb_mouv = 0;
	while (ca < pile_len(*pile_a))
	{
		*pile_a = reverse_rotate(*pile_a);
		write(1, "rra\n", 4);
		ca++;
		nb_mouv++;
	}
	while (cb > 0)
	{
		*pile_b = rotate(*pile_b);
		write(1, "rb\n", 3);
		cb--;
		nb_mouv++;
	}
	return (nb_mouv);
}

int	rr_and_r_2(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	nb_mouv;

	nb_mouv = 0;
	while (cb < pile_len(*pile_b))
	{
		*pile_b = reverse_rotate(*pile_b);
		write(1, "rrb\n", 4);
		cb++;
		nb_mouv++;
	}
	while (ca > 0)
	{
		*pile_a = rotate(*pile_a);
		write(1, "ra\n", 3);
		ca--;
		nb_mouv++;
	}
	return (nb_mouv);
}

int	rotate_a_and_b(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	nb_mouv;

	if (ca > pile_len(*pile_a) / 2 && cb > pile_len(*pile_b) / 2)
		nb_mouv = rrr(pile_a, pile_b, ca, cb);
	else if (ca <= pile_len(*pile_a) / 2 && cb <= pile_len(*pile_b) / 2)
		nb_mouv = rr(pile_a, pile_b, ca, cb);
	else
	{
		if (ca > pile_len(*pile_a) / 2)
			nb_mouv = rr_and_r(pile_a, pile_b, ca, cb);
		else
			nb_mouv = rr_and_r_2(pile_a, pile_b, ca, cb);
	}
	return (nb_mouv);
}
