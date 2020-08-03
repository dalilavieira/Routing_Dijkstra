#!/bin/bash

for i in `ls headers`
do
	#cat headers/$i
	cp headers/$i inputs.h
	#gcc route.c
	gcc route36.c
	./a.out > $i
	python file2.py $i
done
