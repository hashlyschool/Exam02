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

Название программы  | get_next_line
:-------------------|:---------------
Прототип функции        | int get_next_line(char **str);
Файлы для сдачи         | get_next_line.c
Параметры			    | №1 - строка, которая была прочитана без '\n'
Возвращаемое значение   | > 0 - количество прочитанных символов; 0: достигнут EOF; -1: произошла ошибка
Разрешенные внешние функции | read, malloc, free
Описание			    | Напишите функцию, которая возвращает строку, прочитанную из 0 дескриптора без '\n' строки.

# inter #

Название программы | inter
:-|:-
Expected files   | inter.c
Allowed functions | write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

	Напишите программу, которая принимает две строки и отображает без двойников
	символы, которые появляются в обеих строках, в том порядке, в котором они появляются в первой.

	После отображения появится \ n.

	Если количество аргументов не равно 2, программа отображает \ n.
Examples:

	$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
	padinto$
	$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
	df6ewg4$
	$>./inter "nothing" "This sentence hides nothing" | cat -e
	nothig$
	$>./inter | cat -e
	$

# union #

Assignment name  | union
:-:|-
Expected files   | union.c
Allowed functions| write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

	Напишите программу, которая принимает две строки и отображает без двойников
	символы, которые появляются в одной из строк.

	Отображение будет в том порядке, в котором символы отображаются в командной строке, после чего будет следовать символ \ n.

	Если количество аргументов не равно 2, программа отображает \ n.

Example:

	$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
	zpadintoqefwjy$
	$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
	df6vewg4thras$
	$>./union "rien" "cette phrase ne cache rien" | cat -e
	rienct phas$
	$>./union | cat -e
	$
	$>
	$>./union "rien" | cat -e
	$
	$>
