#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

class ListaSequencial {
private:
    int* lista;
    int capacidade;
    int tamanho;

public:
    ListaSequencial(int capacidade);
    ~ListaSequencial();

    bool esta_vazia() const;
    bool esta_cheia() const;
    int obter_tamanho() const;

    int obter_elemento(int posicao) const;
    void modificar_elemento(int posicao, int valor);

    void inserir(int posicao, int valor);
    void remover(int posicao);
};

#endif
