#include <stdio.h>
/*Os comentários são pra minha própria compreensão durante o processo de escrita do código
peço que ignore os comentários e o dialéto do javinha utilizado(me sinto mais confortável) kk*/
int main() {

    //Set tamanho tabuleiro
    int tamanho;
    printf("Digite o tamanho do tabuleiro: \n");
    printf("Regra: O número deve estar entre 5 e 100!\n");
    scanf("%d", &tamanho);
    
    //Valida tamanho tabuleiro
    if (tamanho < 5 || tamanho > 100) {
        //Exceção
        printf("Erro: O tamanho do tabuleiro deve ser entre 5 e 100!\n");
        return 1;
    }

    //Declara matrizes model(Regra de negócio) e view(Tabuleiro visualizado pelo usuário durante o runtime)
    int tabuleiro_model[tamanho][tamanho], tabuleiro_view[tamanho][tamanho];

    //Set quantidade de minas no tabuleiro
    int numMinas;

    printf("Digite a quantidade de minas: \n");
    scanf("%d", &numMinas);

    //Valida quantidade minas
    if (numMinas <= 0 || numMinas >= (tamanho * tamanho)/*Get tamanho total da matiz*/) {
        //Exceção
        printf("Erro: A quantidade de minas eh invalida para este tamanho de tabuleiro!\n");
        return 1;
    }

    //Inicializa tabuleiros
    int i, j, k;//iteradores
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            tabuleiro_model[i][j] = 0;//Zero indica uma casa segura, sem minas em volta
            tabuleiro_view[i][j] = 0;//Zero indica casa oculta, 1 indica casa revelada
        }
    }

    //Set minas (linha : coluna)
    int linha, coluna;
    printf("Digite as posicoes das %d minas (Formato: linha coluna)\n", numMinas);
    for (k = 0; k < numMinas; k++) {
        printf("Mina: %d: ", k + 1);
        scanf("%d %d", &linha, &coluna);

        //Valida posicao mina
        if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho || tabuleiro_model[linha][coluna] == -1) {
            printf("Posicao invalida ou ja ocupada! Tente novamente!\n");
            k--; //Decrementa o contador, assim o jogador pode inserir novamente sem consumir necessariamente uma repetição
            continue;//Volta pro começo do laço, pra nova tentativa, sem inserir um valor inválido do tabuleiro model
        }
        tabuleiro_model[linha][coluna] = -1;//-1 representa uma mina no tabuleiro
    }

    //Calcula minas vizinhas
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            // Se posição atual diferente de uma mina(-1), contar vizinhas
            if (tabuleiro_model[i][j] != -1) {
                int minasVizinhas = 0;
                // Laços para verificar as 8 possíveis posições das minas vizinhas(verticais e horizontais). viz_i para linhas, viz_j para colunas
                for (int viz_i = i - 1; viz_i <= i + 1; viz_i++) {
                    for (int viz_j = j - 1; viz_j <= j + 1; viz_j++) {
                        //Verifica se coordenada vizinha está dentro dos limites do tabuleiro
                        if (viz_i >= 0 && viz_i < tamanho && viz_j > 0 && viz_j < tamanho) {
                            if (tabuleiro_model[viz_i][viz_j] == -1) {
                                minasVizinhas++;
                            } 
                        }
                    }
                }
                tabuleiro_model[i][j] = minasVizinhas;
            }
        }
    }

    //Main do jogo, laço principal onde o jogo irá se manter até a vitória ou derrota;

    return 0;
}