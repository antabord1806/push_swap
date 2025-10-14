/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:09:17 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:09:17 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	argv = join_args(argc, argv);
	if (!argv)
		return (freedom(argv), 0);
	parser(&stack_a, argv);
	if (!ft_isduplicate(&stack_a))
		return (freedom(argv), freedom_stack(&stack_a), ft_err(), 0);
	add_index(&stack_a, &stack_b);
	if (check_if_sorted(&stack_a, 1) || check_if_3(&stack_a))
		return (freedom(argv), freedom_stack(&stack_a), 0);
	push_loop_1(&stack_a, &stack_b);
	push_loop_2(&stack_a, &stack_b);
	freedom(argv);
	freedom_stack(&stack_a);
	return (0);
}
