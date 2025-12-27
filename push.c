/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 14:45:40 by antabord          #+#    #+#             */
/*   Updated: 2025-07-07 14:45:40 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **donator, t_stack **reciever)
{
	t_stack	*tmp;

	if (!*donator)
		return ;
	tmp = *donator;
	*donator = (*donator)->next;
	if (*donator)
		(*donator)->prev = NULL;
	tmp->next = *reciever;
	if (*reciever)
		(*reciever)->prev = tmp;
	tmp->prev = NULL;
	*reciever = tmp;
}

void	pa(t_stack **head_b, t_stack **head_a)
{
	push(head_b, head_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **head_a, t_stack **head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 3);
}
