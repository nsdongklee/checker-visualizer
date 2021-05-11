/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:37:56 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/01 16:17:21 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_rra(t_stack *a, int print)
{
	if (a->size <= 2)
		return ;
	rule_rev_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	ops_rrb(t_stack *b, int print)
{
	if (b->size <= 2)
		return ;
	rule_rev_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	ops_rrr(t_stack *a, t_stack *b, int print)
{
	if (a->size <= 2 || b->size <= 2)
		return ;
	rule_rev_rotate(a);
	rule_rev_rotate(b);
	if (print == 1)
		write(1, "rrr\n", 4);
}
