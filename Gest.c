#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char Nome[50];
    int Idade;
    float Salario;
    char Status;     /* '*' indica que o registro está apagado */
} PESSOA;

void Ler_Pessoa(PESSOA *ptr) {
    printf("Qual é o nome: "); scanf("%s",ptr->Nome);
    printf("Qual é a Idade:"); scanf("%d",&ptr->Idade);
    printf("Qual é o Salário: "); scanf("%f", &ptr->Salario);
    ptr->Status = ' ';
    fflush(stdin);
}

void Mostrar_Pessoa(PESSOA p) {
    printf(" Nome: %s;  Idade: %d;   Salario: %.2f.\n",p.Nome, p.Idade, p.Salario);
}


void Apagar(PESSOA *ptr);

int main(void) {
    int i, s = 0,j;         /* s indica o número de registros ativos */
    int l1,l2;
    PESSOA REGISTRO[MAX];
    PESSOA *ptr;
    char ch;
    char NOME[50];

    do {
        printf("1.Inserir Registro\n2.Alterar Registro\n3.Apagar Registro\n");
        printf("4.Listar Registros\n5.Pesquisas\n0.Sair\n");
        puts("\n");
        scanf("%d", &i);
        fflush(stdin);

        if (i == 1) {
            Ler_Pessoa(&REGISTRO[s]);
            s++;
            printf("%d",s);
            puts("\n");
        }

        if (i==2) {
            printf("Selecione o registro a ser alterado:");
            scanf("%d", &j);
            if ((REGISTRO[j-1]).Status == '*') {
                printf("Registro Apagado");
                printf("Deseja Ativa-lo novamente? (Digite 'S' ou 's' para Sim e outra tecla para não.)"); scanf(" %c", &ch);
                if (ch =='S' || ch == 's') {(REGISTRO[j-1]).Status = ' ';}
                else continue;
            }
            do {
                printf("Qual dado deseja alterar?\n 1.Nome\n2.Idade\n3.Salario\n0.Voltar\n");
                scanf("%d", &i);
                if (i==1) 
                    {
                        printf("Digite o novo nome: "); scanf("%s", (REGISTRO[j-1]).Nome);
                    }
                if (i==2) {
                    printf("Digite a nova idade: "); scanf("%d", &(REGISTRO[j-1]).Idade);
                }
                if(i==3) {
                    printf("Digite o novo Salário: "); scanf("%f", &(REGISTRO[j-1]).Salario);
                }
            }
            while(i!=0);
            i = 1;
        }
        if (i==3) {
            printf("Qual Registro deseja apagar?"); scanf("%d", &j);
            REGISTRO[j-1].Status = '*'; /* O índice sempre começa com 0 */
            puts("\n");
            printf("Registro apagado!\n\n");
        }
        if(i == 4) {
            for(j =0; j<s; j++) {
                if (REGISTRO[j].Status != '*') {
                    printf("%d: ", j+1);
                    Mostrar_Pessoa(REGISTRO[j]);
                }
                
            }
            puts("\n");
        }
        if (i == 5) {
            do {
                printf("1.Pesquisar por Intervalos de Idades\n2.Pesquisar por Nome\n0.Voltar\n");
                scanf("%d", &i);
                fflush(stdin);
                puts("\n");
                if (i ==1 )
                  {
                    printf("Digite o intervalo que deseja: "); scanf("%d%d", &l1, &l2);
                    for (j = 0; j<s; j++)
                        if ((REGISTRO[j]).Idade >=l1 && (REGISTRO[j]).Idade<=l2)
                            Mostrar_Pessoa(REGISTRO[j]);
                    putchar('\n');
                  }
                if (i ==2 )
                    {
                        printf("Digite o nome:"); scanf("%s", NOME);
                        for (j = 0; j<s; j++)
                            if ((strcmp((REGISTRO[j]).Nome, NOME) == 0))
                                Mostrar_Pessoa(REGISTRO[j]);
                    }
            }while (i != 0);
            i = 1;
        }
    }
    while(i != 0);
    return 0;
}

