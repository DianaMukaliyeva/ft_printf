#include "../ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	num = 0;
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

		// num = printf("dd_printf %s, '%-3.d'\n", "hello", 3, 9);
		// num = printf("dd_printf %s, '%5bd'\n", "hello", 9, 7654321);
		num = printf("dd_printf  %d '%ls', '%0-7d' '%c'\n", 9, "Hello", 7654321, 'P');
		// printf("num = %d\n", num);
		ft_printf("ft_printf '%7.6ls', '%0+d' %d '%c'\n", "Hello", 9, 7654321, 'P');
		// ft_printf("ft_printf '%s'\n");

		// int d1=123, d2=42, d3=1543;
   		// printf ("'%d'\n'%6d'\n'%6d'\n",d1,d2,d3);
		// printf ("\n2.3 Вывод чисел c выравниванием по левому краю:\n");
		// printf ("'%-d'\n'%-6d'\n'%-6d'\n",d1,d2,d3);
		// printf("%.d %s\n", 5, "lol");
		// ft_printf("%5.9d %s\n", 5, "lol");
		// printf("flagi '%5-d'\n", 45);

	}
	printf("\nEND\n");
	return (0);
}