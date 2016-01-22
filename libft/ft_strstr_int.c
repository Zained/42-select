/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:10 by mdriay            #+#    #+#             */
/*   Updated: 2015/05/14 21:26:47 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr_int(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (s2[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}
