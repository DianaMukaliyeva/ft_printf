#include "../includes/ft_printf.h"

#include <stdio.h>


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