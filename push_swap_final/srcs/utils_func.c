/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:54:22 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/06 20:38:13 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(char *s, int c)
{
	char temp_c;

	temp_c = (char)c;
	while (*s)
	{
		if (*s == temp_c)
			return ((char *)s);
		s++;
	}
	if (*s == temp_c)
		return ((char *)s);
	return (0);
}

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
