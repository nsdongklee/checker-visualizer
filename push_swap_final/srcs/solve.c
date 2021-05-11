/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:26:29 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/06 21:13:07 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solve(t_stack *a, t_stack *b, int n)
{
	int		mid;
	int		idx;
	int		ra_cnt;
	int		pb_cnt;

	if (n <= 3)
	{
		// print_two_stacks(a, b);
		return (terminate_solve(a, b, n));
	}
	mid = mid_value_in_stack(a, n);
	ra_cnt = 0;
	pb_cnt = 0;
	idx = -1;
	while (1 < a->size && ++idx < n)
	{
		// print_two_stacks(a, b);
		if (a->head->num > mid)
			ops_with_cnt_ra(a, &ra_cnt);
		else
			ops_with_cnt_pb(a, b, &pb_cnt);
		// print_two_stacks(a, b);
	}
	move_rev_return_a(a, ra_cnt);
	solve(a, b, ra_cnt);
	solve_sub(a, b, pb_cnt);
	return (0);
}

int		solve_sub(t_stack *a, t_stack *b, int n)
{
	int		mid;
	int		idx;
	int		rb_cnt;
	int		pa_cnt;

	if (n <= 1)
	{
		// print_two_stacks(a, b);
		return (terminate_solve_sub(a, b, n));
	}
	mid = mid_value_in_stack(b, n);
	rb_cnt = 0;
	pa_cnt = 0;
	idx = -1;
	while (1 < b->size && ++idx < n)
	{
		// print_two_stacks(a, b);
		if (b->head->num < mid)
			ops_with_cnt_rb(b, &rb_cnt);
		else
			ops_with_cnt_pa(a, b, &pa_cnt);
		// print_two_stacks(a, b);
	}
	move_rev_return_b(b, rb_cnt);
	solve(a, b, pa_cnt);
	solve_sub(a, b, rb_cnt);
	return (0);
}
