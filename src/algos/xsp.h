#pragma once
#include "algos/algo.h"

namespace sse{
    class xsp : public algo{
    public:
        bool on_market_update() override;
    };
}
