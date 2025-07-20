/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <kbouarfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:42:00 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/15 02:52:44 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int k)
{
	while (*s)
	{
		if (*s == (char)k)
			return ((char *)s);
		s++;
	}
	if ((char)k == '\0')
		return ((char *)s);
	return (NULL);
}
