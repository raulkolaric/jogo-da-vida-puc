//Jogo-da-Vida-MODEL.h - Projeto Jogo da Vida
//??/??/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

int dimensao;
char matriz[60][60];
char matrizAuxiliar[60][60];

printf("Qual a dimensão desejada? (10 a 60): ");
scanf("%d", dimensao);

if (dimensao < 10 || dimensao > 60) {
	printf("Valor invalido.");
}

else {
	matriz[dimensao][dimensao];
}
 
