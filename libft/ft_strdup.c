/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:44:15 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_lenght;
	char	*ptr;

	str_lenght = ft_strlen(str);
	ptr = malloc(str_lenght + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, str_lenght + 1);
	return (ptr);
}
