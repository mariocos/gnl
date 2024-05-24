/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:15:00 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/24 14:53:48 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **backup, char *buffer)
{
	int			check;
	char		*temp;

	check = 1;
	while (check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check <= 0)
		{
			free (buffer);
			return (NULL);
		}
		if (!backup)
			backup[fd] = ft_strdup("");
		temp = backup[fd];
		buffer[check] = '\0';
		backup[fd] = ft_strjoin(temp, buffer);
		free (temp);
		if (ft_strchr(backup[fd], '\n') == 1)
			break ;
	}
	free(buffer);
	return (backup[fd]);
}

char	*format_str(char *backup)
{
	int		i;
	char	*ret;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	ret = malloc(i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
	{
		ret[i] = backup[i];
		i++;
	}
	ret[i] = '\n';
	i++;
	ret[i] = '\0';
	return (ret);
}

char	*format_backup(char *backup)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	ret = malloc(ft_strlen(backup) - i + 1);
	if (!ret)
		return (NULL);
	while (backup[i] != '\0')
		ret[j++] = backup[i++];
	ret[j] = '\0';
	free (backup);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*backup[BUFFER_SIZE];
	char		*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	backup[fd] = read_line(fd, backup, buffer);
	if (!backup[fd])
		return (NULL);
	str = format_str(backup[fd]);
	backup[fd] = format_backup(backup[fd]);
	return (str);
} 
