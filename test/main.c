#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdint.h>

void	check_s()
{
	int	x = 0;
	int	y = 0;
	int	width[9] = {0,1,2,4,5,7,8,12,100};
	int	precision[9] = {0,1,2,4,5,7,8,12,100};
	char	*num[6] = {"","hi","hello","how are you","-\0-",NULL};
	int	res = 0;
	int	ft_res = 0;
	int	dif = 0;
	char *number = num[5];

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			printf("\033[0;32mtest 1.1' '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% *.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% *.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.2'-'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.3'+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.4'0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.5  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res += printf("'%*.*s'\n", width[x], precision[y], number);
			ft_res += ft_printf("'%*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.6'-+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.7'-0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-0*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-0*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.8'- '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- *.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- *.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.9'+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.10'+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+ *.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+ *.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.11' +'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% +*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% +*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.12'0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0 *.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0 *.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.13'-+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+0*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+0*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.14'-+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+ *.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+ *.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.15'+0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0 *.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0 *.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;


			printf("\033[0;32mtest 1.16'- 0+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- 0+*.*s'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- 0+*.*s'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;			
			y++;
		}
		x++;
	}
	printf("STR ITOGO DIFF %d\n", dif);
}

void	check_c()
{
	
	int	x = 0;
	int	y = 0;
	int	width[9] = {0,1,2,4,5,7,8,12,100};
	int	precision[9] = {0,1,2,4,5,7,8,12,100};
	int	res = 0;
	int	ft_res = 0;
	int	dif = 0;
	char number = 'p';

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			printf("\033[0;32mtest 1.1' '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% *.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% *.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.2'-'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.3'+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.4'0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.5  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res += printf("'%*.*c'\n", width[x], precision[y], number);
			ft_res += ft_printf("'%*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.6'-+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.7'-0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-0*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-0*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.8'- '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- *.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- *.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.9'+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.10'+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+ *.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+ *.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.11' +'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% +*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% +*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.12'0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0 *.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0 *.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.13'-+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+0*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+0*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.14'-+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+ *.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+ *.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.15'+0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0 *.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0 *.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;


			printf("\033[0;32mtest 1.16'- 0+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- 0+*.*c'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- 0+*.*c'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;			
			y++;
		}
		x++;
	}
	printf("Char ITOGO DIFF %d\n", dif);
}

void	check_di()
{
	int	x = 0;
	int	y = 0;
	int	width[9] = {0,1,2,4,5,7,8,12,100};
	int	precision[9] = {0,1,2,4,5,7,8,12,100};
	// int	precision[9] = {0,1,2,7,100};
	int	num[6] = {0,11111,-11111,1,10, -4};
	int	res = 0;
	int	ft_res = 0;
	int	dif = 0;
	int number = num[0];

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			printf("\033[0;32mtest 1.1' '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% *.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.2'-'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.3'+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.4'0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			// printf("\033[0;32mtest 1.5  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			// rs += printf("'% *.*d'\n", width[x], precision[y], number);
			// ft_rs += ft_printf("'% *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.6'-+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.7'-0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-0*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-0*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.8'- '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- *.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.9'+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.10'+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+ *.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+ *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.11' +'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% +*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% +*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.12'0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0 *.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0 *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.13'-+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+0*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+0*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.14'-+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+ *.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+ *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.15'+0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0 *.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0 *.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;


			printf("\033[0;32mtest 1.16'- 0+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- 0+*.*d'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- 0+*.*d'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;			
			y++;
		}
		x++;
	}
	printf("ITOGO DIFF %d\n", dif);
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
	int	x = 0;
	int	y = 0;
	int	width[9] = {0,1,2,4,5,7,8,12,100};
	int	precision[9] = {0,1,2,4,5,7,8,12,100};
	int	res = 0;
	int	ft_res = 0;
	int	dif = 0;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			printf("\033[0;32mtest 1.1' '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% *.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'% *.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.2'-'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-*.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%-*.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.3'+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+*.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%+*.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.4'0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0*.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%0*.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			// printf("\033[0;32mtest 1.5  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			// rs += printf("'% *.*%'\n", width[x], precision[y]);
			// ft_rs += ft_printf("'% *.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.6'-+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+*.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%-+*.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.7'-0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-0*.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%-0*.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.8'- '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- *.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%- *.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.9'+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0*.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%+0*.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.10'+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+ *.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%+ *.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.11' +'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% +*.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'% +*.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.12'0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0 *.%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%0 *.%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.13'-+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+0*.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%-+0*.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.14'-+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+ *.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%-+ *.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.15'+0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0 *.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%+0 *.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;


			printf("\033[0;32mtest 1.16'- 0+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- 0+.*%'\n", width[x], precision[y]);
			ft_res = ft_printf("'%- 0+.*%'\n", width[x], precision[y]);
			if (res != ft_res)
				dif++;
			y++;
		}
		x++;
	}
	printf("%% ITOGO DIFF %d\n", dif);
}
void	check_o()
{
	// printf("'%#.o %#.0o'\n", 0, 0);
	// ft_printf("'%#.o %#.0o'\n", 0, 0);
	// printf("'%#5.o' '%#.0o'\n", 54, -54);
	// ft_printf("'%#5.o' '%#.0o'\n", 54, -54);
	// printf("'%-+#5.5o' '%#1.10o'\n", 54, -54);
	// ft_printf("'%-+#5.5o' '%#1.10o'\n", 54, -54);
	
	int	x = 0;
	int	y = 0;
	int	width[9] = {0,1,2,4,5,7,8,12,100};
	int	precision[9] = {0,1,2,4,5,7,8,12,100};
	// int	precision[9] = {0,1,2,7,100};
	intmax_t	num[6] = {0,11111,-11111,1,10, -4};
	int	res = 0;
	int	ft_res = 0;
	int	dif = 0;
	int number = num[0];

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			printf("\033[0;32mtest 1.1' '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% *.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.2'-'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.3'+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.4'0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			// printf("\033[0;32mtest 1.5  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			// rs += printf("'% *.*o'\n", width[x], precision[y], number);
			// ft_rs += ft_printf("'% *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.6'-+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.7'-0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-0*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-0*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.8'- '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- *.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.9'+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.10'+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+ *.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+ *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.11' +'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'% +*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'% +*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.12'0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%0 *.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%0 *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.13'-+0'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+0*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+0*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.14'-+ '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%-+ *.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%-+ *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;

			printf("\033[0;32mtest 1.15'+0 '  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%+0 *.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%+0 *.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;


			printf("\033[0;32mtest 1.16'- 0+'  width = %d, precision = %d\n\033[0m", width[x], precision[y]);
			res = printf("'%- 0+*.*o'\n", width[x], precision[y], number);
			ft_res = ft_printf("'%- 0+*.*o'\n", width[x], precision[y], number);
			if (res != ft_res)
				dif++;			
			y++;
		}
		x++;
	}
	printf("OCTAL ITOGO DIFF %d\n", dif);

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
		// printf("'%u'\n", -9223372036854775808);
		// ft_printf("'%u'\n", -9223372036854775808);
		// printf("'%5.25lld'\n", -9223372036854775808);
		// ft_printf("'%5.25lld'\n", -9223372036854775808);
		// printf("@moulitest: %s\n", NULL);
		// ft_printf("@moulitest: %s\n", NULL);
		// printf("'%04.0bs' \n", "string");
		// ft_printf("'%04.0cs' \n", 'b');
		
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

printf("");
ft_printf("");
		printf("'%#3o'\n", 0);
		ft_printf("'%#3o'\n", 0);

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