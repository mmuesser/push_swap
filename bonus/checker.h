/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:11:18 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/30 21:33:33 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./push_swap.h"

/*check_pile.c*/
int	check_pile(t_pile *pile_a, int ac);

/*checker.c*/
t_pile	*checker(t_pile *pile_a, t_pile *pile_b, int ac);

/*create_list_op.c*/
int		verif_op(char **list_op);
char	*ft_read(void);
char	**create_list_op(void);

/*do_op.c*/
void	do_op2(t_pile **pile_a, t_pile **pile_b, char **list_op, int i);
void	do_op(t_pile **pile_a, t_pile **pile_b, char **list_op);

/*utils.c*/
char	*ft_strjoin(char *s1, char *s2);
char	*fill_line(char *dest, char *str, char c, int len);
char	**create_line(char **dest, char *str, char c);
int		count_line(char *str, char c);
char	**ft_split(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
void	free_list_op(char **list_op);

#endif