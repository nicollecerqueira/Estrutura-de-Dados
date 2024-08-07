class ListaSequencial:
    def __init__(self, capacidade):
        self.capacidade = capacidade
        self.lista = [None] * capacidade
        self.tamanho = 0

    def esta_vazia(self):
        return self.tamanho == 0

    def esta_cheia(self):
        return self.tamanho == self.capacidade

    def obter_tamanho(self):
        return self.tamanho

    def obter_elemento(self, posicao):
        if posicao < 1 or posicao > self.tamanho:
            raise IndexError("Posição inválida")
        return self.lista[posicao - 1]

    def modificar_elemento(self, posicao, valor):
        if posicao < 1 or posicao > self.tamanho:
            raise IndexError("Posição inválida")
        self.lista[posicao - 1] = valor

    def inserir(self, posicao, valor):
        if posicao < 1 or posicao > self.tamanho + 1:
            raise IndexError("Posição inválida")
        if self.esta_cheia():
            raise OverflowError("Lista cheia")
        for i in range(self.tamanho, posicao - 1, -1):
            self.lista[i] = self.lista[i - 1]
        self.lista[posicao - 1] = valor
        self.tamanho += 1

    def remover(self, posicao):
        if posicao < 1 or posicao > self.tamanho:
            raise IndexError("Posição inválida")
        for i in range(posicao - 1, self.tamanho - 1):
            self.lista[i] = self.lista[i + 1]
        self.lista[self.tamanho - 1] = None
        self.tamanho -= 1

# Exemplo de uso e testes
if __name__ == "__main__":
    lista = ListaSequencial(5)
    
    print("Inserindo elementos na lista...")
    lista.inserir(1, 10)
    lista.inserir(2, 20)
    lista.inserir(3, 30)
    lista.inserir(2, 15)
    
    print("Lista atual:", [lista.obter_elemento(i+1) for i in range(lista.obter_tamanho())])
    
    print("Modificando o valor na posição 2 para 25...")
    lista.modificar_elemento(2, 25)
    
    print("Lista atualizada:", [lista.obter_elemento(i+1) for i in range(lista.obter_tamanho())])
    
    print("Removendo o elemento na posição 3...")
    lista.remover(3)
    
    print("Lista final:", [lista.obter_elemento(i+1) for i in range(lista.obter_tamanho())])
