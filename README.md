
# 🐍 Snake Game - Estudo de Lógica e Segurança (SI)

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Field](https://img.shields.io/badge/Field-Information_Security-red.svg)
![Status](https://img.shields.io/badge/Level-Student_Project-yellow.svg)

Este projeto foi desenvolvido durante oano de 2024 porém este README somente estou fazenso no meu 2º semestre de **Segurança da Informação**. O objetivo foi aplicar conceitos de programação estruturada em C e entender como a manipulação de bibliotecas como `ncurses` interage com o sistema operacional.

"A segurança começa na base. Construir esse jogo me ajudou a visualizar como pequenas falhas de lógica podem se tornar riscos de segurança no futuro."

## 🎓 Objetivos de Aprendizado

Como estudante de SI, utilizei este projeto para explorar:
* **Gerenciamento de Fluxo:** Criação de um *Game Loop* funcional para entender processos em tempo real.
* **Estruturas de Dados:** Uso de `structs` para organizar coordenadas espaciais.
* **Interação com Hardware:** Uso da biblioteca `ncurses` para controle de input/output no terminal.

---

## 🛡️ Olhar de Segurança (O que aprendi até agora)

Mesmo sendo um projeto acadêmico, analisei o código buscando vulnerabilidades comuns que estudamos em sala de aula:

1.  **Limites de Array (Buffer Awareness):** O corpo da cobra está limitado a um array de 100 posições (`snake[100]`). Notei que, se o jogador ultrapassar essa pontuação, o programa pode tentar escrever em uma área de memória não reservada. Identificar isso foi meu primeiro contato prático com o conceito de **Stack Buffer Overflow**.
    
2.  **Entrada de Dados (Input Handling):** O uso de `getch()` da `ncurses` ensina como o sistema lida com o buffer do teclado. Aprendi que não validar ou não "limpar" entradas pode causar comportamentos inesperados no software.

3.  **Controle de Sinais:** Percebi que se o programa for fechado abruptamente (Ctrl+C), o terminal pode ficar "desconfigurado". Isso me mostrou a importância do tratamento de interrupções para manter a integridade do ambiente do usuário.



---

## 🚀 Próximos Passos (Evolução Acadêmica)

Como pretendo aprofundar meus conhecimentos em **Segurança de Aplicações (AppSec)**, minhas próximas metas para este código são:
* [ ] Implementar uma verificação de limite no array da cobra para evitar transbordamento.
* [ ] Estudar como substituir o array estático por uma lista encadeada (alocação dinâmica).
* [ ] Adicionar um sistema de logs simples para monitorar eventos do jogo.

---

## ⚙️ Como Executar (Ambiente Linux)

Para rodar este projeto, você precisará da biblioteca `ncurses` instalada:

```bash
# Instalação da dependência
sudo apt-get install libncurses5-dev libncursesw5-dev

# Compilação
gcc snake.c -o snake -lncurses

# Execução
./snake

