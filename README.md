# ft_printf

Codam [42 Network] project: the aim of this project was to recode the printf function in C.
<br/><br/>

## Specifications
- manages the following conversions: `cspdiuxX%`
- manages any combination of the following flags: `-0.*` and minimum field width with all conversions
<br/><br/>

## Instructions
- run `make` to compile and create the `libftprintf.a` library
- write a simple main such as this:
``` C
#include "includes/ft_printf.h"

int main()
{
    char    str[] = "hey whats up?";
    int     num = 56;

    ft_printf("str = %s\n", str);
    ft_printf("num = %d\n", num);
    ft_printf("pointer address of str = %p\n", str);
    return(0);
}
```
- now compile with `gcc main.c libftprintf.a` and run program `./a.out`
<br/><br/>

## Skills
- Algorithms & AI
<br/><br/>

## Objectives
- Unix logic
