#ifndef FILA_SEQUENCIAL_H
#define FILA_SEQUENCIAL_H

#include <iostream>

class FilaSequencial {
private:
    int* array;
    int capacidade;
    int inicio;
    int fim;
    int quantidade;

public:
    FilaSequencial(int tamanho);
    ~FilaSequencial();

    void adicionarFim(int valor);
    int removerInicio();
    int verInicio();
    int tamanho();
    bool filaVazia();
    bool filaCheia();
};

#endif
