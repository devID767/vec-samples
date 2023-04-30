#include <chrono>
#include <iostream>
#include <random>
#include <vector>

int main() {
    const int N = 100000000;
    std::vector<double> arr(N);

    // Fill the array with random values between 0 and 1
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (int i = 0; i < N; i++) {
        arr[i] = dist(rng);
    }

    auto start = std::chrono::high_resolution_clock::now();

    // Calculate the sum of the array elements
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Sum of " << N << " elements: " << sum << std::endl;
    std::cout << "Time taken: " << duration.count() << "ms" << std::endl;

    return 0;
}