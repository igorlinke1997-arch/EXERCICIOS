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

// Função de partição (igual Atividade 7)
int particao(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    // Coloca o pivô no lugar correto
    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1; // posição do pivô
}

// 🔁 Quick Sort recursivo
void quickSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int posPivo = particao(v, inicio, fim);

        quickSort(v, inicio, posPivo - 1); // esquerda
        quickSort(v, posPivo + 1, fim);    // direita
    }
}

int main() {
    printf("==== ATIVIDADE 8 ====\n\n");

    int cpfs[] = {4321, 1111, 9999, 3333, 7777, 2222, 5555};
    int n = 7;

    printf("Vetor original: ");
    imprimir(cpfs, n);

    quickSort(cpfs, 0, n - 1);

    printf("\nVetor ordenado: ");
    imprimir(cpfs, n);

    return 0;
}