#include "controle.h"

//aloca novo n�
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->Chave = x;
        novo->pEsq = NULL;
        novo->pDir = NULL;
        novo->FatBal = 0;
    }
    else
        printf("\nN�o foi possivel alocar um novo no!\n");
    return novo;
}

//Retorna a altura de um n� ou -1 caso ele seja nulo
int altura(No *no){
    if(no == NULL){
        return 0;
    }
    else{
        int esq = altura( no->pEsq );
        int dir = altura( no->pDir );
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

//Calcula e salva o fator de balanceamento de um n�
void fatorDeBalanceamento(No *no){	
    no->FatBal = (altura(no->pEsq) - altura(no->pDir));    
}

//passa por cada n� para ser impresso em ordem
void imprimir(No *no, int nivel){
    int i;
    if(no){
        imprimir(no->pEsq, nivel + 1);
        printf("\n\n");
        printf("Chave: %d FB: %d", no->Chave, no->FatBal);
        imprimir(no->pDir, nivel + 1);
    }
}

//passa por cada n� para salvar o FB
void salvaFator(No *no){
    if(no){
        salvaFator(no->pDir);
        fatorDeBalanceamento(no);
        salvaFator(no->pEsq);
    }
}

//desalocar cada um dos nos
void desaloca(No *no){
    if(no){
        desaloca(no->pDir);
        desaloca(no->pEsq);
        free(no);
    }
}

//fun��o cria a arvore e retorna
No* criaArvore(No *no, int x){
    if(no == NULL) 
        return novoNo(x);
    else{ 
        if(x < no->Chave)
            no->pEsq = criaArvore(no->pEsq, x);
        else if(x > no->Chave)
            no->pDir = criaArvore(no->pDir, x);
        else
            printf("\nElemento %d ingnorado pois j� existe.\n", x);
    }
    return no;
}


