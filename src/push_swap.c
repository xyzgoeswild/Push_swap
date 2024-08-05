/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:12:50 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:41:38 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int ac, char **av)
{
	t_stack_a	a;
	int			size;

	check_empty_args(ac, av);
	join_and_split_args(&a, ac, av);
	check_digits_in_array(&a);
	sort_and_check_fill(&a);
	check_duplicates_in_array(&a);
	fill_stack_a(&a);
	ssort_array_elements(&a);
	fill_index_values(&a);
	size = ft_lstsize(a.a);
	if (size == 3)
		sort_3(&a);
	else if (size == 5)
		sort_5(&a);
	else
		algo_chance(&a);
	exit(0);
}
