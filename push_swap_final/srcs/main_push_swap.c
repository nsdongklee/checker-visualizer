/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:59:34 by easternstar       #+#    #+#             */
/*   Updated: 2021/05/06 20:37:54 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_pivot	pivot;

	if (ac <= 2)
		return (0);
	if (exception_handle(ac, av) || check_duplicated(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_arguments_sorted(av))
		return (0);
	initiate_stack(&stack_a, &stack_b);
	insert_data(av, &stack_a);
	if (ac <= 4)
		sort_under_three(&stack_a, &stack_b, 3);
	else if (ac <= 6)
		sort_under_five(&stack_a, &stack_b, &pivot, 5);
	else
		solve(&stack_a, &stack_b, (stack_a.size + stack_b.size - 2));
	release_all_nodes(&stack_a);
	release_all_nodes(&stack_b);
	return (0);
}
