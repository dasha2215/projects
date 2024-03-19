#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int r;
	void *p = NULL;
    printf("%c%c%c", 'a', '\t', 'b');
	ft_printf("%c%c%c", 'a', '\t', 'b');
}
