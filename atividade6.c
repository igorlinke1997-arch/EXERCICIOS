#include <stdio.h>

// Função para imprimir vetor
void imprimir(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Função merge (da atividade 5)
void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int temp[100]; // vetor auxiliar

    while (i <= meio && j <= fim) {
        if (v[i] < v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = v[i++];
    }

    while (j <= fim) {
        temp[k++] = v[j++];
    }

    // Copiar de volta
    for (i = inicio, k = 0; i <= fim; i++, k++) {
        v[i] = temp[k];
    }
}

// Merge Sort recursivo
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        printf("Dividindo...\n");

        int meio = (inicio + fim) / 2;

        mergeSort(v, inicio, meio);     // esquerda
        mergeSort(v, meio + 1, fim);    // direita

        merge(v, inicio, meio, fim);    // junta
    }
}

int main() {
    printf("==== ATIVIDADE 6 ====\n\n");

    int vetor[] = {44, 21, 98, 12, 55, 73, 31, 8};
    int n = 8;

    printf("Vetor original: ");
    imprimir(vetor, n);
    printf("\n");

    mergeSort(vetor, 0, n - 1);

    printf("\nVetor ordenado: ");
    imprimir(vetor, n);

    return 0;
}