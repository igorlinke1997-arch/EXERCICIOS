#include <stdio.h>

// Função para imprimir o vetor
void imprimirVetor(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void insertionSortRaioX(int v[], int n) {
    int comparacoes = 0;

    printf("Estado inicial: ");
    imprimirVetor(v, n);

    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        // Move os maiores pra frente
        while (j >= 0) {
            comparacoes++; // contando o teste do if

            if (v[j] > chave) {
                v[j + 1] = v[j];
                j--;
            } else {
                break; // para cedo (otimização natural do insertion)
            }
        }

        v[j + 1] = chave;

        printf("Passo %d: ", i);
        imprimirVetor(v, n);
    }

    printf("\nTotal de comparações: %d\n", comparacoes);
}

int main() {
    printf("==== ATIVIDADE 3 ====\n");
    printf("Insertion Sort - caso quase ordenado\n\n");

    int pagamentos[] = {101, 102, 103, 104, 105, 99};
    int n = 6;

    insertionSortRaioX(pagamentos, n);

    return 0;
}