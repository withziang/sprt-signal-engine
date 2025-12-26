#pragma once
#include <string>
#include <cstdint>

namespace sse{
    struct IngestInput{
        std::string website;
        std::int64_t timestamp;
        std::string league;
        std::string game_name;
        std::string team1;
        std::string team2;
        sse::BetType bet_type;
        int team1_line;
        double team1_odd;
        int team2_line;
        double team2_odd;
    };

    enum class BetType{
        MoneyLine,
        Spread,
        Total
    };

    enum class IngestResult{
        Accepted,
        RejectedInvalid,
        RejectedStale
    };
};