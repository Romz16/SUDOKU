
// Verifica a Linha do tabuleiro, se houverem numeros iguais
// a função retorna 0, caso contrário ela retorna 1;

int validaLinha(int matriz[9][9]){
    int igual = 1;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
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

// Verifica a Coluna do tabuleiro, se houverem numeros iguais
// a função retorna 0, caso contrário ela retorna 1;

int validaColuna(int matriz[9][9]){
    int igual = 1;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
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
