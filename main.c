#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	len, len2;

	len = printf("%m");
	len2 = ft_printf("%k");
	printf("printf lenght : %d\n", len);
	printf("ft_printf lenght : %d\n", len2);
}