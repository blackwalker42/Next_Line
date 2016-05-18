/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 07:04:21 by knage             #+#    #+#             */
/*   Updated: 2016/05/18 07:23:25 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 2

int	get_next_line(const int fd, char **line)
{
	char		c;
	static int	i;
	int			j;
	int			k;
	char		str[BUFF_SIZE];

	i = 0;
	j = 0;
	k = 0;
	while (read(fd, &c, 1) && k != BUFF_SIZE && c != '\n')
	{
		if (j == i)
		{
			str[k] = c;	
			i++;
			k++;
		}
		j++;
	}
	str[k] = '\0';
	while (c != '\n')
	{
		read(fd, &c, 1);
		i++;
	}
	//i++;
	puts(str);
	*line = str;
	return (0);
}

int	main(void)
{
	char line[10];
	char *c = line;
	int fd;
	char test;

	fd = open("testfile", O_RDONLY);
	get_next_line(fd, &c);
	get_next_line(fd, &c);
	get_next_line(fd, &c);
	return (0);
}
