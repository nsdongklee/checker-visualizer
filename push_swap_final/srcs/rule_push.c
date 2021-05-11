/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:38:47 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/03 11:19:24 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_pa(t_stack *a, t_stack *b, int print)
{
	if (b->size <= 1)
		return ;
	rule_push(b, a);
	if (print == 1)
		write(1, "pa\n", 3);
}

void	ops_pb(t_stack *a, t_stack *b, int print)
{
	if (a->size <= 1)
		return ;
	rule_push(a, b);
	if (print == 1)
		write(1, "pb\n", 3);
}
