#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void cleanBuffer(); 

int main() {
    char *buff, fn[10]; 
    int fd, n;

    buff = malloc(100);

    printf("Entre com o nome de um arquivo novo:\n");
    scanf("%s", fn);

    cleanBuffer();

    printf("Entre com o texto que será inserido nesse arquivo novo:\n");
    fgets(buff, 100, stdin);

    fd = open(fn, O_CREAT | O_WRONLY, 0777);
    n = write(fd, buff, strlen(buff));
    close(fd);
    free(buff);

    printf("\n\nVeja o conteúdo do arquivo criado\n");

    return 0;
}

void cleanBuffer() {
    int ch;

    while((ch = getchar()) != EOF && ch != '\n') {
        
    }
}