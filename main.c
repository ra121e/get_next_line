/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:48:25 by athonda           #+#    #+#             */
/*   Updated: 2024/06/14 19:04:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*p;

	fd = open("./test_open_short.txt", 0);
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