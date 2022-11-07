/*
Implementação de lista encadeada
com funções de busca, remoção e inserção
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


typedef struct no_{

    //critério de busca
    //ordenacao
    int chave;

    //carga util do no
    /*num cenario real, poderia
    ser por exemplo, nome, endereco...*/
    int valor;

    //ponteiro que aponta para o proximo no
    struct no_ * prox;
}no;

//ponteiro que aponta para o inicio da lista = cabeça
    no* ptlista;


//retorna lista vazia
no* inicia_lista(){
    no* tmp = new(no);
    tmp->chave = 0;
    tmp->valor = 0;
    tmp->prox = NULL;

    return tmp;
}


//desaloca espaço previamete alocado para lista encadeada
//realiza alocação do espaço para que a lista possa começar a receber nós
void encerra_lista(){
    no* ant = ptlista->prox;
    no* pont = ant->prox;

    while(pont != NULL){
        free(ant);
        ant = pont;
        pont = pont->prox;
    }
    free(ant);

    free(ptlista);
}


//recebe chave a ser buscada
//recebe ant, ponteiro anterior a posição encontrada
//recebe pont, aponta para a posição encontrada
//busca pelo valor de chave passado dentro da lista encadeada
void busca_enc(int chave, no** ant, no** pont){
    *ant = ptlista;
    *pont = NULL;
    no* ptr = ptlista->prox;
    while(ptr != NULL){
        if(ptr->chave < chave){
            *ant = ptr;
            ptr = ptr->prox;
        }else{ 
            if (ptr->chave == chave) {
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}


//recebe chave a ser inserida
//recebe valor a ser inserido
//-1 = falha e 0 = sucesso
//realiza inserção da lista encadeada ordenada sem repetições
int insere_enc(int chave, int valor){
    int retorno = -1;
    no* ant;
    no* pont;
    busca_enc(chave, &ant, &pont);

    if( pont == NULL){
        no * ptr = new(no);
        ptr->chave = chave;
        ptr->valor = valor;
        ptr->prox = ptlista->prox;
        ptlista->prox = ptr;
        retorno = 0;
    }else{}

    return retorno;
}


//recebe chave do elemento a ser removido
//nulo em caso de lista vazia ou elemento inexistente, ou no do elemento removido
//realiza a remoção do elemento passado caso ele exista na lista encadeada
int remove_enc(int chave){
    int retorno = NULL;
    no* ant;
    no* pont;
    busca_enc(chave, &ant, &pont);
    if(pont != NULL){
        ant->prox = pont->prox;
        printf("entrou .......... ");
        free(pont);
        retorno = 0;

    }
    return retorno;

}


//imprime a lista encadeada
void imprime(){
    no* ptr = ptlista->prox;
    while(ptr != NULL){
        printf("chave, valor : (%d, %d)\n", ptr->chave,  ptr->valor);
        printf("---------------------\n");

        ptr = ptr->prox;
    }
}


int main(){
    
    ptlista = inicia_lista();


printf("<---------------------------->\n");
printf("1\n");
printf("valor retornado %d\n", insere_enc(1, 5));
imprime();

printf("2\n");
printf("valor retornado %d\n", insere_enc(2, 10));
imprime();

printf("3\n");
printf("valor retornado %d\n", insere_enc(3, 15));
imprime();

printf("4\n");
printf("resultado de remocao %d\n\n", remove_enc(2));
imprime();

printf("5\n");
printf("valor retornado %d\n", insere_enc(2, 10));
imprime();

printf("<---------------------------->\n");





    encerra_lista();





    return (EXIT_SUCCESS);
}