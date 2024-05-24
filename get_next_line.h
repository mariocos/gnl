/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:16:09 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/22 15:39:49 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char			*ft_strjoin(char *backup, char *buffer);
char		*format_str(char *backup);
char		*format_backup(char *backup);
char			*get_next_line(int fd);

char			*ft_strjoin(char *backup, char *buffer);
char			*ft_strdup(char *s);
char			*get_next_line(int fd);
int				ft_strlen(char	*backup);
int				ft_strchr(char *s, int c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif
