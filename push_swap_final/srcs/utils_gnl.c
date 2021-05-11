/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:26:16 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/05 11:54:59 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strlen(char *s)
{
	int idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

int		ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	idx;
	int	len_src;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	idx = 0;
	while ((idx < len_src) && (idx + 1) < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (len_src);
}

int		ft_strlcat(char *dst, char *src, int dstsize)
{
	int src_len;
	int dst_len;
	int idx;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	idx = 0;
	while (src[idx] && (dst_len + idx + 1 < dstsize))
	{
		dst[dst_len + idx] = src[idx];
		idx++;
	}
	dst[dst_len + idx] = '\0';
	if (dst_len < dstsize)
		return (dst_len + src_len);
	return (dstsize + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*mal_s;
	int		len;
	int		idx;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mal_s = (char *)malloc(sizeof(char) * len);
	if (mal_s == NULL)
		return (0);
	idx = ft_strlcpy(mal_s, s1, len);
	ft_strlcat((mal_s + idx), s2, len);
	return (mal_s);
}

char	*ft_strdup(char *s1)
{
	int		s_len;
	int		idx;
	char	*dup;

	s_len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dup == NULL)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		dup[idx] = s1[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}
