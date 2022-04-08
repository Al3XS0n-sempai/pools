#include "pool.hpp"

namespace pool {
    namespace detail {
        PoolImpl::PoolImpl() :
            water_(0), parent_(nullptr) {
            parent_ = this;
        }
        PoolImpl::PoolImpl(double water) :
            water_(water), parent_(nullptr) {
            parent_ = this;
        }

        double PoolImpl::getWater() {
            PoolImpl* agent = getAgent();
            return (1. * agent->water_) / agent->count_of_members_;
        }

        void PoolImpl::tryToConnect(PoolImpl& pool) {
            PoolImpl* agent1 = getAgent();
            PoolImpl* agent2 = pool.getAgent();
            if (agent1 == agent2) {
                return;
            }
            if (agent1->depth_of_tree_ <= agent2->depth_of_tree_) {
                agent2->count_of_members_ += agent1->count_of_members_;
                agent2->water_ += agent1->water_;
                agent1->parent_ = agent2;
                agent2->depth_of_tree_ += (agent1->depth_of_tree_ == agent2->depth_of_tree_);
            } else {
                agent1->count_of_members_ += agent2->count_of_members_;
                agent1->water_ += agent2->water_;
                agent2->parent_ = agent1;
            }
        }

        PoolImpl* PoolImpl::getAgent() {
            if (parent_ != this) {
                parent_ = parent_->getAgent();
            }
            return parent_;
        }

        void PoolImpl::addWater(double water) {
            PoolImpl* agent = getAgent();
            agent->water_ += water;
        }
    }

    double Pool::measure() {
        return poolImpl_.getWater();
    }

    void Pool::connect(Pool &pool) {
        poolImpl_.tryToConnect(pool.poolImpl_);
    }

    void Pool::add(double water) {
        poolImpl_.addWater(water);
    }

    Pool::Pool(double water) : poolImpl_(water) {
    }
} // namespace pool