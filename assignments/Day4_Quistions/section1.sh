#!/usr/bin/bash

name=0
familyName=0

#takes the user name and his family name
read -p "Please enter your name: " name
read -p "Please enter your family name: " familyName

exist=$(cut -d: -f1 /etc/passwd | grep $name | wc -w)

if [ '0' -eq $exist ]
then
	echo "$name user is not fount, Please enter your data to creat it"
	sudo adduser $name
fi
