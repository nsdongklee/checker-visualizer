/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:28:41 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/06 18:40:56 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		initiate_stack(t_stack *a, t_stack *b)
{
	b->size = 1;
	b->head = (t_node *)malloc(sizeof(t_node));
	if (b->head == NULL)
		return (0);
	a->size = 1;
	a->head = (t_node *)malloc(sizeof(t_node));
	if (a->head == NULL)
		return (0);
	a->head->down = NULL;
	a->head->up = NULL;
	return (0);
}

int		release_all_nodes(t_stack *ab)
{
	t_node	*tmp;
	t_node	*tmp_down;
	int		idx;

	tmp = ab->head;
	if (tmp == NULL)
		return (0);
	idx = 0;
	while (++idx < ab->size)
	{
		tmp_down = tmp->down;
		free(tmp);
		tmp = tmp_down;
		if (tmp == ab->head)
			return (0);
	}
	return (0);
}

int		operate_parsed_argument(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		ops_sa(a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ops_sb(b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ops_ss(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ops_pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ops_pb(a, b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ops_ra(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ops_rb(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ops_rr(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ops_rra(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ops_rrb(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ops_rrr(a, b, 0);
	else
		ft_error_exit();
	return (0);
}

int		parse_operators(t_stack *a, t_stack *b)
{
	char	*line;
	int		byte;
	int		flag;
	int		fd;

	flag = 0;
	fd = 0;
	while ((byte = get_next_line(fd, &line)) > 0)
	{
		operate_parsed_argument(line, a, b);
		free(line);
	}
	free(line);
	if (is_sorted_node(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
