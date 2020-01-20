#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdint.h>

void	check_s();
void	check_c();
void	check_di();
void	check_percent();
void	check_o();
void	check_f();

void	check_p()
{

}
void	check_u()
{

}
void	check_x()
{

}
void	check_big_x()
{

}
void	check_d(int width, int precision, int num)
{
	
	// printf("'%5.25lld'\n", -9223372036854775808);
	// ft_printf("'%5.25lld'\n", -9223372036854775808);
	// printf("'%5.lld'\n", -9223372036854775807);
	// ft_printf("'%5.lld'\n", -9223372036854775807);
	// printf("'%50.2d'\n", -1234);
	// ft_printf("'%50.2d'\n", -1234);
	
	// printf("'%3.2d'\n", -123);
	// ft_printf("'%3.2d'\n", -123);

	// printf("'%-+10.5d'\n", 4242);
	// ft_printf("'%-+10.5d'\n", 4242);


	printf("\033[0;32mtest 1.1\n\033[0m");
	printf("'% *.*d'\n", width, precision, num);
	ft_printf("'% *.*d'\n", width, precision, num);

	printf("\033[0;32mtest 1.2\n\033[0m");
	printf("'%-*.*d'\n", width, precision, num);
	ft_printf("'%-*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.3\n\033[0m");
	printf("'%+*.*d'\n", width, precision, num);
	ft_printf("'%+*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.4\n\033[0m");
	printf("'%0*.*d'\n", width, precision, num);
	ft_printf("'%0*.*d'\n", width, precision, num);
	
	// printf("\033[0;32mtest 1.5\n\033[0m");
	// printf("'% *.*d'\n", width, precision, num);
	// ft_printf("'% *.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.6\n\033[0m");
	printf("'%-+*.*d'\n", width, precision, num);
	ft_printf("'%-+*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.7\n\033[0m");
	printf("'%-0*.*d'\n", width, precision, num);
	ft_printf("'%-0*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.8\n\033[0m");
	printf("'%- *.*d'\n", width, precision, num);
	ft_printf("'%- *.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.9\n\033[0m");
	printf("'%+0*.*d'\n", width, precision, num);
	ft_printf("'%+0*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.10\n\033[0m");
	printf("'%+ *.*d'\n", width, precision, num);
	ft_printf("'%+ *.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.11\n\033[0m");
	printf("'% +*.*d'\n", width, precision, num);
	ft_printf("'% +*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.12\n\033[0m");
	printf("'%0 *.*d'\n", width, precision, num);
	ft_printf("'%0 *.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.13\n\033[0m");
	printf("'%-+0*.*d'\n", width, precision, num);
	ft_printf("'%-+0*.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.14\n\033[0m");
	printf("'%-+ *.*d'\n", width, precision, num);
	ft_printf("'%-+ *.*d'\n", width, precision, num);
	
	printf("\033[0;32mtest 1.15\n\033[0m");
	printf("'%+0 *.*d'\n", width, precision, num);
	ft_printf("'%+0 *.*d'\n", width, precision, num);
	

	printf("\033[0;32mtest 1.16\n\033[0m");
	printf("'%- 0+*.*d'\n", width, precision, num);
	ft_printf("'%- 0+*.*d'\n", width, precision, num);
}

int	main(int argc, char **argv)
{
	int	num = 0;
	int	i = 0;
	char	c;
	num = 55;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c == 's')
				check_s();
			else if (c == 'c')
				check_c();
			else if (c == 'p')
				check_p();
			else if (c == 'd')
				check_di();
			else if (c == 'o')
				check_o();
			else if (c == 'u')
				check_u();
			else if (c == 'x')
				check_x();
			else if (c == 'X')
				check_big_x();
			else if (c == 'f')
				check_f();
			else if (c == '%')
				check_percent();
			i++;
		}
	}
	else
	{
		// printf("'%5.25d'\n", -9223372036854775808);
		// ft_printf("'%5.25d'\n", -9223372036854775808);
		// printf("@moulitest: %s\n", NULL);
		// ft_printf("@moulitest: %s\n", NULL);
		// printf("'%04.0s' \n", "string");
		// ft_printf("'%04.0s' \n", "string");
		
		// printf("'%014s' \n", "string");
		// ft_printf("'%014s' \n", "string");
		
		// printf("'%-25lld'\n", -9223372036854775808);
		// ft_printf("'%-25lld'\n", -9223372036854775808);
		
		printf("'%Lf'\n", -9223372036854775807.54);
		ft_printf("'%Lf'\n", -9223372036854775807.54);
		
		printf("%d = \n", printf("'%p' \n", 0));
		printf("%d = \n", ft_printf("'%p' \n", 0));
		
		printf("'%*d'\n", -9, 54);
		ft_printf("'%*d'\n", -9, 54);
		
		// ft_printf("'%p' \n", 0);
		
		// printf("'%#5o'\n", 55);
		// ft_printf("'%#5o'\n", 55);
		
		
		// printf("'%#05o'\n", 55);
		// ft_printf("'%#05o'\n", 55);
		
		// printf("'%#.5o'\n", 55);
		// ft_printf("'%#.5o'\n", 55);
		// printf("'%o'\n", 55);
		// ft_printf("'%o'\n", 55);
		
		// printf("'%5o'\n", 55);
		// ft_printf("'%5o'\n", 55);
		
		
		// printf("'%00o'\n", 55);
		// ft_printf("'%00o'\n", 55);
		
		// printf("'%#-8o'\n", 55);
		// ft_printf("'%#-8o'\n", 55);
		
		// printf("'%#8o'\n", 55);
		// ft_printf("'%#8o'\n", 55);
		
		// printf("@moulitest: %.o %.0o\n", 0, 0);
		// ft_printf("@moulitest: %.o %.0o\n", 0, 0);

		// printf("@moulitest: %5.o %5.0o\n", 0, 0);
		// ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);

		// printf("@moulitest: %#.o %#.0o\n", 0, 0);
		// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);

		// printf("'%#.o'\n", 0);
		// ft_printf("'%#.o'\n", 0);
		
		// printf("%#o\n", 0);
		// ft_printf("%#o\n", 0);

		// printf("{%25.*d}\n", 15, 42);
		// ft_printf("{%25.*d}\n", -15, 42);

		// printf("{%*d}\n", -5, 42);
		// ft_printf("{%*d}\n", -5, 42);

		// printf("@moulitest: %#.o %#.0o\n", 0, 0);
		// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
		// printf("%lu\n", -42);
		// ft_printf("%lu\n", -42);

// printf("");
// ft_printf("");
		// printf("'%05bd'\n", 0);
		// ft_printf("'%05bd'\n", 0);

		// printf("'%#0x'\n", 0);
		// ft_printf("'%#0x'\n", 0);
		// printf("'%#08x'\n", 42);
		// ft_printf("'%#08x'\n", 42);

		// printf("'%#8.6x'\n", 42);
		// ft_printf("'%#8.6x'\n", 42);
		// printf("'%#08.6x'\n", 42);
		// ft_printf("'%#08.6x'\n", 42);

		// printf("{%*d}\n", -5, 42);
		// ft_printf("{%*d}\n", -5, 42);

		// printf("{%*3d}\n", 5, 0);
		// ft_printf("{%*3d}\n", 5, 0);

		// printf("%x\n", 42);
		// ft_printf("%x\n", 42);
		// printf("'%# 5.3o' '%# 8.6o'\n", 6, 8975);
		// ft_printf("'%# 5.3o' '%# 8.6o'\n", 6, 8975);
		// printf("% Z%s\n", "test");
		// ft_printf("% Z%s\n", "test");
		// printf("'%.50lld'\n", -9223372036854775807);
		// ft_printf("'%.50lld'\n", -9223372036854775807);
		// check_s();
		// check_c();
		check_p();
		// check_di();
		// check_d(atoi(argv[1]), atoi(argv[2]));
		// check_percent();
		// check_o();
		check_u();
		check_x();
		check_big_x();
		check_f();
		
		
		// printf("Kogda zakanch\n\n");
		// printf("%2$d %2$d;\n","16",17);
		// printf("%2$d %1$s; %1$d %1$s\n","16",17);

		// num = printf("dd_printf %s, '%-3.d'\n", "hello", 3, 9);
		// num = printf("dd_printf %s, '%5bd'\n", "hello", 9, 7654321);
		// num = printf("dd_printf  '%05d' |||| '% 8d' '%7.3s', '%4.15d' ppp\n", -42, -57897, "Hello", 42);
		// ft_printf("ft_printf  '%05d' |||| '% 8d' '%7.3s', '%4.15d' ppp\n", -42, -57897, "Hello", 42);

		

		// num = printf("dd_printf  '%05d' |||| '% 8d' '%7.3s', '%-+3.0d' ppp\n", -42, -57897, "Hello", 0);
		// printf("num = %d\n", num);
		// ft_printf("ft_printf '%7.6ls', '%0+d' %d '%c'\n", "Hello", 9, 7654321, 'P');
		// printf("dd_printf '%s'\n");
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