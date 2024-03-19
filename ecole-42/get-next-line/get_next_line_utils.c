#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	while (i < len  && s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	if (i <= len)
		s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char		*s2;
	size_t		i;

	i = 0;
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (0);
	while (i < len && s[start])
	{
		s2[i] = s[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		full_size;
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	full_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(full_size * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*pp;

	p = (char *)s;
	pp = 0;
	while (*p)
	{
		if ((unsigned char)*p == (unsigned char) c)
			pp = p;
		p++;
	}
	if ((unsigned char)*p == (unsigned char) c)
		return (p);
	return (pp);
}
