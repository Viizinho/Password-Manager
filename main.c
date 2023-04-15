#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int len; // comprimento da senha

    printf ("Insira o número de caracteres: "); scanf ("%d", &len);
    
    char password[len + 1]; // +1 para o caractere nulo no final da string
    
    // inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));
    
    // gera a senha
    for (i = 0; i < len; i++) {
        int random_char = rand() % 62;
        if (random_char < 10) {
            password[i] = random_char + '0'; // dígitos numéricos
        } else if (random_char < 36) {
            password[i] = random_char - 10 + 'A'; // letras maiúsculas
        } else {
            password[i] = random_char - 36 + 'a'; // letras minúsculas
        }
    }
    
    password[len] = '\0'; // adiciona o caractere nulo no final da string
    
    printf("Senha gerada: %s\n", password);
    
    return 0;
}