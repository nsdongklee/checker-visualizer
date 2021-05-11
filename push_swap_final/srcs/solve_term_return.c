/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_term_return.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:48:54 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/05 11:53:33 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		terminate_solve(t_stack *a, t_stack *b, int n)
{
	if (n <= 1)
		return (0);
	else if (n <= 3)
	{
		sort_under_three(a, b, n);
		return (0);
	}
	return (0);
}

int		terminate_solve_sub(t_stack *a, t_stack *b, int n)
{
	if (n < 1)
		return (0);
	if (b->size <= 1 || n == 0)
		return (0);
	if (b->size > 1)
		ops_pa(a, b, 1);
	return (0);
}

int		move_rev_return_a(t_stack *a, int rotate_cnt)
{
	int		idx;

	idx = -1;
	while (++idx < rotate_cnt)
		ops_rra(a, 1);
	return (0);
}

int		move_rev_return_b(t_stack *b, int rotate_cnt)
{
	int		idx;

	idx = -1;
	while (++idx < rotate_cnt)
		ops_rrb(b, 1);
	return (0);
}
