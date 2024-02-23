#include <stdio.h>

int executaRoundRobin(int processos[20], int numProcesso, int timeSlice) {
    int maior;

    printf("\n");

    for(int c = 0; c < numProcesso; c++) {
        if(c == 0) {
            maior = processos[0];
        }

        else {
            if(processos[c] > maior) {
                maior = processos[c];
            }
        }
    }

    while(maior != 0) {
        for(int c = 0; c < numProcesso; c++) {
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

int main() {
    int timeSlice;
    int numProcessosAltaPrioridade;
    int numProcessosBaixaPrioridade;
    int processosAltaPrioridade[20];
    int processosBaixaPrioridade[20];

    printf("Informe a quantidade de processos com prioridade: ");
    scanf("%d", &numProcessosAltaPrioridade);

    printf("Informe a quantidade de processos sem prioridade: ");
    scanf("%d", &numProcessosBaixaPrioridade);

    printf("\nLista de processos com prioridade:\n");

    for(int i = 1; i <= numProcessosAltaPrioridade; i++) {
        printf("\tInforme o tempo de execução do processo P%d: ", i);
        scanf("%d", &processosAltaPrioridade[i - 1]);
    }

    printf("\nLista de processos sem prioridade:\n");

    for(int i = 1; i <= numProcessosBaixaPrioridade; i++) {
        printf("\tInforme o tempo de execução do processo P%d: ", i);
        scanf("%d", &processosBaixaPrioridade[i - 1]);
    }

    printf("\nInforme o time slice do CPU: ");
    scanf("%d", &timeSlice);

    for(int i = 0; i < numProcessosAltaPrioridade; i++) {
        if(processosAltaPrioridade[i] != 0) {
            printf("\nAlta prioridade!!!\n");
            executaRoundRobin(processosAltaPrioridade, numProcessosAltaPrioridade, timeSlice);
        }

        else {
            for(int c = 0; c < numProcessosBaixaPrioridade; c++){
                if(processosBaixaPrioridade[i] != 0) {
                    printf("\nBaixa prioridade!!!\n");
                    executaRoundRobin(processosBaixaPrioridade, numProcessosBaixaPrioridade, timeSlice);
                }
            }
        }
    }
}