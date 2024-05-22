#include "get_next_line.h"

char	*ft_strjoin(char *Backup, char *Buffer)
{
	char	*Ret;
	int		Backup_Index;
	int		Buffer_Index;

	Backup_Index = 0;
	Buffer_Index = 0;
	Ret = malloc(ft_strlen(Backup) + ft_strlen(Buffer) + 1);
	if (!Ret)
		return (NULL);
	while (Backup && Backup[Backup_Index] != '\0')
	{
		Ret[Backup_Index] = Backup[Backup_Index];
		Backup_Index++;
	}
	while (Buffer && Buffer[Buffer_Index] != '\0')
		Ret[Backup_Index++] = Buffer[Buffer_Index++];
	Ret[Backup_Index] = '\0';
	return (Ret);
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

int	ft_strlen(char	*Backup)
{
	int	i;

	i = 0;
	if (!Backup)
		return (0);
	while (Backup[i] != '\0')
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

