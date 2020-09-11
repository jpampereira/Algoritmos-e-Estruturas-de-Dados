# Aula 2 - Vetores e Ponteiros

***

## Exercício 1: Mínimo e máximo
Escreva um programa que, dada uma sequência de números inteiros, calcula e devolve o menor e o maior valor dessa sequência.

**Entrada:** Para uma sequência de n números, a entrada é formada por n + 1 valores. O primeiro número indica a quantidade de números que a sequência possui. Após esse número, a entrada é formada por n números, que compõem a sequência propriamente dita.

**Saída:** A saída consiste em apenas dois números: o menor valor presente na sequência e o maior valor presente na sequência dada como entrada.

Exemplo de teste:
---
Entrada|Saída
:---: | :---:
5|
3 6 8 2 1|1 8

[Minha Solução](https://github.com/jpampereira/Algoritmos-e-Estruturas-de-Dados/blob/master/Aula%202%20-%20Vetores%20e%20Ponteiros/exercicio1.c)
:man_technologist:

***

## Exercício 2: Palíndromo
Uma palavra é dita "palíndromo" quando apresenta a mesma sequência de letras se lida da esquerda para a direita, ou da direita para a esquerda.

Escreva um programa que recebe uma lista de palavras e identifica palíndromos. Para fins de avaliação, seu programa deverá ignorar as diferenças entre letras maiúsculas e minúsculas. Cada palavra possui, no máximo, 40 caracteres.

**Entrada:** A entrada de dados é formada por uma sequência de palavras, sendo uma em cada linha.

**Saída:** Para cada palavra da entrada, a saída exibe a mensagem "PALINDROMO" caso a palavra seja um palíndromo, ou "NAO PALINDROMO" caso contrário.

Exemplo de teste:
---
Entrada|Saída
:---: | :---:
Ana|PALINDROMO
cana|NAO PALINDROMO
radar|PALINDROMO

[Minha Solução](https://github.com/jpampereira/Algoritmos-e-Estruturas-de-Dados/blob/master/Aula%202%20-%20Vetores%20e%20Ponteiros/exercicio2.c)
:man_technologist:

***

## Exercício 3: Ordenação de Vetores
Escreva um programa que lê um vetor de números inteiros. Seu programa deverá combinar os números de modo que eles fiquem ordenados crescentemente.

**Entrada:** O primeiro valor da entrada é um número n, que representa a quantidade de números inteiros presente no vetor. Na linha seguinte são exibidos n números inteiros, que representam os valores do vetor propriamente dito. Esses números são apresentados na mesma linha e separados por espaço branco.

**Saída:** A saída é formada pelos n números do vetor de entrada, exibidos em ordem crescente na mesma linha e separados por espaço branco.

 Exemplo de teste:
---
Entrada|Saída
:---: | :---:
5|
3 1 8 6 9|1 3 6 8 9

[Minha Solução](https://github.com/jpampereira/Algoritmos-e-Estruturas-de-Dados/blob/master/Aula%202%20-%20Vetores%20e%20Ponteiros/exercicio3.c)
:man_technologist:

***

## Exercício 4: Intercalação de caracteres 
Escreva um programa de intercalação de caracteres. 

O seu programa deverá ler duas palavras p1 e p2 e produzir uma terceira s, formada pela intercalação das duas palavras iniciais. A primeira letra de s é a primeira letra de p1, seguida pela primeira letra de p2, seguida pela segunda letra de p1, seguida pela segunda letra de p2 e assim por diante. Caso p1 termine, o restante de p2 é concatenado com s. O mesmo raciocínio vale para p2.

**Entrada:** A entrada possui vários casos de teste. O primeira linha contém um número inteiro N que indica o número de testes. Cada teste é composto por duas palavras apresentadas na mesma linha e separadas por um espaço branco. Cada palavra possui entre 1 e 50 caracteres, inclusive.

**Saída:** A saída é formada por uma única palavra, que é a intercalação das duas palavras lidas na entrada.

Exemplo de teste:
---
Entrada|Saída
:---: | :---:
2|
Tpo oCder|TopCoder
aa bb|abab

[Minha Solução](https://github.com/jpampereira/Algoritmos-e-Estruturas-de-Dados/blob/master/Aula%202%20-%20Vetores%20e%20Ponteiros/exercicio4.c)
:man_technologist:
