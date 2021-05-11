/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:23:31 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/03 13:08:09 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		size_under_three(t_stack *a, int mid)
{
	if (a->size == 3 && a->head->num > a->head->down->num)
		ops_sa(a, 1);
	else if (a->size == 4)
	{
		if (a->head->num == mid && a->head->down->num < mid)
			ops_sa(a, 1);
		else if (a->head->num == mid && a->head->down->num > mid)
			ops_rra(a, 1);
		else if (a->head->num > mid && a->head->down->num == mid)
		{
			ops_sa(a, 1);
			ops_rra(a, 1);
		}
		else if (a->head->num > mid && a->head->down->num < mid)
			ops_ra(a, 1);
		else if (a->head->num < mid && a->head->down->num > mid)
		{
			ops_sa(a, 1);
			ops_ra(a, 1);
		}
	}
	return (0);
}

int		num_over_mid(t_stack *a, t_stack *b, int mid)
{
	if (a->head->num > mid && a->head->down->num == mid)
	{
		ops_sa(a, 1);
		ops_pb(a, b, 1);
		ops_sa(a, 1);
		ops_pa(a, b, 1);
		ops_sa(a, 1);
	}
	else if (a->head->num > mid && a->head->down->num < mid)
	{
		ops_sa(a, 1);
		ops_pb(a, b, 1);
		ops_sa(a, 1);
		ops_pa(a, b, 1);
	}
	return (0);
}

int		size_over_three(t_stack *a, t_stack *b, int mid, int r)
{
	if (r == 2 && a->head->num > a->head->down->num)
		ops_sa(a, 1);
	else if (r == 3)
	{
		if (a->head->num == mid && a->head->down->num < mid)
			ops_sa(a, 1);
		else if (a->head->num == mid && a->head->down->num > mid)
		{
			ops_pb(a, b, 1);
			ops_sa(a, 1);
			ops_pa(a, b, 1);
			ops_sa(a, 1);
		}
		else if (a->head->num > mid)
			num_over_mid(a, b, mid);
		else if (a->head->num < mid && a->head->down->num > mid)
		{
			ops_pb(a, b, 1);
			ops_sa(a, 1);
			ops_pa(a, b, 1);
		}
	}
	return (0);
}

int		sort_under_three(t_stack *a, t_stack *b, int r)
{
	int		mid;

	if (r == 3 && a->size >= 4)
		mid = find_mid_value(a, r);
	else
		mid = 0;
	size_under_three(a, mid);
	size_over_three(a, b, mid, r);
	return (0);
}
