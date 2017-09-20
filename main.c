#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencialEstatica.h"

int main() {
    // Variável inteira auxiliar
    int varAux = 0;

    // Declarando a estrutura para obter o retorno das informações
    struct aluno alunoRetorno;

    Lista* listaDeAlunos;

    listaDeAlunos = criar_lista();

    // Inserção de dados
    listaDeAlunos->dadosAluno[0].numeroMatricula = 1;
    strcpy(listaDeAlunos->dadosAluno[0].nome, "Rodrigo Moreira Baptista");
    listaDeAlunos->dadosAluno[0].nota01 = 7;
    listaDeAlunos->dadosAluno[0].nota02 = 9;
    listaDeAlunos->dadosAluno[0].nota03 = 5;

    varAux = inserit_no_inicio_da_lista(listaDeAlunos, listaDeAlunos->dadosAluno[0]);

    // Verificando o tamanho da lista
    varAux = tamanho_da_lista(listaDeAlunos);
    printf("Tamanho da lista: %d\n", varAux);

    //Busca de dados pela nota03
    varAux = buscar_por_conteudo_na_lista(listaDeAlunos, 1, &alunoRetorno);
    printf("Nota 03 do aluno: %.1f\n", alunoRetorno.nota03);

    return 0;
}
