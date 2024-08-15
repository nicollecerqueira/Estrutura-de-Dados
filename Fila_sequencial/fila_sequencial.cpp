#include "fila_sequencial.h"
#include <stdexcept>

using namespace std;

// Construtor
FilaSequencial::FilaSequencial(int tamanho) {
    array = new int[tamanho];
    capacidade = tamanho;
    inicio = 0;
    fim = -1;
    quantidade = 0;
}

// Destrutor
FilaSequencial::~FilaSequencial() {
    delete[] array;
}

// Inserir no fim da fila
void FilaSequencial::adicionarFim(int valor) {
    if (filaCheia()) {
        cout << "Erro: Fila cheia" << endl;
        return;
    }

    fim = (fim + 1) % capacidade;
    array[fim] = valor;
    quantidade++;
}

// Remover no início da fila
int FilaSequencial::removerInicio() {
    if (filaVazia()) {
        cout << "Erro: Fila vazia" << endl;
        return -1;
    }

    int valorRemovido = array[inicio];
    inicio = (inicio + 1) % capacidade;
    quantidade--;
    return valorRemovido;
}

// Consultar o início da fila
int FilaSequencial::verInicio() {
    if (filaVazia()) {
        cout << "Erro: Fila vazia" << endl;
        return -1;
    }
    return array[inicio];
}

// Tamanho atual da fila
int FilaSequencial::tamanho() {
    return quantidade;
}

// Verifica se a fila está vazia
bool FilaSequencial::filaVazia() {
    return (quantidade == 0);
}

// Verifica se a fila está cheia
bool FilaSequencial::filaCheia() {
    return (quantidade == capacidade);
}
