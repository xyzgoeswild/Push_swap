/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:39:58 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	fill_array_b(t_stack_a *a)
{
	t_list	*temp;
	int		i;

	temp = a->b;
	a->array_size_b = ft_lstsize(a->b);
	i = 0;
	a->array_b = malloc(a->array_size_b * 4);
	if (!a->array_b)
		exit(1);
	while (temp)
	{
		a->array_b[i] = *temp->content;
		temp = temp->next;
		i++;
	}
	sort_it_big(a);
}

int	find_next(int x, t_stack_a *data)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = data->b;
	while (temp)
	{
		if (*temp->content == x)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

int	check(t_stack_a *a, int x, int size)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = a->a;
	while (temp)
	{
		if (temp->index <= x || temp->index <= x + size)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

int	find(t_stack_a *a, int x)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = a->a;
	while (temp)
	{
		if (*temp->content == x)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

int	find_smallest(t_stack_a *a)
{
	int		small;
	t_list	*temp;

	temp = a->a;
	small = *temp->content;
	while (temp)
	{
		if (small <= *temp->content)
			temp = temp->next;
		else
			small = *temp->content;
	}
	return (small);
}
