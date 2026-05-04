#include <stdio.h>

// ---------- imprimir ----------
void imprimir(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// ---------- Insertion Sort ----------
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// ---------- Partição (Quick Sort) ----------
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

    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

// ---------- Quick Sort ----------
void quickSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}

// ---------- SUPER SORT ----------
void super_sort(int v[], int n) {
    if (n < 10) {
        printf("Usando Insertion Sort (vetor pequeno)\n");
        insertionSort(v, n);
    } else {
        printf("Usando Quick Sort (vetor grande)\n");
        quickSort(v, 0, n - 1);
    }
}

// ---------- MAIN ----------
int main() {
    printf("==== ATIVIDADE 10 ====\n\n");

    // Teste 1: vetor pequeno (8 posições)
    int v1[] = {9, 3, 7, 1, 8, 2, 5, 4};
    int n1 = 8;

    printf("Vetor pequeno:\n");
    imprimir(v1, n1);
    super_sort(v1, n1);
    printf("Resultado: ");
    imprimir(v1, n1);

    printf("\n----------------------\n\n");

    // Teste 2: vetor grande (15 posições)
    int v2[] = {45, 12, 78, 34, 23, 90, 11, 67, 56, 89, 10, 5, 99, 2, 1};
    int n2 = 15;

    printf("Vetor grande:\n");
    imprimir(v2, n2);
    super_sort(v2, n2);
    printf("Resultado: ");
    imprimir(v2, n2);

    return 0;
}