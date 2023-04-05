/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:11:18 by mmuesser          #+#    #+#             */
/*   Updated: 2023/04/05 21:01:19 by mmuesser         ###   ########.fr       */
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
int		verif_op(char **list_op);
char	*ft_read(void);
char	**create_list_op(void);

/*do_op.c*/
void	do_op2(t_pile **pile_a, t_pile **pile_b, char **list_op, int i);
void	do_op(t_pile **pile_a, t_pile **pile_b, char **list_op);

/*main_checker.c*/
t_pile	*checker(t_pile *pile_a, t_pile *pile_b, int ac);

/*utils.c*/
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	free_list_op(char **list_op);

/*utils_2.c*/
char	**ft_split(char *str, char c);

/*calcul_mediane.c*/
int		calcul_mediane(t_data **data, t_pile **tmp, int len);
void	calcul_t_quartile(t_data **data, t_pile **tmp, int len);
void	calcul_f_quartile(t_data **data, t_pile **tmp, int len);
t_data	*mediane(t_pile *pile);

/*calcul_mediane2.c*/
t_pile	*set_tmp_min_max(t_pile *pile, t_pile *tmp);
t_pile	*set_tmp2(t_pile *pile, t_pile *tmp, int len);
t_pile	*set_tmp(t_pile *pile, int len);

/*check_arg.c*/
int		ft_strlen(char *str);
int		verif_nbr(char *str, int nb);
int		check_nbr(int ac, char **av);
int		check_char(int ac, char **av);
int		parsing_arg(int ac, char **av);

/*count_mouv.c*/
int		count_max_or_min(t_pile *pile_a, t_pile *pile_b, int ib);
int		count_mouv_2(t_pile *pile_a, t_pile *pile_b, int ib);
int		count_mouv(t_pile *pile_a, t_pile *pile_b);

/*ft_atoi.c*/
int		ft_atoi(const char *str);

/*gest_pile.c*/
t_pile	*lstnew(int content);
t_pile	*init_pile(int ac, char **av);
t_pile	*lstadd_back(t_pile *pile, t_pile *new);
t_pile	*lstadd_front(t_pile *pile, t_pile *new);
void	lst_del(t_pile **pile);

/*main_push_swap.c*/
t_pile	*push_swap(t_pile *pile_a, t_pile *pile_b);

/*operations.c*/
t_pile	*swap(t_pile *pile);
void	push_a(t_pile **pile_a, t_pile **pile_b, t_data *data, char **str);
void	push_b(t_pile **pile_b, t_pile **pile_a, t_data *data, char **str);
t_pile	*rotate(t_pile *pile);
t_pile	*reverse_rotate(t_pile *pile);

/*pretri.c*/
void	pretri_2(t_pile **pile_a, t_pile **pile_b, t_data *data);
void	fq_and_tq(t_pile **pile_a, t_pile **pile_b, t_data *data);
void	pretri(t_pile **pile_a, t_pile **pile_b, t_data *data);

/*set_piles.c*/
void	rrr(t_pile **pile_a, t_pile **pile_b, int ca, int cb);
void	rr(t_pile **pile_a, t_pile **pile_b, int ca, int cb);
void	rr_and_r(t_pile **pile_a, t_pile **pile_b, int ca, int cb);
void	rr_and_r_2(t_pile **pile_a, t_pile **pile_b, int ca, int cb);
void	rotate_a_and_b(t_pile **pile_a, t_pile **pile_b, int ca, int cb);

/*tri_a.c*/
int		count_b(t_pile *pile_b, int elem);
int		count_a(t_pile *pile_a, int elem);
void	sort_3(t_pile **pile);
void	tri_a(t_pile **pile_a, t_pile **pile_b, t_data *data);

/*utils.c*/
int		pile_len(t_pile *pile);
void	free_pile(t_pile **pile);
int		calcul_lowest(t_pile *pile);
int		calcul_highest(t_pile *pile);
int		check_order(int ac, char **av);

/*utils_2.c*/
void	set_a_final(t_pile **pile_a, t_data *data);
int		error(t_pile **pile_a, t_pile **pile_b, t_data *data, char **str);
int		check_double(t_pile *pile_a);

#endif