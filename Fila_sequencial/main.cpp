#include "fila_sequencial.h"
#include <iostream>

using namespace std;

int main() {
    FilaSequencial fila(4);

    cout << "Adicionando elementos à fila..." << endl;
    fila.adicionarFim(1);
    fila.adicionarFim(2);
    fila.adicionarFim(3);
    fila.adicionarFim(4);

    cout << "Elemento no início da fila: " << fila.verInicio() << endl;

    cout << "Tentando adicionar novo elemento à fila..." << endl;
    fila.adicionarFim(5);

    cout << "Fila está cheia? " << (fila.filaCheia() ? "Sim" : "Não") << endl;

    fila.removerInicio();
    cout << "Elemento removido. Novo elemento no início da fila: " << fila.verInicio() << endl;

    cout << "Adicionando mais elementos à fila..." << endl;
    fila.adicionarFim(6);

    cout << "Fila está cheia? " << (fila.filaCheia() ? "Sim" : "Não") << endl;

    while (!fila.filaVazia()) {
        cout << "Removendo: " << fila.removerInicio() << endl;
    }

    cout << "Fila está vazia? " << (fila.filaVazia() ? "Sim" : "Não") << endl;

    return 0;
}
