#include <iostream>
#include <vector>
#include <chrono>
#include "selection-sort.cpp"
#include "insertion-sort.cpp"

// Função para imprimir um vetor
void print_vector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> sizes;
    std::ifstream size_file("nstancias-num");
    int size;
    
    while (size_file >> size) {
        sizes.push_back(size);
    }

    size_file.close();

    for (int n : sizes) {
        std::vector<int> vec(n);
        std::srand(std::time(nullptr));
        for (int& num : vec) {
            num = std::rand() % 1000;
        }

        std::vector<int> vec_copy;

        // Testar Selection Sort
        vec_copy = vec;
        auto start = std::chrono::high_resolution_clock::now();
        selection_sort(vec_copy);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> selection_sort_time = end - start;

        std::ofstream selection_sort_log("selection_sort_log.txt", std::ios::app);
        selection_sort_log << "Array size: " << n << std::endl;
        selection_sort_log << "Selection Sort Time: " << selection_sort_time.count() << " seconds" << std::endl;
        selection_sort_log.close();

        // Testar Insertion Sort
        vec_copy = vec;
        start = std::chrono::high_resolution_clock::now();
        insertion_sort(vec_copy);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> insertion_sort_time = end - start;

        std::ofstream insertion_sort_log("insertion_sort_log.txt", std::ios::app);
        insertion_sort_log << "Array size: " << n << std::endl;
        insertion_sort_log << "Insertion Sort Time: " << insertion_sort_time.count() << " seconds" << std::endl;
        insertion_sort_log.close();
    }

    return 0;
}
