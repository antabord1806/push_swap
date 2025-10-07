/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 14:10:07 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 14:10:07 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*cur;
	t_stack	*prev;

	prev = NULL;
	if (!head || !*head || !(*head)->next)
		return ;
	cur = *head;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = *head;
	*head = cur;
}

void	rrr(t_stack **head_a, t_stack **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	write(1, "rrr\n", 4);
}

void	rra(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}
