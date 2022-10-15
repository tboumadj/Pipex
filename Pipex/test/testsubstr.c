#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	b;

	b = 0;
	while (str[b])
		++b;
	return (b);
}

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

int main()
{
    char a[] = "bonjourlesamis";
    
    printf("%s\n", ft_substr(a, 4, 3));
}
