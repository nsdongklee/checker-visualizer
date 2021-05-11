/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: easternstar <easternstar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:29:44 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/03 15:27:05 by easternstar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pivot_in_stack(t_stack *ab, t_pivot *pivot)
{
	int		*answer;

	answer = (int *)malloc(sizeof(int) * (ab->size - 1));
	if (answer == NULL)
		return (0);
	init_data_arr(ab, answer, (ab->size - 1));
	quick_sort_arr(answer, 0, (ab->size - 2));
	if (ab->size < 2)
	{
		pivot->sml = 0;
		pivot->big = 0;
	}
	else if (ab->head != NULL && ab->size == 2)
	{
		pivot->sml = 0;
		pivot->big = (int)(ab->head->num);
	}
	else
	{
		pivot->sml = (int)(answer[(ab->size - 1) / 3]);
		pivot->big = (int)(answer[(ab->size - 1) / 3 * 2]);
	}
	free(answer);
	return (0);
}

int		mid_value_in_stack(t_stack *ab, int n)
{
	int		mid;
	int		idx;
	int		*answer;

	mid = 0;
	if (ab->head == NULL)
		return (0);
	answer = (int *)malloc(sizeof(int) * n);
	if (answer == NULL)
		return (0);
	init_data_arr(ab, answer, n);
	idx = -1;
	while (++idx < n)
		mid += answer[idx];
	mid /= n;
	free(answer);
	return (mid);
}

int		find_mid_value(t_stack *ab, int r)
{
	int		*res;
	int		answer;

	answer = 0;
	if (ab->size < 3)
		return (0);
	res = (int *)malloc(sizeof(int) * 3);
	if (res == NULL)
		return (0);
	init_data_arr(ab, res, 3);
	quick_sort_arr(res, 0, 2);
	if (r == 3)
		answer = res[1];
	free(res);
	return (answer);
}
