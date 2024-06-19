/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 11:27:01 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/16 11:27:02 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	total;

	total = count * size;
	dest = malloc(total);
	if (dest != NULL)
		ft_bzero(dest, (total));
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*hold;
	int		is1;
	int		is2;
	int		ih;

	hold = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!hold)
		return (NULL);
	is1 = 0;
	is2 = 0;
	ih = 0;
	while (s1[is1] != '\0')
	{
		hold[ih] = s1[is1];
		ih++;
		is1++;
	}
	while (s2[is2] != '\0')
	{
		hold[ih] = s2[is2];
		ih++;
		is2++;
	}
	hold[ih] = '\0';
	return (hold);
}
