/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 12:26:15 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 12:26:15 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*tail;

	tail = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = (*head);
	*head = (*head)->next;
	tail->next->next = NULL;
}

void	ra(t_stack **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rb(t_stack **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
