/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:08:34 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/06 21:01:56 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define FD_SIZE	4096
# define BUF_SIZE	3

typedef struct		s_node
{
	int				num;
	struct s_node	*up;
	struct s_node	*down;
}					t_node;

typedef struct		s_stack
{
	int				size;
	t_node			*head;
}					t_stack;

typedef struct		s_pivot
{
	int				sml;
	int				big;
}					t_pivot;

/*
**	functions related push_swap program
*/
int					insert_node(t_stack *a, int *cnt);
int					node_count(char **av);
int					insert_data(char **av, t_stack *a);

int					is_sorted_node(t_stack *a, t_stack *b);
int					nogada_sorted(t_stack *a, t_stack *b);

int					quick_sort_arr(int *arr, int start, int end);
int					init_data_arr(t_stack *a, int *arr, int size);
int					mid_value_in_stack(t_stack *ab, int n);
int					find_mid_value(t_stack *ab, int r);

int					size_under_three(t_stack *a, int mid);
int					num_over_mid(t_stack *a, t_stack *b, int mid);
int					size_over_three(t_stack *a, t_stack *b, int mid, int r);
int					sort_under_three(t_stack *a, t_stack *b, int r);

int					terminate_under_three(t_stack *a, t_stack *b, int r);
int					ops_over_pivot(t_stack *a, int *ra_cnt);
int					ops_under_pivot(t_stack *b, t_pivot *pivot, int *rb_cnt);
int					sort_under_five(t_stack *a, t_stack *b, t_pivot *pivot, \
																		int r);
int					pivot_in_stack(t_stack *ab, t_pivot *pivot);
int					move_back(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt);

int					ops_with_cnt_ra(t_stack *a, int *ra_cnt);
int					ops_with_cnt_pb(t_stack *a, t_stack *b, int *pb_cnt);
int					ops_with_cnt_rb(t_stack *b, int *rb_cnt);
int					ops_with_cnt_pa(t_stack *a, t_stack *b, int *pa_cnt);

int					terminate_solve(t_stack *a, t_stack *b, int n);
int					terminate_solve_sub(t_stack *a, t_stack *b, int n);
int					move_rev_return_a(t_stack *a, int rotate_cnt);
int					move_rev_return_b(t_stack *b, int rotate_cnt);
int					solve(t_stack *a, t_stack *b, int n);
int					solve_sub(t_stack *a, t_stack *b, int n);

/*
**	instructions
*/
void				ops_sa(t_stack *a, int print);
void				ops_sb(t_stack *b, int print);
void				ops_ss(t_stack *a, t_stack *b, int print);
void				ops_pa(t_stack *a, t_stack *b, int print);
void				ops_pb(t_stack *a, t_stack *b, int print);
void				ops_ra(t_stack *a, int print);
void				ops_rb(t_stack *b, int print);
void				ops_rr(t_stack *a, t_stack *b, int print);
void				ops_rra(t_stack *a, int print);
void				ops_rrb(t_stack *b, int print);
void				ops_rrr(t_stack *a, t_stack *b, int print);
void				ft_swap(int *a, int *b);
int					rule_swap(t_stack *ab);
int					rule_rotate(t_stack *ab);
int					rule_rev_rotate(t_stack *ab);
int					rule_push(t_stack *from, t_stack *to);
int					push_to_null_stack(t_stack *from, t_stack *to, \
																t_node *swap);

/*
**	libft_utils
*/
int					ft_isdigit(int c);
int					ft_is_num(char *num);
int					find_overflow(char *str);
int					ft_atoi(const char *str);

/*
**	get_next_line_utils
*/
int					get_next_line(int fd, char **line);
int					ft_strlen(char *s);
int					ft_strlcpy(char *dst, char *src, int dstsize);
int					ft_strlcat(char *dst, char *src, int dstsize);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *s1);

/*
**	main utils
*/
int					initiate_stack(t_stack *a, t_stack *b);
int					exception_handle(int ac, char **av);
int					release_all_nodes(t_stack *ab);
int					operate_parsed_argument(char *line, t_stack *a, t_stack *b);
int					parse_operators(t_stack *a, t_stack *b);
int					check_duplicated(char **av);
int					check_arguments_sorted(char **av);
void				ft_error_exit(void);

void				print_two_stacks(t_stack *a, t_stack *b);

#endif
