/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_move_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:50:55 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:16 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	int	temp;

	if (a && a->next && a->len > 1)
	{
		temp = a->content;
		a->content = a->next->content;
		a->next->content = temp;
	}
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	int	temp;

	if (b && b->next && b->len > 1)
	{
		temp = b->content;
		b->content = b->next->content;
		b->next->content = temp;
	}
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a && *a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
		if (*b && (*b)->next)
			(*b)->len = (*b)->next->len + 1;
		else
			(*b)->len = 1;
	}
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (b && *b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
		if (*a && (*a)->next)
			(*a)->len = (*a)->next->len + 1;
		else
			(*a)->len = 1;
	}
	write(1, "pa\n", 3);
}
