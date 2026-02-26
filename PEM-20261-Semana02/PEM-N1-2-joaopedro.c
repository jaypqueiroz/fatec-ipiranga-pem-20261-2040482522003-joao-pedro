#include <stdio.h>
#include <string.h>

int main() {

    char frase[100];
    int i = 0; 
    int palavras = 0; 
    int tamanho = 0;

    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);

    tamanho = strlen(frase);

    if (frase[tamanho - 1] == '\n') {
        frase[tamanho - 1] = '\0';
        tamanho--;
    }

    for (i = 0; i < tamanho; i++) {

        if (i == 0 && frase[i] != ' ') {
            palavras++;
        }

        if (frase[i] == ' ' && frase[i + 1] != ' ' &&  frase[i + 1] != '\0') {
            palavras++;
        }
    }

    printf("Total de palavras: %d\n", palavras);

    return 0;
}