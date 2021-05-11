/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:54:02 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/06 20:37:32 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac <= 2)
		return (0);
	if (exception_handle(ac, av) || check_duplicated(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	initiate_stack(&stack_a, &stack_b);
	insert_data(av, &stack_a);
	parse_operators(&stack_a, &stack_b);
	release_all_nodes(&stack_a);
	release_all_nodes(&stack_b);
	return (0);
}
