/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:38:29 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/03 11:19:56 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_ra(t_stack *a, int print)
{
	if (a->size <= 2)
		return ;
	rule_rotate(a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	ops_rb(t_stack *b, int print)
{
	if (b->size <= 2)
		return ;
	rule_rotate(b);
	if (print == 1)
		write(1, "rb\n", 3);
}

void	ops_rr(t_stack *a, t_stack *b, int print)
{
	if (a->size <= 2 || b->size <= 2)
		return ;
	rule_rotate(a);
	rule_rotate(b);
	if (print == 1)
		write(1, "rr\n", 3);
}
