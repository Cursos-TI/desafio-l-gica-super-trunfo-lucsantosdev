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

  // Comparação entre duas cartas com menu interativo
  char estadoCarta1, estadoCarta2;
  int cidadeCarta1, cidadeCarta2;
  int e1, e2;
  int opcaoMenu;
  int continuarComparando = 1;

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

  // Loop do menu interativo
  while (continuarComparando) {
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Comparando: %s x %s\n\n", carta1.codigo, carta2.codigo);
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("8 - Comparação Completa (todos os atributos)\n");
    printf("0 - Sair\n");
    printf("\nOpção: ");
    scanf("%d", &opcaoMenu);

    printf("\n");

    // Switch para o menu interativo
    switch (opcaoMenu) {
      case 1: // População
        printf("=== COMPARAÇÃO: POPULAÇÃO ===\n");
        printf("Carta %s: %d habitantes\n", carta1.codigo, carta1.populacao);
        printf("Carta %s: %d habitantes\n", carta2.codigo, carta2.populacao);
        
        // Lógica de comparação aninhada com desempate
        if (carta1.populacao == carta2.populacao) {
          printf("\nEmpate em População!\n");
          printf("Aplicando critério de desempate: PIB per Capita...\n");
          
          if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta %s vence (PIB per Capita: %.2f > %.2f)\n", 
                   carta1.codigo, carta1.pibPerCapita, carta2.pibPerCapita);
          } else if (carta1.pibPerCapita < carta2.pibPerCapita) {
            printf("Resultado: Carta %s vence (PIB per Capita: %.2f > %.2f)\n", 
                   carta2.codigo, carta2.pibPerCapita, carta1.pibPerCapita);
          } else {
            printf("Empate total mesmo após desempate!\n");
          }
        } else if (carta1.populacao > carta2.populacao) {
          printf("\n*** Carta %s VENCE por População! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por População! ***\n", carta2.codigo);
        }
        break;

      case 2: // Área
        printf("=== COMPARAÇÃO: ÁREA ===\n");
        printf("Carta %s: %.2f km²\n", carta1.codigo, carta1.area);
        printf("Carta %s: %.2f km²\n", carta2.codigo, carta2.area);
        
        if (carta1.area == carta2.area) {
          printf("\nEmpate em Área!\n");
          printf("Aplicando critério de desempate: Pontos Turísticos...\n");
          
          if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
            printf("Resultado: Carta %s vence (Pontos Turísticos: %d > %d)\n", 
                   carta1.codigo, carta1.pontosTuristicos, carta2.pontosTuristicos);
          } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
            printf("Resultado: Carta %s vence (Pontos Turísticos: %d > %d)\n", 
                   carta2.codigo, carta2.pontosTuristicos, carta1.pontosTuristicos);
          } else {
            printf("Empate total mesmo após desempate!\n");
          }
        } else if (carta1.area > carta2.area) {
          printf("\n*** Carta %s VENCE por Área! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por Área! ***\n", carta2.codigo);
        }
        break;

      case 3: // PIB
        printf("=== COMPARAÇÃO: PIB ===\n");
        printf("Carta %s: %.2f milhões\n", carta1.codigo, carta1.pib);
        printf("Carta %s: %.2f milhões\n", carta2.codigo, carta2.pib);
        
        if (carta1.pib == carta2.pib) {
          printf("\nEmpate em PIB!\n");
          printf("Aplicando critério de desempate: População...\n");
          
          if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta %s vence (População: %d > %d)\n", 
                   carta1.codigo, carta1.populacao, carta2.populacao);
          } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta %s vence (População: %d > %d)\n", 
                   carta2.codigo, carta2.populacao, carta1.populacao);
          } else {
            printf("Empate total mesmo após desempate!\n");
          }
        } else if (carta1.pib > carta2.pib) {
          printf("\n*** Carta %s VENCE por PIB! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por PIB! ***\n", carta2.codigo);
        }
        break;

      case 4: // Pontos Turísticos
        printf("=== COMPARAÇÃO: PONTOS TURÍSTICOS ===\n");
        printf("Carta %s: %d pontos turísticos\n", carta1.codigo, carta1.pontosTuristicos);
        printf("Carta %s: %d pontos turísticos\n", carta2.codigo, carta2.pontosTuristicos);
        
        if (carta1.pontosTuristicos == carta2.pontosTuristicos) {
          printf("\nEmpate em Pontos Turísticos!\n");
          printf("Aplicando critério de desempate: Área...\n");
          
          if (carta1.area > carta2.area) {
            printf("Resultado: Carta %s vence (Área: %.2f km² > %.2f km²)\n", 
                   carta1.codigo, carta1.area, carta2.area);
          } else if (carta1.area < carta2.area) {
            printf("Resultado: Carta %s vence (Área: %.2f km² > %.2f km²)\n", 
                   carta2.codigo, carta2.area, carta1.area);
          } else {
            printf("Empate total mesmo após desempate!\n");
          }
        } else if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
          printf("\n*** Carta %s VENCE por Pontos Turísticos! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por Pontos Turísticos! ***\n", carta2.codigo);
        }
        break;

      case 5: // Densidade Populacional (menor vence)
        printf("=== COMPARAÇÃO: DENSIDADE POPULACIONAL ===\n");
        printf("Carta %s: %.2f hab/km²\n", carta1.codigo, carta1.densidadePopulacional);
        printf("Carta %s: %.2f hab/km²\n", carta2.codigo, carta2.densidadePopulacional);
        printf("(Obs: Menor densidade vence)\n");
        
        if (carta1.densidadePopulacional == carta2.densidadePopulacional) {
          printf("\nEmpate em Densidade Populacional!\n");
          printf("Aplicando critério de desempate: Super Poder...\n");
          
          if (carta1.superPoder > carta2.superPoder) {
            printf("Resultado: Carta %s vence (Super Poder: %.2f > %.2f)\n", 
                   carta1.codigo, carta1.superPoder, carta2.superPoder);
          } else if (carta1.superPoder < carta2.superPoder) {
            printf("Resultado: Carta %s vence (Super Poder: %.2f > %.2f)\n", 
                   carta2.codigo, carta2.superPoder, carta1.superPoder);
          } else {
            printf("Empate total mesmo após desempate!\n");
          }
        } else if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
          printf("\n*** Carta %s VENCE por Densidade Populacional! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por Densidade Populacional! ***\n", carta2.codigo);
        }
        break;

      case 6: // PIB per Capita
        printf("=== COMPARAÇÃO: PIB PER CAPITA ===\n");
        printf("Carta %s: %.6f\n", carta1.codigo, carta1.pibPerCapita);
        printf("Carta %s: %.6f\n", carta2.codigo, carta2.pibPerCapita);
        
        if (carta1.pibPerCapita == carta2.pibPerCapita) {
          printf("\nEmpate em PIB per Capita!\n");
          printf("Aplicando critério de desempate: PIB...\n");
          
          if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta %s vence (PIB: %.2f > %.2f)\n", 
                   carta1.codigo, carta1.pib, carta2.pib);
          } else if (carta1.pib < carta2.pib) {
            printf("Resultado: Carta %s vence (PIB: %.2f > %.2f)\n", 
                   carta2.codigo, carta2.pib, carta1.pib);
          } else {
            printf("Empate total mesmo após desempate!\n");
          }
        } else if (carta1.pibPerCapita > carta2.pibPerCapita) {
          printf("\n*** Carta %s VENCE por PIB per Capita! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por PIB per Capita! ***\n", carta2.codigo);
        }
        break;

      case 7: // Super Poder
        printf("=== COMPARAÇÃO: SUPER PODER ===\n");
        printf("Carta %s: %.2f\n", carta1.codigo, carta1.superPoder);
        printf("Carta %s: %.2f\n", carta2.codigo, carta2.superPoder);
        
        if (carta1.superPoder == carta2.superPoder) {
          printf("\nEmpate em Super Poder!\n");
          printf("Aplicando critério de desempate aninhado...\n");
          
          // Múltiplos níveis de desempate aninhados
          if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta %s vence (População: %d > %d)\n", 
                   carta1.codigo, carta1.populacao, carta2.populacao);
          } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta %s vence (População: %d > %d)\n", 
                   carta2.codigo, carta2.populacao, carta1.populacao);
          } else {
            // Segundo nível de desempate
            if (carta1.pib > carta2.pib) {
              printf("Resultado: Carta %s vence (PIB: %.2f > %.2f)\n", 
                     carta1.codigo, carta1.pib, carta2.pib);
            } else if (carta1.pib < carta2.pib) {
              printf("Resultado: Carta %s vence (PIB: %.2f > %.2f)\n", 
                     carta2.codigo, carta2.pib, carta1.pib);
            } else {
              printf("Empate total mesmo após múltiplos desempates!\n");
            }
          }
        } else if (carta1.superPoder > carta2.superPoder) {
          printf("\n*** Carta %s VENCE por Super Poder! ***\n", carta1.codigo);
        } else {
          printf("\n*** Carta %s VENCE por Super Poder! ***\n", carta2.codigo);
        }
        break;

      case 8: // Comparação Completa
        printf("=== COMPARAÇÃO COMPLETA ===\n\n");
        
        int vitoriasC1 = 0, vitoriasC2 = 0, empates = 0;
        
        // População
        printf("1. População: ");
        if (carta1.populacao == carta2.populacao) {
          printf("Empate (%d)\n", carta1.populacao);
          empates++;
        } else if (carta1.populacao > carta2.populacao) {
          printf("Carta %s vence (%d > %d)\n", carta1.codigo, carta1.populacao, carta2.populacao);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%d > %d)\n", carta2.codigo, carta2.populacao, carta1.populacao);
          vitoriasC2++;
        }
        
        // Área
        printf("2. Área: ");
        if (carta1.area == carta2.area) {
          printf("Empate (%.2f km²)\n", carta1.area);
          empates++;
        } else if (carta1.area > carta2.area) {
          printf("Carta %s vence (%.2f > %.2f km²)\n", carta1.codigo, carta1.area, carta2.area);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%.2f > %.2f km²)\n", carta2.codigo, carta2.area, carta1.area);
          vitoriasC2++;
        }
        
        // PIB
        printf("3. PIB: ");
        if (carta1.pib == carta2.pib) {
          printf("Empate (%.2f milhões)\n", carta1.pib);
          empates++;
        } else if (carta1.pib > carta2.pib) {
          printf("Carta %s vence (%.2f > %.2f)\n", carta1.codigo, carta1.pib, carta2.pib);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%.2f > %.2f)\n", carta2.codigo, carta2.pib, carta1.pib);
          vitoriasC2++;
        }
        
        // Pontos Turísticos
        printf("4. Pontos Turísticos: ");
        if (carta1.pontosTuristicos == carta2.pontosTuristicos) {
          printf("Empate (%d)\n", carta1.pontosTuristicos);
          empates++;
        } else if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
          printf("Carta %s vence (%d > %d)\n", carta1.codigo, carta1.pontosTuristicos, carta2.pontosTuristicos);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%d > %d)\n", carta2.codigo, carta2.pontosTuristicos, carta1.pontosTuristicos);
          vitoriasC2++;
        }
        
        // Densidade Populacional (menor vence)
        printf("5. Densidade Populacional: ");
        if (carta1.densidadePopulacional == carta2.densidadePopulacional) {
          printf("Empate (%.2f hab/km²)\n", carta1.densidadePopulacional);
          empates++;
        } else if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
          printf("Carta %s vence (%.2f < %.2f)\n", carta1.codigo, carta1.densidadePopulacional, carta2.densidadePopulacional);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%.2f < %.2f)\n", carta2.codigo, carta2.densidadePopulacional, carta1.densidadePopulacional);
          vitoriasC2++;
        }
        
        // PIB per Capita
        printf("6. PIB per Capita: ");
        if (carta1.pibPerCapita == carta2.pibPerCapita) {
          printf("Empate (%.6f)\n", carta1.pibPerCapita);
          empates++;
        } else if (carta1.pibPerCapita > carta2.pibPerCapita) {
          printf("Carta %s vence (%.6f > %.6f)\n", carta1.codigo, carta1.pibPerCapita, carta2.pibPerCapita);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%.6f > %.6f)\n", carta2.codigo, carta2.pibPerCapita, carta1.pibPerCapita);
          vitoriasC2++;
        }
        
        // Super Poder
        printf("7. Super Poder: ");
        if (carta1.superPoder == carta2.superPoder) {
          printf("Empate (%.2f)\n", carta1.superPoder);
          empates++;
        } else if (carta1.superPoder > carta2.superPoder) {
          printf("Carta %s vence (%.2f > %.2f)\n", carta1.codigo, carta1.superPoder, carta2.superPoder);
          vitoriasC1++;
        } else {
          printf("Carta %s vence (%.2f > %.2f)\n", carta2.codigo, carta2.superPoder, carta1.superPoder);
          vitoriasC2++;
        }
        
        // Resultado final
        printf("\n--- PLACAR FINAL ---\n");
        printf("Carta %s: %d vitórias\n", carta1.codigo, vitoriasC1);
        printf("Carta %s: %d vitórias\n", carta2.codigo, vitoriasC2);
        printf("Empates: %d\n", empates);
        
        if (vitoriasC1 > vitoriasC2) {
          printf("\n*** VENCEDOR GERAL: Carta %s ***\n", carta1.codigo);
        } else if (vitoriasC2 > vitoriasC1) {
          printf("\n*** VENCEDOR GERAL: Carta %s ***\n", carta2.codigo);
        } else {
          printf("\n*** EMPATE GERAL ***\n");
        }
        break;

      case 0: // Sair
        printf("Encerrando comparações...\n");
        continuarComparando = 0;
        break;

      default:
        printf("Opção inválida! Tente novamente.\n");
        break;
    }
  }

  return 0;

} 