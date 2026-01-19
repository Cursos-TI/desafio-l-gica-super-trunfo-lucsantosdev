#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {

  // Área para definição das variáveis para armazenar as propriedades das cidades
  #define ESTADOS 8
  #define CIDADES_POR_ESTADO 4

  typedef struct {

    char codigo[4]; // Ex: A01

    // Propriedades inseridas pelo usuário
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;

    // Propriedades calculadas
    double densidadePopulacional;
    double pibPerCapita;

    double superPoder;

  } Carta;

  Carta cartas[ESTADOS][CIDADES_POR_ESTADO];
    char estado;
    int cidade;

  // Título do Jogo    
  printf("=== Super Trunfo - Tema: Países ===\n\n");

  // Área para entrada de dados
  for (int i = 0; i < ESTADOS; i++) {
    estado = 'A' + i;

    for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
      cidade = j + 1;

      // Gerando o código da carta
      sprintf(cartas[i][j].codigo, "%c%02d", estado, cidade);
      
      // Cadastrando a cidade
      printf("Cadastro da cidade %s\n", cartas[i][j].codigo);

      // Cadastro da população
      printf("População: ");
      scanf("%d", &cartas[i][j].populacao);

      // Cadastro da Área (em km²)
      printf("Área (km²): ");
      scanf("%lf", &cartas[i][j].area);

      // Cadastro do PIB (em milhões)
      printf("PIB (em milhões): ");
      scanf("%lf", &cartas[i][j].pib);

      // Cadastro do Número de Pontos Turísticos
      printf("Número de pontos turísticos: \n");
      scanf("%d", &cartas[i][j].pontosTuristicos);

      printf("------------------------------\n");

      // Cálculos de propriedades calculadas
      cartas[i][j].densidadePopulacional = 
        cartas[i][j].populacao / 
        cartas[i][j].area;

      cartas[i][j].pibPerCapita = 
        cartas[i][j].pib / 
        cartas[i][j].populacao;

      cartas[i][j].superPoder = 
        cartas[i][j].populacao +
        cartas[i][j].area +
        cartas[i][j].pib +
        cartas[i][j].pontosTuristicos +
        cartas[i][j].densidadePopulacional +
        cartas[i][j].pibPerCapita;

    }             
  }

  // Área para exibição dos dados da cidade
  printf("\n=== Cartas Cadastradas ===\n\n");

  for (int i = 0; i < ESTADOS; i++) {
    for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
      printf("Código da Carta: %s\n", cartas[i][j].codigo);
      printf("População: %d\n", cartas[i][j].populacao);
      printf("Área: %.2f km²\n", cartas[i][j].area);
      printf("PIB: %.2f bilhões\n", cartas[i][j].pib);
      printf("Pontos Turísticos: %d\n", cartas[i][j].pontosTuristicos);
      printf("Densidade Populacional: %.2f hab/km²\n", cartas[i][j].densidadePopulacional);
      printf("PIB per Capita: %.6f\n", cartas[i][j].pibPerCapita);
      printf("Super Poder: %.2f\n", cartas[i][j].superPoder);
      printf("------------------------------\n");
    }
  }

  // Comparação entre duas cartas
  char estadoCarta1, estadoCarta2;
  int cidadeCarta1, cidadeCarta2;
  int e1, e2;

  printf("\n=== COMPARAÇÃO DE CARTAS ===\n");

  printf("Escolha a Carta 1 (estado A-H e cidade 1-4): ");
  scanf(" %c %d", &estadoCarta1, &cidadeCarta1);

  printf("Escolha a Carta 2 (estado A-H e cidade 1-4): ");
  scanf(" %c %d", &estadoCarta2, &cidadeCarta2);

  // Convertendo as entradas para índices do array (A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7)
  e1 = estadoCarta1 - 'A'; 
  e2 = estadoCarta2 - 'A';

  // Armazenando as cartas escolhidas
  Carta carta1 = cartas[e1][cidadeCarta1 - 1];  // cidade 1-4 vira índice 0-3
  Carta carta2 = cartas[e2][cidadeCarta2 - 1];

  printf("\n=== COMPARAÇÃO %s x %s ===\n\n", carta1.codigo, carta2.codigo);

  // Comparação de População 
  printf("População: ");
  if (carta1.populacao == carta2.populacao) {
    printf("Empate\n");
  } else if (carta1.populacao > carta2.populacao) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  // Comparação de Área 
  printf("Área: ");
  if (carta1.area == carta2.area) {
    printf("Empate\n");
  } else if (carta1.area > carta2.area) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  // Comparação de PIB 
  printf("PIB: ");
  if (carta1.pib == carta2.pib) {
    printf("Empate\n");
  } else if (carta1.pib > carta2.pib) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  // Comparação de Pontos Turísticos 
  printf("Pontos Turísticos: ");
  if (carta1.pontosTuristicos == carta2.pontosTuristicos) {
    printf("Empate\n");
  } else if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  // Comparação de PIB per Capita 
  printf("PIB per Capita: ");
  if (carta1.pibPerCapita == carta2.pibPerCapita) {
    printf("Empate\n");
  } else if (carta1.pibPerCapita > carta2.pibPerCapita) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  // Comparação de Densidade Populacional (menor vence)
  printf("Densidade Populacional: ");
  if (carta1.densidadePopulacional == carta2.densidadePopulacional) {
    printf("Empate\n");
  } else if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  // Comparação de Super Poder
  printf("Super Poder: ");
  if (carta1.superPoder == carta2.superPoder) {
    printf("Empate\n");
  } else if (carta1.superPoder > carta2.superPoder) {
    printf("Carta 1 vence\n");
  } else {
    printf("Carta 2 vence\n");
  }

  return 0;

} 