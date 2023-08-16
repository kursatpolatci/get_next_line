/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:24 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/04 15:29:30 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*init_str(int fd, char *str);
char	*line_str(char *str);
char	*clean_str(char *str);

int		founded_to_nl(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
#endif