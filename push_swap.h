/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 10:09:22 by antabord          #+#    #+#             */
/*   Updated: 2025-09-23 10:09:22 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			number;
	int				idx;
	int				rr;
	int				rrr;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// aux functions
int					ft_strlen(const char *str);
long				ft_atol(char *str);
char				**ft_strjoin(char **s1, char **s2);
char				**ft_split(char const *s, char c);
void				*ft_memset(void *s, int c, size_t n);

// main & arg breakdown
int					main(int argc, char **argv);
char				**join_args(int ac, char **av);

// error & free
void				ft_err(void);
void				ft_puterr(char *s);
void				freedom(char **str);
void				freedom_stack(t_stack **stack);

// adding to lst & parsing
void				parser(t_stack **stack, char *av[]);
int					is_it_too_big(const char *str);
int					ft_isduplicate(t_stack **stack);
int					ft_isdigit_mod(char **nbr);
void				add_index(t_stack **stack_a, t_stack **stack_b);

// processing stack
int					check_if_sorted(t_stack **stack, int nbr);
int					check_if_3(t_stack **stack_a);
void				stack_is_2(t_stack **stack_a);
void				stack_is_3(t_stack **stack_a);

// operations
// rotate
void				ra(t_stack **head);
void				rb(t_stack **head);
void				rr(t_stack **head_a, t_stack **head_b);
// reverse rotate
void				rra(t_stack **head);
void				rrb(t_stack **head);
void				rrr(t_stack **head_a, t_stack **head_b);
// push
void				pa(t_stack **head_b, t_stack **head_a);
void				pb(t_stack **head_a, t_stack **head_b);
// swap
void				sa(t_stack **head_a);
void				sb(t_stack **head_b);
void				ss(t_stack **head_a, t_stack **head_b);

// algo implementation -- turksort

void				push_loop_1(t_stack **stack_a, t_stack **stack_b);
void				push_loop_2(t_stack **stack_a, t_stack **stack_b);
void				move_target_to_top_or_push_b(t_stack *target,
						t_stack **stack_a, t_stack **stack_b, int nbr);
int					lst_size(t_stack **stack);
t_stack				*no_target_min(t_stack **stack_a);
t_stack				*no_target_max(t_stack **stack_b);
void				finalize_stack_a(t_stack **stack_a);

#endif
