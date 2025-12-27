/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:39 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:39 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_is_2(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->number < tmp->next->number)
		check_if_sorted(stack_a, 1);
	else
		sa(stack_a);
}

void	stack_is_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	add_index(stack, stack);
}

int	check_if_3(t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 1)
		return (0);
	else if (i == 2)
	{
		stack_is_2(stack_a);
		return (1);
	}
	else if (i == 3)
	{
		stack_is_3(stack_a);
		return (1);
	}
	return (0);
}
