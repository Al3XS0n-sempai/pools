#pragma once

#include <cstdint>

namespace pool {
    namespace detail {
        class PoolImpl {
        public:
            PoolImpl();

            explicit PoolImpl(double water);

            double getWater();

            void tryToConnect(PoolImpl& pool);

            void addWater(double water);

            PoolImpl* getAgent();

        private:
            PoolImpl* parent_;
            uint32_t depth_of_tree_{1};
            uint32_t count_of_members_{1};
            double water_;
        };
    }

    class Pool {
    public:
        Pool() = default;

        explicit Pool(double water);

        double measure();

        void connect(Pool& pool);

        void add(double water);

    private:
        detail::PoolImpl poolImpl_;
    };
} // namespace pool
