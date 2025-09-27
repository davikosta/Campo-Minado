
# 💣 Campo Minado em C

Um simples jogo de **Campo Minado** desenvolvido em **C** para rodar no terminal.  
O jogador deve abrir todas as casas seguras sem acertar nenhuma mina!  

Este projeto foi feito com foco em **praticar lógica de programação**, **matrizes** e **laços de repetição**.

---

## 📝 Regras e funcionamento básico

- Escolha o **tamanho do tabuleiro** (mínimo 5x5, máximo 100x100).  
- Defina a **quantidade de minas**.  
- O jogador insere coordenadas para revelar as casas.  
- O jogo informa quantas minas existem nas casas vizinhas.  
- Vitória ao revelar todas as casas seguras.  
- Derrota ao clicar em uma mina 💥.  
- Exibição do **tabuleiro final** no fim do jogo.

## ⚙️ Como compilar e executar

### **Pré-requisitos**
- Compilador C instalado:
  - [GCC](https://gcc.gnu.org/) ou
  - [MinGW](http://www.mingw.org/) (Windows)
- Terminal ou CMD.

### **Passos**
1. Clone o repositório:
   ```bash
   git clone https://github.com/seuusuario/campo-minado-c.git
   cd campo-minado-c
   ```

2. Compile o programa:
   ```bash
   gcc main.c -o campo-minado
   ```

3. Execute o jogo:
   ```bash
   ./campo-minado
   ```

No Windows:
```bash
campo-minado.exe
```

## 🧩 Estrutura do projeto
```
campo-minado-c/
│
├── main.c          # Código principal do jogo
├── README.md       # Documentação do projeto
└── .gitignore      # Arquivos a serem ignorados pelo Git
```
