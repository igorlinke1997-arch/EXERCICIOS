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

int main() {
    printf("==== ATIVIDADE 7 ====\n\n");

    int v[] = {300, 150, 800, 200, 900, 500};
    int n = 6;

    int pivo = v[n - 1]; // último elemento
    int i = -1;

    printf("Vetor original: ");
    imprimir(v, n);

    // 🔥 Laço de particionamento (Lomuto)
    for (int j = 0; j < n - 1; j++) {
        if (v[j] < pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    int temp = v[i + 1];
    v[i + 1] = v[n - 1];
    v[n - 1] = temp;

    printf("\nDepois do particionamento (pivo = %d):\n", pivo);
    imprimir(v, n);

    return 0;
}