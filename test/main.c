#include "../ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_printf(argv[1]);
	if (argc == 3)
		ft_printf(argv[1], argv[2]);
	if (argc == 4)
		ft_printf(argv[1], argv[2], argv[3]);
	if (argc == 5)
		ft_printf(argv[1], argv[2], argv[3], argv[4]);
	if (argc == 6)
		ft_printf(argv[1], argv[2], argv[3], argv[4], argv[5]);
	printf("\nEND\n");
	return (0);
}