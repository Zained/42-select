/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 20:03:08 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:12:22 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_key_del(t_truc *c)
{
	t_lst *tmp;

	tmp = c->lst;
	if (tmp == tmp->next)
	{
		free(tmp);
		return (0);
	}
	if (c->lst->line == 1)
		c->lst = tmp->next;
	else
	{
		while (tmp->line != 1)
			tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next->line = 1;
	free(tmp->value);
	free(tmp);
	c->count[LINE] -= 1;
	return (1);
}

void	ft_key_down(t_truc *c)
{
	t_lst *tmp;

	tmp = c->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	tmp->next->line = 1;
}

void	ft_key_up(t_truc *c)
{
	t_lst *tmp;

	tmp = c->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	tmp->prev->line = 1;
}

void	ft_command_helper(t_truc *c, char *buffer)
{
	t_lst *tmp;

	tmp = c->lst;
	if (BUFFER == SPACE)
	{
		while (tmp->line != 1)
			tmp = tmp->next;
		if (tmp->select == 0)
			tmp->select = 1;
		else
			tmp->select = 0;
		ft_key_down(c);
	}
	if (BUFFER == DOWN_KEY)
		ft_key_down(c);
	if (BUFFER == UP_KEY)
		ft_key_up(c);
}

int		ft_command(t_truc *c)
{
	char buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY || BUFFER == ENTER_KEY)
	{
		c = NULL;
		tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
		return (0);
	}
	if (ft_check_size(c))
		return (1);
	if (BUFFER == SPACE || BUFFER == DOWN_KEY || BUFFER == UP_KEY)
		ft_command_helper(c, buffer);
	if (BUFFER == DEL_KEY || BUFFER == SUPPR_KEY)
		if (!ft_key_del(c))
			return (0);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
	ft_print_list(c);
	return (1);
}
