import sys
import math

arq_nome = "accumulate_0.in"#input()
arquivo = open(arq_nome, 'r')
edges = []
for linha in arquivo:
#	print(linha)
	try:
		a,b = linha.split(' ')
		A = int(a)
		B = int(b)
		#print(a, b)
		edges.append((A,B))	
	except Exception as e:
		print(e)

arquivo.close()
#valores do arquivo 1
print(len(edges)-1)#a primeira linha também é salva(conta edges)
print(edges)

arq_nome2 = "verilog_accumulate.out"#input()
arquivo2 = open(arq_nome2, 'r')
grids = []
for linha in arquivo2:
#	print(linha)
	try:
		lista = linha.split(' ')
		lista_int = []
		for item in lista:
			lista_int.append(item)
		grids.append(lista)
			#print(item)
		#print(len(lista_int)-1)
	except Exception as e:
		print(e)

print(grids)
print(len(lista_int)-1)#tamanho do grid
print(lista_int)
arquivo2.close()
j = -1
for lista_i in grids:
	j += 1
	arq_out_nome = "inputs"+str(j)+".h"
	arquivo3 = open(arq_out_nome, 'w')

	string1 = "#define V "+str(len(lista_int)-1)+"\n"
	arquivo3.write(string1)
	string2 = "#define TAM "+str(int(math.sqrt(len(lista_int)-1)))+"\n"
	arquivo3.write(string2)

	string3 = "int edges = "+str(len(edges)-1)+";\n"

	arquivo3.write(string3)
	arquivo3.write("int grid[] = {")
	for i in range(len(lista_i)-1):
		arquivo3.write(str(lista_i[i]))
		if i != len(lista_i)-2:
			arquivo3.write(" ,")
	arquivo3.write("};\n")

	#int e_a[] = {1, 2, 2, 3, 3, 7, 6, 5, 5, 4, 8, 9};
	arquivo3.write("int e_a[] = {")
	for i in range(1,len(edges)):
		arquivo3.write(str(edges[i][0]))
		if i != len(edges)-1:
			arquivo3.write(" ,")
	arquivo3.write("};\n")

	#int e_b[] = {4, 4, 5, 5, 6, 6, 9, 9, 8, 8, 10, 10};
	arquivo3.write("int e_b[] = {")
	for i in range(1,len(edges)):
		arquivo3.write(str(edges[i][1]))
		if i != len(edges)-1:
			arquivo3.write(" ,")
	arquivo3.write("};\n")

	arquivo3.close()















