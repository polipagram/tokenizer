/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:34:01 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/12 22:20:12 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	temp = malloc(size * nmemb);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, size * nmemb);
	return (temp);
}
