//JVIDA-6-KLRR-VIEW.cpp - Projeto Jogo da Vida
//25/11/2025 - Grupo: KLRR
//Kaua Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-VIEW.h"

//Exibe o mapa atual
void apresentarMapa() {
	mostrarEsconder();			//Atualiza os '+' se a opcao "mostrar vizinhos" estiver ativada
	
	printf("\n   ");
	
	for (int colunas = 0; colunas < dimensao; colunas++) {
		printf("%d ", colunas + 1);
	}
    
    printf("\n");
    for (int linhas = 0; linhas < dimensao; linhas++) {
    	if (linhas < 9) {
    		printf("%d ", linhas + 1); 
		}
		
		else {
			printf("%d", linhas + 1); 
		}
        for (int i = 0; i < dimensao; i++) {
        	if (i < 10) {
        		printf(" %c", matriz [linhas] [i]);	
			}
			
			else {
				printf("  %c", matriz [linhas] [i]);
			}
        }
        printf("\n");
    }
    
    printf("\nGeracao: %d\n", geracao);
    
    apresentarListas();
}

//Limpa o buffer de entrada
void fclear() {
	char carac;

	while ((carac = fgetc(stdin)) != EOF && carac != '\n') {
	
	}
}

//Limpa a tela do console
void limparTela() {
	system("cls");
}

//Exibe o menu principal e retorna a opcao escolhida
char menu() {
	do {
		limparTela();
				
		printf("\n----------------------------------MENU---------------------------------\n");
		printf("| 1 - Limpar Mapa                                                     |\n");
		printf("| 2 - Incluir/excluir celulas vivas                                   |\n");
		printf("| 3 - Mostrar/Esconder os mortos-vizinhos                             |\n");
		printf("| 4 - INICIAR PROCESSO                                                |\n");
		printf("| 5 - Apresentar as Listas                                            |\n");
		printf("| 6 - Gravar uma geracao inicial                                      |\n");
		printf("| 7 - Recuperar uma geracao inicial cadastrada                        |\n");
		printf("| 8 - Regras de evolucao das celulas                                  |\n");
		printf("| 0 - Sair do programa                                                |\n");
		printf("-----------------------------------------------------------------------\n");
		printf("Opcao selecionada: ");
		scanf("%c", &op);	
		
		if (op >= '0' && op <= '8') {
			break;	
		}
			
		printf("\n--------------OPCAO INVALIDA--------------");	
		Sleep(500);
		fclear();
	} while (1);

	fclear();
	return op; 
}

//Mostra as regras do jogo ao jogador
void regras() {
	limparTela();
	printf("\n---------------------------------------------------Regras resumidas---------------------------------------------------\n");
	printf("\nA ideia base e' que um ser vivo necessita de outros seres vivos para sobreviver e procriar, mas um excesso de densidade"); 
	printf("\npopulacional provoca a morte do ser vivo devido 'a escassez de comida.");
	printf("\nOs individuos vivem num mundo matricial e a geracao seguinte e' gerada a partir da geracao anterior de acordo com as");
	printf("\nseguintes regras:"); 
	printf("\n- Reproducao: Um ser vivo nasce numa celula vazia se essa celula vazia tiver exatamente 3 seres vivos vizinhos.");
	printf("\n- Sobrevivencia: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.");
	printf("\n- Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre porque fica sem comida.");
	printf("\n- Morte por solidao: Um ser vivo com 0 ou apenas 1 vizinho morre de solidao.");
	printf("\nA cada geracao, as regras devem ser aplicadas para todos os seres vivos ao mesmo tempo (isto e no mesmo passo) para"); 
	printf("\nobtermos o proximo passo ou geracao.\n\n");
	system("pause");
}

void tempo (int seg) {
	time_t lt1 = time(NULL), lt2 = lt1;
	
	while (difftime(lt2, lt1) < seg) {
		lt2 = time(NULL);	
	}
}
