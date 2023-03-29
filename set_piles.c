/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:10:50 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/29 14:45:35 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	len_a;
	int	len_b;

	len_a = pile_len(*pile_a);
	len_b = pile_len(*pile_b);
	while (ca < len_a && cb < len_b)
	{
		*pile_a = reverse_rotate(*pile_a);
		ca++;
		*pile_b = reverse_rotate(*pile_b);
		cb++;
		write(1, "rrr\n", 4);
	}
	while (ca < len_a)
	{
		*pile_a = reverse_rotate(*pile_a);
		write(1, "rra\n", 4);
		ca++;
	}
	while (cb < len_b)
	{
		*pile_b = reverse_rotate(*pile_b);
		write(1, "rrb\n", 4);
		cb++;
	}
}

void	rr(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	while (ca > 0 && cb > 0)
	{
		*pile_a = rotate(*pile_a);
		ca--;
		*pile_b = rotate(*pile_b);
		cb--;
		write(1, "rr\n", 3);
	}
	while (ca > 0)
	{
		*pile_a = rotate(*pile_a);
		write(1, "ra\n", 3);
		ca--;
	}
	while (cb > 0)
	{
		*pile_b = rotate(*pile_b);
		write(1, "rb\n", 3);
		cb--;
	}
}

void	rr_and_r(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	len_a;

	len_a = pile_len(*pile_a);
	while (ca < len_a)
	{
		*pile_a = reverse_rotate(*pile_a);
		write(1, "rra\n", 4);
		ca++;
	}
	while (cb > 0)
	{
		*pile_b = rotate(*pile_b);
		write(1, "rb\n", 3);
		cb--;
	}
}

void	rr_and_r_2(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	int	len_b;

	len_b = pile_len(*pile_b);
	while (cb < len_b)
	{
		*pile_b = reverse_rotate(*pile_b);
		write(1, "rrb\n", 4);
		cb++;
	}
	while (ca > 0)
	{
		*pile_a = rotate(*pile_a);
		write(1, "ra\n", 3);
		ca--;
	}
}

void	rotate_a_and_b(t_pile **pile_a, t_pile **pile_b, int ca, int cb)
{
	if (ca > (pile_len(*pile_a) / 2) && cb > (pile_len(*pile_b) / 2))
		rrr(pile_a, pile_b, ca, cb);
	else if (ca <= (pile_len(*pile_a) / 2) && cb <= (pile_len(*pile_b) / 2))
		rr(pile_a, pile_b, ca, cb);
	else
	{
		if (ca > (pile_len(*pile_a) / 2))
			rr_and_r(pile_a, pile_b, ca, cb);
		else
			rr_and_r_2(pile_a, pile_b, ca, cb);
	}
}
