#include "ft_printf.h"
#include <stdio.h>

static int	hexlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n < 16)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_puthex(unsigned long n, char format)
{
	char	*str;
	int		len;
	int		remainder;

	if (n == 0)
		return (ft_putnbr(0));
	len = hexlen(n) + 1;
	str = malloc(len);
	if (!str)
		return (0);
	str[--len] = '\0';
	while (n > 0)
	{
		len--;
		remainder = n % 16;
		n = n / 16;
		if (remainder < 10)
			str[len] = remainder + '0';
		else
			str[len] = (remainder - 10) + 'a';
	}
	while (format == 'X' && str[len])
	{
		str[len] = ft_toupper(str[len]);
		len++;
	}
	len = ft_putstr(str);
	free(str);
	return (len);
}
