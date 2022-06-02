/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:10:51 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/02 21:40:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_left_str(char *save, size_t s_len, size_t nl_len)
{
	size_t	i;
	char	*left_save;

	i = 0;
	if (nl_len != 0)
		nl_len -= 1;
	if (save[nl_len] == 0)
	{
		free(save);
		return (NULL);
	}
	left_save = (char *)malloc((s_len - nl_len + 1) * sizeof(char));
	if (left_save == NULL)
		return (NULL);
	nl_len += 1;
	while (save[nl_len] != '\0')
	{
		left_save[i] = save[nl_len];
		i += 1;
		nl_len += 1;
	}
	left_save[i] = '\0';
	free(save);
	return (left_save);
}

static char	*gnl_get_new_line(char	*save, size_t nl_len)
{
	char	*new_line;

	if (save[0] == 0)
		return (NULL);
	new_line = (char *)malloc((nl_len + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	new_line = (char *)gnl_memmove(new_line, save, nl_len);
	new_line[nl_len] = '\0';
	return (new_line);
}

static size_t	gnl_add_nline_len(size_t b_nl_len, size_t rd_len)
{
	if (b_nl_len != 0)
		return (b_nl_len);
	else
		return (rd_len);
}

static char	*gnl_read_file(int fd, char *save, size_t *s_len, size_t *nl_len)
{
	char		*buff;
	ssize_t		read_byte;
	size_t		b_nl_len;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	read_byte = 1;
	b_nl_len = gnl_strclen(save, '\n');
	while (b_nl_len == 0 && read_byte != 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_byte] = '\0';
		save = gnl_strnjoin(save, buff, s_len[0], (size_t)read_byte);
		b_nl_len = gnl_strclen(buff, '\n');
		s_len[0] += (size_t)read_byte;
		nl_len[0] += gnl_add_nline_len(b_nl_len, (size_t)read_byte);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*new_line;
	size_t		save_len[1];
	size_t		nline_len[1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_len[0] = gnl_strlen(save_str);
	nline_len[0] = gnl_strclen(save_str, '\n');
	if (nline_len[0] == 0)
		nline_len[0] = save_len[0];
	save_str = gnl_read_file(fd, save_str, save_len, nline_len);
	if (save_str == NULL)
		return (NULL);
	new_line = gnl_get_new_line(save_str, nline_len[0]);
	save_str = gnl_left_str(save_str, save_len[0], nline_len[0]);
	return (new_line);
}
