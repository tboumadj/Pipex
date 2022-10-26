/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:33:19 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/26 10:08:22 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		a;
	int		b;

	b = 0;
	while (s[b])
		++b;
	dest = malloc(sizeof(*s) * b + 1);
	if (!dest)
		return (NULL);
	a = 0;
	while (s[a] != '\0')
	{
		dest[a] = s[a];
		++a;
	}
	dest[a] = '\0';
	return (dest);
}
