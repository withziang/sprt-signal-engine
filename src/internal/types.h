#pragma once

namespace sse{
    enum class Signal{
        None,
        Buy,
        Sell,
        Arbitrage
    };

    struct Order{ // NOT YET implemented
        Signal signal;
    };
}