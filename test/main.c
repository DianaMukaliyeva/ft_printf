#include "../ft_printf.h"
#include <stdio.h>

void	check_s()
{
	// printf("printf %s,1- %d, 2- %hd, 3- %hhd\n", "Hello", "a", "a", "a");
	// ft_printf("printf %s,1- %d, 2- %hd, 3- %hhd\n", "Hello", "a", 5, 5);
	
	// printf("\n\n");
	// printf("printf %s \t'\n", "hello");
	// ft_printf("printf %s \t'\n", "hello");
}

void	check_c()
{
	
}

void	check_di()
{
	int	x = 0;
	int	y = 0;
	int	width[4] = {4,5,8,12};
	int	precision[5] = {0,4,5,8,12};
	int	num[3] = {0,11111,-11111};

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 5)
		{
			printf("\033[0;32mtest 1.1' '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'% *.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'% *.*d'\n", width[x], precision[y], num[1]);

			printf("\033[0;32mtest 1.2'-'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%-*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%-*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.3'+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%+*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%+*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.4'0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%0*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%0*.*d'\n", width[x], precision[y], num[1]);
			
			// printf("\033[0;32mtest 1.5  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			// printf("'% *.*d'\n", width[x], precision[y], num[1]);
			// ft_printf("'% *.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.6'-+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%-+*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%-+*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.7'-0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%-0*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%-0*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.8'- '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%- *.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%- *.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.9'+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%+0*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%+0*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.10'+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%+ *.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%+ *.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.11' +'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'% +*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'% +*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.12'0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%0 *.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%0 *.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.13'-+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%-+0*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%-+0*.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.14'-+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%-+ *.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%-+ *.*d'\n", width[x], precision[y], num[1]);
			
			printf("\033[0;32mtest 1.15'+0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%+0 *.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%+0 *.*d'\n", width[x], precision[y], num[1]);
			

			printf("\033[0;32mtest 1.16'- 0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			printf("'%- 0+*.*d'\n", width[x], precision[y], num[1]);
			ft_printf("'%- 0+*.*d'\n", width[x], precision[y], num[1]);
			y++;
		}
		x++;
	}
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
void	check_percent()
{

}
void	check_o()
{

}
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
void	check_f()
{

}

int	main(int argc, char **argv)
{
	int	num = 0;
	int	i = 0;
	char	c;
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
			// else if (c == 'd')
			// 	check_d();
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
	else if (argc > 3)
		check_d(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	else
	{
		// printf("'%03.2d'\n", -1);
		// ft_printf("'%03.2d'\n", -1);
		// printf("@moulitest: '%5.d' '%5.0d'\n", 0, 0);
		// ft_printf("@moulitest: '%5.d' '%5.0d'\n", 0, 0);
		check_s();
		check_c();
		check_p();
		check_di();
		// check_d(atoi(argv[1]), atoi(argv[2]));
		check_percent();
		check_o();
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