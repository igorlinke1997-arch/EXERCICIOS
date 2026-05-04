#include <stdio.h>

// Função auxiliar para imprimir o vetor formatado
void imprimirVetor(int senhas[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%02d", senhas[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Função do Bubble Sort
void bubbleSortRaioX(int senhas[], int tamanho) {
    printf("Estado inicial da fila: ");
    imprimirVetor(senhas, tamanho);
    printf("\n");

    // Laço externo: controla as passadas
    for (int i = 0; i < tamanho - 1; i++) {

        // Laço interno: faz as comparações
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (senhas[j] > senhas[j + 1]) {
                int aux = senhas[j];
                senhas[j] = senhas[j + 1];
                senhas[j + 1] = aux;
            }
        }

        // Imprimindo estado após cada passada
        printf("Passo %d: ", i + 1);
        imprimirVetor(senhas, tamanho);
        printf("\n");
    }
}
