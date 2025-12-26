#pragma once
#include <string>
#include <cstdint>

namespace sse{
    enum class BetType{
        Moneyline,
        Spread,
        Total
    };

    enum class IngestResult{
        Accepted,
        RejectedInvalid,
        RejectedStale
    };
    
    struct IngestInput{
        std::string website;
        std::int64_t timestamp;
        std::string league;
        std::string game_name;
        std::string team1;
        std::string team2;
        BetType bet_type;
        double team1_line;
        double team1_odd;
        double team2_line;
        double team2_odd;
    };
}