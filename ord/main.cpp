#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

void selection_sort(vector<int>& arr);
void insertion_sort(vector<int>& arr);
extern void print_array(std::vector<int>& arr);

void read_file(string& filename, vector<int>& arr) {
    ifstream file(filename);

    if (!file) {
        cout << "Não foi possível abrir o arquivo " << filename << endl;
        return;
    }

    int tamanho;
    file >> tamanho;
    arr.resize(tamanho);
    for (int i = 0; i < tamanho; i++) {
        file >> arr[i];
    }
}

void marca_tempo_exec(string& algoritmo, string& filename, double time_used) {
    ofstream arquivo_log(algoritmo + "_sort_log.txt", ios::app); // Abre um arquivo de saída em modo de "append"
    arquivo_log << "Algoritmo: " << algoritmo << "; Instancia: " << filename << "; Tempo de execução: " << time_used << " segundos" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) { 
        cout << "Uso incorreto do algoritmo: " << argv[0] << " <algoritmo> <arquivo_de_entrada>" << endl;
        return 1;
    }

    string algoritmo = argv[1];
    string file_entrada = argv[2];
    vector<int> arr;

    read_file(file_entrada, arr);

    clock_t start, end;
    double cpu_time_used;

    if (algoritmo == "selection") {
        start = clock(); // Marca o tempo
        selection_sort(arr);
        end = clock();
    } else if (algoritmo == "insertion") {
        start = clock();
        insertion_sort(arr);
        end = clock();
    } else {
        cout << "Algoritmo não reconhecido: " << algoritmo << endl;
        return 1;
    }

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC; // Calcula o tempo utilizado para rodar
    cout << "Resultado do array ordenado: " << endl;
    print_array(arr);
    cout << "Tempo de execução do " << algoritmo << " sort: " << cpu_time_used << " segundos" << endl;

    // Marca o empo de execução no arquivo de log
    marca_tempo_exec(algoritmo, file_entrada, cpu_time_used);

    return 0;
}