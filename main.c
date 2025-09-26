#include <stdio.h>
//Os comentários são pra minha própria compreensão durante o processo de escrita do código, peço que ignore os comentários e o dialéto do javinha utilizado(me sinto mais confortável) kk
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
    int i, j, k;
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            tabuleiro_model[i][j] = 0;//Zero indica uma casa segura, sem minas em volta
            tabuleiro_view[i][j] = 0;//Zero indica casa oculta, 1 indica 
        }
    }



    return 0;
}