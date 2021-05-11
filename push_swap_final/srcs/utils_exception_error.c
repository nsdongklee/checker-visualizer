/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exception_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:03:05 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/06 20:37:34 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exception_handle(int ac, char **av)
{
	int		i;

	if (ac <= 1)
		write(2, "Error\n", 6);
	i = 0;
	while (av[++i] != NULL)
	{
		if (ft_is_num(av[i]) == 0)
			return (1);
		else if (ft_is_num(av[i]) == 1)
		{
			if (find_overflow(av[i]) != 0)
				return (1);
		}
	}
	return (0);
}

int		check_arguments_sorted(char **av)
{
	int		num;
	int		cnt;
	int		flag;
	int		i;
	int		j;

	cnt = node_count(av);
	flag = 0;
	i = 0;
	while (++i < cnt)
	{
		num = ft_atoi(av[i]);
		j = i + 1;
		while (j < cnt)
		{
			if (num > ft_atoi(av[j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int		check_duplicated(char **av)
{
	char	*check;
	int		cnt;
	int		i;
	int		j;

	cnt = node_count(av);
	i = 0;
	while (++i < cnt)
	{
		check = ft_strdup(av[i]);
		j = i + 1;
		while (j < cnt)
		{
			if (ft_strcmp(check, av[j]) == 0)
			{
				free(check);
				return (1);
			}
			j++;
		}
		free(check);
	}
	return (0);
}

int		find_overflow(char *str)
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
			return (-1);
		else if ((flag * result) > 2147483647)
			return (1);
		idx++;
	}
	return (0);
}
