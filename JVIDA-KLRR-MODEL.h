//Jogo-da-Vida-MODEL.h - Projeto Jogo da Vida
//14/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

int coordenadaX, coordenadaY;		//Coordenadas da célula a ser manipulada
int dimensao;						//Dimensão do tabuleiro (tamanho da matriz)
char excluir;						//Indica se o jogador deseja excluir um ser vivo ou célula
int geracao = 1;
char matriz[60][60];				//Matriz principal representando o estado atual do jogo
char matrizAuxiliar[60][60];
 
