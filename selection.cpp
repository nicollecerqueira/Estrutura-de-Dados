#include <vector>
#include <algorithm>
#include "selection-sort.h"

// Função de ordenação Selection Sort
void selection_sort(std::vector<int>& vec) {
    size_t n = vec.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(vec[min_idx], vec[i]);
    }
}