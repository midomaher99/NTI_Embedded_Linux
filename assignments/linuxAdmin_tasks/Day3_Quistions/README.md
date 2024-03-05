## Section1
The script created two variables `HELLO` which is environmen variable and `LOCAL` which is local variable and we will discuss the visibility of each one in both termenals. the terminal which the script ran at it will be called **OLDTERMINAL** and the terminal which is opend from the script will be called **NEWTERMINAL**.

`HELLO`: is only visible in the **NEWTERMINAL** only as the environment variable `HELLO` was appended to .bashrc before **NEWTERMINAL** execution

`LOCAL`: is not visibl in **both** terminals as it was local variable for the proccess of the running script not for any terminal of them.

## Section 2
### Q1: List the user commands and redirect the output to /tmp/commands.list
`compgen -c >> /tmp/commands.list`

### Q2: 

### Q3: What is the command to count the word in a file or number of file in directory.
`wc` command.
* Count the number of user commands.
`compgen -c | wc -l`

### Q4: What happens if you execute:
1. `cat filename1 | cat filename2`
    only filename2 will be printed pn the terminal as the frist `cat` output is redirected from terminal to be input to the secend `cat` which ignord this input as it has its own input from filename2
2. `ls | rm`
    nothing will happen as `rm` expects an input form arguments not from an input file.
3. `ls /etc/passwd | wc –l`
    will display the number of lines of the output of `ls /etc/passwd` which is 1 as there is only one file has a name matches the pattern /etc/passwd.
### Q5: Write a command to search for all files on the system that, its name is “.profile”.
`locate -b '.profile'`

### Q6: 

### Q7: Create a symbolic link of /etc/passwd in /boot.
`sudo ln -s /etc/passwd /boot/mysoftln`

### Q8: Create a hard link of /etc/passwd in /boot. Could you? Why?
can't creat this hard link as hard link can't be created outside the same file system.

### Q9: