#include <stdio.h>

int main() {
    int vet[5] = {82, 45, 12, 78, 23};
    int i, j, temp;

    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - 1 - i; j++) {
            if (vet[j] > vet[j + 1]) {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }

        printf("Passo %d: ", i + 1);
        for (int k = 0; k < 5; k++) {
            printf("%d ", vet[k]);
        }
        printf("\n");
    }

    return 0;
}