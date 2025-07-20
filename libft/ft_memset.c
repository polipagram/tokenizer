/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:38:45 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/11 23:38:52 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t nbrb)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < nbrb)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
