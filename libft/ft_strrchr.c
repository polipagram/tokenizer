/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:45:41 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/13 15:59:16 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int k)
{
	char	*lst_occu;

	lst_occu = NULL;
	while (*s)
	{
		if (*s == (char)k)
			lst_occu = (char *)s;
		s++;
	}
	if ((char)k == '\0')
		lst_occu = (char *)s;
	return (lst_occu);
}
