#include "lista.h"
#include <stdexcept>

ListaSequencial::ListaSequencial(int capacidade) : capacidade(capacidade), tamanho(0) {
    lista = new int[capacidade];
}

ListaSequencial::~ListaSequencial() {
    delete[] lista;
}

bool ListaSequencial::esta_vazia() const {
    return tamanho == 0;
}

bool ListaSequencial::esta_cheia() const {
    return tamanho == capacidade;
}

int ListaSequencial::obter_tamanho() const {
    return tamanho;
}

int ListaSequencial::obter_elemento(int posicao) const {
    if (posicao < 1 || posicao > tamanho) {
        throw std::out_of_range("Posição inválida");
    }
    return lista[posicao - 1];
}

void ListaSequencial::modificar_elemento(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho) {
        throw std::out_of_range("Posição inválida");
    }
    lista[posicao - 1] = valor;
}

void ListaSequencial::inserir(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho + 1) {
        throw std::out_of_range("Posição inválida");
    }
    if (esta_cheia()) {
        throw std::overflow_error("Lista cheia");
    }
    for (int i = tamanho; i >= posicao; --i) {
        lista[i] = lista[i - 1];
    }
    lista[posicao - 1] = valor;
    tamanho++;
}

void ListaSequencial::remover(int posicao) {
    if (posicao < 1 || posicao > tamanho) {
        throw std::out_of_range("Posição inválida");
    }
    for (int i = posicao - 1; i < tamanho - 1; ++i) {
        lista[i] = lista[i + 1];
    }
    tamanho--;
}
