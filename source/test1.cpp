#include <iostream>
#include <pool.hpp>

int main() {
    pool::Pool pool1(10.);
    pool::Pool pool2(20.);
    std::cout << "water in pool_1 before connection " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 before connection " << pool2.measure() << std::endl;
    pool1.connect(pool2);
    pool1.connect(pool2);
    std::cout << "water in pool_1 after connection 1-2 " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 after connection 1-2 " << pool2.measure() << std::endl;
    pool1.add(20.);
    std::cout << "water in pool_1 after adding 20 " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 after adding 20 " << pool2.measure() << std::endl;
    pool2.add(10.);
    std::cout << "water in pool_1 after adding 10 " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 after adding 10 " << pool2.measure() << std::endl;
    pool::Pool pool3(10.);
    pool::Pool pool4(33.);
    std::cout << "water in pool_1 before connection " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 before connection " << pool2.measure() << std::endl;
    std::cout << "water in pool_3 before connection " << pool3.measure() << std::endl;
    std::cout << "water in pool_4 before connection " << pool4.measure() << std::endl;
    pool3.connect(pool4);
    std::cout << "water in pool_1 after connection 3-4 " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 after connection 3-4 " << pool2.measure() << std::endl;
    std::cout << "water in pool_3 after connection 3-4 " << pool3.measure() << std::endl;
    std::cout << "water in pool_4 after connection 3-4 " << pool4.measure() << std::endl;
    pool1.connect(pool3);
    std::cout << "water in pool_1 after connection 3-1 " << pool1.measure() << std::endl;
    std::cout << "water in pool_2 after connection 3-1 " << pool2.measure() << std::endl;
    std::cout << "water in pool_3 after connection 3-1 " << pool3.measure() << std::endl;
    std::cout << "water in pool_4 after connection 3-1 " << pool4.measure() << std::endl;
    return 0;
}
