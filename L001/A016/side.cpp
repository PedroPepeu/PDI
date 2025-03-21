#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para calcular o histograma da imagem
vector<int> calcularHistograma(const vector<vector<int>>& imagem) {
    vector<int> histograma(256, 0); // Supondo intensidade de pixel de 0 a 255

    for (const auto& linha : imagem) {
        for (int pixel : linha) {
            histograma[pixel]++;
        }
    }

    return histograma;
}

// Função para calcular a CDF (Função de Distribuição Acumulada)
vector<int> calcularCDF(const vector<int>& histograma) {
    vector<int> cdf(256, 0);
    cdf[0] = histograma[0];

    // Calcula a soma cumulativa dos valores do histograma
    for (int i = 1; i < 256; ++i) {
        cdf[i] = cdf[i - 1] + histograma[i];
    }

    return cdf;
}

// Função para normalizar a CDF
vector<int> normalizarCDF(const vector<int>& cdf, int numPixels) {
    vector<int> cdfNormalizada(256, 0);
    
    int minCDF = *min_element(cdf.begin(), cdf.end());

    // Normaliza os valores da CDF
    for (int i = 0; i < 256; ++i) {
        cdfNormalizada[i] = (cdf[i] - minCDF) * 255 / (numPixels - minCDF);
    }

    return cdfNormalizada;
}

// Função para aplicar a equalização de histograma na imagem
vector<vector<int>> equalizarImagem(const vector<vector<int>>& imagem) {
    int numLinhas = imagem.size();
    int numColunas = imagem[0].size();
    int numPixels = numLinhas * numColunas;

    // Passo 1: Calcular o histograma
    vector<int> histograma = calcularHistograma(imagem);

    // Passo 2: Calcular a CDF
    vector<int> cdf = calcularCDF(histograma);

    // Passo 3: Normalizar a CDF
    vector<int> cdfNormalizada = normalizarCDF(cdf, numPixels);

    // Passo 4: Criar a imagem equalizada
    vector<vector<int>> imagemEqualizada(numLinhas, vector<int>(numColunas));

    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            imagemEqualizada[i][j] = cdfNormalizada[imagem[i][j]];
        }
    }

    return imagemEqualizada;
}

// Função para exibir a imagem como matriz
void exibirImagem(const vector<vector<int>>& imagem) {
    for (const auto& linha : imagem) {
        for (int pixel : linha) {
            cout << pixel << " ";
        }
        cout << endl;
    }
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
