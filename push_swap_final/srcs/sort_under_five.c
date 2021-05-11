/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: easternstar <easternstar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:24:17 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/03 15:16:40 by easternstar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		terminate_under_three(t_stack *a, t_stack *b, int r)
{
	sort_under_three(a, b, r);
	while (b->size > 1)
		ops_pa(a, b, 1);
	return (0);
}

int		ops_over_pivot(t_stack *a, int *ra_cnt)
{
	ops_ra(a, 1);
	(*ra_cnt)++;
	return (0);
}

int		ops_under_pivot(t_stack *b, t_pivot *pivot, int *rb_cnt)
{
	if (b->head->num >= pivot->sml)
	{
		ops_rb(b, 1);
		(*rb_cnt)++;
	}
	return (0);
}

int		sort_under_five(t_stack *a, t_stack *b, t_pivot *pivot, int r)
{
	int		ra_cnt;
	int		rb_cnt;
	int		pb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	if (a->size <= 4 || (r <= 3 && a->size >= 4))
		return (terminate_under_three(a, b, r));
	pivot_in_stack(a, pivot);
	while (a->head != NULL && r > 0)
	{
		if (a->head->num >= pivot->big)
			ops_over_pivot(a, &ra_cnt);
		else
		{
			ops_with_cnt_pb(a, b, &pb_cnt);
			ops_under_pivot(b, pivot, &rb_cnt);
		}
		r--;
	}
	move_back(a, b, ra_cnt, rb_cnt);
	sort_under_five(a, b, pivot, ra_cnt);
	return (0);
}
