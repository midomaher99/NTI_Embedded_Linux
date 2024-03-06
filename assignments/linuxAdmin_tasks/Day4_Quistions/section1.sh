#!/usr/bin/bash

name=0
familyName=0

#takes the user name and his family name
read -p "Please enter your name: " name
read -p "Please enter your family name: " familyName
echo ""
exist=$(cut -d: -f1 /etc/passwd | grep $name | wc -w)

if [ '0' -eq $exist ]
then
	echo "$name user is not found, Please enter the user informatoin to creat it"
	echo ""
	sudo adduser $name
fi

exist=$(cut -d: -f1 /etc/group | grep $familyName | wc -w)

if [ '0' -eq $exist ]
then
	echo "$familyName group is not found, It will be created"
	echo ""	
	sudo addgroup  $familyName
fi

sudo usermod -aG $familyName $name

#printing user data
echo "#######################################"
echo "User data:"
echo "##########"
echo "User name            : $(cat /etc/passwd | grep $name | cut -d: -f1)"
echo "User ID              : $(cat /etc/passwd | grep $name | cut -d: -f3)"
echo "User primary group IG: $(cat /etc/passwd | grep $name | cut -d: -f4)"
echo "User home directory  : $(cat /etc/passwd | grep $name | cut -d: -f6)"
echo "User login shell     : $(cat /etc/passwd | grep $name | cut -d: -f7)"

echo "#######################################"
echo "Group data:"
echo "##########"

members=$(cat /etc/group | grep $familyName | cut -d: -f4 )
numOfMembers=$(echo $members |  awk -v FS=, '{print NF}')

echo "Group name           : $(cat /etc/group | grep $familyName | cut -d: -f1)"
echo "Group ID             : $(cat /etc/group | grep $familyName| cut -d: -f3)"
echo "Number of members    : $numOfMembers"
echo "Group members        :"
for (( i = 1; i <= numOfMembers; i++ ))
do
	echo "                       $i)$(echo $members | cut -d, -f$i)"
done
