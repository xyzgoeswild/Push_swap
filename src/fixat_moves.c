/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:08:53 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ss(t_stack_a *a, int flag)
{
	int	temp_a;
	int	temp_b;

	if (ft_lstsize(a->a) > 1)
	{
		temp_a = *a->a->content;
		*a->a->content = *a->a->next->content;
		*a->a->next->content = temp_a;
	}
	if (ft_lstsize(a->b) > 1)
	{
		temp_b = *a->b->content;
		*a->b->content = *a->b->next->content;
		*a->b->next->content = temp_b;
	}
	if (flag == 0)
		write(1, "ss\n", 3);
}

void	rr(t_stack_a *a, int flag)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (ft_lstsize(a->a) > 1)
	{
		temp_a = a->a;
		a->a = a->a->next;
		temp_a->next = NULL;
		ft_lstadd_back(&a->a, temp_a);
	}
	if (ft_lstsize(a->b) > 1)
	{
		temp_b = a->b;
		a->b = a->b->next;
		temp_b->next = NULL;
		ft_lstadd_back(&a->b, temp_b);
	}
	if (flag == 0)
		write(1, "rr\n", 3);
}

void	rrr(t_stack_a *a, int flag)
{
	t_list	*temp_a;
	t_list	*temp1_a;
	t_list	*temp_b;
	t_list	*temp1_b;

	temp1_a = a->a;
	temp1_b = a->b;
	if (ft_lstsize(a->a) > 1)
	{
		temp_a = ft_lstlast(a->a);
		while (temp1_a->next != temp_a)
			temp1_a = temp1_a->next;
		temp1_a->next = NULL;
		ft_lstadd_front(&a->a, temp_a);
	}
	if (ft_lstsize(a->b) > 1)
	{
		temp_b = ft_lstlast(a->b);
		while (temp1_b->next != temp_b)
			temp1_b = temp1_b->next;
		temp1_b->next = NULL;
		ft_lstadd_front(&a->b, temp_b);
	}
	if (flag == 0)
		write(1, "rrr\n", 4);
}
