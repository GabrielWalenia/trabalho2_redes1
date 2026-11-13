#ifndef __ROLETA__
#define __ROLETA__

// roleta:
// Tabuleiro de 0 a 36
// Sorteia um número aleatório entre 0 e 36

// Jogadores podem apostar em:
// Número especifico: paga 36 para 1
// Pretos e vermelhos: 1 para 1
// Par ou impar: 1 para 1
// Extras:
// Colunas: 3 para 1
// Altas ou baixas: 1 para 1

struct quadrado{
    int valor;
    int cor;
};

struct aposta {
    char tipo;
    int opcao;
    int fichas;
};

void inicializar_tabuleiro(struct quadrado **tabuleiro);
int fazer_aposta();
int girar_roleta();
void distribuir_premios();
void destruir_roleta();
#endif