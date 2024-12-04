/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:23 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/04 16:17:38 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	remain(t_stack *stack, int start, int end)
{
	while (stack)
	{
		if (stack->content > start && stack->content <= end)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	r_or_rr(t_stack **stack, int start, int end)
{
	t_stack	*temp;
	t_stack	*pos_top;
	t_stack	*pos_bottom;

	if (!stack || !(*stack))
		return (0);
	temp = *stack;
	pos_top = NULL;
	while (temp)
	{
		if (temp->content <= end && temp->content > start)
		{
			if (pos_top == NULL)
				pos_top = temp;
			pos_bottom = temp;
		}
		temp = temp->next;
	}
	if (((*stack)->len - pos_top->len) < pos_bottom->len)
		return (1);
	else if (((*stack)->len - pos_top->len) == pos_bottom->len)
		return ((pos_bottom->content < pos_top->content) + 1);
	return (2);
}

void	smart_pb(t_stack **a, t_stack **b, int start, int size)
{
	int	end;

	end = start + size;
	if (((*a)->content <= end && (*a)->content > start) || \
	((*a)->content == minimum(*a) && minimum(*a) == start))
	{
		pb(a, b);
		if ((*b)->content <= (end - (size / 2)))
		{
			if (remain(*a, start, end) && r_or_rr(a, start, end) == 1)
				rr(a, b);
			else
				rb(b, 1);
		}
	}
	else if (r_or_rr(a, start, end) == 1)
		ra(a, 1);
	else
		rra(a, 1);
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	nb_chunks;

	nb_chunks = 3;
	if ((*a)->len > 200)
		nb_chunks = 8;
	chunk_end = maximum(*a);
	chunk_size = ((abs(maximum(*a)) + abs(minimum(*a))) / nb_chunks) + 1;
	while (!is_sorted(*a) && nb_chunks > 0)
	{
		chunk_start = chunk_end - chunk_size;
		while (remain(*a, chunk_start, chunk_end))
			smart_pb(a, b, chunk_start, chunk_size);
		if (!(maximum(*a) > chunk_end && maximum(*a) <= chunk_end + chunk_size))
			organize(a, b, chunk_end);
		put_to_a(a, b);
		chunk_end = chunk_start;
		nb_chunks--;
	}
	while (!is_sorted(*a))
		rra(a, 1);
}
