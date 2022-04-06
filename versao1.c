#include <stdio.h>         //entrada/saída
#include <math.h>          //fornece um conjunto de funções para operações matemáticas
#include <stdlib.h>        //funções envolvendo alocação de memória, controle de processos, conversões e outras
#include <string.h>        //fornece meios para a manipulação das strings7
#include <stdbool.h>
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
    printf("1ª Regra - Cada linha deve conter os números de 1 a 9, sem repetições;\n");
    printf("2ª Regra - Os números de 1 a 9 apenas podem estar presentes uma vez por coluna;\n");
    printf("3ª Regra - Cada dígito apenas pode estar presente uma vez por grupo;\n");
    printf("4ª Regra - O valor da soma de cada linha, coluna e grupo é de 45;\n\n");
   

    printf("Para jogar:\n\n");
    printf("-Comandos: Quando lhe for requerido as coordenadas passe primeiro X e apos Y, de forma que"); 
    printf(" haja um espaço entre cada numero EX:[4 1], \nposteriormente informe algum numero de 1 a 9; \n");
    printf("- Resolver o jogo todo -> passe uma das coordenadas como 0 ( 0, 1 );\n");
    printf("- Sair do jogo -> passe as duas coordenadas como 0 ( 0, 0 );\n\n");
}

int validaLinha(int matriz[9][9]){
    int igual = 1;
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            for(int k = 0; k < TAM; k++){
                if(j != k){
                    if(matriz[i][j] == matriz[i][k]){ //verifica se há igualdade;
                        igual = 0;
                    }
                }
            }
        }
    }
    return igual;
}

int validaColuna(int matriz[TAM][TAM]){
    int igual = 1;
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            for(int k = 0; k < TAM; k++){
                if(i != k){
                    if(matriz[i][j] == matriz[k][k]){ //verifica se há igualdade;
                        igual = 0;
                    }
                }
            }
        }
    }
    return igual;
}

// falta incluir;
/*int separaMatriz(int matriz[TAM][TAM]){
    int menorMatriz[3][3];

    for(int i = 0; i < TAM; i += 3){ // a iteração ocorre de 3 em 3 para passar por cada posição na região;
        for(int j = 0; j < TAM; j += 3){
            for(int k = 0; k < 3; k++){ // itera sobre os elementos da menor matriz (3x3);
                for(int l = 0; l < 3; l++){
                    menorMatriz[k][l] = matriz[k+i][l+j]; // atribui os valores de uma região na menor matriz;
                }
            }
        }
    }
    return 1;
}*/

// falta incluir;
/*int verificaMenorMatriz(int menorMatriz[3][3]){
    int contador;
    for(int repete = 1; repete <= TAM; repete++){ // variável "repete" serve para percorrer toda a matriz;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(menorMatriz[i][j] == repete){ // se "repete" for achado mais de uma vez, existem numeros iguais;
                    contador++; // variável "contador" serve para contar quantas vezes um número se repetiu;
                }
            }
        }

        if(contador > 1){ // se houve repetição de números, a função retorna 0 (Erro no Sudoku);
            return 0;
        }

        contador = 0; // contador zerado significa que não houve repetições, a região verificada é válida;
    }
    return 1;
}*/

int** TabuleiroInicializa(char *nomeArq){
    int i, j;
    int** puzzle;
    int arrayPuzzle[9][9];

    FILE *arq = fopen(nomeArq,"r");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        
            fscanf(arq,"%d",&arrayPuzzle[i][j]);
        
    }
    fclose(arq);

    puzzle = (int**)malloc(sizeof(int*) * TAM);

    for (i = 0; i < TAM; i++){
        puzzle[i] = (int*)malloc(sizeof(int) * TAM);
        for(j = 0; j < TAM; j++){
            puzzle[i][j] = arrayPuzzle[i][j];
        }
    }
    
    return puzzle;
}

int** copiaPuzzle(int** puzzle){
    int i, j;
    int** copiaTab;

    copiaTab = (int**)malloc(sizeof(int*) * TAM);
    for (i = 0; i < TAM; i++){
        copiaTab[i] = (int*)malloc(sizeof(int) * TAM);
        for(j = 0; j < TAM; j++){
            copiaTab[i][j] = puzzle[i][j];
        }
    }
    return copiaTab;
}

bool valoresValidos(int** puzzle, int* linha, int* coluna){
    int i, j;

    for (i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if (puzzle[i][j] == 0){
                *linha = i;
                *coluna  = j;
                return true;
            }
        }
    }

    return false;
}

bool Ehvalido(int** puzzle, int linha, int coluna, int val){
    int i, j;
    int linhabloco, colunabloco;

    //CHECK VERTICAL
    for(i = 0; i < TAM; i++){
        if(validaLinha(puzzle) == 0){
            // valores iguais na linha
            return 0;
        }else{
            if (puzzle[i][coluna] == val)
                return false;
        }

    }

    //CHECK HORIZONTAL
    for(j = 0; j < TAM; j++){
        if(validaColuna(puzzle) == 0){
            // valores iguais na coluna
            return 0;
        }else{
            if (puzzle[linha][j] == val)
                return false;
        }

    }

    //CHECK SQUARE
    linhabloco = linha - linha % 3;
    colunabloco = coluna - coluna % 3;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(puzzle[linhabloco + i][colunabloco + j] == val)
                return false;
        }
    }

    return true;
}

bool Resolver(int** puzzle){
    int i, j, val;

    if(!valoresValidos(puzzle, &i, &j))
        return true;

    for(val = 1; val < 10; val++){
        if(Ehvalido(puzzle, i, j, val)){
            puzzle[i][j] = val;
            if(Resolver(puzzle))
                return true;
            else
                puzzle[i][j] = 0;
        }
    }
    return false;
}


void printPuzzle(int** puzzle){
    int i, j, a;

    printf("\n");
    printf(" 0 | 1  2  3 | 4  5  6 | 7  8  9 | X\n");
    printf(" ---------------------------------\n");
    for (i = 0, a = 1; i < TAM; i++, a++){
        for(j = 0; j < TAM; j++){
            if (j == 0)
                printf(" %d |", a);
            else if ((j) % 3 == 0)
                printf("|");
            printf(" %d ", puzzle[i][j]);
            if (j == 8)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
            printf(" ---------------------------------\n");
    }
    printf(" Y\n");
}

void Jogo(int** userPuzzle, int** tempPuzzle,int **Puzzle){
    int i, j;
    int posX, posY, userVal;

    while(1){
    if(!valoresValidos(userPuzzle, &i, &j)){
        printf("\nPARABENS, VOCE CONSEGUIU RESOLVER SOZINHO!!!\n");
        return;
    }

    

    printf("\n ADICIONE OS VALORES PARA AS COORDENADAS NO FORMATO:\"X Y\":\n");
    scanf("%d %d", &posX, &posY);

    while(1){
        if ((posX > TAM) || (posY > TAM) || (userPuzzle[posY - 1][posX - 1] != 0)){
            printf("\nSinto muito, esse valor nao eh valido, tente novamente\n");
            scanf("%d %d",&posX, &posY);
        }
        else if ((posX==0) || (posY==0))
        {   getchar();
            Resolver(Puzzle);
            printf("\n PUZZLE RESOLVIDO:\n");
            printPuzzle(Puzzle);
            return;
        }
        else if((posX==0) && (posY==0))
        {
            getchar();
            printf("\nSaindo...");
            exit(0);
        }
        
        else {
            posX -= 1;
            posY -= 1;
            break;
        }

    }


    printf("\nAdicione um valor de  1 a 9\n");
    scanf("%d", &userVal);
    while(1){
        if((userVal > TAM) || (userVal < 1)){
            printf("\nvalor invalido, tente novamente :\n");
            scanf("%d", &userVal);
        }
        else
             break;
    }

    if(Ehvalido(userPuzzle, posY, posX, userVal))
        userPuzzle[posY][posX] = userVal;
    else{
         userPuzzle[posY][posX] = userVal;
         printf("Alguma coisa deu errado...  Invalidos:\n\n");
    }
    for (i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            tempPuzzle[i][j] = userPuzzle[i][j];
        }
    }

  
    getchar();
    printPuzzle(userPuzzle);
    }

    return;
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
    int** puzzle = TabuleiroInicializa( nomeArq);
    int** userPuzzle = copiaPuzzle(puzzle);
    int** tempPuzzle = copiaPuzzle(puzzle);
    printPuzzle(userPuzzle);
    Jogo(userPuzzle,tempPuzzle,puzzle);
    free(puzzle);
    free(userPuzzle);
    free(tempPuzzle);
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