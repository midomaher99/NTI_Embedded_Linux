# CheatSheet

## Important files and directories
* `/etc/shells` valid login shells.
* `/etc/profile` default settings for all users when starting a **login shell**.
* `/etc/bashrc` defaults for all users when starting a **subshell**
* `~/.profile` Specific setting for one user applied when starting a **login shell**.
* `~/.bashrc` Specific setting for one user applied when starting a **subshell**.

## Important variables
* `$SHELL` the user default shell.
* `$HOME` the home directory of current user.
* `$PWD` the current working directory.
* `$USER` the current user's username.
* `$HOSTNAME` the name of the host (Computer).
* `$PATH` the directories wher executables located.
* 

## Commands
* `pwd` prints the current working directory.
* `man` linux documentation system.
* `info` GNU documentation system.
* `help` shell documentation system for built-in commands.
* `type` display information about command type.
* `apropos` `man -k` search for a pattern in manual pagers.
* `cd` change working directory.
    * \- go to previous 
* `ls` list files and directories.
    * \-ahl -> all, human reading, long format
* `touch` create file.
* `mkdir` create directory.
* `cp` copy.
* `mv` move or rename.
* `rmdir` remove empty directory.
* `rm` remove.
* `diff` compare files line by line.
* `env` `printenv` prints the environment variables.
* `which` show which exact command will be executed by shell.
* `alias` creating alias for commands.
* `unalias` removing aliases of a command.