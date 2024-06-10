/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/10 15:52:40 by athonda          ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	static char	*p;

	read(fd, buf, 3);
	p = buf;
	return (p);
}

int	main(void)
{
	int	fd;
	char	*p;

	fd = open("./test_open_jp.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	p = get_next_line(fd);
	write(1, p, 3);
	close(fd);
	return (0);
}