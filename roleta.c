#include <stdio.h>
#include "roleta.h"

// Inicializa o tabuleiro com os devidos números
void inicializar_tabuleiro(int **tabuleiro)
{
    int cont = 1;
    for (int j = 0; j < 13; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j == 0)
            {
                tabuleiro[i][j] = 0;
            }
            else
            {
                tabuleiro[i][j] = cont;
                cont++;
            }
        }
    }
}
void fazer_aposta()
{
}
void girar_roleta()
{
}
void distribuir_premios()
{
}
void destruir_roleta()
{
}