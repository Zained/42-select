/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 19:12:43 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:11:59 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_exit_sig(void)
{
	t_truc	*c;
	char	cp[2];

	c = NULL;
	c = ft_restruct(c, 1);
	cp[0] = c->term.c_cc[VSUSP];
	cp[1] = 0;
	c->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
	tcsetattr(0, 0, &(c->term));
	tputs(tgetstr("te", NULL), 1, ft_putchar_auto);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_auto);
	ioctl(0, TIOCSTI, cp);
}

void	ft_stop_sig(void)
{
	t_truc *c;

	c = NULL;
	c = ft_restruct(c, 1);
	if (c != NULL)
		ft_end_termios(c);
	exit(0);
}

void	ft_cont_sig(void)
{
	t_truc *c;

	c = NULL;
	c = ft_restruct(c, 1);
	c->term.c_lflag &= ~(ICANON | ECHO);
	c->term.c_cc[VMIN] = 1;
	c->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(c->term));
	tputs(tgetstr("ti", NULL), 1, ft_putchar_auto);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_auto);
	signal(SIGTSTP, ft_select_signal);
	ft_resize_window();
}

void	ft_resize_window(void)
{
	struct winsize	win;
	t_truc			*c;

	c = NULL;
	c = ft_restruct(c, 1);
	ioctl(0, TIOCGWINSZ, &win);
	c->nb_row = win.ws_row;
	c->nb_col = win.ws_col;
	ft_check_size(c);
}
