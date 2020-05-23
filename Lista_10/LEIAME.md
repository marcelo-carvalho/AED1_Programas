# Lista de Exercícios 10

## Considerações iniciais

A construção deste programa foi realizada utilizando a linguagem de programação **C**, com o intuito de se resolver 10 problemas propostos fazendo uso do recurso de Matrizes e Registros. Para cada um dos problemas propostos, funções e/ou procedimentos foram implementadas de forma a darem as respoastas esperadas, muitas vezes as soluções constam com a implementação de uma função e/ou procedimento ou com a combinação de outros já criados anteriormente. 
De forma a se manter um contexto, e também uma linearidade na apresentação das soluções, todas as funções de solução foram combinadas na forma de um **menu**, onde o usuário tem acesso individual a cada uma das soluções implementadas. A função _menu()_ tem por si só a função de estabelecer essa conexão entre as demais respostas dos problemas propostos. Vejamos:

```
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

De maneira geral o código acima, implementa um laço de repetição que aguarda por uma entrada do usuário que pode variar de 0 à 10. A entrada do usuário é armazenada na váriavel _index_ caso o valor informado pelo usuário encontra-se dentro da faixa de valores informada pelo usuário este valor é retornado para a função chamadora (note que a função _menu()_ retorna um valor do tipo _int_). Em caso de o valor informado pelo usuário estiver fora do intervalo determinado uma mensagem de "Valor invalido" é retornada ao usuário e um novo valor é requisitado. 
Uma segunda função contribui para o objetivo de contextualização das soluções dos problemas. A função _matrizOpcao()_, tem por objetivo oferecer ao usuário a possibilidade de se preencher a matriz de forma automatica ou de forma manual. Isto possibilita o usuário a possibilidade de escolha de ter uma matriz preenchida de forma automática pelo programa, agilizando o processo de verificação das soluções, mas sem tirar do usuário a possibilidade de informar os valores que desejar. Vejamos:

```
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

A função _matrizOpcao()_ retorna um valor do tipo _int_ que varia entre **0** e **1**, ou seja, possui uma função _booleana_ onde, **00** é retornado a função chamadara quando o usuário deseja 

## Parte I - Matrizes

Para a solução dos exercícios da **Parte I** exigiu-se que os as matrizes deveriam ser construidas 

```
if(tralala)
```
