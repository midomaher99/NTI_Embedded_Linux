## Section 2
### Q1: Create a supplementary (Secondary) group called pgroup with group ID of 30000
`sudo addgroup ---gid 30000 pgroup`

### Q2: Lock any user created account so he can't log in
`sudo usermod -L USER`

### Q3: Delete user account
`sudo userdel USER`

### Q4: Delete group account
`sudo groupdel GROUP`

### Q5: State the difference between adduser and useradd with example shown.

* `useradd` is a low level utility to add users to the system, every thing required to the user should be specified in the command options.

* `adduser` is a front end to the low level utility `useradd` which give the user a simple interface to set a parameters for the new user and it automatically creat the home directory and copy the required files from `/etc/skel` to the new user.