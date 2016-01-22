/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 18:50:58 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:00:11 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_print_menu(t_lst *lst)
{
	if (lst->line == 1 && lst->select == 1)
	{
		tputs(tgetstr("us", NULL), 1, ft_putchar_auto);
		tputs(tgetstr("so", NULL), 1, ft_putchar_auto);
		ft_putendl_fd(lst->value, 2);
		tputs(tgetstr("se", NULL), 1, ft_putchar_auto);
		tputs(tgetstr("ue", NULL), 1, ft_putchar_auto);
	}
	else if (lst->line == 1)
	{
		tputs(tgetstr("us", NULL), 1, ft_putchar_auto);
		ft_putendl_fd(lst->value, 2);
		tputs(tgetstr("ue", NULL), 1, ft_putchar_auto);
	}
	else if (lst->select == 1)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_auto);
		ft_putendl_fd(lst->value, 2);
		tputs(tgetstr("se", NULL), 1, ft_putchar_auto);
	}
	else
		ft_putendl_fd(lst->value, 2);
}

void	ft_print_list(t_truc *c)
{
	t_lst *tmp;

	tmp = NULL;
	tmp = c->lst->next;
	tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
	ft_print_menu(c->lst);
	while (tmp != c->lst)
	{
		ft_print_menu(tmp);
		tmp = tmp->next;
	}
}
