#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int calculaFatorial(int);
void executaTorreHanoi(int, char, char, char);
int executaSerieFibonacci(int);
void executaProcessoPai();
void executaProcessoFilho();
void executaProcessoNeto();

int main() {
    pid_t pid;

    pid = fork();

    if(pid == 0) {
        pid_t otherPid;

        otherPid = fork();

        if(otherPid == 0) {
            executaProcessoNeto();
            exit(0);
        }

        else {
            executaProcessoFilho();
            wait(NULL);
            exit(0);
        }
    }

    else {
        executaProcessoPai();
    }

    return 0;
}

int calculaFatorial(int num) {
    int fatorial;

    fatorial = 1;

    if(num == 1) {
        return 1;
    }

    if(num >= 20) {
        printf("ERRO!\n");
        return -1;
    }

    for(int i = num; i != 1; i--) {
        fatorial *= i;
    }

    return fatorial;
}

void executaTorreHanoi(int discos, char ori, char dest, char aux) {
    if(discos == 1) {
        printf("\tDisco %d foi movido do pino %c para o pino %c\n", discos, ori, dest);
    }

    else {
        executaTorreHanoi(discos - 1, ori, aux, dest);
        printf("\tDisco %d foi movido do pino %c para o pino %c\n", discos, ori, dest);
        executaTorreHanoi(discos - 1, aux, dest, ori);
    }
}

int executaSerieFibonacci(int num) {
    int a, b;
    long aux;

    a = 0;
    b = 1;
    aux = 0;

    if(num == 1) {
        return 1;
    }

    for(int i = 1; i < num; i++) {
        aux = a + b;
        a = b;
        b = aux;
    }

    return aux;
}

void executaProcessoPai() {
    for(int i = 1; i <= 100; i++) {
        printf("Processo pai, PID = %d\n\t%d° termo de fibonnaci = %d\n", getpid(), i, executaSerieFibonacci(i));
    }
}

void executaProcessoFilho() {
    printf("Processo filho, PID = %d\n\tExecutando torre de Hanoi:\n", getpid());
    executaTorreHanoi(6, 'O', 'D', 'A');
}

void executaProcessoNeto() {
    printf("Processo neto, PID = %d\n\tCalculando fatorial de 5 = %d\n", getpid(), calculaFatorial(5));
}