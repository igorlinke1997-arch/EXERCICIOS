#include <stdio.h>

// Imprime vetor
void imprimir(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Copia vetor
void copiar(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

// 🔵 Bubble Sort
void bubbleSort(int v[], int n, int *comp, int *trocas) {
    *comp = 0;
    *trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

// 🟢 Selection Sort
void selectionSort(int v[], int n, int *comp, int *trocas) {
    *comp = 0;
    *trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
            (*trocas)++;
        }
    }
}

int main() {
    printf("==== ATIVIDADE 4 ====\n\n");

    int original[] = {9,8,7,6,5,4,3,2,1};
    int n = 9;

    int vBubble[9], vSelection[9];
    int compB, trocasB;
    int compS, trocasS;

    copiar(original, vBubble, n);
    copiar(original, vSelection, n);

    printf("Vetor original: ");
    imprimir(original, n);
    printf("\n");

    // Bubble
    bubbleSort(vBubble, n, &compB, &trocasB);
    printf("Bubble Sort:\n");
    imprimir(vBubble, n);
    printf("Comparacoes: %d\n", compB);
    printf("Trocas: %d\n\n", trocasB);

    // Selection
    selectionSort(vSelection, n, &compS, &trocasS);
    printf("Selection Sort:\n");
    imprimir(vSelection, n);
    printf("Comparacoes: %d\n", compS);
    printf("Trocas: %d\n\n", trocasS);

    // Comparação final
    printf("==== COMPARACAO FINAL ====\n");
    printf("Bubble -> Comparacoes: %d | Trocas: %d\n", compB, trocasB);
    printf("Selection -> Comparacoes: %d | Trocas: %d\n", compS, trocasS);

    return 0;
}