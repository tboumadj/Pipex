/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:54:59 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/23 18:55:44 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *str)
{
	int	b;

	b = 0;
	if (!str)
		return (0);
	while (str[b])
		++b;
	return (b);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[i] != '\0')
		dst[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dst[j++] = s2[i++];
	dst[j] = '\0';
	free (s1);
	return (dst);
}
