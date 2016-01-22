/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 18:58:56 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:12:04 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_loop(char **av, t_truc *c)
{
	ft_argv_list(av, c);
	if (!ft_check_size(c))
		ft_print_list(c);
	ft_restruct(c, 0);
	while (1)
	{
		if (!ft_command(c))
			return (0);
	}
	return (0);
}

void	ft_end_termios(t_truc *c)
{
	c->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(c->term)) == -1)
		return ;
	tputs(tgetstr("te", NULL), 1, ft_putchar_auto);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_auto);
	ft_key_enter(c);
}

int		ft_msg_error(int i)
{
	if (i == 1)
		ft_putstr("Problem with environment, please check your system.\n");
	if (i == 2)
		ft_putstr("Problem with termcaps, please check your system.\n");
	if (i == 3)
		ft_putstr("Problem to set termcaps, please check your system.\n");
	return (1);
}

int		ft_init_termios(t_truc *c)
{
	struct winsize win;

	if (tgetent(NULL, getenv("TERM")) < 1)
		return (ft_msg_error(1));
	if (tcgetattr(0, &(c->term)) == -1)
		return (ft_msg_error(2));
	c->term.c_lflag &= ~(ICANON | ECHO);
	c->term.c_cc[VMIN] = 1;
	c->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	c->nb_col = win.ws_col;
	c->nb_row = win.ws_row;
	if (tcsetattr(0, 0, &(c->term)) == -1)
		return (ft_msg_error(3));
	tputs(tgetstr("ti", NULL), 1, ft_putchar_auto);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_auto);
	return (0);
}

int		main(int ac, char **av)
{
	t_truc c;

	(void)ac;
	(void)av;
	if (ac == 1)
	{
		ft_putstr("Usage : ./ft_select [argv1] [argv2] ... OR ./ft_select *\n");
		return (0);
	}
	c.lst = NULL;
	ft_signal();
	if (ft_init_termios(&c))
		return (0);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_auto);
	if (ac >= 2)
		ft_loop(av, &c);
	ft_end_termios(&c);
	return (0);
}
