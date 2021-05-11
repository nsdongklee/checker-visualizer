/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: easternstar <easternstar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:30:58 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/04 01:00:32 by easternstar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		insert_node(t_stack *a, int *cnt)
{
	if ((*cnt) == 1)
		a->head->up = NULL;
	else if ((*cnt) > 1)
	{
		a->head->up = (t_node *)malloc(sizeof(t_node));
		if (a->head->up == NULL)
			return (0);
		a->head = a->head->up;
	}
	return (1);
}

int		node_count(char **av)
{
	int		cnt;

	if (av == NULL)
		return (0);
	cnt = 1;
	while (av[cnt])
		cnt++;
	return (cnt);
}

int		insert_data(char **av, t_stack *a)
{
	t_node	*before;
	int		flag;
	int		cnt;

	before = a->head;
	flag = 0;
	cnt = node_count(av);
	while (--cnt > 0)
	{
		a->head->num = ft_atoi(av[cnt]);
		if (flag == 0)
		{
			a->head->down = NULL;
			flag = 1;
		}
		else if (flag == 1)
		{
			a->head->down = before;
			before = a->head;
		}
		insert_node(a, &cnt);
		a->size++;
	}
	return (1);
}
