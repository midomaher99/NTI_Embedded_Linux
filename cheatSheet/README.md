# CheatSheet

## Important files and directories
* `/etc/shells` valid login shells.
* `/etc/profile` default settings for all users when starting a **login shell**.
* `/etc/bashrc` defaults for all users when starting a **subshell**
* `~/.profile` Specific setting for one user applied when starting a **login shell**.
* `~/.bashrc` Specific setting for one user applied when starting a **subshell**.
* `/etc/sudoers`
* `/etc/paswwd` username:paswwd status:UID:GID:comments:home dir:login shell
* `/etc/shadow` 
* `/etc/group` GroupName:EncryptedGroupPassword: GroupID:GroupMember
* `/etc/gshadow` GroupName:Password:GroupAdmin

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
* `set` Change the value of shell attributes and positional parameters, or display the names and values of shell variables.
* `export var=value` to make global variables can be inherited by child processes.
* `tee` read from standard input and write to standard output and files.
* `whereis` locate the binary, source, and manual page files for a command.
* `whereis -b` locate only the binary a command.
* `locate` to locate a file in the whole file system.
    * `-b` to locate a file with only the exact name 
* `find path-to-search –name search-word` To search for files in a directory hierarchy.
* `grep` to search inside files
    * `grep pattern file`
    * `grep -v` to print all lines without the matched pattern
    * `grep -w` to search for a specific word
    * `grep -r pattern` to search recursivly in all files in current directory
    * `grep -r pattern [dir path]` to search recursivly in all files in a specified dir
* `cut -d(delimiter) -f(column num) filename` print only specified column from a delimited file
* `wc` print the number oflines, words, and characters in a file. 
* `ln` creat hard link
* `ln -s` creat symbolic link
* `whoami` print the current user.
* `hostname` print the host name.
* `date` print date and time.
* `uptime` print how long the system has been running.
* `uname -a` print all system information. 
* `free` print the used and free mwmory
* `df` report file system space usage.
* `du` report the file estimated soace usage
* `dmesg` print or control the kernel ring buffer (print kernel log)
* `lsusb` List USB devices
* `lspci` List all PCI devices
* `lscpu` Display information about the CPU architecture
* `lsmod` List loaded modules
* `tar -cf` archiving
* `tar -xf` extracting
    add before `f`
    * `-J` for compress or decompress by xz algorithm
    * `-j` for compress or decompress by bzipz algorithm
    * `-z` for compress or decompress by gzip algorithm
    * `xz` `unxz` `bzip2` `bunbzip2` `gzip` `gzip -d` compressing and decompressing
* `su` temporary switch to another user without changing full
environment.
* `su -` switch to full user environment as log-out then login to another user
* `adduser` `addgroup` friendlier fron end tho the low level tools `useradd` `groupadd` as they configure the environment for the new user
* `usermod` modify a user account 
    * `-aG` to append new primary groups
    * `-g` to change the initial group
    * `-L` to lock user password
    * `-U` to unlock user password
    * `-l` to change the login name
* `userdel` delete a user 
    `-r` It will remove user’s home directory and the user’s mail spool. Files located in other file systems will have to be searched for and deleted
* `gtoupmod`
    * `-n` change the groupname
    * `-g` change the group id
* `groupmems` to see the group members
* `groupdel` to delete a group
* `chage` to set up password aging
    * `-m`
    * `-M`
    * `-E`
    * `-I`
    * `-W
* `passwd` change user passwords and can change aging and lock/unlock user.
* `compgen -c` print all commands can br ran by the shell


 -------------------------DAY 5 process management remained----------------
 