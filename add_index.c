/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:27 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:27 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_stack **stack_a, t_stack **stack_b)
{
	int		index;
	t_stack	*curr;

	index = 0;
	curr = *stack_a;
	while (curr)
	{
		curr->idx = index;
		curr = curr->next;
		index++;
	}
	index = 0;
	curr = *stack_b;
	while (curr)
	{
		curr->idx = index;
		curr = curr->next;
		index++;
	}
}

int	check_if_sorted(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number && nbr == 0)
		{
			rra(stack);
			add_index(stack, stack);
		}
		else if (tmp->number > tmp->next->number && nbr != 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	lst_size(t_stack **stack)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = *stack;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

t_stack	*no_target_max(t_stack **stack_b)
{
	t_stack	*ptr;
	t_stack	*target;

	ptr = *stack_b;
	target = ptr;
	while (ptr)
	{
		if (ptr->number < target->number)
			target = ptr;
		ptr = ptr->next;
	}
	return (target);
}

t_stack	*no_target_min(t_stack **stack_a)
{
	t_stack	*ptr;
	t_stack	*target;

	ptr = *stack_a;
	target = ptr;
	while (ptr)
	{
		if (ptr->number < target->number)
			target = ptr;
		ptr = ptr->next;
	}
	return (target);
}
