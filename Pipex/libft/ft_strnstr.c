/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:09:42 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/29 17:30:43 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	char			*str;

	a = 0;
	c = ft_strlen(s2);
	str = (char *)s1;
	if (c == '\0' || s1 == s2)
		return (str);
	while (s1[a] != '\0' && a < len)
	{
		b = 0;
		while (str[a + b] && s2[b] && str[a + b] == s2[b] && a + b < len)
			b++;
		if (b == c)
			return (str + a);
		a++;
	}
	return (NULL);
}
