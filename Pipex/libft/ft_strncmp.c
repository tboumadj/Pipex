/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 06:52:52 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/26 10:08:44 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] == s2[a] && s1[a] && s2[a] && a < n - 1)
		++a;
	return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
}
