/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanuel- <lmanuel-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:21:00 by lmanuel-          #+#    #+#             */
/*   Updated: 2025/04/18 20:41:32 by lmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = 0;
	len_src = ft_strlen(src);
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	if (len_dst == size)
		return (size + len_src);
	while (src[i] && (len_dst + i + 1) < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (size > 0 && len_dst + i < size)
		dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
