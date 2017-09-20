#include <stdio.h>
#include <stdlib.h>
#include <ListaSequencialEstatica.h>

Lista* criar_lista() {
    Lista* li;
    
    li = (Lista*)malloc(sizeof(struct lista));

    if(li != null)
        li->qtde = 0;

    return li;
}

void liberar_lista(Lista* li) {
    free(li);
}

int tamanho_da_lista(Lista *li) {
    if(li == null)
        return -1;
    
    return li->qtde;
}

int lista_cheia(Lista *li) {
    if(li == null)
        return -1;
    
    if(li->qtde == MAX)
        return 1;

    return 0;
}

int lista_vazia(Lista *li) {
    if (li == null)
        return -1;

    if (li->qtde == 0)
        return 1;

    return 0;
}

int inserit_no_inicio_da_lista(Lista *li, struct aluno al) {
    if(li == null)
        return 0;

    // Lista cheia
    if(li->qtde == MAX)
        return 0;

    /**
    * Deslocando todos os valores uma posição para frente na lista
    * para que o novo valor seja inserido na primeira posição
    */
    for(int i=li->qtde-1; i>0; i--) {
        li->dadosAluno[i+1] = li->dadosAluno[i];
    }

    // Inserindo o novo aluno pa posição 0 do array
    li->dadosAluno[0] = al;

    // Incrementando o contador de quandidade de valores preenchidos do array
    li->qtde += 1;

    return 1;
}

int inserir_no_final_da_lista(Lista li, struct aluno al) {
    // Lista não existe
    if(li == null)
        return 0;

    // Lista cheia
    if(li->qtde == MAX)
        return 0;

    // Insere na última posição do array
    li->dadosAluno[li->qtde] = la;

    return 1;
}

int remover_do_inicio_da_lista(Lista *li) {
    //Verifica se a lista existe, se não existir, retorna 0
    if(li == null)
        return 0;

    // Verifica se a lista está vazia. Se estiver retorna 0
    if(li->qtde == 0)
        return 0;

    /**
    * Move todos os elementos para uma posição anterior da sua atual.
    * Desse modo o primeiro elemento é apagado.
    */
    for(int i=0; i<li->qtde; i++) {
        li->dadosAluno[i] = li->dadosAluno[i+1];
    }

    // Decrementa a quantidade de itens no array de alunos
    li->qtde -= 1;
}

int remover_do_final_da_lista(Lista *li) {
    //Verifica se a lista existe
    if(li == null)
        return 0;

    // Verifica se existem elementos na lista que possam ser removidos
    if(li->qtde == 0)
        return 0;

    // Remover 1 da quantidade de elementos já faz excluir o último elemento
    li->qtde -= 1;
}

int busca_por_posicao(Lista* li, int pos, struct aluno* al) {
    if(li == null || pos <= 0 || li->qtde == 0 || pos > li->qtde)
        return 0;

    // Traz a referência do endereço de memória do aluno naquela posição do array
    *al = li->dadosAluno[pos-1];

    return 1;
}

int buscar_por_conteudo_na_lista(Lista *li, int numMatr, struct aluno *al) {
    if(li == null)
        return 0;

    // Percorre o aray até achar o número da matrícula que está sendo buscado
    int i = 0;
    while(i < li->qtde && li->dadosAluno[i].numeroMatricula != numMatr) {
        i++;
    }

    // Caso o contador seja igual o número de elemetos do array, quer dizer que o elemento não foi encontrado
    if(i == li->qtde)
        return 0;

    *al = li->dadosAluno[i];

    return 1;
}