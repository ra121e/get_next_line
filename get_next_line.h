/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:55 by athonda           #+#    #+#             */
/*   Updated: 2024/06/11 14:14:00 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif // BUFFER_SIZE

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
int	read_file(int fd, char *box);
char	*get_next_line(int fd);
#endif // GET_NEXT_LINE_H