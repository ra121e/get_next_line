/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/11 17:57:38 by athonda          ###   ########.fr       */
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

int	read_file(int fd, char *box)
{
	ssize_t	len;
	char	buf[BUFFER_SIZE];
	int	i;

	len = 0;
	len = read(fd, buf, 1);
	*box = *buf;
	box++;
	while (len > 0 && *buf != '\n')
	{
		len = len + read(fd, buf, 1);
		*box = *buf;
		box++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	p[BUFFER_SIZE];
	ssize_t		len;

	len = read_file(fd, p);
	p[len + 1] = '\0';
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
	p = get_next_line(fd);
	while (*p)
	{
		write(1, p, BUFFER_SIZE);
		p++;
	}
	close(fd);
	return (0);
}