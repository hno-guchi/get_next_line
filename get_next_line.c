/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:10:51 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/05/31 19:23:35 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_left_str(char *str, size_t r_len, size_t n_len)
{
	size_t	i;
	char	*left_str;

	i = 0;
	if (n_len != 0)
		n_len -= 1;
	if (str[n_len] == 0)
	{
		free(str);
		return (NULL);
	}
	left_str = (char *)malloc((r_len - n_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	n_len += 1;
	while (str[n_len] != '\0')
	{
		left_str[i] = str[n_len];
		i += 1;
		n_len += 1;
	}
	left_str[i] = '\0';
	free(str);
	return (left_str);
}

static char	*get_new_line(char	*str, size_t len)
{
	char	*new_line;

	if (str[0] == 0)
		return (NULL);
	new_line = (char *)malloc((len + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	new_line = (char *)gnl_memmove(new_line, str, len);
	new_line[len] = '\0';
	return (new_line);
}

static char	*gnl_read_file(int fd, char *str, size_t *s_len, size_t *nl_len)
{
	char		buff[BUFFER_SIZE + 1];
	ssize_t		read_byte;
	size_t		b_nl_len;

	read_byte = 1;
	b_nl_len = gnl_strclen(str, '\n');
	if (b_nl_len != 0)
		nl_len[0] = b_nl_len;
	else
		nl_len[0] = s_len[0];
	while (b_nl_len == 0 && read_byte != 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		buff[read_byte] = '\0';
		str = gnl_strnjoin(str, buff, s_len[0], (size_t)read_byte);
		b_nl_len = gnl_strclen(buff, '\n');
		s_len[0] += (size_t)read_byte;
		if (b_nl_len != 0)
			nl_len[0] += b_nl_len;
		else
			nl_len[0] += (size_t)read_byte;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*new_line;
	size_t		save_len[1];
	size_t		nline_len[1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nline_len[0] = 0;
	save_len[0] = 0;
	if (save_str != NULL)
		save_len[0] = ft_strlen(save_str);
	save_str = gnl_read_file(fd, save_str, save_len, nline_len);
	if (save_str == NULL)
		return (NULL);
	new_line = get_new_line(save_str, nline_len[0]);
	save_str = gnl_left_str(save_str, save_len[0], nline_len[0]);
	return (new_line);
}
