/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:47:56 by tboumadj          #+#    #+#             */
/*   Updated: 2022/10/23 18:52:06 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_read(int fd, char *str)
{
	int		ret;
	char	*temp;

	ret = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	while (ret != 0)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if (ret == -1)
		{
			free (temp);
			return (0);
		}
		temp[ret] = '\0';
		str = ft_strjoin_gnl(str, temp);
		if (ft_strchr_gnl(str, '\n'))
		{
			free (temp);
			return (str);
		}
	}
	free (temp);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		++i;
	temp = (char *)malloc(sizeof(char) * (i + 3));
	if (!temp)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_save(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (!temp)
		return (0);
	i++;
	while (str[i] != '\0')
		temp[j++] = str[i++];
	temp[j] = '\0';
	free (str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	temp = ft_line(str);
	str = ft_save(str);
	return (temp);
}
