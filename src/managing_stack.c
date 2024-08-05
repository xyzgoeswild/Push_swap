/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:34:20 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	fill_stack_a(t_stack_a *a)
{
	int	i;
	int	*temp;

	i = 0;
	a->b = NULL;
	a->a = NULL;
	while (i < a->array_size)
	{
		temp = malloc(4);
		if (!temp)
			exit(1);
		*temp = a->array[i++];
		ft_lstadd_back(&a->a, ft_lstnew(temp));
	}
}

void	fill_index_values(t_stack_a *a)
{
	t_list	*temp;
	int		i;

	temp = a->a;
	while (temp)
	{
		i = 0;
		while (*temp->content != a->array[i])
			i++;
		temp->index = i;
		temp = temp->next;
	}
	a->chunk_size = (15.0 / 400.0) * a->array_size + (15 - 15.0 / 4.0);
}

void	b_to_a(t_stack_a *a)
{
	int	i;

	i = 0;
	fill_array_b(a);
	while (i < a->array_size_b)
	{
		if (*a->b->content == a->array_b[i])
		{
			pa(a, 0);
			i++;
		}
		else if (find_next(a->array_b[i], a) > ft_lstsize(a->b) / 2)
			rrb(a, 0);
		else
			rb(a, 0);
	}
}

void	ssort_array_elements(t_stack_a *a)
{
	int	temp;
	int	i;
	int	j;

	i = 1;
	while (i < a->array_size)
	{
		temp = a->array[i];
		j = i - 1;
		while (j >= 0 && a->array[j] > temp)
		{
			a->array[j + 1] = a->array[j];
			j--;
		}
		a->array[j + 1] = temp;
		i++;
	}
}

void	sort_it_big(t_stack_a *a)
{
	int	temp;
	int	i;
	int	j;

	i = 1;
	while (i < a->array_size_b)
	{
		temp = a->array_b[i];
		j = i - 1;
		while (j >= 0 && a->array_b[j] < temp)
		{
			a->array_b[j + 1] = a->array_b[j];
			j--;
		}
		a->array_b[j + 1] = temp;
		i++;
	}
}
