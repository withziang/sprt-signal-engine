#pragma once
#include "algos/algo.h"

namespace sse{
    class Xsp : public Algo{
    public:
        bool on_market_update() override;
    };
}
