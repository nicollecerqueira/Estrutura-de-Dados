#include "LinkedList.h"
#include <iostream>
#include <stdexcept>

// Construtor de Node
Node::Node(int value) : data(value), next(nullptr) {}

// Construtor de LinkedList
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Destrutor de LinkedList
LinkedList::~LinkedList() {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Verifica se a lista está vazia
bool LinkedList::isEmpty() const {
    return size == 0;
}

// Retorna o tamanho da lista
int LinkedList::getSize() const {
    return size;
}

// Obtém o valor na posição especificada
int LinkedList::get(int position) const {
    if (position < 1 || position > size) {
        throw std::out_of_range("Posição inválida");
    }
    Node* current = head;
    for (int i = 1; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}

// Modifica o valor na posição especificada
void LinkedList::set(int position, int value) {
    if (position < 1 || position > size) {
        throw std::out_of_range("Posição inválida");
    }
    Node* current = head;
    for (int i = 1; i < position; ++i) {
        current = current->next;
    }
    current->data = value;
}

// Insere um novo elemento na posição especificada
void LinkedList::insert(int position, int value) {
    if (position < 1 || position > size + 1) {
        throw std::out_of_range("Posição inválida");
    }
    Node* newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    ++size;
}

// Remove o elemento da posição especificada
void LinkedList::remove(int position) {
    if (position < 1 || position > size) {
        throw std::out_of_range("Posição inválida");
    }
    Node* toDelete = head;
    if (position == 1) {
        head = head->next;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; ++i) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }
    delete toDelete;
    --size;
}

// Imprime todos os elementos da lista
void LinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
