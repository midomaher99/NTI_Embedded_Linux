#!/bin/bash

if [ -f ~/.bashrc ] ; then

	echo HELLO=$HOSTNAME >> ~/.bashrc
	LOCAL=$(whoami)
	x=5
	gnome-terminal

fi
