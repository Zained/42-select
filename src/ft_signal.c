/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 19:13:22 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 19:52:34 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_truc	*ft_restruct(t_truc *c, int i)
{
	static t_truc *tmp = NULL;

	if (i == 0)
		tmp = c;
	return (tmp);
}

void	ft_select_signal(int i)
{
	if (i == SIGCONT)
		ft_cont_sig();
	else if (i == SIGTSTP)
	{
		if (isatty(1) == 1)
			ft_exit_sig();
	}
	else if (i == SIGWINCH)
		ft_resize_window();
	else
		ft_stop_sig();
}

void	ft_signal(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, ft_select_signal);
		i++;
	}
}
