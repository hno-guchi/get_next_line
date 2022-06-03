/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:11:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/03 17:17:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strclen(const char *s, int c)
{
	size_t			len;
	unsigned char	chr;

	if (s == NULL)
		return (0);
	len = 0;
	chr = (unsigned char)c;
	if (chr == '\0')
	{
		while (s[len] != '\0')
			len += 1;
		return (len);
	}
	else
	{
		while (s[len] != '\0')
		{
			if (s[len] == chr)
				return (len + 1);
			len += 1;
		}
		if (s[len] == chr)
			return (len + 1);
		return (0);
	}
}

char	*gnl_free_null(char *s)
{
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
	return (NULL);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	if (dst == src || n == 0)
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

	if (dst == NULL || src == NULL)
		return (dst);
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

char	*gnl_strnjoin(char *save, char *buff, size_t s_len, size_t b_len)
{
	char	*dst;

	if (buff == NULL)
		return (gnl_free_null(save));
	dst = (char *)malloc((s_len + b_len + 1) * sizeof(char));
	if (dst == NULL)
		return (gnl_free_null(save));
	(void)gnl_memmove(dst, save, s_len);
	(void)gnl_memmove(&dst[s_len], buff, b_len + 1);
	(void)gnl_free_null(save);
	return (dst);
}
