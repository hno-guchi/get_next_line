/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:11:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/05/31 19:23:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len += 1;
	return (len);
}

size_t	gnl_strclen(const char *s, int c)
{
	ssize_t			i;
	unsigned char	chr;

	if (s == NULL)
		return (0);
	i = 0;
	chr = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return (i + 1);
		i += 1;
	}
	if (s[i] == chr)
		return (i + 1);
	return (0);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	if (n == 0 || dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	while (i < n)
	{
		dst_uc[i] = src_uc[i];
		i += 1;
	}
	return (dst);
}

void	*gnl_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_uc;
	unsigned char		*src_uc;

	if (dst == src || len == 0)
		return (dst);
	i = 1;
	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	if (src < dst)
	{
		while (i <= len)
		{
			dst_uc[len - i] = src_uc[len - i];
			i += 1;
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}

char	*gnl_strnjoin(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	char	*dst;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char *));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	(void)gnl_memmove(dst, s1, s1_len);
	(void)gnl_memmove(&dst[s1_len], s2, s2_len + 1);
	free(s1);
	return (dst);
}
