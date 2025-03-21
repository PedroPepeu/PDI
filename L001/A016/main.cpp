// Aplicar o algoritmo para a equalização de histograma na imagem abaixo.
// 2 1 2 1 3 4 3 3 6 7
// 9 8 6 6 3 3 2 2 3 3
// 15 3 12 4 3 3 11 10 2 2
// 11 2 1 0 0 2 13 2 3 4
// 9 2 1 14 1 3 11 3 7 5
// 1 3 0 1 0 3 3 3 2 9
// 6 7 5 3 11 2 5 6 4 4
// 0 2 2 3 2 4 7 11 2 10
// 15 3 1 3 3 3 2 1 4 9
// 12 4 5 7 0 4 8 9 8 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para exibir a imagem como matriz
void exibirImagem(const vector<vector<int>>& imagem) {
    for (const auto& linha : imagem) {
        for (int pixel : linha) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

// Função para aplicar a equalização de histograma na imagem
vector<vector<int>> equalizarImagem(const vector<vector<int>>& imagem) {
    // Definir a tabela de CDF para a transformação
    vector<int> cdf_transformada = {1, 2, 5, 8, 10, 10, 11, 12, 12, 13, 13, 14, 14, 15, 15};

    int numLinhas = imagem.size();
    int numColunas = imagem[0].size();

    // Criar a imagem equalizada
    vector<vector<int>> imagemEqualizada(numLinhas, vector<int>(numColunas));

    // Aplicar a transformação de CDF
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            // Substituir o valor do pixel com a transformação
            int valorOriginal = imagem[i][j];
            imagemEqualizada[i][j] = cdf_transformada[valorOriginal];
        }
    }

    return imagemEqualizada;
}

int main() {
    // Definir a matriz de imagem fornecida (tamanho 10x10)
    vector<vector<int>> imagem = {
        {2, 1, 2, 1, 3, 4, 3, 3, 6, 7},
        {9, 8, 6, 6, 3, 3, 2, 2, 3, 3},
        {15, 3, 12, 4, 3, 3, 11, 10, 2, 2},
        {11, 2, 1, 0, 0, 2, 13, 2, 3, 4},
        {9, 2, 1, 14, 1, 3, 11, 3, 7, 5},
        {1, 3, 0, 1, 0, 3, 3, 3, 2, 9},
        {6, 7, 5, 3, 11, 2, 5, 6, 4, 4},
        {0, 2, 2, 3, 2, 4, 7, 11, 2, 10},
        {15, 3, 1, 3, 3, 3, 2, 1, 4, 9},
        {12, 4, 5, 7, 0, 4, 8, 9, 8, 1}
    };

    cout << "Imagem Original:" << endl;
    exibirImagem(imagem);

    // Aplicar a equalização de histograma
    vector<vector<int>> imagemEqualizada = equalizarImagem(imagem);

    cout << "\nImagem Equalizada:" << endl;
    exibirImagem(imagemEqualizada);

    return 0;
}
