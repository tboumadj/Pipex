/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:22:39 by tboumadj          #+#    #+#             */
/*   Updated: 2022/03/08 15:52:32 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	i = start;
	j = 0;
	k = len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	dst = malloc (len + 1);
	if (!dst || !s)
		return (NULL);
	while (((char *)s)[i] != '\0' && j < k)
		dst[j++] = ((char *)s)[i++];
	dst[j] = '\0';
	return (dst);
}
