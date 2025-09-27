#include <stdio.h>
#include <stdlib.h> //Para método system, que permite apagar o terminal
/*Os comentários são pra minha própria compreensão durante o processo de escrita do código
peço que ignore os comentários e o dialéto do javinha utilizado(me sinto mais confortável) kk*/
int main()
{

    // Set tamanho tabuleiro
    int tamanho;
    printf("Digite o tamanho do tabuleiro: \n");
    printf("Regra: O número deve estar entre 5 e 100!\n");
    scanf("%d", &tamanho);

    // Valida tamanho tabuleiro
    if (tamanho < 5 || tamanho > 100)
    {
        // Exceção
        printf("Erro: O tamanho do tabuleiro deve ser entre 5 e 100!\n");
        return 1;
    }

    // Declara matrizes model(Regra de negócio) e view(Tabuleiro visualizado pelo usuário durante o runtime)
    int tabuleiroModel[tamanho][tamanho], tabuleiroView[tamanho][tamanho];

    // Set quantidade de minas no tabuleiro
    int numMinas;

    printf("Digite a quantidade de minas: \n");
    scanf("%d", &numMinas);

    // Valida quantidade minas
    if (numMinas <= 0 || numMinas >= (tamanho * tamanho) /*Get tamanho total da matiz*/)
    {
        // Exceção
        printf("Erro: A quantidade de minas eh invalida para este tamanho de tabuleiro!\n");
        return 1;
    }

    // Inicializa tabuleiros
    int i, j, k; // iteradores
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            tabuleiroModel[i][j] = 0; // Zero indica uma casa segura, sem minas em volta
            tabuleiroView[i][j] = 0;  // Zero indica casa oculta, 1 indica casa revelada
        }
    }

    // Set minas (linha : coluna)
    int linha, coluna;
    printf("Digite as posicoes das %d minas (Formato: linha coluna)\n", numMinas);
    for (k = 0; k < numMinas; k++)
    {
        printf("Mina: %d: ", k + 1);
        scanf("%d %d", &linha, &coluna);

        // Valida posicao mina
        if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho || tabuleiroModel[linha][coluna] == -1)
        {
            printf("Posicao invalida ou ja ocupada! Tente novamente!\n");
            k--;      // Decrementa o contador, assim o jogador pode inserir novamente sem consumir necessariamente uma repetição
            continue; // Volta pro começo do laço, pra nova tentativa, sem inserir um valor inválido do tabuleiro model
        }
        tabuleiroModel[linha][coluna] = -1; //-1 representa uma mina no tabuleiro
    }

    // Calcula minas vizinhas
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            // Se posição atual diferente de uma mina(-1), contar vizinhas
            if (tabuleiroModel[i][j] != -1)
            {
                int minasVizinhas = 0;
                // Laços para verificar as 8 possíveis posições das minas vizinhas(verticais e horizontais). viz_i para linhas, viz_j para colunas
                for (int viz_i = i - 1; viz_i <= i + 1; viz_i++)
                {
                    for (int viz_j = j - 1; viz_j <= j + 1; viz_j++)
                    {
                        // Verifica se coordenada vizinha está dentro dos limites do tabuleiro
                        if (viz_i >= 0 && viz_i < tamanho && viz_j >= 0 && viz_j < tamanho)
                        {
                            if (tabuleiroModel[viz_i][viz_j] == -1)
                            {
                                minasVizinhas++;
                            }
                        }
                    }
                }
                tabuleiroModel[i][j] = minasVizinhas;
            }
        }
    }

    // Main do jogo, laço principal onde o jogo irá se manter até a vitória ou derrota;
    int jogoAtivo = 1;

    // Atributos necessários para inserir o X nas posições abertas, mas sem minas em volta
    int ultimaLinha = linha, ultimaColuna = coluna;

    // Atributos para verificar as condições de vitória
    int celulasParaVencer = (tamanho * tamanho) - numMinas, celulasReveladas = 0;

    while (jogoAtivo) {
        // Limpa tela, insere perfurmaria (linhas e espaçamentos) e imprime tabuleiro view
        system("cls");
        printf("    ");
        for (j = 0; j < tamanho; j++)
        {
            printf("%2d", j); // Espaçamento entre as colunas
        }
        printf("\n");

        printf("    ");
        for (j = 0; j < tamanho; j++)
        {
            printf("---"); // Perfurmaria, linhas horizontais
        }
        printf("\n");

        // Imprime tabuleiro view
        for (i = 0; i < tamanho; i++)
        {
            printf("%2d | ", i); // Perfumaria, linhas verticais
            for (j = 0; j < tamanho; j++)
            {
                if (tabuleiroView[i][j] == 0)
                {
                    // Posição oculta, exibe O
                    printf(" O ");
                }
                else
                {
                    // Se posicao revelada
                    if (tabuleiroModel[i][j] == 0)
                    {
                        // E não há minas em volta
                        printf(" X ");
                    }
                    else
                    {
                        // Há minas em volta, então exibe o número de minas em volta
                        printf(" %d ", tabuleiroModel[i][j]);
                    }
                }
            }
            printf("\n");
        }
        printf("\n");

        // Set jogada
        printf("\nDigite a sua jogada (linha : coluna): ");
        scanf("%d %d", &linha, &coluna);

        // Valida jogada
        if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho)
        {
            printf("Posicao invalida! Pressione Enter para continuar. . .");
            getchar(); // Limpa o buffer
            getchar(); // Limpa o enter que funciona como uma pausa, solicitando o jogador a pressionar para continuar
            continue;
        }

        if (tabuleiroView[linha][coluna] == 1)
        {
            printf("Posicao ja revelada! Pressione Enter para continuar. . .");
            getchar();
            getchar();
            continue;
        }

        // Armazena a jogada atual para que possa ser marcada como um X no tabuleiro
        ultimaLinha = linha;
        ultimaColuna = coluna;

        // Processa jogada
        if (tabuleiroModel[linha][coluna] == -1)
        {
            // Gameover | Derrota
            system("cls");
            printf("Gamer over! Voce acertou uma mina");
            jogoAtivo = 0; // Encerra o while
        }
        else
        {
            // Jogada segura (Jogada em casas seguras do tabuleiro, onde não há minas)
            tabuleiroView[linha][coluna] = 1;
            celulasReveladas++; // Informação será usada pra verificar se todas as casas seguras foram abertas, assim vencendo o jogo

            // Imprime mensagem sobre quantidade de minas próximas
            int minasProximas = tabuleiroModel[linha][coluna];
            printf("A posicao (%d, %d) possui %d mina(s) em volta.\n", linha, coluna, minasProximas);
            printf("Pressione Enter para continuar. . .");
            getchar();
            getchar();

            // Verifica condição de vitória
            if (celulasReveladas == celulasParaVencer)
            {
                system("cls");
                printf("Parabéns! Você venceu o jogo\n\n");
                jogoAtivo = 0;
            }
        }
    }

    // Exibe tabuleiro final, seja por vitória ou derrota
    printf("    ");
    for (j = 0; j < tamanho; j++) {
        printf("%2d", j); // Espaçamento entre as colunas
    }
    printf("\n");

    printf("    ");
    for (j = 0; j < tamanho; j++) {
        printf("---"); // Perfurmaria, linhas horizontais
    }
    printf("\n");

    for (i = 0; i < tamanho; i++) {
        printf("%2d | ", i);
        for (j = 0; j < tamanho; j++) {
            if (tabuleiroModel[i][j] == -1) {
                printf(" * ");//As casas onde haviam minas são marcadas com *
            } else {
                printf(" %d ", tabuleiroModel[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}