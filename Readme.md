### A mais simples delas é usar um vetor de nós

```c

typedef struct NO;

```
</br>

### Dessa forma, cada nó possui pelo menos três valores

```c

typedef struct NO {
	int dado; // É relevante estabelecer um atributo "dado" que irá armazenar o conteúdo do nó.
	struct NO *pai; // referência para o pai do nó
	struct NO *esq; // referência para o filho à esquerda do nó
	struct NO *dir; // referência para o filho à direita do respectivo nó.
} NO;

```

- O atributo "pai" vai apontar para a posição na qual o pai do nó se encontra, no vetor.

- O atributo "esquerda" vai armazenar a posição da raiz da sub-árvore à esquerda do nó.

- O atributo "direita" guarda a posição da raiz da sub-árvore direita do nó, no vetor.

</br>

### Sempre que um novo dado estiver para ser adicionado junto à árvore, ele será comparado com o nó raiz. Se ele é menor do que a raiz, deverá ser adicionado na sub-árvore esquerda, caso contrário na sub-árvore direita.
 
- Considere que, no seu primeiro estágio, ao realizar um teste no seu programa que implementa árvores binárias, você inseriu os números de seu RA (da esquerda para a direita) como se cada algarismo fosse um nó na árvore


```c

  //Valores menores -> esquerda
  //Valores maiores ou iguais -> direita

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

```

</br>

* **Dessa forma, altere o código-fonte dado para que seu programa, durante a execução, monte uma árvore binária a partir dos dígitos de seu RA.**

```c

  typedef struct ARVORE{
    NO *raiz;
  }ARVORE;

```

* O seu programa não deve realizar a inserção automaticamente ordenada, ou seja, não é preciso desenvolver um método que realize a inserção ordenadamente.

* Você mesmo pode construir a árvore (via inserções simples, porém seguindo as regras de inserção ordenada), de maneira a compor a árvore ordenada com os números de seu RA.

- **Criar uma função que seja capaz de realizar o percurso pré-ordem na árvore recém-criada, partindo da raiz e imprimindo na tela os nós visitados de acordo com esse método**.

```c

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

```

</br>

* Por exemplo, considere que seu RA é igual a 61207895. Abaixo temos um exemplo de como sua árvore ordenada deveria ser, bem como o resultado do caminhamento pré-ordem quando executado a partir da raiz da respectiva árvore.
 
* Visitação pré-ordem: 6 1 0 2 7 5 8 9