/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:45 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:45 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(void)
{
	ft_puterr("Error\n");
	exit(EXIT_FAILURE);
}

int	is_it_too_big(const char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
		i++;
	return (i <= 10);
}

void	freedom(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	freedom_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	ft_isdigit_mod(char **nbr)
{
	int	i;
	int	j;

	if (!nbr || !nbr[0])
		return (0);
	i = 0;
	while (nbr[i])
	{
		j = 0;
		if (nbr[i][j] == '+' || nbr[i][j] == '-')
			j++;
		if (!nbr[i][j])
			return (0);
		while (nbr[i][j])
		{
			if (nbr[i][j] < '0' || nbr[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
