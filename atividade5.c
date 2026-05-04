#include <stdio.h>

// Função merge
void merge(int v1[], int n1, int v2[], int n2, int resultado[]) {
    int i = 0, j = 0, k = 0;

    // Enquanto houver elementos nos dois vetores
    while (i < n1 && j < n2) {
        if (v1[i] < v2[j]) {
            resultado[k] = v1[i];
            i++;
        } else {
            resultado[k] = v2[j];
            j++;
        }
        k++;
    }

    // Copiar o que sobrou do v1
    while (i < n1) {
        resultado[k] = v1[i];
        i++;
        k++;
    }

    // Copiar o que sobrou do v2
    while (j < n2) {
        resultado[k] = v2[j];
        j++;
        k++;
    }
}

// Função para imprimir vetor
void imprimir(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("==== ATIVIDADE 5 ====\n\n");

    int norte[] = {20, 40, 60};
    int sul[]   = {10, 30, 50, 70};

    int resultado[7];

    printf("Escola Norte: ");
    imprimir(norte, 3);

    printf("Escola Sul: ");
    imprimir(sul, 4);

    merge(norte, 3, sul, 4, resultado);

    printf("\nResultado (Merge): ");
    imprimir(resultado, 7);

    return 0;
}