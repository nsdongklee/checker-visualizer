/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: easternstar <easternstar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:31:38 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/03 23:36:30 by easternstar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rule_swap(t_stack *ab)
{
	ft_swap(&ab->head->num, &ab->head->down->num);
	return (0);
}

int		rule_rotate(t_stack *ab)
{
	while (ab->head->down != NULL)
	{
		ft_swap(&ab->head->num, &ab->head->down->num);
		ab->head = ab->head->down;
	}
	while (ab->head->up != NULL)
		ab->head = ab->head->up;
	return (0);
}

int		rule_rev_rotate(t_stack *ab)
{
	while (ab->head->down != NULL)
		ab->head = ab->head->down;
	while (ab->head->up != NULL)
	{
		ft_swap(&ab->head->num, &ab->head->up->num);
		ab->head = ab->head->up;
	}
	return (0);
}

int		push_to_null_stack(t_stack *from, t_stack *to, t_node *swap)
{
	if (to->size == 1)
	{
		from->head->down->up = NULL;
		if (to->head != NULL)
		{
			free(to->head);
			to->head = NULL;
		}
		to->head = swap;
		from->head = from->head->down;
		to->head->down = NULL;
		to->head->up = NULL;
	}
	return (1);
}

int		rule_push(t_stack *from, t_stack *to)
{
	t_node	*swap;

	swap = from->head;
	if (from->size <= 1 && (from->size == 2 && to->size == 1))
		return (0);
	if (from->size == 2 && to->size != 1)
	{
		to->head->up = swap;
		swap->down = to->head;
		to->head = swap;
		from->head = NULL;
	}
	else if (to->size > 1)
	{
		from->head->down->up = NULL;
		from->head = from->head->down;
		to->head->up = swap;
		swap->down = to->head;
		to->head = swap;
	}
	else if (to->size == 1)
		push_to_null_stack(from, to, swap);
	from->size--;
	to->size++;
	return (0);
}
