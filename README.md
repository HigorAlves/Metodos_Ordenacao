#Métodos de Ordenação

##Sumario

- Introdução

- Implementação

- Resultado e Discussões

- Conclusão

- Bibliografia


###Introdução

Neste trabalho irei apresentar diferentes tipos de métodos de ordenação, sendo eles:

- SelectSort

- InsertSort

- ShellSort

- QuickSort

- HeapSort

- GnomeSort (método extra :metal:)

Irei fazer comparações quanto ao tempo de execução, número de comparações e número de movimentações para diferentes tamanhos de entradas ordenadas de forma crescente, decrescente ou de forma aleatória. A intenção desse experimento é observar qual o melhor algoritmo de ordenação para certos tamanhos de entradas e formas de entrada. Os resultados que serão apresentados são frutos de experimentos feitos com o código que segue em arquivo juntamente com este relatório. O programa é, de maneira geral bem simples criando e alocando um vetor que irá conter os dados a serem estudados em suas quantidades e formas. Cada método pode ser facilmente usado assim como alterar o tamanho da entrada. Após a execução o tempo será computado e para o cálculo das comparações e movimentações será adicionado um contador dentro de cada método de ordenação assim o mesmo retornará o resultado. Gráficos gerados no programa R serão usados para a comparação dos dados coletados nos experimentos e que serão apresentados posteriormente.


##Implementação

- SelectSort

Seleciona o n-ésimo menor ou maior elemento do vetor e vai efetuando trocas para ordenar o vetor. Essas trocas são feitas do início para o fim do vetor começando de i=0 até n que é o tamanho do vetor. Quando i = n-1 o vetor já estará ordenado.

```c
void selectionsortP(Pequeno num[], int tam){
  int i,j,min,aux;
  for(i = 0;i < (tam-1);i++){
    min = i;
    for (j = (i+1); j < tam; j++){
      if(num[j].chave < num[min].chave)
        min = j;
    }
    if (i != min){
      aux = num[i].chave;
      num[i].chave = num[min].chave;
      num[min].chave = aux;
    }
  }
}
```

Para ordenar na forma decrescente basta inverter no sinal de < desta linha do código:

```c
for (j = (i+1); j < tam; j++){
  if(num[j].chave < num[min].chave)
    min = j;
}
```

- InsertSort

Desloca-se o número para sua devida posição de acordo com a ordem que deseja (crescente ou decrescente) Movimenta-se da esquerda para a direita e medida que i for avançado os elementos anteriores a ele já estarão ordenados.

```c
void insertionSortP(Pequeno array[], int tamanho){
  int i, j, tmp;
  for(i = 1; i < tamanho; i++){
    j = i;
    while(j > 0 && array[j - 1].chave > array[j].chave){
      tmp = array[j].chave;
      array[j].chave = array[j - 1].chave;
      array[j - 1].chave = tmp;
      j--;
    }
  }
}
```

Para ordenar de forma decrescente basta inverter o sinal de < desta linha do código:

![alt tag](http://i.imgur.com/aJsh5He.jpg)

- ShellSort

Os itens são selecionados em intervalos de h (no código esta como gap) posições e este h vai diminuindo a medida que o vetor vai sendo ordenado. h começa com o valor 1 e é multiplicado por 3 e somado em 1 a cada enquanto seu valor não ultrapassar o valor de n que é o tamanho do vetor a ser ordenado. se caso o valor de h final for menor que o do inicial o mesmo é trocado. Ex: vetor = {7 5 6 8 3 1} para h = 4 Os primeiros a serem comparados são 7 e 3, como o 3 é menor ambos trocam de posição. O valor de h não pode ser menor que 1.

![alt tag](http://i.imgur.com/GVnV92e.jpg)

Para ordenar de forma decrescente basta inverter o sinal de > desta linha no código:

![alt tag](http://i.imgur.com/eI41yQH.jpg)

- QuickSort

O princípio do QuickSort é dividir o vetor a ser ordenado em dois sub vetores e os mesmos em outros dois até que os mesmos serão ordenados separadamente e os resultados serão combinados para fazer o vetor ordenado. Obtemos um pivô a partir da equação v[(*i + *j) / 2] e este pivô que irá mostrar qual o tamanho dos sub vetores a serem ordenados.

![alt tag](http://i.imgur.com/X6JSAPX.jpg)

Para ordenar de forma decrescente basta inverter os sinal de > destas linhas no código:

![alt tag](http://i.imgur.com/0Lp1Ks9.jpg)

- HeapSort

Utiliza-se uma estrutura chamada heap para a ordenação crescente ou decrescente do vetor. Após toda inserção é refeito o heap a fim de que ao final de todas as inserções todos os números possam ser retirados do início e assim que retirados refaz o heap para o que próximo retirado do início seja o seguinte na ordem. O heap pode ser considerado uma árvore e o número sempre retirado do início seja a raiz da mesma, uma vez refeita após uma remoção o número que tomará o lugar da raiz será sempre o filho mais a direta da árvore esquerda da raiz.

![alt tag](http://i.imgur.com/Q34a2yX.jpg)

Para ordenar de forma decrescente basta inverter o sinal de < desta linha no código:

![alt tag](http://i.imgur.com/dWfcTnm.jpg)

- GnomeSort

Algoritmo similar ao InsertionSort com a diferença que o GnomeSort leva um elemento para sua posição correta, com uma sequencia grande de trocas assim como o BubbleSort.
O algoritmo percorre o vetor comparando seus elementos dois a dois, assim que ele encontra um elemento que está na posição incorreta, ou seja, um número maior antes de um menor, ele troca a posição dos elementos, e volta com este elemento até que encontre o seu respectivo lugar.

![alt tag](http://i.imgur.com/d4189Wi.jpg)

> Características
>> Complexidadee de tempo: Θ(n²)

- Arquivo de Bibliotecas .h

Todos os métodos tem suas devidas bibliotecas que funcionam como uma function, nele são descritas as funções e o struct do vetor de inteiros.

![alt tag](http://i.imgur.com/KgsVqwg.jpg)

- Main.c

Inicia-se com variáveis básicas como o “i,p,q” que são usadas nos fors, além da alocação dinâmica da memória do vetor usando a funcão malloc. Em seguida há o for para preenchimento do vetor utilizando a função rand() que gera números aleatóriosque serve para que a cada execução do programa os números aleatórios gerados sejam sempre diferentes. Contém também o código para cálculo do tempo das funções, a chamada das funções que executam cada algoritmo de ordenação, um fprintf para o tempo gasto. Por fim um free para liberar a memória do vetor alocada dinamicamente.

![alt tag](http://i.imgur.com/C1P63bw.jpg)

#Resultados e Discuções

- SelectSort

Quanto ao tempo quando a entrada é decrescente o tempo gasto é maior. Quanto as comparações ambos seguem a mesma linha não importando a ordem da entrada. Quanto as movimentações quando a entrada é aleatória são feitas mais movimentações.

- InsertSort

Quanto ao tempo quando a entrada é a aleatória é quando se gasta o maior tempo. Quanto as comparações quando a entrada é decrescente se faz o maior número das mesmas. Quanto as movimentações quando a entrada é decrescente se faz o maior número das mesmas.

- ShellSort

Quanto ao tempo quando a entrada é a aleatória é quando se gasta o maior tempo. Quanto as comparações quando a entrada é aleatória se faz o maior número das mesmas. Quanto as movimentações quando a entrada é aleatória se faz o maior número das mesmas.

- QuickSort

Quanto ao tempo quando a entrada é a aleatória é quando se gasta o maior tempo. Quanto as comparações quando a entrada é decrescente se faz o maior número das mesmas. Quanto as movimentações ambos seguem a mesma linha não importando a ordem da entrada.

- HeapSort

Quanto ao tempo quando a entrada é a aleatória é quando se gasta o maior tempo. Quanto as comparações quando a entrada é crescente se faz o maior número das mesmas. Quanto as movimentações quando a entrada é crescente se faz o maior número das mesmas.

- GnomeSort

Quanto ao tempo quando a entrada é a aleatória é quando se gasta o maior tempo. Quanto as comparações quando a entrada é decrescente se faz o maior número das mesmas. Quanto as movimentações quando a entrada é decrescente se faz o maior número das mesmas destacando-se um pouco das outras.


##Comparações entre os algoritmos

- Ordem crescente /crescente QTO para grandes e pequenas
> Para a ordem crescente o SelectSort é o algotimo que gasta mais tempo e o InsertSort o que gasta menos.

- Ordem decrescente /decrescente QTO para grandes e pequenas
> Para ordem decrescente o SelectSort seguido do InsertSort são os que gastam mais tempo e o QuickSort é o que gasta menos tempo.

- Ordem aleatório /crescente e decrescente
> Para ordem aleatória o InsertSort começa sendo o mais lento, mas em certo ponto o SelectSort o ultrapassa e passa a gastar mais tempo e o QuickSort é o que gasta menos tempo.

#Conclusão

De grande valia obter um conhecimento melhor sobre os principais algoritmos de ordenação, quando e como usar os mesmos, assim como calcular o tempo de execução de uma função e a geração de números aleatórios.Tive um pouco de dificuldades com o malloc por falta de pratica com ponteiros. Achei um pouco cansativa a coleta de dados uma vez que seriam no mínimo 10 execuções para cada tipo de entrada e para cada algoritmo, e após essa coleta de dados peguei uma média dos dados obtidos para gerar os gráficos. Também tive dificuldades na geração dos gráficos e por fim optei usar o Excel do Linux.
O código teve de ser cuidadosamente avaliado para saber onde colocar os contadores e quando o código era recursivo a atenção era muito maior, pois os contadores deveriam ser mandados como parâmetros da função e as alterações eram feitas pelos ponteiros e não direto na variável.


#Bibliografia

>https://pt.wikipedia.org/wiki/Gnome_sort
>https://pt.wikipedia.org/wiki/Shell_sort
>http://www.devmedia.com.br/algoritmos-de-ordenacao-analise-e-comparacao/28261
>https://pt.wikipedia.org/wiki/Heapsort

##Especificações do Ambiente onde todos os testes foram realizados

Processador: I7 3.5GHz
Memoria RAM: 16GB RAM 2400MHz
Placa de Video: GTX 770 SC
