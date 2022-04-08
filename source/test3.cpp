#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <pool.hpp>

uint64_t count_of_pools = 16u * 1000u * 1000u;
uint32_t count_of_connections = 6u * 1000u * 1000u;
uint64_t max_water = 30u * 1000u * 1000u;

void init(std::vector<pool::Pool>& pools) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniformIntDistribution(0, max_water);
    for (size_t i = 0; i < count_of_pools; ++i) {
        pools[i].add(uniformIntDistribution(gen));
    }
}

void test(std::vector<pool::Pool>& pools) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniformIntDistribution(0, count_of_pools - 1);

    std::cout << "Start to connect" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < count_of_connections; ++i) {
        int first = uniformIntDistribution(gen);
        int second = uniformIntDistribution(gen);
        pools[first].connect(pools[second]);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Finished" << std::endl;

    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time spend: " << millis.count() << " milliseconds or ";
    std::cout << micros.count() << " microseconds" << std::endl;
}

int main() {
    std::cout << "Enter count of pools: ";
    std::cin >> count_of_pools;
    std::cout << "Enter count of connections: ";
    std::cin >> count_of_connections;
    std::cout << "Enter max value of water: ";
    std::cin >> max_water;
    std::vector<pool::Pool> pools(count_of_pools);
    init(pools);
    test(pools);
    return 0;
}
