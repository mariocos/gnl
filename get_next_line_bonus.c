/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:15:00 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/24 16:42:56 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **backup, char *buffer)
{
	int			check;
	char		*temp;

	check = 1;
	while (check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
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
	ret = (char *)malloc(i + 2);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, backup, i + 2);
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*format_backup(char *backup)
{
	char	*ret;
	int		i;

	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	ret = malloc(ft_strlen(backup) - i + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, backup + i + 1, ft_strlen(backup) - i + 1);
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
