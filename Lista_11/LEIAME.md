# Lista de Exercícios 11

## Considerações iniciais

Os dois programas mencionados neste documento tratam da solução de dois problemas propostos. Foi utilizada a linguagem de programação **C** principalmente focados na manipulação de arquivos e uso de registros (_structs_). Como cada problema trata de um problema completamente diferente do outro, optou-se por fazer dois programas distintos, uma vez que não seria muito didático criar uma forma de contextualizar ambos os problemas em um único programa. Por consequência, este documento será divido em duas partes, cada parte trará um registro do desenvolvimento de cada um de dois programas, explicando a lógica aplicada, o funcionamento de funções procedimentos, registros e bibliotecas.

Um importante aspecto que foi considerado no desenvolvimento da solução foi o da relação entre cada uma dos procedimentos e/ou funções (daqui em diante chamadas apenas de funções) criados para resolver o problema. Ao pensar no design da solução um foco especial é preciso ser dado na relação que cada uma das funções tem com o programa principal, uma vez que estas precisam trabalhar em conjunto para uma determinada finalidade. Ao desenhar pequenas funções que, juntas, realizam uma tarefa maior, o programa ganha quando a simplicidade e modularidade são empregadas. Podemos dizer, então, que um programa modularizado e simplificado é mais fácil de se dar manutenção, decidindo-se pela construção de funções com responsabilidade especificas e muito bem definidas, já que a alteração de um comportamento é em uma única função do sistema.

Uma característica mais evidente para aplicação da simplificação é o baixo acoplamento das funções. Por exemplo, é fácil notar nas soluções que a única dependência existente entre todas as funções em cada um dos programas se concentra nas variáveis globais. Durante o processo de criação percebeu-se que duas variáveis eram responsáveis por ditar toda a dinâmica de funcionamento dos programas, logo, por que não as globalizar e torná-las de fácil manipulação para todas as funções, evitando assim passagens por referência por entre muitas funções causando um evidente aumento de complexidade dos programas? Pois, assim, este recurso foi implementado nas soluções culminando em excelentes resultados que poderão ser vistos a seguir na divulgação das soluções.

## **A Soma das Distâncias**

O problema consiste em desenvolver um programa capaz de acessar um arquivo qualquer contendo uma sequência de coordenadas _x_, _y_ e _z_, em seguida o programa deve ser capaz de extrair as coordenadas e as armazenar em uma _struct_ e com isso calcular as distâncias entre elas. Uma segunda etapa do problema consiste em realizar a soma das distâncias entre cada uma das coordenadas. Assim partimos para o primeiro requisito que problema exige, as coordenadas devem ser extraídas para uma _struct_ construída especificamente para armazenar as coordenadas.
Atendendo ao requisito a seguinte estrutura foi criada:

```c
typedef struct coordenada{
    int x;
    int y;
    int z;
} Coordenada;
```

A instrução _typedef_ foi utilizada de forma evitar o constante uso da chamada _struct coordenada_, simplificando a chamada do tipo apenas para _Coordenda_. O registro _Coordenada_ é bastante autoexplicativa, contém três variáveis do tipo _int_ correspondendo a de um ponto no espaço cartesiano representadas nos pontos _x_, _y_ e _z_.

### ***Arquivos de Coordendas***

Como requisito principal, o programa precisa ser capaz de acessar um determinado tipo de arquivo contendo as coordenadas, porém esses arquivos precisam ser criados. O problema não pede explicitamente que uma implementação focada para esse proposito seja criada, mas em ordem de tornar o processo padronizado duas funções foram elaboradas para que o arquivo de coordenadas seja produzido com mais facilidade. Uma função é capaz de produzir valores aleatórios e preencher o arquivo com a quantidade de coordenadas desejada pelo usuário, a segunda função, por sua vez, espera por valores informados pelo usuário; vejamos a implementação das funções:

```c
int criaArquivo(){
    FILE *fp;
    int aux, cont = 0;
    Coordenada coord;
    srand(time(NULL));

    if((fp = fopen("coordenadas.dat", "wb")) == NULL){
        puts("Arquivo não criado");
        return 0;
    }

    do{
        coord.x = rand() % 100;
        coord.y = rand() % 100;
        coord.z = rand() % 100;

        if(fwrite(&coord,1,sizeof(Coordenada),fp) != sizeof(Coordenada)){
            puts("Um erro ocorreu durante a gravação.");
            puts("Programa será finalziado.");
            return 0;
        }
        printf("\nCoordanada[%d] (x = %d, y = %d, z = %d) foi adicionada ao arquivo.\n", cont+1, coord.x, coord.y, coord.z);
        cont++;
        puts("Deseja adicionar outro coordenada ao arquivo? (S/N)");
        aux = validaEscolha();
        if(cont < 2 && aux == 1){
            puts("Pelo menos duas coordenadas são necessárias para o funcionamento do programa.");
            puts("Uma nova coordenada será inserida automaticamente.");
            aux = 0;
        }
    } while(aux == 0 && cont < N);

    fclose(fp);
    return cont;
}
```

A função acima inicia invocado um tipo _FILE_, este tipo de variável armazena as informações referentes a um arquivo, é utilizada para interagir com as funções da biblioteca padrão que trabalham com arquivos. Normalmente este tipo de variável é trabalhado na sua forma de ponteiro devido a características da implementação de funções na biblioteca padrão, isso será melhor explicado adiante. Um outro aspecto interessante dessa biblioteca é a presença da função _srand(time(NULL))_ essa função é responsável pela variação da semente que produz números aleatórios baseado no tempo atual do computador, ou seja, garante que novos números aleatórios sejam produzidos todas as vezes que a função for chamada.
Um dos pontos mais importantes nessa implementação é desvio condicional responsável pela abertura do arquivo de coordenada:


```c
if((fp = fopen("coordenadas.dat", "wb")) == NULL){
    puts("Arquivo não criado")
    return 0;
}
```

A função _fopen()_ é responsável por abrir o caminho especificado para o arquivo que se deseja abrir, ela retorna um ponteiro do tipo _FILE_ que pode ser usado para escrever, ler e efetuar operações em cima desse arquivo. As operações permitidas com o arquivo dependem do modo utilizado para abrir o arquivo; dependendo do modo, o arquivo pode apenas ser lido, ou apenas escrito ou lido e escrito. No caso da implementação optou-se pela condição _wb_ ou seja o arquivo pode ser escrito em um formato binário. Grosso modo formato binário é um recurso da biblioteca padrão permitindo que blocos de bytes sejam escritos em arquivos de forma a facilitar a leitura e escrita de blocos de dados maiores e mais apropriados a registros (_structs_) ou matrizes de dados. Observe que caso o ponteiro retornado pela função _fopen()_ seja _NULL_ é tratado como se uma falha ocorresse, uma mensagem de erro é exibida ao usuário e a função interrompe seu fluxo.
Não havendo problemas com a abertura do arquivo a função segue para um laço de repetição _do...while_ onde as coordenadas são produzidas e imediatamente gravadas no arquivo.

```c
if(fwrite(&coord,1,sizeof(Coordenada),fp) != sizeof(Coordenada)){
    puts("Um erro ocorreu durante a gravação.");
    puts("Programa será finalziado.");
    fclose(fp);
    return 0;
}
```

A função _fwrite()_ é uma função apropriada para a gravação de dados no formato binário, ela envia diretamente ao arquivo texto um bloco de dados que é de certa forma compatível com o registro _Coordenada_ e tem como retorno a quantidade de bytes que foram gravadas no arquivo. Este retorno por sua vez é utilizado para comparar com o tamanho que um tipo _Coordenada_ deveria produzir, caso os valores gravados sejam incompatíveis uma mensagem de erro é apresentada ao usuário interrompendo o fluxo da função. A função foi moldada para que retornasse **0** caso alguma coisa errada acontecesse, em caso de tudo ocorrer corretamente a variável **cont** é retornada a função chamadora em ordem de informar a esta a quantidade de coordenadas inseridas no arquivo de coordenadas.

A segunda função implementada para criação do arquivo de coordenadas, funciona exatamente da mesma maneira, porém ao invés de se ter os números de coordenadas sendo gerados automaticamente a função aguarda o usuário informar o número desejado para cada uma das coordenadas. Vejamos:

```c
int criaArquivoManual(){
    FILE *fp;
    int aux, cont = 0;
    Coordenada coord;
    srand(time(NULL));

    if((fp = fopen("coordenadas.dat", "wb")) == NULL){
        puts("Arquivo não criado");
        return 0;
    }

    do{
        printf("Informe valor de x: ");
        scanf("%d%*c", &coord.x);
        printf("Informe valor de y: ");
        scanf("%d%*c", &coord.y);
        printf("Informe valor de z: ");
        scanf("%d%*c", &coord.z);

        if(fwrite(&coord,1,sizeof(Coordenada),fp) != sizeof(Coordenada)){
            puts("Um erro ocorreu durante a gravação.");
            puts("Programa será finalziado.");
            fclose(fp);
            return 0;
        }
        printf("\nCoordanada[%d] (x = %d, y = %d, z = %d) foi adicionada ao arquivo.\n", cont+1, coord.x, coord.y, coord.z);
        cont++;
        puts("Deseja adicionar outro coordenada ao arquivo? (S/N)");
        aux = validaEscolha();
        if(cont < 2 && aux == 1){
            puts("Pelo menos duas coordenadas são necessárias para o funcionamento do programa.");
            puts("Uma nova coordenada será inserida automaticamente.");
            aux = 0;
        }
    } while(aux == 0 && cont < N);

    fclose(fp);
    return cont;
}
```

Por fim a função _fclose()_ é responsável por fechar o arquivo, esta função força que os dados que ainda permanecem no buffer sejam gravados no arquivo e o encerra com segurança.
O intuito de se ter duas funções com o mesmo propósito é permitir ao usuário ter opção de escolha quando iniciar o programa, podendo gerar a lista de coordenadas rapidamente caso precise de um teste rápido, ou pode informá-las quando precisar realizar um teste mais preciso no funcionamento do programa.

Perceba que em ambas as funções a tarefa de abrir/criar, ler e fechar o arquivo ficou a cargo da própria função. Isso é um exemplo do que foi dito anteriormente neste documento, trata-se da aplicação da separação de responsabilidade. Isso quer dizer, que o arquivo poderia ter sido aberto/criado na função principal e o ponteiro que faz referência a ela ter sido enviado para as funções que compõe o programa. Essa prática teria aumentado a complexidade do programa podendo causar problemas futuros caso houvesse necessidade de manutenção do programa. Aqui não temos um programa de complexidade alta, mas já complexo o bastante para perceber que alguns problemas mais complexos essa prática poderia ser um grande transtorno em vias de manutenção do código fonte.

### **Leitura do Arquivo de Coordenadas**

Uma vez que temos os arquivos de coordenadas criados, uma função responsável por fazer a leitura desse arquivo. A função de leitura foi criada seguindo o princípio da separação de responsabilidades, uma vez que esta também é capaz de invocar o seu próprio ponteiro de _FILE_ e administrar por si mesma a abertura, escrita e fechamento do arquivo. Vejamos a implementação:

```c
float leArquivo(int cont){
    FILE *fp;
    Coordenada c1, c2;
    float soma = 0;

    if((fp = fopen("coordenadas.dat","rb")) == NULL){
        puts("Arquivo .dat não pode ser criado/encontrado.");
        puts("Programa será encerrado.");
        return 0;
    }

    if(fread(&c1,1,sizeof(Coordenada), fp) == sizeof(Coordenada)){
        cont--;
        while(cont > 0){
            if(fread(&c2,1,sizeof(Coordenada), fp) == sizeof(Coordenada)){
                cont--;
                soma += calcDistancia(c1,c2);
                printf("\nX1 = %d, \tY1 = %d, \tZ1 = %d", c1.x,c1.y,c1.z);
                printf("\nX2 = %d, \tY2 = %d, \tZ2 = %d", c2.x,c2.y,c2.z);
                printf("\nDistância %f\n",calcDistancia(c1,c2));
            }
            else{
                puts("Problemas na leitura do arquivo.");
                puts("Programa será encerrado.");
                return 0;
            }
            c1 = c2;
        }
    }
    else{//Em caso de falha de leitura.
        puts("Problemas na leitura do arquivo.");
        puts("Programa será encerrado.");
        return 0;
    }

    fclose(fp);
    return soma;
}
```

Assim como na função de criação do arquivo, aqui também temos o mesmo desvio condicional responsável por fazer a verificação da abertura do arquivo. Exatamente o mesmo princípio é aplicado, a função _fopen_ tenta abrir o arquivo e caso o ponteiro retornado seja _NULL_, uma mensagem de erro aparece para o usuário e retorna **0** para a função principal indicando falha na operação.

```c
if((fp = fopen("coordenadas.dat","rb")) == NULL){
    puts("Arquivo .dat não pode ser criado/encontrado.");
    puts("Programa será encerrado.");
    return 0;
}
```

Uma vez que o arquivo foi aberto corretamente, inicia-se um processo de leitura das coordenadas inseridas no mesmo. Como as coordenadas foram armazenadas na forma binária, a função de leitura _fread()_ deve ser configura de forma a esperar um bloco de bytes equivalente ao registro _Coordenada_, por essa razão que o valor retornado por _fread()_ é comparado com _sizeof(Coorenada)_. Caso algum problema ocorra nessa operação uma mensagem de erro é retornada ao usuário e a operação é encerrada.
A algoritmo realiza duas leituras, de forma que ele sempre tenha duas coordenadas armazenadas para o cálculo das distâncias entre as coordenadas. Uma vez que o cálculo é realizado, as coordenadas em _c2_ são transferidas para _c1_ e _C1_ recebe novos valores lidos do arquivo. Todo esse processo é controlado pela variável _cont_ indicando a quantidade de coordenadas que foram inseridas no arquivo, para cada coordenada que é extraída do arquivo uma unidade é decrementada em _cont_. A variável _soma_ recebe a soma das distâncias calculadas e as armazena para no final da rotina a retornar para a função chamadora.

### **Cálculo das distâncias**

Por fim, o cálculo das distâncias é realizado pela função _calcDistancia()_ e tem a mais simples das implementações. Trata-se de uma distância euclidiana calculada da seguinte maneira:

$\sqrt{(x_{2} - x_{1})^2+(y_{2} - y_{1})^2+(z_{2} - z_{1})^2}$

A função recebe duas variáveis do tipo _Coordenda_ e aplica a fórmula nos dados contidos nas variáveis e em seguida retorna o resultado da operação para a função chamadora:

```c
float calcDistancia(Coordenada c1, Coordenada c2){
    return sqrt(pow(c2.x - c1.x,2) + pow(c2.y - c1.y,2) + pow(c2.z - c1.z,2));
}
```

## **Cadastro de Alunos**

