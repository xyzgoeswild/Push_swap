/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 05:01:09 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	sb(t_stack_a *a, int flag)
{
	int	temp;

	if (ft_lstsize(a->b) > 1)
	{
		temp = *a->b->content;
		*a->b->content = *a->b->next->content;
		*a->b->next->content = temp;
	}
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	rb(t_stack_a *a, int flag)
{
	t_list	*temp;

	if (ft_lstsize(a->b) > 1)
	{
		temp = a->b;
		a->b = a->b->next;
		temp->next = NULL;
		ft_lstadd_back(&a->b, temp);
	}
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rrb(t_stack_a *a, int flag)
{
	t_list	*temp;
	t_list	*temp1;

	temp1 = a->b;
	if (ft_lstsize(a->b) > 1)
	{
		temp = ft_lstlast(a->b);
		while (temp1->next != temp)
			temp1 = temp1->next;
		temp1->next = NULL;
		ft_lstadd_front(&a->b, temp);
	}
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	pa(t_stack_a *a, int flag)
{
	t_list	*temp;

	temp = a->b;
	if (ft_lstsize(a->b) > 1)
	{
		if (a->b->next)
		{
			a->b = a->b->next;
			temp->next = NULL;
		}
		ft_lstadd_front(&a->a, temp);
	}
	else
	{
		a->b = NULL;
		ft_lstadd_front(&a->a, temp);
	}
	if (flag == 0)
		write(1, "pa\n", 3);
}
