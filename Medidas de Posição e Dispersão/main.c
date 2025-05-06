#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "estatistica.h"

int main() {
	setlocale(LC_ALL, "portuguese");
	double media, moda, mediana;
	double amplitude, desvPadrao, variancia, coeficienteVariacao;
	double valores[MAX_NUM];
	char continuar = 's';
	int quantidade;

	do {
		system("cls");
		printf("==============================================\n");
		printf("  *********  CÁLCULO  ESTATÍSTICO  *********  \n");
		printf("==============================================\n\n");

		printf("Digite a quantidade de números (máx. 100): ");
		do {
			if (scanf("%i", &quantidade) != 1) {
				printf("Erro, entrada inválida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
				quantidade = -1;
			}
			else {
				if (quantidade <= 0) {
					printf("Quantidade deve ser maior que 0!\nInsira outro valor: ");
				}
				else {
					if (quantidade > 100) {
						printf("A quantidade máxima de números é 100!\nInsira outro valor: ");
					}
				}
			}
			setbuf(stdin, NULL);
		} while (quantidade <= 0 || quantidade > 100);

		printf("\n-----------  Inserção dos Valores  -----------\n\n");

		for (int i = 0; i < quantidade; i++) {
			printf("Digite o %i° valor da amostra: ", i + 1);
			if (scanf("%lf", &valores[i]) != 1) {
				printf("Erro, entrada inválida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
				valores[i] = 0;
				i--;
			}
			setbuf(stdin, NULL);
		}

		// Realização das operações

		rol(valores, quantidade);
		media = CalculoMedia(valores, quantidade);
		mediana = CalculoMediana(valores, quantidade);
		moda = valores[CalculoModa(valores, quantidade)];

		amplitude = CalculoAmplitude(valores, quantidade);
		variancia = CalculoVariancia(valores, quantidade, media);
		desvPadrao = CalculoDesvio(variancia);
		coeficienteVariacao = CalculoCoeficienteVariacao(desvPadrao, media);

		printf("\n----------  Resultados das Medidas  ----------\n\n");

		printf("Valores organizados em rol: ");
		for (int i = 0; i < quantidade; i++) {
			printf("%.2lf ", valores[i]);
		}

		printf("\n\nMédia: %.2lf", media);
		printf("\nMediana: %.2lf", mediana);
		printf("\nModa: %.2lf", moda);

		printf("\n\nAmplitude: %.2lf", amplitude);
		printf("\nVariância: %.2lf", variancia);
		printf("\nDesvio Padrão: %.2lf", desvPadrao);
		printf("\nCoeficiente de Variação: %.2lf%%", coeficienteVariacao * 100);

		(void)_getch();
		
		printf("\n\n----------  Reiniciar ou Finalizar  ----------\n\n");

		printf("Fazer um novo cálculo? (S / N): ");
		do {
			if (scanf("%c", &continuar) != 1) {
				printf("Erro, entrada inválida!\nInsira outro valor: ");
				setbuf(stdin, NULL);
				continuar = '\0';
			}
			else {
				continuar = toupper(continuar);
				if (continuar != 'S' && continuar != 'N') {
					printf("\nResponda \'S\' para SIM e \'N\' para NÃO: ");
				}
			}

			setbuf(stdin, NULL);

		} while (continuar != 'S' && continuar != 'N');

	} while (continuar != 'N');

	return 0;
}
