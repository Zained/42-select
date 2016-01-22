/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 18:50:58 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/14 20:01:03 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_lst		*ft_list_init(void)
{
	t_lst *tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	tmp->value = NULL;
	tmp->select = 0;
	tmp->line = 0;
	tmp->len = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_lst		*ft_list_add(char *str)
{
	t_lst *tmp;

	tmp = ft_list_init();
	tmp->value = ft_strdup(str);
	tmp->len = ft_strlen(tmp->value);
	return (tmp);
}

void		ft_list_push(t_truc *c, t_lst *l)
{
	t_lst *tmp;

	if (c->lst == NULL)
	{
		l->prev = l;
		l->next = l;
		c->lst = l;
		l->line = 1;
	}
	else
	{
		tmp = c->lst->prev;
		tmp->next = l;
		l->next = c->lst;
		l->prev = tmp;
		c->lst->prev = l;
	}
}

void		ft_argv_list(char **av, t_truc *c)
{
	int		i;
	t_lst	*l;

	i = 1;
	while (av[i])
	{
		l = ft_list_add(av[i]);
		ft_list_push(c, l);
		if (l->len > c->count[COL])
			c->count[COL] = l->len;
		i++;
	}
	c->count[LINE] = i;
}
