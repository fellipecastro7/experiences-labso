#include <stdio.h>

int main() {
    int i;
    int c;
    int processos[20];
    int numProcessos;
    int timeSlice;
    int maior;

    printf("Informe o time slice do CPU: ");
    scanf("%d", &timeSlice);

    printf("Informe a quantidade de processos da fila: ");
    scanf("%d", &numProcessos);

    for(i = 1; i <= numProcessos; i++) {
        printf("Informe o tempo de execução do processo P%d: ", i);
        scanf("%d", &processos[i - 1]);
    }

    printf("\n");

    i = i - 1;

    for(c = 0; c < i; c++) {
        if(c == 0){
            maior = processos[0];
        }

        else {
            if(processos[c] > maior) {
                maior = processos[c];
            }
        }
    }

    while(maior != 0) {
        for(c = 0; c < i; c++) {
            if(processos[c] > timeSlice) {
                printf("P%d, %d; ", c + 1, timeSlice);
                processos[c] = processos[c] - timeSlice;
            }
          
            else {
                if(processos[c] <= timeSlice & processos[c] != 0) {
                    printf("P%d, %d*; ", c + 1, processos[c]);
                    processos[c] = 0;
                }
            }
        }

        printf("\n");

        maior = maior - timeSlice;

        if(maior < 0) {
            maior = 0;
        }
    }
}