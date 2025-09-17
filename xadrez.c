#include <stdio.h>

// Função recursiva para movimentar a Torre (linha reta)
void moverTorre(int casas, char direcao) {
    if (casas <= 0) return; // Caso base: para a recursão quando não há mais casas para mover

    switch (direcao) {
        case 'C': case 'c': printf("Torre moveu 1 casa para CIMA\n"); break;
        case 'B': case 'b': printf("Torre moveu 1 casa para BAIXO\n"); break;
        case 'E': case 'e': printf("Torre moveu 1 casa para ESQUERDA\n"); break;
        case 'D': case 'd': printf("Torre moveu 1 casa para DIREITA\n"); break;
    }

    moverTorre(casas - 1, direcao); // Chamada recursiva até mover todas as casas
}

// Função recursiva para movimentar o Bispo (diagonal)
void moverBispo(int casas, char dirVertical, char dirHorizontal) {
    if (casas <= 0) return; // Caso base da recursão

    printf("Bispo moveu 1 casa para %s e %s\n",
           (dirVertical == 'C' || dirVertical == 'c') ? "CIMA" : "BAIXO",
           (dirHorizontal == 'E' || dirHorizontal == 'e') ? "ESQUERDA" : "DIREITA");

    moverBispo(casas - 1, dirVertical, dirHorizontal); // Chamada recursiva
}

// Função recursiva para movimentar a Rainha (combina torre + bispo)
void moverRainha(int casas, char tipo, char dir1, char dir2) {
    if (casas <= 0) return;

    if (tipo == 'T') { // Movimento como Torre
        switch (dir1) {
            case 'C': case 'c': printf("Rainha moveu 1 casa para CIMA\n"); break;
            case 'B': case 'b': printf("Rainha moveu 1 casa para BAIXO\n"); break;
            case 'E': case 'e': printf("Rainha moveu 1 casa para ESQUERDA\n"); break;
            case 'D': case 'd': printf("Rainha moveu 1 casa para DIREITA\n"); break;
        }
    } else { // Movimento como Bispo
        printf("Rainha moveu 1 casa para %s e %s\n",
               (dir1 == 'C' || dir1 == 'c') ? "CIMA" : "BAIXO",
               (dir2 == 'E' || dir2 == 'e') ? "ESQUERDA" : "DIREITA");
    }

    moverRainha(casas - 1, tipo, dir1, dir2); // Chamada recursiva
}

// Movimento do Cavalo usando loops aninhados
void moverCavalo(int vezes) {
    for (int i = 0; i < vezes; i++) {
        printf("\n--- Movimento %d do Cavalo ---\n", i + 1);
        for (int j = 0; j < 3; j++) {
            if (j < 2) { // Move duas casas para cima
                printf("Cavalo moveu 1 casa para CIMA\n");
                continue;
            }
            printf("Cavalo moveu 1 casa para DIREITA\n"); // Depois move para direita
        }
        printf("Cavalo completou um movimento em 'L'!\n");
    }
}

int main() {
    int peca, casas, vezes;
    char direcao1, direcao2;

    // Introdução explicando os movimentos
    printf("*** Bem-vindo ao Xadrez! ***\n");
    printf("\nNeste programa, você poderá movimentar peças do xadrez.\n");
    printf("Veja como cada peça se move:\n");
    printf("- Torre: move-se em linha reta (CIMA, BAIXO, ESQUERDA ou DIREITA).\n");
    printf("- Bispo: move-se na diagonal (CIMA/BAIXO + ESQUERDA/DIREITA).\n");
    printf("- Rainha: combina os movimentos da Torre e do Bispo.\n");
    printf("- Cavalo: move-se em formato de 'L' (duas casas em uma direção e uma em outra).\n");

    // Menu principal (mantido como antes)
    printf("\n============================================\n");
    printf("Escolha a peça que deseja movimentar:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("============================================\n");
    printf("Digite sua escolha: ");
    scanf("%d", &peca);

    switch (peca) {
        case 1: // Torre
            printf("\nVocê escolheu a TORRE.\n");
            printf("Quantas casas deseja mover? ");
            scanf("%d", &casas);

            printf("\nEscolha a direção (C = Cima | B = Baixo | E = Esquerda | D = Direita): ");
            scanf(" %c", &direcao1);

            moverTorre(casas, direcao1);
            printf("\nMovimento concluído!\n");
            break;

        case 2: // Bispo
            printf("\nVocê escolheu o BISPO.\n");
            printf("Quantas casas deseja mover? ");
            scanf("%d", &casas);

            printf("\nEscolha a direção vertical (C = Cima | B = Baixo): ");
            scanf(" %c", &direcao1);

            printf("Escolha a direção horizontal (E = Esquerda | D = Direita): ");
            scanf(" %c", &direcao2);

            moverBispo(casas, direcao1, direcao2);
            printf("\nMovimento concluído!\n");
            break;

        case 3: // Rainha
            printf("\nVocê escolheu a RAINHA.\n");
            printf("Quantas casas deseja mover? ");
            scanf("%d", &casas);

            printf("\nA Rainha pode se mover como uma Torre ou como um Bispo.\n");
            printf("Escolha o tipo de movimento (T = Torre | B = Bispo): ");
            scanf(" %c", &direcao1);

            if (direcao1 == 'T' || direcao1 == 't') { 
                printf("\nVocê escolheu movimento em linha reta.\n");
                printf("Escolha a direção (C = Cima | B = Baixo | E = Esquerda | D = Direita): ");
                scanf(" %c", &direcao2);
                moverRainha(casas, 'T', direcao2, ' ');
            } else { 
                char direcaoH;
                printf("\nVocê escolheu movimento na diagonal.\n");
                printf("Direção vertical (C = Cima | B = Baixo): ");
                scanf(" %c", &direcao2);

                printf("Direção horizontal (E = Esquerda | D = Direita): ");
                scanf(" %c", &direcaoH);

                moverRainha(casas, 'B', direcao2, direcaoH);
            }
            printf("\nMovimento concluído!\n");
            break;

        case 4: // Cavalo
            printf("\nVocê escolheu o CAVALO.\n");
            printf("Quantas vezes deseja mover o Cavalo? ");
            scanf("%d", &vezes);

            printf("\nO Cavalo sempre irá se mover em 'L': duas casas para cima e uma para direita.\n");
            moverCavalo(vezes);
            printf("\nMovimento concluído!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    return 0;
}
