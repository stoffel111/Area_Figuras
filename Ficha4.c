#include <ctype.h>
#include <stdio.h>

#define PI 3.1415

char menu(int n_triangulo,int n_circulo,int n_retangulo,int n_quadrado);

int leNumero(void);

void areaRetangulo(int comprimento,int largura);
int leDadosRetangulo(int *comprimento);

void areaQuadrado(int lado_1,int lado_2);
int leDadosQuadrado(int *lado_1);

void areaTriangulo(int base,int altura);
int leDadosTriangulo(int *base);

void areaCirculo(int raio);


int main(void) {
    int comprimento,largura;//Retangulo
    int lado1,lado2; // Quadrado
    int base,altura; // Triangulo
    int raio; // Circulo
    int n_triangulo=0,n_circulo=0,n_retangulo=0,n_quadrado=0; //Contadores
    char opcao;

    do{
        opcao = menu(n_triangulo,n_circulo,n_retangulo,n_quadrado);
        opcao = toupper(opcao);
        switch(opcao) {
            case 'R':
                largura = leDadosRetangulo(&comprimento);
                areaRetangulo(comprimento,largura);
                n_retangulo++;
                break;
            case 'Q':
                lado2 = leDadosQuadrado(&lado1);
                areaQuadrado(lado1,lado2);
                n_quadrado++;
                break;
            case 'T':
                altura = leDadosTriangulo(&base);
                areaTriangulo(base,altura);
                n_triangulo++;
                break;
            case 'C':
                printf("RAIO!\n");
                raio = leNumero();
                areaCirculo(raio);
                n_circulo++;
                break;
            case 'F':
                printf("FIM!\nA Sair...");
                break;
            default:
                printf("ERRO - comando desconhecido!\n");
                break;
        }

    }while(opcao != 'F');

  return 0;
}

char menu(int n_triangulo,int n_circulo,int n_retangulo,int n_quadrado){
    char opcao;
    printf("\t\tCalculo de Areas\n");
    printf("Triangulo(Nº): %d \t\tRetangulo(Nº): %d\n",n_triangulo,n_retangulo);
    printf("Circulo(Nº): %d \t\tQuadrado(Nº): %d\n",n_circulo,n_quadrado);
    printf("\n");
    printf("\tOPCOES\n");
    printf("\t(T)riangulo\n");
    printf("\t(R)etangulo\n");
    printf("\t(Q)uadrado\n");
    printf("\t(C)irculo\n");
    printf("\t(F)im\n");
    printf("Selecione opcao: ");
    scanf(" %c",&opcao);
    return opcao;

}

int leNumero(void){
    int numero;
    do{
        printf("Indique um numero inteiro positivo: ");
        scanf("%d",&numero);
        if(numero <= 0){
            printf("Erro - o numero tem que ser positivo!!!\n");
        }
    }while(numero <= 0);
        return numero;
}

void areaRetangulo(int comprimento,int largura){
    int area;

    area = comprimento * largura;
    printf("Area Retangulo: %d\n",area);

}

int leDadosRetangulo(int *comprimento){
    int largura;
    do{
        printf("Comprimento!\n");
        *comprimento = leNumero();
        printf("Largura!\n");
        largura = leNumero();
        if(*comprimento == largura){
            printf("ERRO - um retangulo tem que ter largura e comprimento diferentes!\n");
        }
    }while(*comprimento == largura);

    return largura;
}

void areaQuadrado(int lado_1, int lado_2){
    int area;

    area = lado_1 * lado_2;
    printf("Area Quadrado: %d\n",area);

}

int leDadosQuadrado(int *lado_1){
    int lado_2;
    do{
        printf("LADO 1! \n");
        *lado_1 = leNumero();
        printf("LADO 2! \n");
        lado_2 = leNumero();
        if(*lado_1 != lado_2){
            printf("ERRO - lado_1 tem que ser igual ao lado_2 !\n");
        }

    }while(*lado_1 != lado_2);

    return lado_2;
}

void areaTriangulo(int base,int altura){
    int area;
    area = (base * altura) / 2;
    printf("Area Triangulo: %d\n",area);

}

int leDadosTriangulo(int *base){
    int altura;
    printf("BASE!\n");
    *base = leNumero();
    printf("ALTURA!\n");
    altura = leNumero();

    return altura;
}

void areaCirculo(int raio){
    float area;
    area = PI * (float)(raio*raio);
    printf("Area Circulo: %.2f\n",area);
}
