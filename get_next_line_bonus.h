/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:11:47 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/03 12:14:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

size_t	gnl_strclen(const char *s, int c);
char	*gnl_free_null(char *s);
void	*gnl_memmove(void *dst, const void *src, size_t len);
char	*gnl_strnjoin(char *s1, char *s2, size_t s1_len, size_t s2_len);
char	*get_next_line(int fd);

#endif
