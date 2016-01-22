/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 19:53:21 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:11:51 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include <sys/ioctl.h>
# define BUFFER *(unsigned int *)buffer
# define LINE 0
# define COL 1

typedef struct		s_lst
{
	char			*value;
	int				select;
	int				line;
	int				len;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef enum		e_enum
{
	ESC_KEY = 27,
	SPACE = 32,
	DOWN_KEY = 4348699,
	UP_KEY = 4283163,
	ENTER_KEY = 10,
	DEL_KEY = 127,
	SUPPR_KEY = 2117294875,
}					t_enum;

typedef struct		s_truc
{
	struct termios	term;
	char			*name;
	int				nb_col;
	int				nb_row;
	int				enter;
	int				count[2];
	char			**tab_value;
	t_lst			*lst;
}					t_truc;

t_lst				*ft_list_init(void);
t_lst				*ft_list_add(char *str);
void				ft_list_push(t_truc *c, t_lst *l);
void				ft_argv_list(char **av, t_truc *c);
int					ft_command(t_truc *c);
void				ft_print_list(t_truc *c);
int					ft_putchar_auto(int c);
void				ft_print_menu(t_lst *lst);
void				ft_key_down(t_truc *c);
void				ft_key_enter(t_truc *c);
void				ft_key_enter_bis(t_truc *c);
int					ft_key_del(t_truc *c);
int					ft_check_size(t_truc *c);
void				ft_signal(void);
void				ft_select_signal(int i);
void				ft_resize_window();
t_truc				*ft_restruct(t_truc *c, int i);
int					ft_loop(char **av, t_truc *c);
void				ft_end_termios(t_truc *c);
void				ft_exit_sig(void);
void				ft_cont_sig(void);
void				ft_stop_sig(void);
int					ft_init_termios(t_truc *c);
void				ft_key_enter_print(t_truc *c);

#endif
