#define MAX 100

// Definindo estrutura do aluno
struct aluno {
    int numeroMatricula;
    char nome[30];
    float nota01, nota02, nota03;
}

// Definindo o tipo da Lista (que contém o campo qtde e o campo dadosAluno)
struct lista {
    int qtde;
    struct aluno dadosAluno[MAX];
}

typedef struct lista Lista;

Lista* criar_lista();

void liberar_lista(Lista* li);

int tamanho_da_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int inserit_no_inicio_da_lista(Lista* li, struct aluno al);

int inserir_no_final_da_lista(Lista li, struct aluno al);

int remover_do_inicio_da_lista(Lista* li);

int remover_do_final_da_lista(Lista* li);

int busca_por_posicao(Lista *li, int pos, struct aluno *al);

int buscar_por_conteudo_na_lista(Lista* li, int numMatr, struct aluno* al);