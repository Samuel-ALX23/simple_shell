ALX Simple Shell Project

This project is a simple shell interpreter written in C. It is designed to imitate the sh shell and provide an interface between the user and the kernel by executing commands.

Features

Displays a prompt and waits for the user to type a command.
Executes basic commands, such as ls, cd, and pwd.
Supports the exit command.
Supports the PATH environment variable.
Supports comments (#).
Supports the history feature.
Supports file input.

Builtins

The following builtins are currently implemented:

exit: Exit the shell, with an optional exit status.
env: Print the environment.
setenv: Set an environment variable.
unsetenv: Remove an environment variable.
cd: Change the directory.
help: Get documentation for a built-in.
Usage

To build the shell, run the following command:

make

To run the shell, simply type the following command:

./seashell

Once the shell is running, you can type commands at the prompt. To exit the shell, type exit.

Examples

# List the contents of the current directory

ls

# Change to the home directory

cd ~

# Print the environment

env

# Set the environment variable FOO to the value BAR

setenv FOO BAR

# Remove the environment variable FOO

unsetenv FOO

# Exit the shell

exit

Contributing

Feel free to contribute to this project by adding new features, fixing bugs, or improving the documentation. To contribute, simply fork the repository and make your changes. Once you are finished, create a pull request and we will review your changes.

Limitations

The ALX Simple Shell has some limitations:

It does not support advanced shell features such as shell scripting, environment variable expansion, or shell built-in functions.
It does not handle complex command structures such as quotes or escape characters.
It does not implement all POSIX shell specifications.
About
ALX Simple Shell was developed by Samuel Ayitey and Mariam Yoda as part of the ALX Software Engineering program. It is provided as-is without any warranty or guarantee of fitness for any particular purpose. You are free to use, modify, and distribute this software according to the terms of the MIT License.

For bug reports or suggestions, please contact ayitey.samuel@gmail.com or myoda067@gmail.com.

License

This project is licensed under the MIT License.
