#include "ft_printf.h"

/*static int	ft_format(va_list args, const char format)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		count += (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		count += (ft_putaddress(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		count += (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		count += (ft_put_unsigned_int(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		count += (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			i++;
			count += ft_format(args, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}*/

static int	ft_format(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (format == 'X' || format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putaddress(ptr));
		return (ft_putstr("0x0"));
	}
	else if (format == 'u')
		return (ft_put_unsigned_int(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_strchr("cspdiuxX%", *(str + i + 1)))
		{
			length += ft_format(args, *(str + i + 1));
			i++;
		}
		else
			length += ft_putchar(*(str + i));
		i++;
	}
	va_end(args);
	return (length);
}

/*static int	ft_format(va_list args, const char *format)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while(format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			i++;
			if (format[i] == 'c')
				count += (ft_putchar(va_arg(args, int)));
			else if (format[i] == 's')
				count += (ft_putstr(va_arg(args, char *)));
			else if (format[i] == 'p')
				count += (ft_putaddress(va_arg(args, void *)));
			else if (format[i] == 'd' || format[i] == 'i')
				count += (ft_putnbr(va_arg(args, int)));
			else if (format[i] == 'u')
				count += (ft_put_unsigned_int(va_arg(args, unsigned int)));
			else if (format[i] == 'x' || format[i] == 'X')
				count += (ft_puthex(va_arg(args, unsigned int), format[i]));
			else if (format[i] == '%')
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count = ft_format(args, format);
	va_end(args);
	return (count);
}*/
