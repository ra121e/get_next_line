/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:51:19 by athonda           #+#    #+#             */
/*   Updated: 2024/06/20 13:53:16 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	char	*p1;
	char	*p2;
	char	*p3;
/*
	int	fd4;
	int	fd5;
	int	fd6;
	int	fd7;
*/

	fd1 = open("./test_open_en.txt", 0);
	if (fd1 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	fd2 = open("./test_open_jp.txt", 0);
	if (fd2 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	fd3 = open("./test_open_ch.txt", 0);
	if (fd3 == -1)
	{
		printf("file open error!\n");
		return (0);
	}

	p1 = get_next_line(fd1);
	p2 = get_next_line(fd2);
	p3 = get_next_line(fd3);

	while (p1 || p2 || p3)
	{
		printf("%s", p1);
		free(p1);
		printf("%s", p2);
		free(p2);
		printf("%s", p3);
		free(p3);
		p1 = get_next_line(fd1);
		p2 = get_next_line(fd2);
		p3 = get_next_line(fd3);
	}
	close(fd1);
	close(fd2);
/*
	fd2 = open("./variable_nls.txt", 0);
	if (fd2 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd2)))
	{
		printf("%s", p);
		free(p);
	}
	fd3 = open("./test_open_nl.txt", 0);
	if (fd3 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd3)))
	{
		printf("%s", p);
		free(p);
	}
	fd4 = open("./test_open_1char.txt", 0);
	if (fd4 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd4)))
	{
		printf("%s", p);
		free(p);
	}
	fd5 = open("./test_open_1char.txt", 0);
	if (fd5 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd5)))
	{
		printf("%s", p);
		free(p);
	}
	fd6 = open("./test_one_newline.txt", 0);
	if (fd6 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd6)))
	{
		printf("%s", p);
		free(p);
	}
	fd7 = open("./test_open_none.txt", 0);
	if (fd7 == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd7)))
	{
		printf("%s", p);
		free(p);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7);
*/
	return (0);
}
