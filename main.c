/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:48:25 by athonda           #+#    #+#             */
/*   Updated: 2024/06/20 13:53:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		printf("%s", p);
		free(p);
	}
	close(fd);
	fd = open("./variable_nls.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	fd = open("./test_open_nl.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	fd = open("./test_open_1char.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	fd = open("./test_open_1char.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	fd = open("./test_one_newline.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	fd = open("./test_open_none.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd);
	return (0);
}
