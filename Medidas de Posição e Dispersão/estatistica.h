#ifndef ESTATISTICA_H
#define ESTATISTICA_H

#define MAX_NUM 100

// FUNÇÃO PARA ORDENAR NÚMEROS

void rol(double num[MAX_NUM], int qtd);

// FUNÇÕES DE MEDIDAS DE POSIÇÃO

double CalculoMedia(double num[MAX_NUM], int qtd);
double CalculoMediana(double num[MAX_NUM], int qtd);
int CalculoModa(double num[MAX_NUM], int qtd);

// FUNÇÕES DE MEDIDAS DE DISPERSÃO

double CalculoAmplitude(double num[MAX_NUM], int qtd);
double CalculoVariancia(double num[MAX_NUM], int qtd, double media);
double CalculoDesvio(double variancia);
double CalculoCoeficienteVariacao(double desvPadrao, double media);

#endif
