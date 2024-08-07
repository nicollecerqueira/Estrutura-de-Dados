#include "LinkedList.h"
#include <iostream>

void testLinkedList() {
    LinkedList list;
    std::cout << "Testando lista encadeada:" << std::endl;

    // Verificar se a lista está vazia
    std::cout << "Lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;

    // Inserir elementos
    list.insert(1, 10);
    list.insert(2, 20);
    list.insert(3, 30);
    list.insert(2, 15);  // Inserir 15 na posição 2

    // Imprimir lista
    std::cout << "Lista após inserções: ";
    list.printList();

    // Obter valor na posição 3
    std::cout << "Valor na posição 3: " << list.get(3) << std::endl;

    // Modificar valor na posição 3
    list.set(3, 25);

    // Imprimir lista após modificação
    std::cout << "Lista após modificação: ";
    list.printList();

    // Remover elemento na posição 2
    list.remove(2);

    // Imprimir lista após remoção
    std::cout << "Lista após remoção: ";
    list.printList();

    // Obter o tamanho da lista
    std::cout << "Tamanho da lista: " << list.getSize() << std::endl;

    // Testar se a lista está vazia
    list.remove(1);
    list.remove(1);
    list.remove(1);
    std::cout << "Lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;
}

int main() {
    testLinkedList();
    return 0;
}
