#include <stdio.h>
#include <stdlib.h>
#include "roleta.h"

// Cores da roleta:
// 0: preto
// 1: vermelho
// 2: verde

// Inicializa o tabuleiro com os devidos números
void inicializar_tabuleiro(struct quadrado **tabuleiro)
{
    int pretas[18]= {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24,26, 28, 29,31,33,35};
    int cont = 1;
    for (int j = 0; j < 13; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j == 0)
            {
                tabuleiro[i][j].valor = 0;
                tabuleiro[i][j].cor = 2;
            }
            else
            {
                tabuleiro[i][j].valor = cont;
                cont++;
            }
        }
    }
}

int aposta_numero_unico(struct aposta *apst) 
{

}

int aposta_cor(struct aposta *apst) {

}

int aposta_paridade(struct aposta *apst)
{

}

int fazer_aposta(struct aposta *apst)
{

}
int girar_roleta()
{

    return (rand() % 37);

}
void distribuir_premios()
{
}
void destruir_roleta()
{
}