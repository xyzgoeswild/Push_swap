/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:12:33 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_1(size_t size, char const *index)
{
	char	*dest;

	dest = malloc(size);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, index, size);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	lenght_str;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	lenght_str = ft_strlen(str);
	if (start >= lenght_str && *str != '\0')
		return (ft_strdup(""));
	if (lenght_str - start - 1 >= len)
		return (dest = malloc_1(len + 1, str + start));
	else
		return (dest = malloc_1(lenght_str - start + 1, str + start));
}
