/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:02:58 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/16 13:01:21 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		if (str)
		{
			if (str)
				free(str);
			str = NULL;
			return (0);
		}
	}
	str = init_str(fd, str);
	if (!str)
		return (0);
	line = line_str (str);
	str = clean_str(str);
	return (line);
}

/* 
// get_next_line.c dosyasındaki get_next_line fonksiyonunu ekrana yazdırma işlemi
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int 	fd = open("get_next_line.c", O_RDONLY);
	int		i = 0;
	char 	*str;

	while(i < 92)
	{
		str = get_next_line(fd);
		i++;
	}
	i = 0;
	while(i < 22)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
}*/