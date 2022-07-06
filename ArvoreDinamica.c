#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes
#define E 0
#define D 1
#define R -1

//Tipo n�
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

//Tipo �rvore
typedef struct ARVORE{
	NO *raiz;
}ARVORE;

//Declara��o da �rvore
ARVORE a;

//Prot�tipos das fun��es
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);
void emOrdem(NO* raiz);
void posOrdem(NO* raiz);

//Fun��o que sempre deve ser chamada ao se criar uma nova �rvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Fun��o utilizada para inicializar um novo n� na �rvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

//Fun��o que realiza a inser��o de maneira ordenada
//Valores menores  v�o � esquerda
//Valores maiores ou iguais v�o � direita
void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserindo no %d. \n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("No inserido na raiz. \n");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("No inserido � esquerda do no %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido � direita do no %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

/*
Criar uma função que seja capaz de realizar o percurso pré-ordem na árvore recém-criada,
partindo da raiz e imprimindo na tela os nós visitados de acordo com esse método.
*/
void preOrdem(NO* raiz)
{
	if(raiz == NULL)
	{
		printf("Arvore vazia.\n");
		return;
	}
	printf("%d ", raiz->dado);
	preOrdem(raiz->esq);
	preOrdem(raiz->dir);
}


//Executa o caminhamento em-ordem a partir do n� indicado por "raiz"
void emOrdem(NO* raiz){
	if(raiz){
		emOrdem(raiz->esq);
		printf("%d \t", raiz->dado);
		emOrdem(raiz->dir);
	}
}

//Executa o caminhamento pos-ordem a partir do n� indicado por "raiz"
void posOrdem(NO* raiz){
	if(raiz){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d \t", raiz->dado);
	}
}

int main()
{
	inicializaArvore(a);
	
	insereNoArvoreOrdenada(10);
	insereNoArvoreOrdenada(15);
	insereNoArvoreOrdenada(5);
	insereNoArvoreOrdenada(3);
	insereNoArvoreOrdenada(7);
	insereNoArvoreOrdenada(12);
	insereNoArvoreOrdenada(17);
	
	printf("\nBusca em ordem: \n");
	emOrdem(a.raiz);
	
	printf("\nBusca pre ordem: \n");
	preOrdem(a.raiz);
	
	printf("\nBusca pos ordem: \n");
	posOrdem(a.raiz);
}

