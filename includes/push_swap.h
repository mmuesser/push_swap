/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:56:43 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/02 18:12:01 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	f_quartile;
	int	mediane;
	int	t_quartile;
}	t_data;

typedef struct s_pile
{
	struct s_pile	*next;
	int		data;
	struct s_pile	*prev;
}	t_pile;

t_pile	*lstnew(int content);
t_pile	*lstadd_back(t_pile *pile, t_pile *new);
t_pile	*lstadd_front(t_pile *pile, t_pile *new);
t_pile	*init_pile(int ac, char **av);
void	lst_del(t_pile **pile);
int		ft_atoi(const char *str);
t_pile	*swap(t_pile *pile);
void    push_a(t_pile **pile_a, t_pile **pile_b);
void	push_b(t_pile **pile_b, t_pile **pile_a);
t_pile	*rotate(t_pile *pile);
t_pile	*reverse_rotate(t_pile *pile);
t_data	mediane(t_pile *pile, t_data data, int ac);
t_data	calcul(t_data data, t_pile *pile_a, int ac);
void	display_pile(t_pile *pile);
int		check_order(int ac, char **av);
t_pile  *tri_b(t_pile *pile_b, int *nb_mouv, int nb_b);
t_pile  *tri_a(t_pile *pile_a, t_pile *pile_b, int *nb_mouv);
int	pile_len(t_pile *pile);
int		check_b(t_pile *pile_b, int nb);
int		check_a(t_pile *pile_a, int nb);
int	parsing_arg(int ac, char **av);
int	sep(t_pile **pile_a, t_pile **pile_b, t_data data);
int	calcul_lowest(t_pile *pile_a);
int	is_trie(t_pile *pile_a, int lowest);

#endif