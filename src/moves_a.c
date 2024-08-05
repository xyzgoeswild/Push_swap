/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:20:39 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	sa(t_stack_a *a, int flag)
{
	int	temp;

	if (ft_lstsize(a->a) > 1)
	{
		temp = *a->a->content;
		*a->a->content = *a->a->next->content;
		*a->a->next->content = temp;
	}
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	ra(t_stack_a *a, int flag)
{
	t_list	*temp;

	if (ft_lstsize(a->a) > 1)
	{
		temp = a->a;
		a->a = a->a->next;
		temp->next = NULL;
		ft_lstadd_back(&a->a, temp);
	}
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rra(t_stack_a *a, int flag)
{
	t_list	*temp;
	t_list	*temp1;

	temp1 = a->a;
	if (ft_lstsize(a->a) > 1)
	{
		temp = ft_lstlast(a->a);
		while (temp1->next != temp)
			temp1 = temp1->next;
		temp1->next = NULL;
		ft_lstadd_front(&a->a, temp);
	}
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	pb(t_stack_a *a, int flag)
{
	t_list	*temp;

	temp = a->a;
	if (ft_lstsize(a->a) > 1)
	{
		if (a->a->next)
		{
			a->a = a->a->next;
			temp->next = NULL;
		}
		ft_lstadd_front(&a->b, temp);
	}
	else
	{
		a->a = NULL;
		ft_lstadd_front(&a->b, temp);
	}
	if (flag == 0)
		write(1, "pb\n", 3);
}
