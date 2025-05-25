#include <iostream>
#include <random>
#include <vector>

int main() {
    // Random number generator setup
    std::random_device rd;  // Seed
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(10.0, 100.0); // Range [10, 100)

    std::vector<double> randomNumbers;

    std::cout << "Generating 25 random real numbers between 10 and 100:\n\n";
    for (int i = 0; i < 25; ++i) {
        double num = dis(gen);
        randomNumbers.push_back(num);
        std::cout << num << "\n";
    }

    return 0;
}
