#include<stdio.h>

typedef struct {
    int r, g, b;
} varColorido;

//Funções e procedimentos
int menuPrincipal() {
    int i, opcao;
    do {
        printf("\n*** Menu Principal ***\n1. Preencher a imagem colorida;\n2. Transformar em tons de cinza;\n3. Imprimir as duas imagens;\n4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        if ((opcao > 4) || (opcao < 1))
            printf("\nOpcao Invalida! Digite novamente\n\n");
    } while ((opcao > 4) || (opcao < 1));
    return opcao;
}
void preencherImagemColorida(varColorido imgCol[3][3], int *contOp1) {
    int i, j;
    printf("\nMenu Principal > Opcao 1\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("Linha %d, Coluna %d:\n", i+1, j+1);
            do {
                printf("R: ");
                scanf("%d", &imgCol[i][j].r);
                if ((imgCol[i][j].r < 0) || (imgCol[i][j].r > 255))
                    printf("\nValor Invalido! Escolha entre 0 e 255.\n");
            } while ((imgCol[i][j].r < 0) || (imgCol[i][j].r > 255));
            do {
                printf("G: ");
                scanf("%d", &imgCol[i][j].g);
                if ((imgCol[i][j].g < 0) || (imgCol[i][j].g > 255))
                    printf("\nValor Invalido! Escolha entre 0 e 255.\n");
            } while ((imgCol[i][j].g < 0) || (imgCol[i][j].g > 255));
            do {
                printf("B: ");
                scanf("%d", &imgCol[i][j].b);
                if ((imgCol[i][j].b < 0) || (imgCol[i][j].b > 255))
                    printf("\nValor Invalido! Escolha entre 0 e 255.\n");
            } while ((imgCol[i][j].b < 0) || (imgCol[i][j].b > 255));
        }
    }
    if (i==3)
        *contOp1 = 1;
}
void transformarImagemCinza(varColorido imgCol[3][3], int imgCin[3][3], int *contOp2) {
    int i, j;
    printf("\nMenu Principal > Opcao 2\n");
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            imgCin[i][j] = (imgCol[i][j].r + imgCol[i][j].g + imgCol[i][j].b)/3;
    if (i==3) {
        *contOp2 = 1;
        printf("Transformacao bem sucedida!\n\n");
    }
}
void imprimirImagemColoridaCinza(varColorido imgCol[3][3], int imgCin[3][3]) {
    int i, j;
    printf("\nMenu Principal > Opcao 3\n");
    printf("\n*** Imagem Colorida (R,G,B) ***\n");
    for(i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("(%d,%d,%d)", imgCol[i][j].r, imgCol[i][j].g, imgCol[i][j].b);
            if ((j==0) || (j==1))
                printf(" | ");
        }
        printf("\n");
    }
    printf("\n*** Imagem tons de Cinza ***\n");
    for(i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("(%d)", imgCin[i][j]);
            if ((j==0) || (j==1))
                printf(" | ");
        }
        printf("\n");
    }
}

//Função principal
int main(void) {
    varColorido imgCol[3][3];
    int imgCin[3][3];
    int opcao, contOp1=0, contOp2=0;

    do {
        opcao = menuPrincipal();

        switch (opcao) {
            case 1:preencherImagemColorida(imgCol, &contOp1); break;
            case 2: 
                if (contOp1 == 1)
                    transformarImagemCinza(imgCol, imgCin, &contOp2);
                else
                    printf("\nPreencha a imagem colorida primeiro!\n");
                break;
            case 3:
                if ((contOp1 == 1) && (contOp2 == 1))
                    imprimirImagemColoridaCinza(imgCol, imgCin);
                else
                    printf("\nPreencha a imagem colorida e a transforme em tons de cinza!\n");
        }
    } while (opcao != 4);
    printf("\nFim do programa!\n\n");

    return 0;
}