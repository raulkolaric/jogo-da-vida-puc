//Jogo-da-Vida-MODEL.h - Projeto Jogo da Vida
//14/10/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

int coordenadaX, coordenadaY;		//Coordenadas da c�lula a ser manipulada
int dimensao;						//Dimens�o do tabuleiro (tamanho da matriz)
char excluir;						//Indica se o jogador deseja excluir um ser vivo ou c�lula
int geracao = 1;
char matriz[60][60];				//Matriz principal representando o estado atual do jogo
char matrizAuxiliar[60][60];
 
