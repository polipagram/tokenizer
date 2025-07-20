/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <kbouarfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:37:29 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/15 00:52:43 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		uc;

	uc = (unsigned char)c;
	str = (const unsigned char *)s;
	while (n--)
	{
		if (*str == uc)
		{
			return ((void *)str);
		}
		str++;
	}
	return (NULL);
}
