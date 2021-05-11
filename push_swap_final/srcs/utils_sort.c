/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:20:43 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/06 20:38:26 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		quick_sort_arr(int *arr, int start, int end)
{
	int		pivot;
	int		left;
	int		right;

	pivot = start;
	left = start + 1;
	right = end;
	if (start >= end)
		return (0);
	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
			ft_swap(&arr[right], &arr[pivot]);
		else
			ft_swap(&arr[left], &arr[right]);
		quick_sort_arr(arr, start, (right - 1));
		quick_sort_arr(arr, (right + 1), end);
	}
	return (0);
}

int		init_data_arr(t_stack *a, int *arr, int size)
{
	t_node	*tmp;
	int		idx;
	int		stack_size;

	tmp = a->head;
	idx = 0;
	stack_size = a->size;
	while (idx < size && stack_size >= 1)
	{
		arr[idx] = tmp->num;
		tmp = tmp->down;
		stack_size--;
		idx++;
	}
	return (0);
}

int		move_back(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt)
{
	int		idx;

	idx = 0;
	while (idx < ra_cnt || idx < rb_cnt)
	{
		if (idx < ra_cnt && idx < rb_cnt)
			ops_rrr(a, b, 1);
		else if (ra_cnt >= idx && idx < rb_cnt)
			ops_rrb(b, 1);
		else if (rb_cnt >= idx && idx < ra_cnt)
			ops_rra(a, 1);
		idx++;
	}
	return (0);
}
