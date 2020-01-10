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
	if (argc == 1)
	{
		// printf("printf %s,1- %d, 2- %hd, 3- %hhd\n", "Hello", "a", "a", "a");
		// ft_printf("printf %s,1- %d, 2- %hd, 3- %hhd\n", "Hello", "a", 5, 5);
		
		// printf("\n\n");
		// printf("printf %s \t'\n", "hello");
		// ft_printf("printf %s \t'\n", "hello");
		
		// printf("Kogda zakanch\n\n");
		// printf("%2$d %2$d;\n","16",17);
		// printf("%2$d %1$s; %1$d %1$s\n","16",17);

		printf("rfsprintf %s\t \n", "hello", 7654321, 9);
		ft_printf("ft_printf %s\t \n", "hello", 7654321, 9);

		// printf("%.d %s\n", 5, "lol");
		// ft_printf("%5.9d %s\n", 5, "lol");
	}
	printf("\nEND\n");
	return (0);
}