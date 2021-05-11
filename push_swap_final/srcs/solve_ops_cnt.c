/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ops_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:42:56 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/03 13:53:33 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ops_with_cnt_ra(t_stack *a, int *ra_cnt)
{
	ops_ra(a, 1);
	(*ra_cnt)++;
	return (0);
}

int		ops_with_cnt_pb(t_stack *a, t_stack *b, int *pb_cnt)
{
	ops_pb(a, b, 1);
	(*pb_cnt)++;
	return (0);
}

int		ops_with_cnt_rb(t_stack *b, int *rb_cnt)
{
	ops_rb(b, 1);
	(*rb_cnt)++;
	return (0);
}

int		ops_with_cnt_pa(t_stack *a, t_stack *b, int *pa_cnt)
{
	ops_pa(a, b, 1);
	(*pa_cnt)++;
	return (0);
}
