//Nó da lista para armazenar valores reais
struct lista {
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

//Estrutura da pilha
struct pilha {
    Lista* prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha * p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
void pilha_iprime(Pilha * p);