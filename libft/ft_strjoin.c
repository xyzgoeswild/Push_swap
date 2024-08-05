/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:16:37 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
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
	free(s1);
	return (dest);
}
