import sys
from collections import deque

class Grafo:
    def __init__(self, matriz_dist):
        
        # inicializa o grafo com a matriz de distâncias e cria a lista de adjacência
        self.num_vertices = len(matriz_dist)
        self.matriz_dist = matriz_dist
        self.matriz_adjacencia = self.criar_matriz_adj(matriz_dist)

    def criar_matriz_adj(self, matriz_dist):
        
        #cria a lista de adjacência a partir da matriz de distâncias
        
        matriz_adj = []

        for i in range(self.num_vertices):
            adjacencias = []
            for j in range(self.num_vertices):
                if matriz_dist[i][j] != 0:  # se existe uma conexão
                    adjacencias.append((j, matriz_dist[i][j]))  # adiciona (vértice, peso)
            adjacencias.sort()  # ordena as adjacências pelo vértice
            matriz_adj.append(adjacencias)

        return matriz_adj

    def BFS(self, inicio, fim):
        
        #busca em Largura (BFS) para encontrar o caminho entre dois vértices.
        
        status = [0] * self.num_vertices  # 0: não visitado, 1: visitado
        parent = [-1] * self.num_vertices  # armazena o vértice anterior no caminho
        fila = deque([inicio])
        status[inicio] = 1

        while fila:
            vertice_atual = fila.popleft()

            for adj in self.matriz_adjacencia[vertice_atual]:
                if status[adj[0]] == 0:
                    status[adj[0]] = 1
                    parent[adj[0]] = vertice_atual
                    fila.append(adj[0])
                    if adj[0] == fim:
                        return parent  # retorna o caminho encontrado

        return parent  # retorna o vetor parent mesmo que não tenha encontrado

    def encontrar_caminho(self, parent, inicio, fim):
        
        #reconstrói o caminho da BFS usando o vetor parent
        
        if parent[fim] == -1:
            print(f"Não foi encontrado caminho entre {inicio} e {fim}")
            return []
        
        caminho = []
        while fim != inicio:
            caminho.insert(0, fim)
            fim = parent[fim]
        caminho.insert(0, inicio)
        return caminho

    def DFS(self):
        
        #busca em Profundidade (DFS) iterativa que gera uma floresta
        
        status = [0] * self.num_vertices  # 0: não visitado, 1: visitado
        pilha = []
        floresta = []

        for i in range(self.num_vertices):
            if status[i] == 0:  # Se o vértice ainda não foi visitado
                arvore = []
                pilha.append(i)

                while pilha:
                    vertice_atual = pilha.pop()
                    if status[vertice_atual] == 0:
                        status[vertice_atual] = 1
                        arvore.append(vertice_atual)

                        for adj in sorted(self.matriz_adjacencia[vertice_atual], key=lambda x: x[0], reverse=True):
                            if status[adj[0]] == 0:
                                pilha.append(adj[0])

                floresta.append(arvore)  # Adiciona a árvore à floresta

        return floresta

def ler_caso(arquivo):
    
    #lê a matriz de distâncias a partir de um arquivo
    with open(arquivo, 'r') as f:
        linhas = f.readlines()
        matriz_dist = []

        for i, linha in enumerate(linhas):
            if i == 0:
                continue  # Ignora a primeira linha
            matriz_dist.append(list(map(int, linha.split())))

        return matriz_dist

def imprime_matriz_dist(matriz_dist):
    
    #imprime a matriz de distâncias
    
    print("Matriz de distâncias:")
    for linha in matriz_dist:
        print(" ".join(map(str, linha)))

def imprime_matriz_adj(matriz_adj):
    
    #imprime a lista de adjacência

    print("Lista de adjacência:")
    for i, adj in enumerate(matriz_adj):
        adj_str = " ".join(f"({v}, {peso})" for v, peso in adj)
        print(f"Vértice {i}: {adj_str}")

def main():
    if len(sys.argv) < 2:
        print("Uso: python main.py [nome_do_arquivo]")
        return

    arquivo = 'casos/' + sys.argv[1]  # adapte o caminho conforme necessário

    # lê a matriz de distâncias a partir do arquivo
    matriz_dist = ler_caso(arquivo)
    grafo = Grafo(matriz_dist)

    # imprime as representações do grafo
    imprime_matriz_dist(matriz_dist)
    imprime_matriz_adj(grafo.matriz_adjacencia)

    # solicita ao usuário os vértices de início e fim
    inicio = int(input("Insira o primeiro vértice: "))
    fim = int(input("Insira o segundo vértice: "))

    # realiza a BFS
    parent = grafo.BFS(inicio, fim)
    caminho = grafo.encontrar_caminho(parent, inicio, fim)
    print(f"Caminho encontrado: {' -> '.join(map(str, caminho))}")

    # realiza a DFS
    floresta = grafo.DFS()
    print(f"Floresta de árvores DFS: {floresta}")

if __name__ == "__main__":
    main()
