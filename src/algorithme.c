/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:38:41 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	algo_chance(t_stack_a *a)
{
	int	x;
	int	chunk_size;

	x = 0;
	chunk_size = (int)a->chunk_size;
	while (x < a->array_size)
	{
		if (a->a->index <= x)
		{
			pb(a, 0);
			rb(a, 0);
			x++;
		}
		else if (a->a->index <= x + chunk_size)
		{
			pb(a, 0);
			x++;
		}
		else if (check(a, x, chunk_size) <= ft_lstsize(a->a) / 2)
			ra(a, 0);
		else
			rra(a, 0);
	}
	b_to_a(a);
}

void	sort_5(t_stack_a *a)
{
	int	small;
	int	i;

	small = find_smallest(a);
	i = 0;
	while (i < 2)
	{
		if (*a->a->content == small)
		{
			pb(a, 0);
			small = find_smallest(a);
			i++;
		}
		else if (find(a, small) < ft_lstsize(a->a) / 2)
			ra(a, 0);
		else
			rra(a, 0);
	}
	sort_3(a);
	pa(a, 0);
	pa(a, 0);
}

void	sort_3(t_stack_a *a)
{
	int		i;
	int		data;
	t_list	*temp;

	i = 0;
	data = *a->a->content;
	temp = a->a;
	while (temp)
	{
		if (data >= *temp->content)
			temp = temp->next;
		else
			data = *temp->content;
	}
	i = find(a, data);
	if (i == 0)
		ra(a, 0);
	else if (i == 1)
		rra(a, 0);
	if (*a->a->content > *a->a->next->content)
		sa(a, 0);
}
