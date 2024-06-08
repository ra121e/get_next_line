/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/08 16:19:26 by athonda          ###   ########.fr       */
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

char	*get_next_line(int fd, char *p)
{
	char	buf[1024];

	read(fd, buf, 100);
	p = buf;
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
	p = get_next_line(fd, p);
	write(1, p, 100);
	close(fd);
	return (0);
}