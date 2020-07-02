#include <iostream>
#include <string>

class Equipamento{
    public:
        int matricula;
        std::string nome;
        std::string descricao;
        float valor;
        int data_dia;
        int data_mes;
        int data_ano;
    
    //Construtor padrão, inicializa objeto com valores padrões.
    Equipamento(){
        nome = "\0";
        matricula = 0;
        valor = 0.0;
        descricao = "Equipamento criado sem atributos.";
        data_dia = 1;
        data_mes = 1;
        data_ano = 2000;
    }

    //Função set para definir nome
    void setNome(std::string novoNome){
        nome = novoNome;
    }

    //Função set para definir nova matrícula
    void setMatricula(int novaMatricula){
        matricula = novaMatricula;
    }

    //Função set para definir valor
    void setValor(float novoValor){
        valor = novoValor;
    }

    //Função set para definir data
    void setData(int dia, int mes, int ano){
        data_dia = dia;
        data_mes = mes;
        data_ano = ano;
    }
    
    //Função set para definir descrição.
    void setComentario(std::string desc){
        descricao = desc;
    }

    //Funções abstratas para serem implementadas nas calasses filhas. 
    void virtual imprimir()=0;
    void virtual salvar(std::string arquivo)=0;
};

//Classe filha herdando atributos de Equipamento. 
class Ferramenta : public Equipamento{
    public:
    //Construtor padrão para a classe filha
    Ferramenta(){
        nome = "\0";
        matricula = 0;
        valor = 0.0;
        descricao = "Equipamento criado sem atributos.";
        data_dia = 1;
        data_mes = 1;
        data_ano = 2000;
    }
    
    //Construtor sobrecarregado.
    Ferramenta(std::string novoNome, int novaMatricula, float novoValor){
        nome = novoNome;
        matricula = novaMatricula;
        valor = novoValor;
        descricao = "Descrição necessária.";
    }

    //Função para imprimier os dados do objeto na tela. 
    void virtual imprimir(){
        std::cout << "Matrícula: " << matricula << std::endl;
        std::cout << "Nome: " << nome << std::endl;
        printf("Valor: R$ %0.2f \n", valor);
        printf("Data de registro: %d/%d/%d\n", data_dia, data_mes, data_ano);
        std::cout << "Descrição: " << descricao << std::endl;
    }

    //Função para salvar os dados do objeto em um arquivo binário. 
    void virtual salvar(std::string arquivo){
        FILE *fp;
        arquivo.append(".dat"); //Adiconiona a extenção .dat no final do arquivo. 
        //Abre o arquivo pra escrita e leitura sem apagar o que já existia.
        if((fp = fopen(arquivo.c_str(), "ab+")) == NULL){
            std::cout << "Error ao abrir ao abrir o arquivo" << std::endl;
            return;
        }

        //Tenta gravar o objeto em um arquivo binário.
        if(fwrite(this,1,sizeof(Ferramenta),fp) != sizeof(Ferramenta)){
            std::cout << "Error ao gravar no arquivo" << std::endl;
            return;
        }

        fclose(fp);
    }
};

int contador = 0;
Ferramenta ferramenta[10];

int menu();
void cadastrar();

int main(){
    int index = 0;
    int matricula;
    int i = 0;
    bool flag = false; // Ferramenta localizada?


    do{
        index = menu();
        switch(index){
            case 1: 
                //Testa se o buffer não está cheio para cadastar novo equipamento. 
                if(contador < 10){
                  cadastrar();
                  contador++;
                }
                else{
                    std::cout << "Buffer cheio, salve antes de cadastrar um novo equipamento" << std::endl;
                }
                break;
            case 2: 
                flag = false; //verdadeito caso ferramenta seja encontrada.
                std::cout << "Informe a matricula do equipamento buscado: ";
                std::cin >> matricula;
                i = 0;
                while(i < contador){
                    if(ferramenta[i].matricula == matricula){
                        ferramenta[i].imprimir();
                        flag = true;
                        break;
                    }
                    i++;
                }
                if(flag == false)
                    std::cout << "Ferramenta não encontrada." << std::endl;
                break;
            case 3:
                i = 0;
                if(contador == 0){
                    std::cout << "Buffer vazio, nada para salvar." << std::endl;
                }
                else{
                    
                    std::string arquivo;
                    std::cout << "Nome do arquivo: ";
                    std::cin >> arquivo;
                    while(i < contador){
                        ferramenta[i].salvar(arquivo);
                        i++;
                    }
                    contador = 0; //Libera o buffer para novos dados.
                }
                break;
            case 0:
                if(contador > 0){ //Garante que os dados serão salvos antes de fechar.
                    std::cout << "Salve antes de fechar" << std::endl;
                    index = 4;
                }
                else{
                    std::cout << "FIM!" << std::endl;
                }
                break;
        }
    }while(index != 0);

    return 0;
}


//Gera um menu. 
int menu(){
    int index = 0;
    puts("\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Cadastrar Ferramenta.\n"
             "2 - Listar dados do Equipamento.\n"
             "3 - Salvar Equipamento.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 6) //Garante a faixa de escolhas possíveis. 
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}


//Função para cadastrar uma nova ferramenta.
void cadastrar(){
    std::string nome;
    int matricula;
    float valor;
    int dia, mes, ano;

    std::cout << "Nome: ";
    std::cin >> nome;
    ferramenta[contador].setNome(nome);
    
    std::cout << "Matrícula: ";
    std::cin >> matricula;
    ferramenta[contador].setMatricula(matricula);

    std::cout << "Valor: ";
    std::cin >> valor;
    ferramenta[contador].setValor(valor);

    std::cout << "Dia: ";
    std::cin >> dia;
    std::cout << "Mês: ";
    std::cin >> mes;
    std::cout << "Ano: ";
    std::cin >> ano;
    ferramenta[contador].setData(dia,mes,ano);

    std::setbuf(stdin,NULL); //Libera o buffer
    std::cout << "Comentario: ";
    std::getline(std::cin, nome);
    ferramenta[contador].setComentario(nome);
}