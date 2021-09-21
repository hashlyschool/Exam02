# Exam Rank 02 #

Описание: В данном репозитории размещены проекты, которые были разработаны в процессе подготовки к экзамену Rank 02


# Содержание #

| Title | Description | Allowed functions | level of difficulty |
|:-----:|-------------|-------------------|:-------------------:|
| [ft_printf](#ft_printf) | Write a function named `ft_printf` that will mimic the real printf | malloc, free, write, va_start, va_arg, va_copy, va_end |:star::star::star::star:|
| [get_next_line](#get_next_line) |Write a function will store, in the parameter "line", a line that has been read from the file descriptor 0|read, free, malloc|:star::star::star:|
| [inter](#inter) |Write a program that takes two strings and displays, without doubles, the characters that appear in both strings, in the order they appear in the first one.|write|:star::star:|
| [union](#union) |Write a program that takes two strings and displays, without doubles, the characters that appear in either one of the strings.|write|:star:|

# ft_printf #

Write a function named “`ft_printf`” that will mimic the real `printf` with the following constraints:

- It will manage only the following conversions: s, d and x;
- It will manage the mininun field width. (we will never test with a field with of 0);
- It will manage only the precison flag '.'.

Your function must be declared as follows:

int ft printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Examples of the function output:

	call: ft_printf("%10.2s\n", "toto");
	out : `       to$`

	call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	out : `Hexadecimal for 42 is 2a$`

# get_next_line #



# inter #



# union #


