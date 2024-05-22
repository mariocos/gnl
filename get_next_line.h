#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *Backup, char *Buffer);
static	 char	*format_str(char *backup);
static 	char	*format_backup(char *backup);
char	*get_next_line(int fd);

char	*ft_strjoin(char *Backup, char *Buffer);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
int		ft_strlen(char	*Backup);
int		ft_strchr(char *s, int c);
#endif