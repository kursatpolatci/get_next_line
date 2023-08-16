/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:05:15 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/16 13:03:16 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*init_str(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (!founded_to_nl(str) && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buff);
			free(str);
			return (0);
		}
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*line_str(char *str)
{
	char	*line;
	int		i;
	int		new_line;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = founded_to_nl(str);
	line = (char *)malloc(sizeof(char) * (i + new_line + 1));
	i = 0;
	if (!line)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	new_str = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (0);
	j = 0;
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free (str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = init_str(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = line_str (str[fd]);
	str[fd] = clean_str(str[fd]);
	return (line);
}

/*
// 12 satır get_next_line.c'den oku
// 12 satır get_next_line.h'den oku
// ardından get_next_line.c'nin devamını oku.
// okurken ekrana yazdır.
// aynı zamanda farklı bir dosyaya tüm bu işlemleri yazdır
#include <stdio.h>
#include <fcntl.h>

void print_and_write(char *str, int *fd)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		write(*fd, &str[i], 1);
		i++;
	}
}

int main()
{
	int fd1 = open("get_next_line.c", O_RDONLY);
	int fd2 = open("get_next_line.h", O_RDONLY);
	int fd = open("deneme.txt", O_RDWR | O_CREAT, 0777);

	char 	*str;
	int		i;

	i = 0;
	while (i < 12)
	{
		str = get_next_line(fd1);
		print_and_write(str, &fd);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		str = get_next_line(fd2);
		print_and_write(str, &fd);
		i++;
	}
	i = 0;
	while(str)
	{
		str = get_next_line(fd1);
		print_and_write(str, &fd);
	}
}*/