/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:18:31 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strjoint(char *s1, char const *s2)
{
	size_t	lenght_s1;
	size_t	lenght_s2;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lenght_s1 = ft_strlen(s1);
	lenght_s2 = ft_strlen(s2);
	dest = malloc(lenght_s1 + lenght_s2 + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, lenght_s1 + 1);
	ft_strlcpy(dest + lenght_s1, s2, lenght_s2 + 1);
	return (dest);
}

void	clean_the_trash(char **trash)
{
	char	*temp;
	char	*str;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	str = NULL;
	while (trash[0][i] != '\n' && trash[0][i])
		i++;
	if (trash[0][i] == '\n')
		flag = 1;
	str = ft_strjoint(str, *trash + i + flag);
	free(*trash);
	*trash = NULL;
	temp = str;
	if (str[0] != '\0')
		*trash = ft_strjoint(*trash, str);
	free(temp);
}

char	*set_the_line(char *trash)
{
	char	*temp;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (trash[i] != '\n' && trash[i])
		i++;
	if (trash[i] == '\n')
		flag = 1;
	temp = (char *)malloc(i + flag + 1);
	if (!temp)
		return (NULL);
	i = -1;
	while (++i >= 0 && trash[i] != '\n' && trash[i])
		temp[i] = trash[i];
	if (trash[i] == '\n')
	{
		temp[i] = '\n';
		temp[i + 1] = '\0';
	}
	else
		temp[i] = '\0';
	return (temp);
}

void	make_trash_full(size_t size, int fd, char **trash)
{
	char		*str;
	char		*temp;
	long int	nbytes;

	str = (char *)malloc(size + 1);
	if (!str)
		return ;
	nbytes = 1;
	while (nbytes != 0 && !ft_strchr(*trash, '\n'))
	{
		nbytes = read(fd, str, size);
		if (nbytes <= 0)
			break ;
		str[nbytes] = '\0';
		temp = *trash;
		*trash = ft_strjoint(*trash, str);
		free(temp);
	}
	free(str);
	if (nbytes < 0)
	{
		free(*trash);
		*trash = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*trash;
	char		*line;
	size_t		size;

	size = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	make_trash_full(size, fd, &trash);
	if (!trash)
		return (NULL);
	line = set_the_line(trash);
	if (!line)
		return (NULL);
	clean_the_trash(&trash);
	return (line);
}
