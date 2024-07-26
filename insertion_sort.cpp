#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& arr) {
    int tamanho, aux, i, j;

    tamanho = arr.size();
    for (i = 1; i < tamanho; i++) {
        aux = arr[i]; // 
        j = i - 1;
        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = aux;
    }
}

extern void print_array(std::vector<int>& arr);