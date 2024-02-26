##Section1
The script created two variables `HELLO` which is environmen variable and `LOCAL` which is local variable and we will discuss the accessibility of each one in both termenals. the terminal which the script ran at it will be called **OLDTERMINAL** and the terminal which is opend from the script will be called **NEWTERMINAL**.

|           |                 HELLO                  |                 LOCAL                  |
|-----------|----------------------------------------|----------------------------------------|
|OLDTERMINAL|not accessible as environment variables |                                        |
|           |are defined when .bashrc script runs and|                                        |
|           |it only runs once when the shell starts |not accessible for both terminals as it |
|-----------|----------------------------------------|is local variable for the process of the|
|NEWTERMINAL|accissible as .bashrc script ran when it|running script.                         |
|           |started and **HELLO** variable was      |                                        |
|           |appended to .bashrc before it started   |                                        |
|-----------|----------------------------------------|----------------------------------------|
