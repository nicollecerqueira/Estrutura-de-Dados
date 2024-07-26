#!/bin/bash

# Executar o algoritmo em um arquivo específico
executar_algoritmo() {
    algoritmo=$1
    arquivo=$2
    echo "Testando $algoritmo sort com o arquivo de entrada $arquivo"
    ./main $algoritmo $arquivo
    echo
}

g++ -o main main.cpp selection-sort.cpp insertion-sort.cpp

> selection_sort_log.txt
> insertion_sort_log.txt
> comparacao_log.txt

if [ "$#" -eq 2 ]; then
    # Se apenas um arquivo específico for fornecido, executa o algoritmo
    algoritmo=$1
    arquivo=$2
    executar_algoritmo $algoritmo $arquivo
else
    # Executa os testes para todos os arquivos e algoritmos
    for algoritmo in selection insertion; do
        for arquivo in instancias-num/*.in; do
            executar_algoritmo $algoritmo $arquivo
        done
    done

    # Cria um arquivo de comparação e compara os tempos de execução
    echo "Tempos de execução (selection-sort vs insertion-sort)" > comparacao_log.txt

    for arquivo in instancias-num/*.in; do
        selection_time=$(grep "$arquivo" selection_sort_log.txt | awk -F '; ' '{print $3}' | awk '{print $4}')
        insertion_time=$(grep "$arquivo" insertion_sort_log.txt | awk -F '; ' '{print $3}' | awk '{print $4}')
        echo "Instancia: $arquivo; Selection: $selection_time segundos; Insertion: $insertion_time segundos" >> comparacao_log.txt
    done

    echo "Comparação dos tempos de execução completa."
fi