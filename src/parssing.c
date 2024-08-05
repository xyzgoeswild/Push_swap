/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:31:28 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/07/23 03:44:04 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	check_empty_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if (!av[i][0])
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		while (av[i][j] && !ft_isdigit(av[i][j]))
			j++;
		if (!av[i][j])
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		i++;
	}
}

void	join_and_split_args(t_stack_a *a, int ac, char **av)
{
	int		i;

	i = 1;
	a->join = NULL;
	while (i < ac)
	{
		a->join = ft_strjoin(a->join, av[i]);
		if (!a->join)
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		a->join = ft_strjoin(a->join, " ");
		i++;
	}
	a->splited = ft_split(a->join, ' ');
	if (!a->splited)
		exit(2);
}

void	check_digits_in_array(t_stack_a *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->splited[i])
	{
		j = 0;
		while (a->splited[i][j])
		{
			if (((a->splited[i][j] == '-' || a->splited[i][j] == '+')
					&& ft_isdigit(a->splited[i][j + 1]))
				|| (ft_isdigit(a->splited[i][j]) && a->splited[i][j + 1] != '+'
					&& a->splited[i][j + 1] != '-'))
				j++;
			else
			{
				write(2, "ERROR\n", 6);
				exit(8);
			}
		}
		i++;
	}
	a->array_size = i;
	if (i < 1)
		exit(4);
}

void	sort_and_check_fill(t_stack_a *a)
{
	int	i;
	int	sort_flag;

	i = 0;
	sort_flag = 1;
	a->array = malloc(a->array_size * sizeof(int));
	if (!a->array)
		exit(1);
	while (a->splited[i])
	{
		a->array[i] = ft_atoi(a->splited[i]);
		if (i != 0 && a->array[i] <= a->array[i - 1] && sort_flag == 1)
			sort_flag = 0;
		i++;
	}
	if (sort_flag == 1)
		exit(1);
}

void	check_duplicates_in_array(t_stack_a *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->array_size - 1)
	{
		j = i + 1;
		while (j < a->array_size && a->array[i] != a->array[j])
			j++;
		if (j != a->array_size)
		{
			write(2, "ERROR\n", 6);
			exit(6);
		}
		i++;
	}
}
