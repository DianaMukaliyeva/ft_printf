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
		// printf("%f\n", 23.00041);
		// ft_printf("%f\n", 23.00041);
		
		// printf("%f\n", 1.0);
		// ft_printf("%f\n", 1.0);

		// printf("%f\n", 0.000001);
		// ft_printf("%f\n", 0.000001);

		printf("%f\n", -0.000001);
		ft_printf("%f\n", -0.000001);

		// printf("%f\n", -0.000001);
		// ft_printf("%f\n", -0.000001);

		// printf("%f\n", -875.000001);
		// ft_printf("%f\n", -875.000001);

		// printf("%f\n", 0.0894255);
		// ft_printf("%f\n", 0.0894255);

		// printf("%f\n", 43.4399999);
		// ft_printf("%f\n", 43.4399999);

		// printf("%f\n", -5.0299999);
		// ft_printf("%f\n", -5.0299999);

		// printf("%f\n", 3.9999999);
		// ft_printf("%f\n", 3.9999999);

		// printf("%f\n", -5.9999999);
		// ft_printf("%f\n", -5.9999999);

		// printf("this %.0f float\n", 1.6);
		// ft_printf("this %.0f float\n", 1.6);

		// printf("%.0f\n", -3.85);
		// ft_printf("%.0f\n", -3.85);

		// printf("%.1f\n", -3.85);
		// ft_printf("%.1f\n", -3.85);

		// printf("%.3f\n", 1.0);
		// ft_printf("%.3f\n", 1.0);

		// printf("%.7f\n", 1.0);
		// ft_printf("%.7f\n", 1.0);

		// printf("%.7f\n", 0.0000001);
		// ft_printf("%.7f\n", 0.0000001);

		// printf("%.7f\n", -0.0000001);
		// ft_printf("%.7f\n", -0.0000001);

		// printf("%.7f\n", 43.43999949);
		// ft_printf("%.7f\n", 43.43999949);

		// printf("%.7f\n", -5.02999949);
		// ft_printf("%.7f\n", -5.02999949);

		// printf("%.7f\n", 1.99999949);
		// ft_printf("%.7f\n", 1.99999949);

		// printf("%.7f\n", -0.99999949);
		// ft_printf("%.7f\n", -0.99999949);

		// printf("%.8f\n", 1.0);
		// ft_printf("%.8f\n", 1.0);

		// printf("%.8f\n", 23.375094499);
		// ft_printf("%.8f\n", 23.375094499);

		// printf("%#.0f\n", 7.4);
		// ft_printf("%#.0f\n", 7.4);

		// printf("%#.0f\n", -7.4);
		// ft_printf("%#.0f\n", -7.4);

		// printf("%Lf\n", 0.08942555l);
		// ft_printf("%Lf\n", 0.08942555l);

		// printf("%Lf\n", 43.4399999l);
		// ft_printf("%Lf\n", 43.4399999l);

		// printf("%Lf\n", -5.0299999l);
		// ft_printf("%Lf\n", -5.0299999l);

		// printf("%Lf\n", 3.9999999l);
		// ft_printf("%Lf\n", 3.9999999l);

		// printf("%Lf\n", -5.9999999l);
		// ft_printf("%Lf\n", -5.9999999l);

		// printf("%.7Lf\n", 1.0l);
		// ft_printf("%.7Lf\n", 1.0l);

		// printf("%.7Lf\n", 1.99999949l);
		// ft_printf("%.7Lf\n", 1.99999949l);

		// printf("%.7Lf\n", -0.99999949l);
		// ft_printf("%.7Lf\n", -0.99999949l);

		// printf("%.8Lf\n", 1.0l);
		// ft_printf("%.8Lf\n", 1.0l);

		// printf("%.8Lf\n", 23.375094499l);
		// ft_printf("%.8Lf\n", 23.375094499l);

		// printf("%.8Lf\n", -985.765426499l);
		// ft_printf("%.8Lf\n", -985.765426499l);

		// printf("%f\n", (double)42);
		// ft_printf("%f\n", (double)42);

		// printf("'%.50lld'\n", -9223372036854775808);
		// ft_printf("'%.50lld'\n", -9223372036854775808);

		// printf("'%*.*.*c'\n", 15, 7, 3, 'h');
		// ft_printf("'%*.*.*c'\n", 15, 7, 3, 'h');

		// printf("@moulitest: %#.o %#.0o\n", 0, 0);
		// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);

		// printf("@moulitest: %#.x %#.0x\n", 0, 0);
		// ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);

		// printf("@moulitest: %#.u %#.0u\n", 0, 0);
		// ft_printf("@moulitest: %#.u %#.0u\n", 0, 0);

		// printf("'%#X'\n", 42);
		// ft_printf("'%#X'\n", 42);

		// printf("'%#0 33..1..#00d'\n", 256);
		// printf("'%#0 33..1..#00d'\n", 256);
		// ft_printf("'%#0 33..1..#00d'\n", 256);
		// ft_printf("'%#0 33..1..#00d'\n", 256);

	}
	printf("\nEND\n");
	// while (1){};
	return (0);
}


/* for test

		printf("'%10.0f'\n", -12.9999999);
		ft_printf("'%10.0f'\n", -12.9999999);

		printf("'%10.0f'\n", -12.44);
		ft_printf("'%10.0f'\n", -12.44);

		printf("'%f'\n", 54.27);
		ft_printf("'%f'\n", 54.27);
		
		printf("'%f'\n", 54.0);
		ft_printf("'%f'\n", 54.0);
		
		printf("'%5p' \n", 0);
		ft_printf("'%5p' \n", 0);
		
		printf("'%014s' \n", "string");
		ft_printf("'%014s' \n", "string");
		
		printf("'%.50lld'\n", -9223372036854775807);
		ft_printf("'%.50lld'\n", -9223372036854775807);

		printf("'%#8o'\n", 55);
		ft_printf("'%#8o'\n", 55);
		
		printf("%lu\n", -42);
		ft_printf("%lu\n", -42);

		printf("'%# 5.3o' '%# 8.6o'\n", 6, 8975);
		ft_printf("'%# 5.3o' '%# 8.6o'\n", 6, 8975);

		printf("%x\n", 42);
		ft_printf("%x\n", 42);

		printf("'%#8.6x'\n", 42);
		ft_printf("'%#8.6x'\n", 42);
*/