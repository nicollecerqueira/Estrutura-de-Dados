#include <vector>
#include "insertion-sort.h"

// Função de ordenação Insertion Sort
void insertion_sort(std::vector<int>& vec) {
    size_t n = vec.size();
    for (size_t i = 1; i < n; ++i) {
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}
