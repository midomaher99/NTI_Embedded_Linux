## Q1 List the available shells in your system.
Using `cat /etc/shells` command:
the availables shells are
* /bin/sh
* /bin/bash
* /usr/bin/bash
* /bin/rbash
* /usr/bin/rbash
* /bin/dash
* /usr/bin/dash

## Q2 List the environment variables in your current shell.
Using the `env` command.

## Q3 Display your current shell name.
Using `echo $SHELL` command:
the current shell name is /bin/bash

## Q4 Execute the following command :echo \ then press enter. What is the purpose of \ ?
the '\' is telling the bash that the command will be entered in more than one line then the bash gives me a new line to type the remained part of the command.

## Q5 Create a Bash shell alias named PrintPath for the “echo $PATH” command
Using `alias printpath="echo $PATH"` command.