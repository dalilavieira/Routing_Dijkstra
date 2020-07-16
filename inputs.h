A4 B5
ret 100origem=4 dest=5

A5 B9
ret 100origem=5 dest=9

A5 B1
ret 100origem=5 dest=1

A1 B0
ret 100origem=1 dest=0

A0 B2
ret 201A0 B8
ret 200A8 B13
ret 200A8 B12
ret 100origem=8 dest=12

A13 B10
ret 200A10 B6
ret 100origem=10 dest=6

A10 B14
ret 100origem=10 dest=14

A6 B7
ret 100origem=6 dest=7

A14 B7
ret 301A12 B15
ret 301A15 B14
ret 101origem=15 dest=14

A2 B11
ret 301A11 B15
ret 100origem=11 dest=15

A9 B3
ret 401A3 B2
ret 100origem=3 dest=2

INICIA PASSO 2
A0 B2chaama dijkistra
ret 202


origem=1 dest=2
dest e B 
origem=0 dest=1
A0 B8chaama dijkistra
ret 200


origem=4 dest=8
origem=0 dest=4
A8 B13chaama dijkistra
ret 200


origem=12 dest=13
origem=8 dest=12
A13 B10chaama dijkistra
ret 201


origem=9 dest=10
dest e B 
origem=13 dest=9
A14 B7chaama dijkistra
ret 302


origem=11 dest=7
dest e B 
origem=15 dest=11
origem=14 dest=15
A12 B15chaama dijkistra
ret 2147483647

distancia infinita no dijkstra
DEU RUIM
