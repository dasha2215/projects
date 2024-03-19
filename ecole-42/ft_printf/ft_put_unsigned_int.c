#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}
