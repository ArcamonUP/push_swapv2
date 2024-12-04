/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:42:46 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/02 14:24:28 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_value(t_stack **a)
{
	int	min;
	int	max;

	min = minimum(*a);
	max = maximum(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)->content == min)
	{
		rra(a, 1);
		sa(*a, 1);
		return ;
	}
	if ((*a)->content == max)
		ra(a, 1);
	if ((*a)->next->content == max)
		rra(a, 1);
	if (!is_sorted(*a))
		sa(*a, 1);
}

void	sort_four_value(t_stack **a, t_stack **b)
{
	int	min;

	if (is_sorted(*a))
		return ;
	min = minimum(*a);
	if ((*a)->content == min)
	{
		pb(a, b);
		sort_three_value(a);
		pa(a, b);
		return ;
	}
	else if ((*a)->next->content == min)
		ra(a, 1);
	else
		rra(a, 1);
	sort_four_value(a, b);
}

void	sort_five_value(t_stack **a, t_stack **b)
{
	int	min;

	if (is_sorted(*a))
		return ;
	min = minimum(*a);
	if ((*a)->len == 4)
	{
		sort_four_value(a, b);
		pa(a, b);
		return ;
	}
	if ((*a)->content == min)
		pb(a, b);
	else if ((*a)->next->content == min || (*a)->next->next->content == min)
		ra(a, 1);
	else
		rra(a, 1);
	sort_five_value(a, b);
}
