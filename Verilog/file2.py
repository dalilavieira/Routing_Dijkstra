import sys
import math


if len(sys.argv) > 1:
	a = sys.argv[1]
else:
	exit(1)

arq_nome = a
arquivo = open(arq_nome, 'r')

i = 0
for linha in arquivo:
	i = 0

if linha.find("RUIM") != -1:
		i = 1

if i == 1:
	print("deu ruim", sys.argv[1])	
