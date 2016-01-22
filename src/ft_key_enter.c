/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 20:02:18 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:11:58 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_key_enter_print(t_truc *c)
{
	int i;

	i = 0;
	while (c->tab_value[i])
	{
		ft_putstr(c->tab_value[i]);
		if (c->tab_value[i + 1])
			ft_putchar(32);
		i++;
	}
}

void	ft_key_enter_bis(t_truc *c)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	if (c->lst->select == 1)
	{
		c->tab_value[i] = c->lst->value;
		i++;
	}
	tmp = c->lst->next;
	while (tmp != c->lst)
	{
		if (tmp->select == 1)
		{
			c->tab_value[i] = tmp->value;
			i++;
		}
		tmp = tmp->next;
	}
	c->tab_value[i] = 0;
	ft_key_enter_print(c);
}

void	ft_key_enter(t_truc *c)
{
	int		count;
	t_lst	*tmp;

	count = 0;
	if (c->lst->select == 1)
		count++;
	tmp = c->lst->next;
	while (tmp != c->lst)
	{
		if (tmp->select == 1)
			count++;
		tmp = tmp->next;
	}
	c->tab_value = (char **)malloc(sizeof(char *) * (count + 1));
	ft_key_enter_bis(c);
}
