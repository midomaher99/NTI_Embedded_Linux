##Section1
The script created two variables `HELLO` which is environmen variable and `LOCAL` which is local variable and we will discuss the visibility of each one in both termenals. the terminal which the script ran at it will be called **OLDTERMINAL** and the terminal which is opend from the script will be called **NEWTERMINAL**.

`HELLO`: is only visible in the **NEWTERMINAL** only as the environment variable `HELLO` was appended to .bashrc before **NEWTERMINAL** execution

`LOCAL`: is not visibl in **both** terminals as it was local variable for the proccess of the running script not for any terminal of them.

