/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:57:17 by imorina           #+#    #+#             */
/*   Updated: 2022/04/03 16:57:20 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1000
# endif

size_t	ft_strlen(const char *s);
char	*ft_strljoin(const char *s1, const char *s2, int len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strldup(const char *s1, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		read_file(char **line, int fd);
char	*get_next_line(int fd);

#endif
