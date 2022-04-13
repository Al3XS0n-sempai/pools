#pragma once

#include <cstdint>

namespace pool {
    namespace detail {
        class PoolImpl {
        public:
            explicit PoolImpl(uint64_t water);

            double getWater();

            void tryToConnect(PoolImpl& pool);

            void addWater(uint64_t water);

            PoolImpl* getAgent();

        private:
            PoolImpl* parent_;
            uint32_t depth_of_tree_{1};
            uint32_t count_of_members_{1};
            uint64_t water_;
        };
    }

    class Pool {
    public:
        explicit Pool(uint64_t water);

        double measure();

        void connect(Pool& pool);

        void add(uint64_t water);

    private:
        detail::PoolImpl poolImpl_;
    };
} // namespace pool
