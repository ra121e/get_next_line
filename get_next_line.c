/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/13 09:56:17 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief write a function that returns a line read from a file descriptor
 */

#include "get_next_line.h"

/**
 * @fn char	*get_next_line(int fd)
 * @brief
 * @param[in]	fd file descriptor
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src && n != 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof (char) * (len_s1 + len_s2 + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len_s1);
	ft_memcpy(ptr + len_s1, s2, len_s2);
	ptr[len_s1 + len_s2] = '\0';
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}

int	read_file(int fd, char **box)
{
	ssize_t	len;
	ssize_t len_check;
	char	buf[BUFFER_SIZE + 1];
	char	*new;

	len = 0;
	len_check = read(fd, buf, 1);
	if (len_check < 0)
		return (-1);
	buf[len_check] = '\0';
	len = len_check;
	new = ft_strjoin(*box, buf);
	free(*box);
	*box = new;
	while (*buf != '\n')
	{
		len_check = read(fd, buf, 1);
		if (len_check < 0)
			return (-1);
		if (len_check == 0)
			return (0);
		buf[len_check] = '\0';
		len = len + len_check;
		new = ft_strjoin(*box, buf);
		free(*box);
		*box = new;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	char	*p;
	ssize_t		len;

	p = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (p == NULL)
		return (NULL);
	ft_bzero(p, BUFFER_SIZE + 1);
	len = read_file(fd, &p);
	if (len == -1 || len == 0)
		return (NULL);
	p[len - 1] = '\0';
	return (p);
}

int	main(void)
{
	int	fd;
	char	*p;

	fd = open("./test_open.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s\n", p);
		free(p);
	}
	close(fd);
	return (0);
}