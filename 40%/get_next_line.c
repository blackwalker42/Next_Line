/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:46:01 by knage             #+#    #+#             */
/*   Updated: 2016/05/18 17:42:59 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

//void	*getnl(int fd, char *buf, int i)
//{
//	char	*str;
//	int		stri;
//
//	stri = 0;
//	str = (char *)malloc(BUFF_SIZE);
//	if (buf[++i] != '\0')
//	{
//		while (buf[i] != '\n' && buf[i] != '\0')
//			str[stri++] = buf[i++];
//		if (buf[i] == '\n')
//			{
//				*line = **p2;
//				return (1);
//			}
//		else if (buf[i] == '\0')
//			getnl(fd, buf);
//	}
//}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static int		i;
	char			*str;
	//static char		statchar;
	char			**p1;
	char			***p2; 
	static char		buf[BUFF_SIZE + 1];

	i = 0;
	str = (char *)malloc(BUFF_SIZE);
	p1 = &str;
	p2 = &p1;
	*line = "";
	ret = read(fd, buf, BUFF_SIZE);
	if (i != 0)
		puts("failed");
		//getnl(fd, buf, i);
	else
		//strt_tP(fd, &*line, &**p2)
		while (1)
		{
			if	(buf[i] != '\n' && buf[i] != '\0')
			{
				str[i] = buf[i];
				//ft_bzero(buf, i);
				i++;
			}
			else if (buf[i] == '\n')
			{
				str[i] = '\0';
				*line = **p2;
				puts(*line);
				return (1);
			}
			else if (buf[i] == '\0')
			{
				str[i] = '\0';
				*line = **p2;
				puts(*line);
				return (0);
			}
		}
	return (0);
}




int main()
{
	char *lolstr;
	int fd = open("testfile2", O_RDONLY);
	get_next_line(fd, &lolstr);
	printf("%s\n", lolstr);
	get_next_line(fd, &lolstr);
	printf("%s\n", lolstr);
	return 0;
}
