## Section 1
### Q1: Create a folder called myteam in your home directory and change its permissions to read only for the owner.
```
mkdir ~/myteam
chmod u-wx myteam    #set read only for the owner
```

### Q2: Log out and log in by another user
`su - user2`

### Q3: Try to access (by cd command) the folder (myteam)
It will be accesible as we removed the execute permission for only the owner.

### Q4: Using the command Line
#### 1. Change the permissions of oldpassw file to give owner read and write permissions and for group write and execute and execute only for the others (using chmod in 2 different ways)
```
chmod u=rw,g=wx,o=x oldpasswd
chmod 631 oldpasswd
```

#### 2. Change your default permissions to be as above.


#### 3. What is the maximum permission a file can have, by default when it is just created? And what is that for directory.
For files the max permissions are 666 which is read and write for the owner, group and other users, and for directories the max permissions are 777, which is read, write and execute for the owner, group and other users

#### 4. Change your default permissions to be no permission to everyone then create a directory and a file to verify.
by setting umask in `.profile` file under the home directory to `777` then
```
touch file
mkdir dir

ls -l #to see the permissions
```

#### 5. State who can access this file if any with proof.
only the root or a user with superuser privilege can access this file, because that the file permission is not applied on the root user or superusers.

### Q5: Create a file with permission 444. Try to edit in it and to remove it? Note what happened.
```
touch file
chmod 444 file
```
the file can not be edited because no one has a write permission to it, but the users who have the write permission for the directory which contains the file can remove it.

### Q6: What is the difference between the “x” permission for a file and for a directory?
* 'x' permission for files indicates that this is an executable whether it is a binary or a script.
* 'x' permission for directories allows the user who has this permisson to access the directory content, traversing sub-directories, run programs in the directory and etc... .

### Q7: Create a new directory.
`mkdir newDir`
1. Set the sticky bit on the newly created directory.
`chmod +t newDir`
2. set the setgui bit on the created directory.
`chmod g+s newDir`
3. Create multiple user accounts.
assuming that the directory creator is **user1**.
```
adduser user2
adduser user3
```
4. Allow these users to create files within the directory and directory.
By change the group ownership for a group of the three users
```
sudo addgroup group
sudo chown :group newDir
sudo usermod -aG group user2
sudo usermod -aG group user3
```
5. Attempt to delete or rename each other's files.
no one can delete or rename the others files as the sticky bit is set.

### Q8: List the permission passwd command has and explain why it has S
`ls -l /user/bin/passwd`
the permissions are `-rwsr-xr-x`