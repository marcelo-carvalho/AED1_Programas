# Lista de Exercícios 10

## Considerações iniciais

A construção deste programa foi realizada utilizando a linguagem de programação **C**, com o intuito de se resolver 10 problemas propostos fazendo uso do recurso de Matrizes e Registros. Para cada um dos problemas propostos, funções e/ou procedimentos foram implementadas de forma a darem as respostas esperadas, muitas vezes as soluções constam com a implementação de uma função e/ou procedimento ou com a combinação de outros já criados anteriormente.
De forma a se manter um contexto, e, também uma linearidade na apresentação das soluções, todas as funções de solução foram combinadas na forma de um **menu**, onde o usuário tem acesso individual a cada uma das soluções implementadas. A função _menu()_ tem por si só a função de estabelecer essa conexão entre as demais respostas dos problemas propostos. Vejamos:

```c
int menu(){
    int index = 0;
    puts("\n=====================LISTA DE EXERCICIOS 10=====================\n"
             "\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Atividade 1.\n"
             "2 - Atividade 2.\n"
             "3 - Atividade 3.\n"
             "4 - Atividade 4.\n"
             "5 - Atividade 5.\n"
             "6 - Atividade 6.\n"
             "7 - Atividade 7.\n"
             "8 - Atividade 8.\n"
             "9 - Atividade 9.\n"
             "10 - Atividade 10.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 10)
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}
```

De maneira geral o código acima, implementa um laço de repetição que aguarda por uma entrada do usuário que pode variar de 0 à 10. A entrada do usuário é armazenada na variável _index_ caso o valor informado pelo usuário encontra-se dentro da faixa de valores informada pelo usuário este valor é retornado para a função chamadora (note que a função _menu()_ retorna um valor do tipo _int_). Em caso de o valor informado pelo usuário estiver fora do intervalo determinado uma mensagem de "Valor invalido" é retornada ao usuário e um novo valor é requisitado.
Uma segunda função contribui para o objetivo de contextualização das soluções dos problemas. A função _matrizOpcao()_, tem por objetivo oferecer ao usuário a possibilidade de se preencher a matriz de forma automática ou de forma manual. Isto possibilita o usuário a possibilidade de escolha de ter uma matriz preenchida de forma automática pelo programa, agilizando o processo de verificação das soluções, mas sem tirar do usuário a possibilidade de informar os valores que desejar. Vejamos:

```c
int matrizOpcao(){
    char opcao = '\0';
    int resp = -1;

    do{

        setbuf(stdin,NULL);
        puts("Deseja preecher a matriz manualmente? (S/N)");
        scanf("%c%*c", &opcao);  
        setbuf(stdin,NULL);
        if(opcao == 's' || opcao == 'S')
            resp = 1;
        else if(opcao == 'n' || opcao == 'N')
            resp = 0;
        else{
            puts("Opcao invalida...");
            resp = -1;
        }
    }while(resp == -1);

    return resp;
}
```

A função _matrizOpcao()_ retorna um valor do tipo _int_ que varia entre **0** e **1**, ou seja, possui uma função _booleana_ onde, **0** é retornado à função chamadora quando o usuário não deseja preencher a matriz de forma manual e retorna **1** caso deseja preencher a matriz de forma manual. O algoritmo inicia questionando o usuário se este deseja preencher a matriz de forma manual ou não, em seguida espera uma resposta do tipo _char_ **S** ou **N**. Repare como o armazenamento da resposta é feito na variável _opcao_:

```c
scanf("%c%*c", &opcao)
```

A configuração _%c%*c_ espera por dois caracteres do tipo _char_ onde o segundo caractere será descartado após a leitura. Isso dá devido ao sistema operacional considerar o _enter_ um caractere alfanumérico o que pode causar alguns transtornos na hora de checar os valores de entrada no _if_. Um outro recurso que merece ser mencionado nessa função é a instrução _setbuf(stdin,NULL)_. Esta instrução garante que o buffer de entrada do teclado seja _setado_ para **NULL**, ou seja qualquer valor vindo do teclado que porventura ali possa estar armazenada e não é de nosso interesse dentro do contexto da função, será por sua vez apagado. E isso é feito em dois momentos, um no início da função e logo após armazenar o valor selecionado na variável _opcao_.
Outros dois procedimentos que mencionares a seguir, são responsáveis pelo preenchimento das matrizes. O procedimento _matrizManual(int mat[][M])_ faz o preenchimento manual da matriz _mat_, de forma simplificada esse procedimento consiste apenas de um laço _for_ que percorre todos os elementos da matriz e atribuindo a estes o valor informado pelo usuário.
O procedimento _matrizAutomatico(int mat[][M])_, como pode ser visto no código abaixo, realiza os mesmo processo porém ao invés de termos o usuário informando os valores de entrada da matriz, temos um gerados de números pseudo aleatórios realizado esse processo.

```c
void matrizAutomatico(int mat[][M]){
    srand(time(NULL));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            mat[i][j] = rand() % 100;
        }
    }
}
```

Para se gerar números aleatórios em C, podemos usar a função _rand()_ presente na biblioteca _stdlib.h_. Quando esta função é chamada ela produz um valor aleatório na faixa entre 0 e a constante **RAND_MAX** (o valor desta constante também encontra-se definido na biblioteca _stdlib.h_), porém para o contexto deste procedimentos limitados o valor máximo para cada entrada da matriz em até 100, por essa razão vemos a função _rand()_ seguida de _% 100_.
Ao se realizar testes, verificou-se que a função _rand()_ sempre gerava a mesma sequência de valores, isso ocorre pois a função _Rand()_ precisa de um valor inicial chamado de _semente_. Se nenhum valor é passado a _rand()_ ele assume como padrão o valor **1**, ou seja, produzindo sempre a mesma sequência de valores. Em ordem de se evitar que isso, inclui-se a instrução _srand(time(NULL))_, mas para isso é necessário adicionar a biblioteca _time.h_, isso era informar a função _rand()_ uma nova _seed_ para cada vez que o método de preenchimento automático for acionado. Maiores informações sobre as funções _rand()_ e _srand()_ podem ser encontradas [aqui](https://www.ime.usp.br/~pf/algoritmos/aulas/random.html).
Precisamos falar, ainda, de um último procedimento fora do contexto das soluções, trata-se de um procedimento simples criado apenas para facilitar a impressão do conteúdo da matriz no monitor.

```c
void imprimeMatriz(int mat[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("Mat[%d][%d] = %d\t", i,j, mat[i][j]);
        }
        printf("\n");
    }
}
```

Assim como no preenchimento manual trata-se apenas de dois laços de repetição encadeados percorrendo todas as posições da matriz e em seguida exibindo-as na tela do computador. Para cada finalização do laço interno uma quebra de linha é adicionada _printf("\n")_ para a visualização da matriz ficar de uma forma mais intuitiva para compreensão.
Todos os procedimentos e funções supracitados foram criados de forma a atender ao requisito do trabalho proposto em lhe dar um contexto e integridade na hora de apresentar as soluções para cada um dos exercícios apresentados.
As próximas seções são divididas em duas, uma específica para as soluções aos problemas envolvendo matrizes, e uma outra seção demostrando a solução de um problema que requer o uso de _registros_, vejamos agora como essas soluções foram construídas.

## Parte I - Matrizes

Um dos requisitos exigidos para a solução dos exercícios propostos está relacionado a dimensão das matrizes, o requisito informa que devem ser matrizes de dimensões **N x M**, onde os valores de **N x M** poderiam ser definidos pelo usuário ou poderia ser pré-determinados como constantes. Por fins de facilidade e integridade das funções a serem desenvolvidas estabeleceu-se os valores de **N x M** como sendo constantes. Evitando assim a necessidade de criação de algoritmos mais complexos e garantindo que as matrizes trabalhadas sempre serão quadradas.

### **1. Copiando de Matrizes**

O primeiro problema requisita a construção de um algoritmo capaz de receber como parâmetro de entrada uma matriz e copiar todos os elementos destas para uma segunda matriz, para solucionar este problema o seguinte algoritmo foi criado:

```c
void copiaMatriz(int mat[][M], int cop[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cop[i][j] = mat[i][j];
        }
    }
}
```

Optou-se por um procedimento onde ambas as matrizes seriam passadas por referência, a razão para escolha dessa solução se dá pelo fato de ser mais fácil de se manipular ambas as matrizes e não ter necessidade de se criar um algoritmo complexo para retornar valor por valor de uma matriz para a outra. A solução é bastante simples, muito semelhante ao que acontece nos procedimentos de impressão ou de preenchimento, temos dois laços de repetição encadeadas que percorre todos os elementos de ambas as matrizes acesso o valor de uma e imediatamente atribuindo este valor a posição equivalente da segunda matriz. Temos como entrada a matriz _mat_ contendo os valores originais e a matriz _cop_ a qual se destina os valores copiados.

### **2. Comparando de Matrizes**

O segundo problema envolve uma solução bastante semelhante, no caso o procedimento criado deverá comparar os elementos de duas matrizes distintas e verificar se as duas matrizes são iguais. Vejamos:

```c
int comparaMatriz(int mat1[][M], int mat2[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(mat1[i][j] != mat2[i][j])
                return 0;
        }
    }
    return 1;
}
```

O procedimento é construído basicamente da mesma maneira que as soluções anteriores. Dois laços de repetição encadeados fazem o acesso a todos os elementos das duas matrizes, que foram recebidos como parâmetros de referência, cada um dos elementos da matriz _mat1_ é comparado com o elemento equivalente na matriz _mat2_ caso algum elemento diferente seja encontrado a condição _if(mat1[i][j] != mat2[i][j])_ será verdadeira e a função será encerrada retornando o valor **0**, equivalente a falso, para a função chamadora indicando que as matrizes são diferentes. Caso a condição não seja verdadeira ao final dos dois laços de repetição, a função retornará **1**, equivalente a verdadeiro, para a função principal indicando que as duas matrizes são iguais.

### **3. Busca em Matrizes**

O terceiro problema envolve uma rotina de busca, ou seja, deseja-se saber a frequência com que um determinado valor especificado pelo usuário aparece em uma dada matriz, vejamos:

```c
int buscaMatriz(int mat[][M], int k){
    int cont = 0;
    for(int i =0; i < M; i++){
        for(int j =0; j < M; j++){
            if(mat[i][j] == k)
                cont++;
        }
    }
    return cont;
}
```

A função foi criada recebendo dois parâmetros de entrada, a matriz _mat_ e o valor a ser buscado **k**. Da mesma forma que nas outras soluções, dois laços de repetição são utilizados para percorrer todos os elementos da matriz, cada vez que o valor é identificado uma variável _cont_ é incrementada em uma unidade. Ao final dos laços de repetição o valor armazenado em _cont_ é retornado à função chamadora contendo a frequência de vezes que o valor buscado foi encontrado na matriz. É muito importante aqui inicializar a função _cont_ com o valor zero para que nenhum valor indesejado seja retornado a função principal podendo causar falsos resultados.

### **4. Busca Personalizada Matrizes**

O quarto exercício também é um problema de busca, a rotina envolve buscar o maior número registrado na matriz e retornar a função chamadora a linha onde este valor se encontra, para solução desse problema foram implementadas duas funções. Seguem as implementações:

```c
int buscaMaiorMatriz(int mat[][M]){
    int maior = 0;
    for(int i=0; i < M; i ++){
        for(int j=0; j < M; j++){
            if(mat[i][j] > maior)
                maior = mat[i][j];
        }
    }
    return maior;
}
```

A função acima utiliza os já conhecidos laços de repetição para percorrer todo toda a matriz em busca do maior valor. Uma vez que um novo valor é acessado na matriz, esta passa por uma condição de comparação, o valor armazenado em _maior_ é comparado com o valor acesso do vetor, caso o valor do vetor seja maior _maior_ o recebe e assim segue o laço de repetição. O maior valor é retornado a função chamadora que o utiliza para acessar uma outra função:

```c
int buscaLinhaMatriz(int mat[][M], int k){
    for(int i=0; i < M; i ++){
        for(int j=0; j < M; j++){
            if(mat[i][j] == k)
                return i;
        }
    }
    return -1;
}
```

Está função realiza uma operação semelhante a já mencionada _buscaMAtriz()_, porém ao invés de retornar a frequência com que o valor buscado aparece na matriz, retorna o valor da variável **i**, onde está armazenada a linha onde está armazenado o valor buscado. Caso o valor buscado não seja encontrado a função irá retornar **-1**.

### **5. Operações com Valores Armazenados Matrizes**

A próxima implementação também exigiu que duas funções fossem implementadas, a primeira função implementa uma rotina que calcula a média dos valores contidos em uma matriz, e para realização do  algoritmo foi utilizado o mesmo processo já mencionado anteriormente, dois laços de repetição percorrem todos os valores da matriz armazenando a soma de cada um deles em uma variável chamada _media_ e ao mesmo tempo uma segunda variável chamada _cont_ é incrementada para cada valor acessado da matriz. No final dos laços o valor de _media_ é divido por _cont_ e retornado para a função chamadora:

```c
float mediaMatriz(int mat[][M]){
    float media = 0;
    int cont = 0;

    for(int i=0; i < M; i++){
        for(int j =0; j < M; j++){
            media += mat[i][j];
            cont++;
        }
    }
    return media/cont;
}
```

A segunda parte da implementação consiste em uma busca seguida de uma comparação, a função implementada recebera o valor da média encontrado pela função anterior e em seguida usará esse valor para fazer uma comparação com os outros valores da matriz, os valores que forem maiores que o valor da média habilitam a condição para que a variável _cont_ seja incrementada em uma unidade. Uma vez que os laços de repetição passarem por todos os campos da matriz, a função irá retornar quantas vezes a variável _cont_ foi incrementada.

```c
int acimaMediaMatriz(int mat[][M], float media){
    int cont = 0;
    for(int i =0; i <M; i++){
        for(int j = 0; j <M; j++){
            if(mat[i][j] > media)
                cont++;
        }
    }
    return cont;
}
```

É importante lembrar que devemos tomar cuidado em sempre iniciar as variáveis _media_ e _cont_ com o valor **0** em ambas as funções, isso garante que nenhum valor previamente contendo na memória prejudique a integridade dos resultados.

### **6. Acessando Valores Acima da Diagonal Principal**

O próximo problema utiliza da mesma solução já criada na **seção 4**, porém com o acréscimo de que o maior valor buscado tem que se encontrar acima da diagonal principal da matriz. Um problema importante que se deve preocupar ao implementar a solução para um problema como esse está justamente na construção da matriz, para que se exista uma diagonal principal a matriz precisa ser do tipo **quadrada**, ou seja, a quantidade de linhas tem que ser igual a quantidade de colunas. Como optamos pela construção de matrizes quadradas sempre, não houve necessidade de implementação de uma ação para verificar se essa condição está sendo respeitada. Outro requisita explicitado pelo problema é que os valores da diagonal principal não devem ser considerados na operação, assim temos a seguinte implementação:

```c
int maiorAcimaDiagMatriz(int mat[][M]){
    int maior = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < i; j++){
            if(maior < mat[i][j])
                maior = mat[i][j];
        }
    }
    return maior;
}
```

A implementação é exatamente igual a feita na **seção 4**, apenas com a inclusão de uma segunda condição no segundo laço de repetição _j < i_, com isso conseguimos garantir que apenas os valores de índice de colunas menores que os índices de linha serão incluídos no laço de repetição, portanto somente os valores acima da diagonal principal. A variável _maior_ exatamente como feito na outra implementação precisa ser iniciada em **0** de forma que haja interferência no resultado.

### **7. Acessando Valores Abaixo da Diagonal Principal**

O sétimo problema é bastante semelhante ao problema anterior, porém este requer uma ampliação na implementação anterior, uma vez que vamos precisar acessar os valores abaixo da diagonal principal. Além disso, implementações que consideram as dimensões variáveis da matriz, precisam se certificar de que a matriz em análise é do tipo *Quadrada* caso contrário não existirá uma diagonal principal de referência. Como mencionado anteriormente, isso não é um problema nesse código, uma vez que as matrizes possuem sempre as mesmas dimensões definidas por constantes.
Para acessar o maior valor abaixo da diagonal principal, basta seguirmos o mesmo exemplo da implementação apresentada na **seção 6**, mas neste caso inclui-se um segundo desvio condicional, vejamos:

```c
int maiorAbaixoDigMatriz(int mat[][M]){
    int maior = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(j < i){
                if(mat[i][j] > maior)
                    maior = mat[i][j];
            }

        }
    }
    return maior;
}
```

O desvio condicional _if((j < i)_ garante que apenas os índices de colunas maiores que os índices de linha poderão entrar na condição e então passarem pela comparação e alimentar a variável _maior_. Optou-se por uma estratégia diferente nessa implementação apenas com o intuito de se explorar diferentes possibilidades de implementação. A variável _maior_ também precisa ser inicializado com valor **0** caso contrário valores indesejáveis podem interferir no resultado da operação.
Porém, o problema proposto pede a diferença entre o maior valor sobre a diagonal principal e o valor abaixo da diagonal principal. Em posso das duas funções, basta alimentar duas variáveis na função _main()_ e fazer a diferença entre elas tendo assim a resposta para o problema proposto.

### **8. Somando Valores de uma Coluna**

Para implementar uma função que faça a soma dos elementos, vamos utilizar os já conhecidos laços de repetição. Estes, por sua vez, irão percorrer todos os elementos da matriz e uma condição de desvio iria garantir que apenas os dados de uma coluna especifica da matriz irão ser considerados para serem somados. A variável _soma_ armazenara os valores da soma a meninda que os laços de repetição percorrem a matriz.

```c
int somaColunaMatriz(int mat[][M], int col){
    int soma = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(j == col)
                soma += mat[i][j];
        }
    }
    return soma;
}
```

Para garantir o funcionamento da função, o usuário deve informar qual coluna deve ser lida. Vale lembrar que antes de aplicar o valor escolhido pelo usuário na função, esta precisa passar por algum tipo de tratamento para garantir de que valores fora da faixa de operação sejam aplicados causando problemas durante a execução do programa. Mais uma vez, _soma_ precisa ser inicializada com valor **0** de forma que nenhum valore indesejado seja considerado na soma.
Uma vez finalizados os laços de repetição, o valor contido na variável _soma_ é retornado à função chamadora.

### **9. Matriz Transposta**

A transposta de uma matriz é uma matriz que apresenta os mesmos elementos de uma outra matriz, porém colocados em uma outra posição. Ela é obtida transportando-se ordenadamente os elementos das linhas da matriz para as colunas da nova matriz transposta. A implementação do procedimento para implementar a função transposta é muito similar ao que já foi feito anteriormente, primeiramente precisamos de dois laços de repetição percorrendo todos os elementos da matriz, e uma segunda matriz para receber esses dados na ordem desejada, vejamos:

```c
void transpostaMatriz(int mat1[][M], int mat2[][M]){
    for(int i = 0; i < M; i ++){
        for(int j = 0; j < M; j++){
            mat2[j][i] = mat1[i][j];
        }
    }
}
```

O procedimento consiste em duas matrizes de entrada, onde _mat1_ é a matriz contendo os dados originais e _mat2_ é a matriz transposta. Tomando como base a definição de matriz transposta, seguiu-se a mesma ideia para implementar o procedimento, a _mat2_ tem os indicadores de índice de linha e coluna trocados em relação a _mat1_, dessa forma o que para em _mat1_ é linha em _mat_ passa a ser coluna, concluindo assim a implementação do problema proposto e também da primeira parte da lista de atividades.

## Parte II - Registros e Matrizes

A **Parte II** da lisa de problemas, consiste em apenas um único problema dividido em partes menores. Primeiramente faz necessário uma contextualização do problema. O desafio das 8 rainhas no tabuleiro de xadrez é um problema matemático onde consiste em dispor oito rainhas em um tabuleiro de xadrez de forma que nenhuma rainha possa atacar a outra. Ou seja, nenhuma rainha pode estar na mesma linha coluna ou diagonal da outra.
o problema pede que uma implementação seja feita de forma que o usuário possa dispor as peças no tabuleiro, e este automaticamente cheque se a posição é válida ou não. Para se chegar a essa implementação o problema foi divido em cinco partes que serão apresentadas a seguir.

### **a. Struct, Vetor de Posições e Jogadas**

A primeira parte para solução do problema consiste em estabelecer as estruturas para facilitar a solução do problema. Um primeiro requisito é que o problema que as jogadas sejam implementadas por meio de uma _struc_ também conhecida como Registro, a _struc_ consta apenas de duas variáveis **x** onde será armazenada a linha onde a peça será posicionada e **y** representando a coluna. Seguindo com a implementação do requisito temos:

```c
struct jogada {
    int x;
    int y;
};
typedef struct jogada Jogada;
```

O registro acima foi utilizado para criação de um vetor _Lista_ de oito posições que irá armazenar a posição de cada uma das jogadas informadas pelo usuário. O vetor de jogadas foi criado de formada global de forma que todas as funções do programa possam fazer modificações no vetor sem que este fique sendo passados por referência de função em função. Apenas a posição atual do vetor é distribuída entre as funções como veremos a seguir. O problema também cita uma matriz 8x8 chamada de _Tabuleiro_ com o intuito de servir como tabuleiro do jogo, armazenando as posições de cada uma das peças. A matriz também foi criada como uma variável global devido as mesmas razões do vetor de jogadas.
Um primeiro paço importante ao se iniciar o programa é garantir que todas as funções do tabuleiro sejam carregadas com o valor zero, o que será importante, maiores detalhes adiante. Abaixo segue o procedimento que realiza essa função

```c
void inicializaTabuleiro(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Tabuleiro[i][j] = 0;
        }
    }
}
```

A função é composta simplesmente por dois laços de repetição que percorrem todas as posições do vetor e armazenada em cada uma delas o valor **0**. Isso permite que o Tabuleiro seja reiniciado todas as vezes que for necessário e garante que todas as posições estão livres para serem ocupadas.
Um procedimento foi implementado para que o usuário tenha alguma interação com o programa, vejamos:

```c
void setJogada(int turno){
    int x;
    int y;
    int flagValida = -1;

    printf("Jogada %i", turno+1);
    printf("\nInforme x: ");
    scanf("%d", &x);

    do{
        if(x < 1 || x >= 9){
            printf("\nValor invalido...");
            printf("\nInforme um valor valido para x: ");
            scanf("%d", &x);
            flagValida = -1;
        }
        else{
            flagValida = 1;
        }
    }while(flagValida == -1);

    printf("Informe y: ");
    scanf("%d", &y);

    do{
        if(y < 1 || y >= 9){
            printf("\nValor invalido...");
            printf("\nInforme um valor valido para y: ");
            scanf("%d", &y);
            flagValida = -1;
        }
        else{
            flagValida = 1;
        }
    }while(flagValida == -1);


    Lista[turno].x = x-1;
    Lista[turno].y = y-1;
    setTabuleiro(turno);
}
```

A função recebe como entrada a posição do vetor _Lista_ de forma que ali possa ser armazenado os valores informados pelo usuário. O procedimento pede ao usuário que informe os valores de linha e coluna ao usuário, e garante que os valores informados se encontram dentro de uma faixa de valores permitidos. Devidamente validados e armazenados no vetor _Lista_, esta primeira iteração irá passar por uma segunda validação.

### **b. Representando a Jogada no Matriz Tabuleiro**

Garantindo que os valores de posições armazenados no vetor _Lista_ encontram-se no intervalo correto, estas informações passam por uma segunda validação. Esta segunda validação ocorre verificando-se se os valores informados encontram-se disponíveis na matriz _Tabuleiro_, e isto é feito verificando se o valor armazenado na posição referenciada pela jogada, se a posição informada for igual a **0** esta posição é válida e pode aceitar a jogada, caso a posição referenciada seja **1** a posição está ocupada e a jogada não pode ser aceita retornando para a função _setJogada_. Segue implementação da função:

```c
void setTabuleiro(int turno){
    if(Tabuleiro[Lista[turno].x][Lista[turno].y] == 0)
        Tabuleiro[Lista[turno].x][Lista[turno].y] = 1;
    else{
        puts("Posição ocuapda.");
        puts("Informe outra jogada.");
        void setJogada(int i);
    }

    imprimeTabuleiro();
}
```

Repare que também a função acima, recebe como parâmetro de entrada a posição do vetor _Lista_ onde encontra-se a jogada do usuário. Devido ao funcionamento desse procedimento que precisamos garantir que a matriz _Tabuleiro_ seja inicializada com todos os valores em **0**, assim podemos fazer uso disso para distribuir as peças no tabuleiro. Caso a posição esteja ocupada o usuário receberá uma mensagem de recusa e novamente será questionado por uma novação posição. Caso a posição esteja de fato vaga, seguiremos para a terceira e última validação.

### **c. Validando Posição**

Última etapa no processo de validação de jogada consiste em verificar se a posição escolhida pelo usuário coloca não a coloca em risco de ser capturada por outra rainha já existente no tabuleiro. Para que essa validação seja possível, foi necessário implementar uma rotina que irá varrer a matriz _Tabuleiro_ em todas as posições em que é possível ter uma outra rainha movimento, ou seja, nas horizontais, nas verticais e nas diagonais.

```c
int validaJogada(int turno){
    int i = Lista[turno].x + 1;
    int j = Lista[turno].y;

    //Norte
    while(i < N){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Norte");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i++;
    }

    //Sul
    i = Lista[turno].x - 1;
    j = Lista[turno].y;
    while(i >= 0){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Sul");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i--;
    }

    //Leste
    i = Lista[turno].x;
    j = Lista[turno].y + 1;
    while(j < N){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Leste");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        j++;
    }

    //Oeste
    i = Lista[turno].x;
    j = Lista[turno].y - 1;
    while(j >= 0){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Oeste");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        j--;
    }

    //Nordeste
    i = Lista[turno].x + 1;
    j = Lista[turno].y + 1;
    while(i < N && j < N ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Nordeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i++;
        j++;
    }

    //Noroeste
    i = Lista[turno].x + 1;
    j = Lista[turno].y - 1;
    while(i < N && j >= 0 ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Noroeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i++;
        j--;
    }

    //Sudeste
    i = Lista[turno].x - 1;
    j = Lista[turno].y + 1;
    while(i >= 0 && j < N ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Sudeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i--;
        j++;
    }

    //Sudoeste
    i = Lista[turno].x - 1;
    j = Lista[turno].y - 1;
    while(i >= 0 && j >= 0 ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Sudoeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i--;
        j--;
    }
    return 1;
}
```

Essa função consiste em percorrer todas as possíveis direções e certificar de que uma rainha não esteja presente garantindo assim a validação da posição escolhida pelo usuário. Cada um dos laços de repetição é responsável por uma possível direção, casa uma peça seja encontrada em alguma das direções a função ira retornar o valor **0** indicando que não é uma jogada valida, do contrário irá retornar o valor **1** indicando uma jogada valida, permitindo o indicador do vetor _Lista_ ser incrementado e passar para a próxima jogada até um total de 8.
Com isso concluímos a implementação das funções que dão solução ao problema, restando agora apenas as funções responsáveis pela exibição dos resultados.

### **d. Imprimindo as Jogadas**

O procedimento abaixo consiste apenas em exibir os valores **x** e **y** que foram admitidos no vetor _Lista_ após a validação dos mesmos.

```c
void imprimeLista(){
    printf("\n");
    printf("Lista de Jogadas");
    for(int i =0; i < N; i++){
        printf("\n x = %d, y = %d", Lista[i].x, Lista[i].y);
    }
    printf("\n");
}
```

## **e. Imprimindo Tabuleiro**

A última função implementada nada mais do que um procedimento responsável pela impressão do tabuleiro na tela, este procedimento é chamado em vários momentos da partida, para que o usuário possua controle das posições inda disponíveis e também é impresso no final uma vez que o tabuleiro seja montado.

```c
void imprimeTabuleiro(){
    printf("\n");
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            printf("|%d|", Tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
```

Esse procedimento de impressão possui uma particularidade em relação aos outros, pelo fato de a o laço externo começar do último termo, isso se dá pois a representação das linhas no tabuleiro de xadrez começam a ser contadas da mesma casa onde se começa a contar as linhas como se fosse o ponto de origem do plano cartesiano.
