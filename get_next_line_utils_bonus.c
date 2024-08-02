/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:34:14 by mariocos          #+#    #+#             */
/*   Updated: 2024/08/02 14:27:15 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *dest, char *src)
{
	char	*ret;
	int		dest_i;
	int		src_i;

	dest_i = 0;
	src_i = 0;
	ret = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (!ret)
		return (NULL);
	while (dest && dest[dest_i] != '\0')
	{
		ret[dest_i] = dest[dest_i];
		dest_i++;
	}
	while (src && src[src_i] != '\0')
		ret[dest_i++] = src[src_i++];
	ret[dest_i] = '\0';
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}
