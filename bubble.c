#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // troca
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                trocou = 1;
            }
        }
        if (trocou == 0)
            break;
    }
}

int main() {
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int i;

    printf("Antes: ");
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    bubbleSort(numeros, n);

    printf("\nDepois: ");
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}