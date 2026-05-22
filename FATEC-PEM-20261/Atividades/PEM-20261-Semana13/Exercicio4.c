/*
---------------------------------------------------------
                    FATEC Ipiranga                       *
 Disciplina: Programaçao Estruturada e Modular           *
       Prof. Veríssimo                                   *
----------------------------------------------------------
                                                         *
O programa demonstra como estruturas (struct) são        *
organizadas na memória. Ele cria uma estrutura do        *
tipo Aluno, mostra os endereços de memória de seus campos*
e calcula a distância, em bytes, entre eles, permitindo  *
observar como os dados são armazenados internamente.     *
                                                         *
Data - 20/05/2026                                        * 
Autor: João Pedro de Queiroz Leite                       *
RA: 2040482522003                                        *
---------------------------------------------------------/
*/

#include <stdio.h>
#include <string.h>

// Definição da estrutura Aluno
struct Aluno{
    // Vetor de caracteres para armazenar o nome (50 bytes)
    char nome[50];

    // Número de matrícula do aluno (4 bytes)
    int matricula;

    // Média do aluno (4 bytes)
    float media;
};

int main(){

    // Declaração de uma variável do tipo struct Aluno
    struct Aluno dados;

    // Copia a string "João Pedro" para o campo nome
    strcpy(dados.nome, "Joao Pedro");

    // Atribui valores aos demais campos da struct
    dados.matricula = 12341234;
    dados.media = 7.5;

    // Exibe os endereços de memória dos campos da struct
    printf("ENDERECOS\n\nnome: %p\nmatricula: %p\nmedia: %p",
           &dados.nome, &dados.matricula, &dados.media);

    // Calcula a distância em bytes entre os campos da estrutura
    // O cast para char* permite a subtração byte a byte
    printf("\n\n\nDISTANCIA ENDERECO\n\ndistancia entre nome e n matricula: %td",
           (char*)&dados.matricula - (char*)&dados.nome);

    printf("\n\ndistancia entre matricula e media: %td\n",
           (char*)&dados.media - (char*)&dados.matricula);

    /*
    ======================================================================
    EXPLICAÇÃO:
    ======================================================================
    Os endereços dos campos de uma struct são sequenciais, porém nem sempre 
    são perfeitamente consecutivos (ou seja, a distância entre eles pode ser 
    maior do que o tamanho estrito dos tipos de dados). 
    
    Isso ocorre devido ao alinhamento de memória (Memory Alignment) e ao 
    preenchimento de bytes extras (Padding) adicionados pelo compilador.
    
    Por exemplo: O vetor 'nome' ocupa exatamente 50 bytes. No entanto, o 
    próximo campo ('matricula') é do tipo int (4 bytes), que requer um 
    alinhamento em posições de memória múltiplas de 4. Para otimizar o acesso 
    do processador, o compilador insere automaticamente 2 bytes fantasmas 
    (padding) após o término do vetor 'nome'. Dessa forma, a distância entre 
    o início do nome e a matrícula passa a ser de 52 bytes em vez de 50.
    ======================================================================
    */

    return 0;
}