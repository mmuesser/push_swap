/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:56:43 by mmuesser          #+#    #+#             */
/*   Updated: 2023/02/21 15:00:35 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

/*CHANGER data EN DATA*/

typedef struct s_pile
{
	struct s_pile	*next;
	int		data;
	struct s_pile	*prev;
}	t_pile;

t_pile	*lstnew(int content);
t_pile	*init_pile(t_pile *pile_a, int ac, char **av);
t_pile	*lstadd_back(t_pile *pile, t_pile *new);
t_pile	*lstadd_front(t_pile *pile, t_pile *new);
void	lst_del(t_pile **pile);
int		ft_atoi(const char *str);
t_pile	*swap(t_pile *pile);
void    push_a(t_pile **pile_a, t_pile **pile_b);
void	push_b(t_pile **pile_a, t_pile **pile_b);
t_pile	*rotate(t_pile *pile);
t_pile	*reverse_rotate(t_pile *pile);
int	mediane(t_pile *pile, int ac);
void	display_pile(t_pile *pile);
int	check_order(int ac, char **av);
t_pile  *tri_b(t_pile *pile_b, int *nb_mouv, int nb_b);
t_pile  *tri_a(t_pile *pile_a, int *nb_mouv, int nb_b, int ac);
int	check_b(t_pile *pile_b, int nb);
int	check_a(t_pile *pile_a, int nb);

#endif