/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:26:54 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/16 18:01:19 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *current_buffer, char *new_line)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(current_buffer, new_line);
	free(current_buffer);
	return (new_buffer);
}

char	*find_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*move_to_next(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*read_file(int fd, char *current_buffer)
{
	int		bytes_read;
	char	*new_buffer;

	if (!current_buffer)
		current_buffer = ft_calloc(1, 1);
	new_buffer = ft_calloc(BUFFER_SIZE + 1, (sizeof(char)));
	if (!new_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_buffer);
			return (NULL);
		}
		new_buffer[bytes_read] = 0;
		current_buffer = join_and_free(current_buffer, new_buffer);
		if (ft_strchr(new_buffer, '\n'))
			break ;
	}
	free(new_buffer);
	return (current_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = find_line(buffer);
	buffer = move_to_next(buffer);
	return (next_line);
}

// int main (void)
// {
//     int fd;
//     char *next_line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf ("error");
//         return (1);
//     }
//     while (1)
//     {
//         next_line = get_next_line (fd);
//         if (next_line == NULL)
//             break ;
//         printf ("%s\n", next_line);
//         free (next_line);
//         next_line = NULL;
//     }
//     close (fd);
//     return (0);
// }