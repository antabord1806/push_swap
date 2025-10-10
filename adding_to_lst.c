/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:08:34 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:08:34 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_lstadd_back_mod(t_stack **lst, t_stack *new)
{
	t_stack	*atual;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		atual = *lst;
		while (atual->next != NULL)
			atual = atual->next;
		atual->next = new;
	}
}

char	**join_args(int ac, char **av)
{
	char	**tmp_str;
	char	**str;
	int		i;

	i = 0;
	str = NULL;
	while (++i < ac)
	{
		tmp_str = ft_split(av[i], ' ');
		if (!tmp_str)
		{
			freedom(str);
			return (NULL);
		}
		str = ft_strjoin(str, tmp_str);
		if (!str)
			return (NULL);
	}
	if (!ft_isdigit_mod(str))
	{
		freedom(str);
		ft_err();
	}
	return (str);
}

int	ft_isduplicate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checking;

	current = *stack;
	while (current != NULL)
	{
		checking = current->next;
		while (checking != NULL)
		{
			if (current->number == checking->number)
			{
				freedom_stack(stack);
				ft_err();
				return (0);
			}
			checking = checking->next;
		}
		current = current->next;
	}
	return (1);
}

void	parser(t_stack **stack, char **av)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (av[i])
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			ft_err();
		new->number = ft_atol(av[i]);
		if (new->number > INT_MAX || new->number < INT_MIN)
		{
			freedom_stack(stack);
			free(new);
			freedom(av);
			ft_err();
		}
		ft_lstadd_back_mod(stack, new);
		i++;
	}
}
