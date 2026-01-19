# 🎮 Super Trunfo - Países 

Um jogo de cartas interativo baseado no clássico Super Trunfo, onde você cadastra cidades de diferentes estados e compara suas características para determinar qual carta é a vencedora!

## 📖 Sobre o Jogo

Super Trunfo é um jogo de cartas colecionáveis onde cada carta possui diferentes atributos. Os jogadores escolhem cartas e comparam seus atributos para determinar qual é a mais forte. Este sistema digital permite cadastrar 32 cartas (8 estados × 4 cidades) e realizar comparações estratégicas entre elas.

## 🎯 Funcionalidades do Sistema

### ✅ Cadastro Completo de Cartas
- **32 Cartas:** 8 estados (A-H) com 4 cidades cada
- **Código Automático:** Cada carta recebe um código único (ex: A01, B02, C03, etc.)
- **Atributos por Carta:**
  - População (habitantes)
  - Área (km²)
  - PIB (em milhões)
  - Número de Pontos Turísticos
  - Densidade Populacional (calculada automaticamente)
  - PIB per Capita (calculado automaticamente)
  - Super Poder (soma ponderada de todos os atributos)

### 🔍 Modos de Comparação

#### 1️⃣ **Comparação Individual por Atributo**
Compare duas cartas escolhendo um atributo específico:
- População (maior vence)
- Área (maior vence)
- PIB (maior vence)
- Pontos Turísticos (maior vence)
- Densidade Populacional (menor vence ⚠️)
- PIB per Capita (maior vence)
- Super Poder (maior vence)

**Destaque:** Sistema de desempate automático! Se houver empate no atributo escolhido, o sistema aplica um critério secundário automaticamente.

#### 2️⃣ **Comparação Completa**
Compara TODOS os 7 atributos simultaneamente:
- Contabiliza vitórias de cada carta
- Exibe placar final
- Declara o vencedor geral

#### 3️⃣ **Comparação com Dois Atributos** 🆕
Modo estratégico onde você escolhe 2 atributos para comparação:
- Análise dual dos atributos selecionados
- Sistema de pontuação (1 ponto por vitória em cada atributo)
- Lógica avançada com operadores ternários
- Critério de desempate inteligente

### 🎲 Menu Interativo
- Navegação fluida com estrutura `switch`
- Loop contínuo: faça quantas comparações quiser
- Opção de sair quando desejar

## 🚀 Como Iniciar o Jogo

### Pré-requisitos
- Compilador C (GCC, MinGW, MSVC, etc.)
- Terminal/Prompt de Comando

### Compilação

**Windows (usando cl.exe - Visual Studio):**
```bash
cl.exe logicaSuperTrunfo.c
```

**Windows/Linux (usando GCC):**
```bash
gcc logicaSuperTrunfo.c -o SuperTrunfo
```

### Execução

**Windows:**
```bash
.\logicaSuperTrunfo.exe
# ou
.\SuperTrunfo.exe
```

**Linux:**
```bash
./SuperTrunfo
```

## 🎮 Como Jogar

### Fase 1: Cadastro das Cartas

1. O sistema solicitará os dados de **32 cidades** (4 por estado)
2. Para cada cidade, informe:
   - População (número inteiro)
   - Área em km² (número decimal)
   - PIB em milhões (número decimal)
   - Número de pontos turísticos (número inteiro)

**Exemplo de entrada:**
```
Cadastro da cidade A01
População: 1000000
Área (km²): 500.50
PIB (em milhões): 25000.75
Número de pontos turísticos: 15
```

3. O sistema calculará automaticamente:
   - Densidade Populacional = População ÷ Área
   - PIB per Capita = PIB ÷ População
   - Super Poder = soma de todos os atributos

### Fase 2: Visualização das Cartas

Após o cadastro, todas as cartas serão exibidas com suas propriedades completas.

### Fase 3: Comparação de Cartas

1. **Escolha duas cartas para comparar:**
   - Digite o estado (A-H) e o número da cidade (1-4)
   - Exemplo: `A 1` para a carta A01

2. **Escolha o modo de comparação:**
   ```
   === MENU DE COMPARAÇÃO ===
   1 - População
   2 - Área
   3 - PIB
   4 - Pontos Turísticos
   5 - Densidade Populacional (menor vence)
   6 - PIB per Capita
   7 - Super Poder
   8 - Comparação Completa (todos os atributos)
   9 - Comparação com Dois Atributos
   0 - Sair
   ```

3. **Veja o resultado:**
   - O sistema mostrará os valores comparados
   - Indicará qual carta venceu e por quê
   - Em caso de empate, aplicará critério de desempate

4. **Continue jogando:**
   - O menu reaparecerá automaticamente
   - Faça quantas comparações quiser com as mesmas cartas
   - Digite `0` para sair

## 📊 Exemplo de Gameplay

```
=== COMPARAÇÃO DE CARTAS ===
Escolha a Carta 1 (estado A-H e cidade 1-4): A 1
Escolha a Carta 2 (estado A-H e cidade 1-4): B 2

=== MENU DE COMPARAÇÃO ===
Comparando: A01 x B02

Opção: 1

=== COMPARAÇÃO: POPULAÇÃO ===
Carta A01: 1000000 habitantes
Carta B02: 850000 habitantes

*** Carta A01 VENCE por População! ***
```

## 🎯 Regras do Jogo

### Regras de Vitória
- **Maior valor vence:** População, Área, PIB, Pontos Turísticos, PIB per Capita, Super Poder
- **Menor valor vence:** Densidade Populacional ⚠️

### Sistema de Desempate
Cada atributo possui um critério secundário de desempate:
- **População** → PIB per Capita
- **Área** → Pontos Turísticos
- **PIB** → População
- **Pontos Turísticos** → Área
- **Densidade** → Super Poder
- **PIB per Capita** → PIB
- **Super Poder** → População, depois PIB (2 níveis!)

### Comparação Dual (2 Atributos)
- Vitória em ambos = vitória direta
- 1 vitória + 1 empate = vitória
- 1 vitória + 1 derrota = critério de desempate aplicado
- 2 empates = empate total

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C (ANSI C)
- **Estruturas de Dados:** Structs, Arrays multidimensionais
- **Estruturas de Controle:** 
  - `if-else` (comparações aninhadas)
  - `switch-case` (menu interativo)
  - `while` (loop do jogo)
  - Operadores ternários (lógica avançada)

## 📚 Conceitos de Programação Aplicados

✅ Estruturas de decisão simples e aninhadas  
✅ Laços de repetição (`for`, `while`)  
✅ Estruturas de dados (`struct`, `arrays`)  
✅ Funções de I/O (`scanf`, `printf`, `sprintf`)  
✅ Operadores ternários para lógica compacta  
✅ Menu interativo com `switch-case`  
✅ Comparações múltiplas e sistema de pontuação  

## 🎓 Níveis de Implementação

Este sistema implementa funcionalidades dos **três níveis**:

- ✅ **Nível Novato:** Cadastro básico e comparações com `if-else`
- ✅ **Nível Aventureiro:** Menu interativo com `switch` e comparação aninhada
- ✅ **Nível Mestre:** Comparação dual, operadores ternários e lógica complexa

## 💡 Dicas para Jogar

1. **Cadastre dados realistas** para uma experiência mais imersiva
2. **Explore diferentes modos** de comparação para descobrir estratégias
3. **Use a Comparação Completa** (opção 8) para ver todas as estatísticas de uma vez
4. **Experimente a Comparação Dual** (opção 9) para análises estratégicas
5. **Observe os critérios de desempate** - eles podem surpreender!

## 🐛 Solução de Problemas

**Problema:** O programa fecha ao iniciar  
**Solução:** Certifique-se de compilar com todas as flags necessárias

**Problema:** Valores estranhos em cálculos  
**Solução:** Use números decimais para área e PIB (ex: 500.5, não 500)

**Problema:** Menu não aparece  
**Solução:** Verifique se digitou corretamente os códigos das cartas (A-H, 1-4)

---

**Desenvolvido como parte do Desafio Super Trunfo - MateCheck**  
*Aprenda programação jogando!* 🚀
