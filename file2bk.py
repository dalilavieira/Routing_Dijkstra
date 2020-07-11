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
	if linha.find("RUIM"):
		i = 1
		break

if i == 1:
	print("deu bom")	
