/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:56:43 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/24 17:33:39 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	int	f_quartile;
	int	mediane;
	int	t_quartile;
}	t_data;

typedef struct s_pile
{
	struct s_pile	*next;
	int				data;
	struct s_pile	*prev;
}	t_pile;

t_pile	*lstnew(int content);
t_pile	*lstadd_back(t_pile *pile, t_pile *new);
t_pile	*lstadd_front(t_pile *pile, t_pile *new);
t_pile	*init_pile(int ac, char **av);
void	lst_del(t_pile **pile);
int		ft_atoi(const char *str);
t_pile	*swap(t_pile *pile);
void	push_a(t_pile **pile_a, t_pile **pile_b);
void	push_b(t_pile **pile_b, t_pile **pile_a);
t_pile	*rotate(t_pile *pile);
t_pile	*reverse_rotate(t_pile *pile);
t_data	mediane(t_pile *pile, t_data data, int ac);
t_data	calcul(t_data data, t_pile *pile_a, int ac);
void	display_pile(t_pile *pile);
int		check_order(int ac, char **av);
int		pile_len(t_pile *pile);
int		parsing_arg(int ac, char **av);
int		sep(t_pile **pile_a, t_pile **pile_b, t_data data);
int		calcul_lowest(t_pile *pile_a);
int		calcul_highest(t_pile *pile);
void	tri_a(t_pile **pile_a, t_pile **pile_b, int *nb_mouv);
int		count_a(t_pile *pile_a, int elem);
int		count_b(t_pile *pile_b, int elem);
int		count_mouv(t_pile *pile_a, t_pile *pile_b);
int		count_mouv_2(t_pile *pile_a, t_pile *pile_b, int pb);
int		rotate_a_and_b(t_pile **pile_a, t_pile **pile_b, int ca, int cb);

#endif