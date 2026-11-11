#ifndef __ROLETA__
#define __ROLETA__

// roleta:
// Tabuleiro de 0 a 36
// Sorteia um número aleatório entre 0 e 36

// Jogadores podem apostar em:
// Número especifico: paga 36 para 1
// Colunas: 3 para 1
// Pretos e vermelhos: 1 para 1
// Par ou impar: 1 para 1
// Altas ou baixas: 1 para 1

// struct roleta{
// };
int **inicializar_tabuleiro();
void fazer_aposta();
void girar_roleta();
void distribuir_premios();
void destruir_roleta();
#endif