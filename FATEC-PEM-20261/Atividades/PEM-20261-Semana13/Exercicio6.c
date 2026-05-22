/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa mexe com campos de struct usando ponteiros.
A gente faz o teste de duas formas: primeiro usando a 
sintaxe de asterisco com ponto, e depois repetindo o 
processo com o operador de seta (->) para comparar os dois.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[40];
    float preco;
    int estoque;
};

int main(){

    struct Produto item;
    struct Produto *ptr = &item;
    
    //Usando apenas desreferenciacao (*) e ponto (.) 
    
    strcpy((*ptr).nome, "Teclado");
    (*ptr).preco = 89.90;
    (*ptr).estoque = 15;

    printf("TESTE 1 (Usando * e .):\n");
    printf("Nome: %s\nPreco: %.2f\nEstoque: %d\n\n", (*ptr).nome, (*ptr).preco, (*ptr).estoque);


    //Repetindo o processo com o operador seta (->) 
    
    strcpy(ptr->nome, "Mouse Gamer");
    ptr->preco = 120.50;
    ptr->estoque = 30;

    printf("TESTE 2 (Usando seta ->):\n");
    printf("Nome: %s\nPreco: %.2f\nEstoque: %d\n", ptr->nome, ptr->preco, ptr->estoque);

    /*
    Comparacao do codigo produzido:
    
    No primeiro teste, os parenteses em (*ptr).nome sao obrigatorios 
    porque o ponto (.) tem mais prioridade que o asterisco (*). Se deixar 
    sem parenteses, o compilador tenta caçar o campo dentro do ponteiro 
    em si e nao no dado apontado, quebrando o codigo.
    
    Ja no segundo teste, o operador seta (->) deixa a escrita muito mais 
    simples e direta. Ele faz exatamente a mesma coisa que a primeira 
    sintaxe por baixo dos panos, mas economiza os parenteses e limpa o visual.
    */

    return 0;
}