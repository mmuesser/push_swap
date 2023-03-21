/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:10:38 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/22 00:19:31 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sep_inf_fquartile(t_pile **pile_a, t_pile **pile_b, t_data data, int len)
{
	int	i;
	int	nb_mouv;

	nb_mouv = 0;
	i = 0;
	while (i < len)
	{
		if ((*pile_a)->data <= data.f_quartile)
		{
			while (*pile_b && ())
			push_b(pile_b, pile_a);
			// printf("pb\n");
			nb_mouv++;
		}
		else
		{
			*pile_a = rotate(*pile_a);
			// printf("ra\n");
			nb_mouv++;
		}
		i++;
	}
	return (nb_mouv);
}

int	sep_sup_tquarile(t_pile **pile_a, t_pile **pile_b, t_data data, int len)
{
	int	i;
	int	nb_mouv;

	nb_mouv = 0;
	i = 0;
	while (i < len)
	{
		if ((*pile_a)->data > data.t_quartile)
		{
			push_b(pile_b, pile_a);
			// printf("pb\n");
			nb_mouv++;
		}
		else
		{
			*pile_a = rotate(*pile_a);
			// printf("ra\n");
			nb_mouv++;
		}
		i++;
	}
	return (nb_mouv);
}

int	sep_inf_tquartile(t_pile **pile_a, t_pile **pile_b, t_data data, int len)
{
	int	i;
	int	nb_mouv;

	nb_mouv = 0;
	i = 0;
	while (i < len)
	{
		if ((*pile_a)->data <= data.t_quartile && (*pile_a)->data > data.mediane)
		{
			push_b(pile_b, pile_a);
			// printf("pb\n");
			nb_mouv++;
		}
		else
		{
			*pile_a = rotate(*pile_a);
			// printf("ra\n");
			nb_mouv++;
		}
		i++;
	}
	return (nb_mouv);
}

int	sep_inf_mediane(t_pile **pile_a, t_pile ** pile_b, t_data data, int len)
{
	int	i;
	int	nb_mouv;

	nb_mouv = 0;
	i = 0;
	while (i < len)
	{
		if ((*pile_a)->data <= data.mediane && (*pile_a)->data > data.f_quartile)
		{
			push_b(pile_b, pile_a);
			// printf("pb\n");
			nb_mouv++;
		}
		else
		{
			*pile_a = rotate(*pile_a);
			// printf("ra\n");
			nb_mouv++;
		}
		i++;
	}
	return (nb_mouv);
}

int	sep(t_pile **pile_a, t_pile **pile_b, t_data data)
{
	int	nb_mouv;
	int	len;

	nb_mouv = 0;
	len = pile_len(*pile_a);
	nb_mouv += sep_inf_fquartile(pile_a, pile_b, data, len);
	display_pile(*pile_b);
	len = pile_len(*pile_a);
	nb_mouv += sep_inf_mediane(pile_a, pile_b, data, len);
	len = pile_len(*pile_a);
	nb_mouv += sep_inf_tquartile(pile_a, pile_b, data, len);
	len = pile_len(*pile_a) - 1;
	nb_mouv += sep_sup_tquarile(pile_a, pile_b, data, len);
	return (nb_mouv);
}