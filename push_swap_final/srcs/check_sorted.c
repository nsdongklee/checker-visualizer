/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:25:37 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/03 11:12:22 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted_node(t_stack *a, t_stack *b)
{
	int		*answer;
	int		temp;
	int		idx;

	if (b->size > 1)
		return (0);
	answer = (int *)malloc(sizeof(int) * (a->size - 1));
	if (answer == NULL)
		return (0);
	init_data_arr(a, answer, (a->size - 1));
	idx = 0;
	temp = answer[idx];
	while (idx < a->size - 2)
	{
		temp = answer[idx];
		if (temp > answer[idx + 1])
			return (0);
		idx++;
	}
	free(answer);
	return (1);
}

int		nogada_sorted(t_stack *a, t_stack *b)
{
	int		*answer;
	int		idx;
	int		size;

	answer = (int *)malloc(sizeof(int) * (a->size - 1));
	if (answer == NULL)
		return (0);
	init_data_arr(a, answer, (a->size - 1));
	quick_sort_arr(answer, 0, (a->size - 2));
	size = a->size - 1;
	idx = 0;
	while (a->size > 1 && idx < size)
	{
		if (a->head->num == answer[idx])
		{
			ops_pb(a, b, 1);
			idx++;
		}
		ops_ra(a, 1);
	}
	while (b->size > 1)
		ops_pa(a, b, 1);
	return (0);
}
