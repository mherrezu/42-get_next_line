# GET_NEXT_LINE - 42

# ⚡ What is get_next_line?

Get the next line of text available on a file descriptor.
Calling get_next_line in a loop will allow us to read the text available on the
file descriptor one line at a time until the end of it.  

> *"May it be a file, stdin, or even later a network connection, you will always
> need a way to read content line by line."* - [42 Subject]

External functions: `read`, `malloc`, `free`

# :computer: Technologies

This Project was made with:

* [C](https://devdocs.io/)
* [Makefile](https://www.gnu.org/software/make/manual/make.html)
* [Shell](https://unixguide.readthedocs.io/en/latest/unixcheatsheet/)
* [gcc](https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/)

# ⚙️ How to Run
```bash
# *************COMMANDS************ #
# run - run compile all the libtest with the your libft and run the all tests
$ make all
# clean - remove the .o and .c files 
$ make clean
# fclean - remove the .o and .c files and the .a
$ make fclean
# re - remove all files and remake all
$ make re

# after run one time the the comand all 
# you can use compile others files .c using this lib 
# and using the function of then.
$ ./get_next_line <path_to_file>
$ For example: ./get_next_line main.c

```
