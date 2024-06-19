/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:27:09 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/16 11:55:45 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 10
# endif

char					*join_and_free(char *current_buffer, char *new_line);
char					*find_line(char *buffer);
char					*move_to_next(char *buffer);
char					*read_file(int fd, char *current_buffer);
char					*get_next_line(int fd);

void					*ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);

#endif
