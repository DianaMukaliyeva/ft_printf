# ft_printf
This project is my recoding of the libc’s printf function.
More detailed information you can see [here](https://github.com/DianaMukaliyeva/ft_printf/blob/master/ft_printf.en.pdf)
***
### Implementation
##### ft_printf achieves the following mandatory requirements:
* managing the following conversions: csp
* managing the following conversions: diouxX with the following flags: hh, h, l and ll
* managing the following conversion: f with the following flags: l and L
* managing %%
* managing the flags #0-+ and space
* managing the minimum field-width and precision
##### My bonuses:
* managing the following flags: j, z
* managing multiple file descriptor (use fd_printf(int fd, char const format, ...) instead of ft_printf)
* managing wildcard length_modifier (%*) : replaces precision and width with parameter in va_list ap.
* managing converting integer to binary with %b
* managing colors and some styles with %<*>:  
%\<D> - Black foreground color  
%\<R> - Red foreground color  
%\<G> - Green foreground color  
%\<Y> - Yellow foreground color  
%\<B> - Blue foreground color  
%\<M> - Magenta foreground color  
%\<C> - Cyan foreground color  
%\<W> - White foreground color  
%\<d> - Black background color  
%\<r> - Red background color  
%\<g> - Green background color  
%\<y> - Yellow background color  
%\<b> - Blue background color  
%\<m> - Magenta background color  
%\<c> - Cyan background color  
%\<w> - White background color  
%\<o> - Inverse off  
%\<0> - Reset / Normal  
%\<f> - Bold  
%\<i> - Italic  
%\<_> - Underline  
%\<q> - Reverse  
%\<n> - Conceal  

### Getting Started
To compile, run make. This will compile library "libftprintf.a". To use, include the header "ft_printf.h" and use just like printf:
```c
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s\n", "Hello world!");
	return (0);
}
```
