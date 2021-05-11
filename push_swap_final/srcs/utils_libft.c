/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:10:57 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/06 21:01:43 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit(int c)
{
	if (('0' <= c && c <= '9') || c == '-')
		return (1);
	return (0);
}

int		ft_is_num(char *num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		if (num[i] == '-' && i != 0)
			return (0);
		if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_atoi(const char *str)
{
	int		idx;
	int		flag;
	long	result;

	idx = 0;
	flag = 1;
	result = 0;
	while (str[idx] == ' ' || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	if (str[idx] == '-')
		flag = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result = (result * 10) + (str[idx] - '0');
		if ((flag * result) < -2147483648)
			return (0);
		else if ((flag * result) > 2147483647)
			return (-1);
		idx++;
	}
	return (flag * result);
}

void	print_two_stacks(t_stack *a, t_stack *b)
{
	int		cnt;
	t_node	*tmp_a;
	t_node	*tmp_b;

	cnt = a->size > b->size ? a->size : b->size;
	tmp_a = a->head;
	tmp_b = b->head;
	printf("---------------overview--------------\n");
	while (cnt > 1)
	{
		if (cnt > a->size || (cnt < a->size && !tmp_a->up && !tmp_a->down))
			printf(" \t\t");
		else if (cnt <= a->size)
		{
			printf("%d\t\t", tmp_a->num);
			tmp_a = tmp_a->down;
		}
		if (cnt > b->size || (cnt < b->size && !tmp_b->up && !tmp_b->down))
			printf(" \n");
		else if (cnt <= b->size)
		{
			printf("%d\n", tmp_b->num);
			tmp_b = tmp_b->down;
		}
		cnt--;
	}
	printf("-\t\t-\na\t\tb\n");
	printf("------------------@------------------\n");
}
