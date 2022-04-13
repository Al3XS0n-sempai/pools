#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <pool.hpp>

const uint32_t count_of_pools = 16 * 1000 * 1000;
const uint32_t count_of_connections = 6 * 1000 * 1000;
const uint32_t count_of_add = 30 * 1000 * 1000;

const uint32_t max_water = 100;

void test(std::vector<pool::Pool>& pools) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pool_id_gen(0, count_of_pools - 1);
    std::uniform_int_distribution<> water_amount_gen(0, max_water);

    std::cout << "Start to connect" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < count_of_connections; ++i) {
        int first = pool_id_gen(gen);
        int second = pool_id_gen(gen);
        pools[first].connect(pools[second]);
    }
    auto end_of_connecting = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < count_of_add; ++i) {
        int pool_id = pool_id_gen(gen);
        uint32_t water_amt = water_amount_gen(gen);
        pools[pool_id].add(water_amt);
    }
    auto end_of_adding = std::chrono::high_resolution_clock::now();

    std::cout << "Finished" << std::endl;
    std::cout << "Time for connecting" << std::endl;
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(end_of_connecting - start);
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(end_of_connecting - start);
    std::cout << "Time spend: " << millis.count() << " milliseconds or ";
    std::cout << micros.count() << " microseconds" << std::endl;
    std::cout << "Time for adding water" << std::endl;
    millis = std::chrono::duration_cast<std::chrono::milliseconds>(end_of_adding - end_of_connecting);
    micros = std::chrono::duration_cast<std::chrono::microseconds>(end_of_adding - end_of_connecting);
    std::cout << "Time spend: " << millis.count() << " milliseconds or ";
    std::cout << micros.count() << " microseconds" << std::endl;
}

int main() {
    std::vector<pool::Pool> pools(count_of_pools, pool::Pool(0));
    test(pools);
    return 0;
}
