#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <math.h>
#include "estatistica.h"

void rol(double num[MAX_NUM], int qtd) {
	for (int m = 0; m < qtd; m++) {
		for (int n = 0; n < qtd - m - 1; n++) {
			if (num[n + 1] < num[n]) {
				double aux;
				aux = num[n];
				num[n] = num[n + 1];
				num[n + 1] = aux;
			}
		}
	}
}

double CalculoMedia(double num[MAX_NUM], int qtd) {
	double soma = 0;
	for (int i = 0; i < qtd; i++) {
		soma += num[i];
	}
	return soma / qtd;
}

double CalculoMediana(double num[MAX_NUM], int qtd) {
	int indice;
	double mediana;
	if ((qtd % 2) == 0) {
		indice = qtd / 2;
		mediana = (num[indice] + num[indice - 1]) / 2;
	}
	else {
		indice = (qtd - 1) / 2;
		mediana = num[indice];
	}
	return mediana;
}

int CalculoModa(double num[MAX_NUM], int qtd) {
	int repeticao[MAX_NUM] = {0}, maxRepeticao = 0, indiceModa = 0;
	for (int i = 0; i < qtd; i++) {
		for (int j = 0; j < qtd; j++) {
			if (num[i] == num[j]) {
				repeticao[i]++;
			}
		}
	}
	
	for (int i = 0; i < qtd; i++) {
		if (repeticao[i] > maxRepeticao) {
			maxRepeticao = repeticao[i];
			indiceModa = i;
		}
	}
	return indiceModa;
}

double CalculoAmplitude(double num[MAX_NUM], int qtd) {
	return num[qtd - 1] - num[0];
}

double CalculoVariancia(double num[MAX_NUM], int qtd, double media) {
	double somatoria = 0;
	for (int i = 0; i < qtd; i++) {
		somatoria += pow(num[i] - media, 2);
	}
	return somatoria / (qtd - 1);
}

double CalculoDesvio(double variancia) {
	return sqrt(variancia);
}

double CalculoCoeficienteVariacao(double desvPadrao, double media) {
	return desvPadrao / media;
}
