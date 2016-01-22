/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 18:50:58 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:11:50 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_check_size(t_truc *c)
{
	if ((c->nb_row - 1) < c->count[LINE])
	{
		tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
		ft_putstr_fd("Window too small.", 2);
		ft_putnbr_fd(c->count[LINE], 2);
		ft_putstr_fd(" elements, lines available: ", 2);
		ft_putnbr_fd(c->nb_row, 2);
		return (1);
	}
	else if (c->nb_col < c->count[COL])
	{
		tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
		ft_putstr_fd("Window too small.", 2);
		ft_putnbr_fd(c->count[COL], 2);
		ft_putstr_fd(" characters needed, columns available : ", 2);
		ft_putnbr_fd(c->nb_col, 2);
		return (1);
	}
	else
	{
		tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
		ft_print_list(c);
	}
	return (0);
}
