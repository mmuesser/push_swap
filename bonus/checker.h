/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:11:18 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/06 12:09:31 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

/*check_pile.c*/
int		check_pile(t_pile *pile_a, int ac);

/*create_list_op.c*/
int		verif_op_2(char **list_op, int i);
int		verif_op(char **list_op);
char	*ft_read(void);
char	**create_list_op(void);

/*do_op.c*/
void	do_op2(t_pile **pile_a, t_pile **pile_b, char **list_op, int i);
void	do_op(t_pile **pile_a, t_pile **pile_b, char **list_op);

/*main_checker.c*/
t_pile	*checker(t_pile *pile_a, t_pile *pile_b, int ac);
int		main(int ac, char **av);

/*utils_2.c*/
char	*ft_rep(const char *str, char c, int i);
char	**ft_create_str(const char *str, char c, char **dest);
size_t	nb_chaines(const char *str, char c);
char	**ft_split(char *str, char c);

/*utils.c*/
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);

/*check_arg.c*/
int		check_double(t_pile *pile_a);
int		verif_nbr(char *str, int nb);
int		check_nbr(int ac, char **av);
int		check_char(int ac, char **av);
int		parsing_arg(int ac, char **av);

/*ft_atoi.c*/
int		ft_atoi(const char *str);

/*gest_pile.c*/
t_pile	*lstnew(int content);
t_pile	*init_pile(int ac, char **av);
t_pile	*lstadd_back(t_pile *pile, t_pile *new);
t_pile	*lstadd_front(t_pile *pile, t_pile *new);
void	lst_del(t_pile **pile);

/*operations.c*/
t_pile	*swap(t_pile *pile);
void	push_a(t_pile **pile_a, t_pile **pile_b, t_data *data, char **str);
void	push_b(t_pile **pile_b, t_pile **pile_a, t_data *data, char **str);
t_pile	*rotate(t_pile *pile);
t_pile	*reverse_rotate(t_pile *pile);

/*utils_2.c*/
int		error(t_pile **pile_a, t_pile **pile_b, t_data *data, char **str);
int		ft_strlen(char *str);
void	set_a_final(t_pile **pile_a, t_data *data);
void	free_str(char **str);

/*utils.c*/
int		pile_len(t_pile *pile);
void	free_pile(t_pile **pile);
int		calcul_lowest(t_pile *pile);
int		calcul_highest(t_pile *pile);
int		check_order(int ac, char **av);

#endif