#include <stdio.h>

int comparacoes = 0;
int chamadas = 0;

// Função de partição (Lomuto)
int particao(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        comparacoes++; // contando comparações

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

// Quick Sort
void quickSort(int v[], int inicio, int fim) {
    chamadas++; // contando chamadas recursivas

    if (inicio < fim) {
        int p = particao(v, inicio, fim);

        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}

int main() {
    printf("==== ATIVIDADE 9 ====\n\n");

    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    quickSort(v, 0, n - 1);

    printf("Comparacoes: %d\n", comparacoes);
    printf("Chamadas recursivas: %d\n", chamadas);

    return 0;
}
