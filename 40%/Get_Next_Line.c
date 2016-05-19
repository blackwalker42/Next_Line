/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 07:04:21 by knage             #+#    #+#             */
/*   Updated: 2016/05/19 17:49:02 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define BUFF_SIZE 1000

char    *strt_tp(char buf[], int *i);
char *lessthanline(int fd, int *i);
char *ft_realloc(char *str, int i);
char	*getnl(char buf[], int *i)
{
	char	*str;
	int		stri;

	stri = 0;
	str = (char *)malloc(BUFF_SIZE);
	if (buf[++(*i)] != '\0')
	{
		while (buf[*i] != '\n' && buf[*i] != '\0')
		{
			str[stri] = buf[*i];
			(*i)++;
			stri++;
		}
		if (buf[*i] == '\n')
		{
			return str;
		}
		else if (buf[*i] == '\0')
			return (str);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static int		i;
	static int pass;
	char			**p1;
	char			***p2;
	static char            *buf;
	static char             *str;

	p1 = &buf;
	p2 = &p1;
	if (pass == 0)
	{
		buf = (char *)malloc(BUFF_SIZE);
		str = (char *)malloc(BUFF_SIZE);
		pass = 1;
	}
	if (i != 0)
	{
		buf = lessthanline(fd, &i);
		*line = **p2;
		return (1);
	}
	else if (i == 0)
	{
		buf = lessthanline(fd, &i);
		*line = **p2;
		return (1);
	}
	else
		return (-1);
}

char *lessthanline(int fd, int *i)
{
	char buf[BUFF_SIZE];
	static int j;
	static int ret;
	int k;
	char *str;
	char *hello;

	j = 0;
	k = 0;
	str = (char *)malloc((char) + 1);
	//if (!j)
		ret = read(fd, buf, BUFF_SIZE);	
	while (buf[j] != '\n' && ret)
	{
		printf("hello");
		str = ft_realloc(str, k);
		str[k] = buf[j];
		j++;
		k++;
		if (j == BUFF_SIZE)
		{
			ret = read(fd, buf, BUFF_SIZE);
			j = 0;
		}
	}
	str[k] = '\0';
	j++;
	*i = j;
	hello = str;
	printf("end\n");
	return (hello);
}

char *ft_realloc(char *str, int i)
{
	char *str2;
	int j;
	int k;

	j = 0;
	k = 0;
	str2 = (char*)malloc(sizeof(char*) * i + 1);
	while (j != i) 
	{
		printf("number: %i -> %c\n", j, str[j]);
		str2[j] = str[j];
		j++;
	}
	return (str2);
}

int main()
{
	char *lolstr;
	int fd = open("testfile2", O_RDONLY);
	if (get_next_line(fd, &lolstr) == 1)
		printf("1We good\n\n%s\n", lolstr);
	else
		printf("1We not good\n\n%s", lolstr);    
	if (get_next_line(fd, &lolstr) == 1)
		printf("2We good\n\n%s\n", lolstr);
	else
		printf("2We not good\n\n%s", lolstr);
	if (get_next_line(fd, &lolstr) == 1)
		printf("3We good\n\n%s\n", lolstr);
	else
		printf("3We not good\n\n%s", lolstr);
	return 0;
}
