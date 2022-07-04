#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int identificador_fila;
    char *nome_alunof;
    int matricula_alunof;
    char *descricaof;
    char *campus_livro;
    char *campus_aluno;
    char *responsavel_enc;
    int prioridade;
    struct pedido *prox;
} PEDIDO;


PEDIDO *inicio_fila = NULL;
PEDIDO *fim_fila = NULL;
int tam_fila = 0;

void add_fila(int identificador, char *nome_aluno, int matricula, char *descricao, char *campus_livro,
              char *campus_aluno, char *responsavel, int prioridade) {

    PEDIDO *novo_ped = malloc(sizeof(PEDIDO));
    novo_ped->identificador_fila = identificador;
    novo_ped->nome_alunof = nome_aluno;
    novo_ped->matricula_alunof = matricula;
    novo_ped->descricaof = descricao;
    novo_ped->campus_livro = campus_livro;
    novo_ped->campus_aluno = campus_aluno;
    novo_ped->responsavel_enc = responsavel;
    novo_ped->prioridade = prioridade;
    novo_ped->prox = NULL;

    if (inicio_fila == NULL) {
        inicio_fila = novo_ped;
        fim_fila = novo_ped;
        tam_fila++;
    }else if(inicio_fila->prioridade < novo_ped->prioridade){
        novo_ped->prox = inicio_fila;
        inicio_fila = novo_ped;
        tam_fila++;
    }else if (fim_fila->prioridade > novo_ped->prioridade){
        fim_fila->prox = novo_ped;
        fim_fila = novo_ped;
        tam_fila++;
    }else{
        PEDIDO *aux_add_fila = inicio_fila;
        while(aux_add_fila->prox != NULL && aux_add_fila->prox->prioridade > novo_ped->prioridade){
            aux_add_fila = aux_add_fila->prox;
        }
        novo_ped->prox = aux_add_fila->prox;
        aux_add_fila->prox = novo_ped;
        tam_fila++;
    }
}


void imprimir_fila() {
    PEDIDO *aux_print = inicio_fila;
    while (aux_print != NULL){
        printf("Identificador: %d\n", aux_print->identificador_fila);
        printf("Nome do aluno: %s\n", aux_print->nome_alunof);
        printf("Matrícula: %d\n", aux_print->matricula_alunof);
        printf("Descrição: %s\n", aux_print->descricaof);
        printf("Campus do Livro: %s\n", aux_print->campus_livro);
        printf("Campus do Aluno: %s\n", aux_print->campus_aluno);
        printf("Responsável pela encomenda: %s\n", aux_print->responsavel_enc);
        printf("Prioridade: %d\n", aux_print->prioridade);
        printf("\n");
        aux_print = aux_print->prox;
    }
}

PEDIDO *remover_fila() {

    if (inicio_fila == NULL) {
        return NULL;
    }else if (tam_fila ==1){
        PEDIDO *lixo = inicio_fila;
        inicio_fila = NULL;
        fim_fila = NULL;
        free(lixo);
        tam_fila--;
        return lixo;
    }else {
        PEDIDO *lixo = inicio_fila;
        inicio_fila = inicio_fila->prox;
        free(lixo);
        tam_fila--;
        return lixo;
    }
}
