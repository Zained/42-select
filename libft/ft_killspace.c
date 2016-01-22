/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_killspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 01:17:10 by mdriay            #+#    #+#             */
/*   Updated: 2015/10/08 01:48:22 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_killspace(char *str)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	dst = ft_strsub(str, i, (ft_strlen(str)));
	return (dst);
}
