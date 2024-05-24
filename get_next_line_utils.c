/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:34:14 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/24 14:45:35 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *backup, char *buffer)
{
	char	*ret;
	int		backup_index;
	int		buffer_index;

	backup_index = 0;
	buffer_index = 0;
	ret = malloc(ft_strlen(backup) + ft_strlen(buffer) + 1);
	if (!ret)
		return (NULL);
	while (backup && backup[backup_index] != '\0')
	{
		ret[backup_index] = backup[backup_index];
		backup_index++;
	}
	while (buffer && buffer[buffer_index] != '\0')
		ret[backup_index++] = buffer[buffer_index++];
	ret[backup_index] = '\0';
	return (ret);
}

char	*ft_strdup(char *s)
{
	int		str_len;
	char	*dest;
	int		i;

	i = 0;
	str_len = ft_strlen(s) + 1;
	dest = malloc(sizeof(char) * str_len);
	if (dest == NULL)
		return (NULL);
	while (s && s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char	*backup)
{
	int	i;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	char	hold;

	hold = c;
	while (*s)
	{
		if (*s == hold)
			return (1);
		s++;
	}
	return (0);
}
