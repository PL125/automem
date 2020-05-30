# automem

A ideia é criar um editor simples de memórias automotivas. 

Existe o plano de expandir esse mesmo projeto para interfacear com o protocolo CAN (utilizando mcp2515), porém no momento está separado em outro projeto.

## Ideia inicial
 - [x] Ler memórias (24Cxx, ST95xx, 93Cxx)
 - [x] Linguagem simples para comunicar entre as diferentes plataformas
 - [ ] Aplicação desktop (atualmente faz a comunicação e envia mensagens, porém incompleta)
 - [ ] Aplicação mobile utilizando bluetooth (e a linguagem comum).  

## Como funciona

Atualmente o processador recebe mensagens no estilo lisp, por exemplo:

``` 
(e 3 4096) 
```
Muda memória para ST95320 de 4 Kbytes

<hr>

``` 
(r 0) 
```
Lê posição 0 da memória

<hr>

``` 
(w 0 2) 
```
Escreve o número 2 na posição 0 da memória

<hr>

Como a ideia é permitir a utilização do display lcd, é necessário realizar operações mais complexas, como por exemplo, existe a memória de determinado veículo que contém a informação contida em uma sequencia de primeiro e último caractere (no hexadecimal) ao longo de 4 endereços, podemos descrever dessa maneira:

```
(m (l (r 24)) (f (r 25)) (l (r 26)) (f (r 27)))
```
<img src="https://github.com/palvs/automem/blob/master/images/tree.jpg?raw=true"/>


Assim qualquer aplicação pode se comunicar.
Inclusive esse código é utilizado pelo próprio processador para obter o resultado que serão mostrados na tela (a ideia é compartilhar a pasta de scripts e dados entre todas as plataformas, no caso do processador, utilizando um cartão sd para guardar todos scripts).

O circuito se encontra nesse dessa maneira no momento

<img src="https://github.com/palvs/automem/blob/master/images/proto.jpg?raw=true"/>