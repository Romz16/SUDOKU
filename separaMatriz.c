
// Para o Sudoku precisamos verificar as regiões, não deve haver nenhuma repetição para ser validado;

// Função que "retira" as regiões 3x3 da matriz 9x9, pega uma parte da 
// matriz e a envia para uma matriz menor;
int separaMatriz(int matriz[9][9]){
    int menorMatriz[3][3];

    for(int i = 0; i < 9; i += 3){ // a iteração ocorre de 3 em 3 para passar por cada posição na região;
        for(int j = 0; j < 9; j += 3){
            for(int k = 0; k < 3; k++){ // itera sobre os elementos da menor matriz (3x3);
                for(int l = 0; l < 3; l++){
                    menorMatriz[k][l] = matriz[k+i][l+j]; // atribui os valores de uma região na menor matriz;
                }
            }
        }
    }
    return 1;
}

// Função que recebe a menor matriz criada anteriormente e
// vai verificar para saber se a região (3x3) é válida;
int verificaMenorMatriz(int menorMatriz[3][3]){
    int contador;
    for(int repete = 1; repete <= 9; repete++){ // variável "repete" serve para percorrer toda a matriz;
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
}

