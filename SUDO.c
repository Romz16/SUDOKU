#include <stdio.h>         //entrada/saída
#include <math.h>          //fornece um conjunto de funções para operações matemáticas
#include <stdlib.h>        //funções envolvendo alocação de memória, controle de processos, conversões e outras
#include <string.h>        //fornece meios para a manipulação das strings
#define TAM 9



//Função para criar e alocar matriz de inteiros
int **alocaMatrizInt()
{
    int **matriz = malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++)
        matriz[i] = malloc(TAM * sizeof(int));

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        
            matriz[i][j] = 0;
    }
    return matriz;
}


//Desaloca matriz de inteiros
void desalocarInt(int **matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

//Função que irá imprimir o menu com os comandos possiveis
char *MenuInicial()
{
    char *menuIni = malloc(25 * sizeof(char)); //Alocação
    printf("Bem vindo ao SUDOKU!\n");
    printf("O que deseja fazer:\n\n");

    printf("1.Comecar um novo jogo\n2.Ver instrucoes do jogo\n");
    printf("\n\nDigite a opcao(Digite \"sair\" a qualquer momento para sair do jogo): ");
    scanf("%s", menuIni); //armazena o comando dado pelo usuario
    getc(stdin);

    return menuIni;
}

//Intruções do jogo
void Instrucoes()
{
    printf("\nInstrucoes\n\n");

    printf("- Para iniciar um novo jogo eh necessario um arquivo de texto onde tenha um tabuleiro\n");
    printf("1ª Regra - Cada linha deve conter os números de 1 a 9, sem repetições\n");
    printf("2ª Regra - Os números de 1 a 9 apenas podem estar presentes uma vez por coluna\n");
    printf("3ª Regra - Cada dígito apenas pode estar presente uma vez por grupo\n");
    printf("4ª Regra - O valor da soma de cada linha, coluna e grupo é de 45\n");
   

    printf("Para jogar\n\n");
    printf("Comandos:\n\n- \n\n");
    printf("- Resolver o jogo todo -> resolver\n");
}

void TabuleiroInicializa(char *nomeArq){
    int tabela[TAM][TAM];
    FILE *arq = fopen(nomeArq,"r");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        
            fscanf(arq,"%d",&tabela[i][j]);
        
    }
    fclose(arq);
    printf("tudo ok ate aqui");
}

//Comeca um jogo novo;
void NovoJogo()
{
    // Lendo arquivo de texto de inicio
    char nomeArq[50];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    getc(stdin);
    if (strcmp(nomeArq, "sair") == 0 || strcmp(nomeArq, "SAIR") == 0)
    { //caso o usuario decida sair
        exit(0);
    }
    if (strstr(nomeArq, ".txt") == NULL)
    { //Caso não tenha .txt no nome do arquivo
        printf("O arquivo precisa ser .txt\n");
        exit(0);
    }
    TabuleiroInicializa( nomeArq);
 
}

int main()
{ //função principal
    char *menu;
    do
    {
        menu = MenuInicial();
        if (strcmp(menu, "1") == 0)
            NovoJogo();
          
        else if (strcmp(menu, "2") == 0)
            Instrucoes();
        else if (strcmp(menu, "sair") == 0)
            return 0;
        else
            printf("Comando Invalido");

    } while (*menu == '2'); //Enquanto a opção selecionada for a de instruçoes o menu ficara em loop

    free(menu);
    return 0;
}
