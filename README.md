---

# Lista Sequencial Ordenada com Redimensionamento Dinâmico

Este projeto implementa uma **Lista Sequencial Ordenada** em C, que utiliza **alocação dinâmica** para gerenciar a capacidade da lista automaticamente. Ele atende ao seguinte objetivo:

- Expandir ou reduzir a capacidade da lista dinamicamente conforme os elementos são adicionados ou removidos, otimizando o uso de memória.

## 📝 Descrição do Projeto

A lista sequencial originalmente usava um vetor de tamanho fixo. Com a modificação, agora ela:
1. **Expande a capacidade automaticamente**: 
   - Quando o número de elementos atinge a capacidade máxima, o tamanho da lista é dobrado.
2. **Reduz a capacidade automaticamente**: 
   - Quando o número de elementos cai para 25% da capacidade, a lista é reduzida pela metade, economizando memória.

Essas operações são realizadas utilizando a função **`realloc`** para redimensionar o vetor dinâmico.

---

## 🚀 Funcionalidades

### 1. Inserção de Elementos Ordenados
- Os elementos são inseridos na posição correta, mantendo a ordem crescente.
- A capacidade é automaticamente expandida se necessário.

### 2. Remoção de Elementos
- Remove o elemento especificado.
- Reduz a capacidade da lista quando o número de elementos cai abaixo de 25% da capacidade total.

### 3. Operações de Consulta
- **Exibir a lista**: Mostra todos os elementos.
- **Primeiro e último elemento**: Retorna os valores correspondentes.
- **Tamanho da lista**: Retorna o número atual de elementos ou o tamanho em bytes.

---

## 📂 Estrutura do Projeto

- **`liord.h`**: Declarações das estruturas e funções da lista.
- **`RediDnamico.c`**: Implementação das funções de manipulação da lista.
- **`ClienteDinamico.c`**: Programa principal que demonstra o uso da lista sequencial.

---

## ⚙️ Requisitos de Uso

- Compilador C (como GCC ou Clang).
- Sistema com suporte a funções de alocação dinâmica (padrão C).

---

## 🛠️ Como Compilar e Executar

1. Compile o programa usando um compilador C:
   ```bash
   gcc ListaOrdenada.c ClienteOrdenada.c -o ListaSequencial
   ```

2. Execute o programa:
   ```bash
   ./ListaSequencial
   ```

---

## 🧪 Exemplos de Uso

1. Inserir elementos na lista:
   - Os elementos são inseridos de forma ordenada.
   - Exemplo: Inserir `9`, `3`, `4`, `1`, e `12`.

2. Excluir elementos:
   - Exclua um elemento especificado.
   - Exemplo: Excluir o elemento `4`.

3. Visualizar a lista:
   - Mostra os elementos e informações como capacidade e tamanho atual.

---

## 📖 Observações

- A capacidade inicial da lista é 50 elementos.
- A lista não permite que elementos ultrapassem a capacidade sem expandir.
- A memória alocada dinamicamente é liberada ao final da execução para evitar vazamentos.

---
