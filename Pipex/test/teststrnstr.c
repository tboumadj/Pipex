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

int main()
{
    char a[] = "bonjrboonnnnnnnnnn";
    char b[] = "jrb";
    
    printf("%s\n", ft_strnstr(a, b, 5));
    printf("%s\n", strnstr(a, b, 5));
}