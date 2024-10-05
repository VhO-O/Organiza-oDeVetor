#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define A 300

void embaralharVet(int *v);
void imprimirVet(int *v);
int buscaSequencial(int *v, int valor);
void bubbleSort(int *v);
void selectionSort(int *v);
int buscaBinaria(int *v, int valor);
void menu();

int main(){
    setlocale(LC_ALL,"Portuguese");
    int v1[A], v2[A], v3[A];
    int op;
    int on = 1;
    int valor;
    int result;

    do{
        menu();
        printf("Digite a opção que deseja selecionar: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            embaralharVet(v1);
            break;
        case 2:
            embaralharVet(v2);
            break;
        case 3:
            embaralharVet(v3);
            break;
        case 4:
            imprimirVet(v1);
            break;
        case 5:
            imprimirVet(v2);
            break;
        case 6:
            printf("\nDigite o valor que deseja buscar: ");
            scanf("%d", &valor);
            result = buscaSequencial(v1, valor);
            if(result != -1){
                printf("\nO valor %d foi encontrado no indice %d do vetor 1", valor, result);
            } else {
                printf("\nO valor %d não foi encontrado no vetor 1", valor);
            }
            break;
        case 7:
            bubbleSort(v1);
            printf("\nVetor ordenado com sucesso!\n");
            printf("\n[ ");
            for(int i=0;i<A;i++){
                printf("%d ", v1[i]);
            }
            printf("]\n");
            break;
        case 8:
            selectionSort(v2);
            printf("\nVetor ordenado com sucesso\n");
            printf("\n[ ");
            for(int i=0;i<A;i++){
                printf("%d ", v2[i]);
            }
            printf(" ]\n");
            break;
        case 9:
            printf("\nDigite o valor que deseja buscar: ");
            scanf("%d", &valor);
            result = buscaBinaria(v2,valor);
            if(result != -1){
                printf("\nO valor %d foi encontrado no indice %d do vetor 2", valor, result);
            } else {
                printf("\nO valor %d não foi encontrado no vetor 2", valor);
            }
            break;
        case 10:
            on = 0;
            break;
        default:
            printf("\nDigite um valor valido!\n");
        }
    }while(on);

    return 0;
}

void menu(){
    printf("\n\n===================================================\n");
    printf("1. Preencher aleatoriamente o primeiro vetor\n2. Preencher aleatoriamente o segundo vetor");
    printf("\n3. Preencher aleatoriamente o terceiro vetor\n4. Imprimir Vetor1\n5. Imprimir Vetor2");
    printf("\n6. Busca Sequencial - (vetor1)\n7. Ordenação por bubbleSort - (vetor1)");
    printf("\n8. Ordenação por seleção - (vetor2)\n9. Busca Binária - (vetor 2)\n10. Sair");
    printf("\n===================================================\n\n");
}

void embaralharVet(int *v) {
    srand(time(NULL));
    int n = A; 

    for(int i=0; i<n; i++){
        v[i] = i + 1;
    }

    for (int i=n-1; i > 0; i--) {
        int j = rand() % (i + 1); 
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }    
}

void imprimirVet(int *v){
    printf("%d: \n", v);
    printf("\n[ ");
        for(int i=0;i<A;i++){
        printf("%d ", v[i]);
    }
    printf(" ]\n");
}

// Busca linear
int buscaSequencial(int *v, int valor){
    for(int i=0;i<A;i++){
        if(v[i]==valor){
            return i;
        }
    }
    return -1;
}

void bubbleSort(int *v){
    int n = A;

    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(v[j]>v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp; 
            }
        }
    }
}

void selectionSort(int *v){
    int n = A;

    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[min]){
                min=j;
            }
        }
        int temp = v[min];
        v[min] = v[i];
        v[i] = temp;
    }
}

int buscaBinaria(int *v, int valor){
    int inicio = 0;
    int fim = A;
    int media;

    while(inicio<=fim){
        media = (inicio + fim)/2;
        if(valor==v[media]){
            return media;
        } else if (valor<v[media]){
            fim = media - 1;
        } else {
            inicio = media + 1;
        }
    }
}