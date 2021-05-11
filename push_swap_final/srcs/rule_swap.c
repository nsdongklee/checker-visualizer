/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:39:13 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/01 16:17:57 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_sa(t_stack *a, int print)
{
	if (a->size <= 2)
		return ;
	rule_swap(a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	ops_sb(t_stack *b, int print)
{
	if (b->size <= 2)
		return ;
	rule_swap(b);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ops_ss(t_stack *a, t_stack *b, int print)
{
	if (a->size <= 2 && b->size <= 2)
		return ;
	rule_swap(a);
	rule_swap(b);
	if (print == 1)
		write(1, "ss\n", 3);
}
