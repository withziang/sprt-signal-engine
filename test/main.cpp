#include <sse/ingest.h>
#include <sse/types.h>

#include <iostream>
#include <cstdint>
#include <chrono>

// switch (output){
//     case sse::IngestResult::Accepted:
//         std::cout << "Accepted\n";
//         break;
//     case sse::IngestResult::RejectedInvalid:
//         std::cout << "Rejected due to invalid\n";
//         break;
//     case sse::IngestResult::RejectedStale:
//         std::cout << "Rejected due to stale\n";
//         break;
// }

void ingest_basic_test(){
    const auto now = std::chrono::system_clock::now(); // TO DO: change to time cache
    int64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ).count();
    const sse::IngestInput input{"website1", now_ms, "league1", "game1",
                                    "team1", "team2", sse::BetType::Moneyline, 2.0, 123.23, 2.0, 213.2};
    sse::IngestResult output = sse::ingest_tick(input);
    std::cout << (output == sse::IngestResult::Accepted) << "\n";
}

void ingest_expired_test(){
    const auto now = std::chrono::system_clock::now(); // TO DO: change to time cache
    int64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ).count();
    const sse::IngestInput input{"website1", now_ms - 2000, "league1", "game1",
                                    "team1", "team2", sse::BetType::Moneyline, 2.0, 123.23, 2.0, 213.2};
    sse::IngestResult output = sse::ingest_tick(input);
    std::cout << (output == sse::IngestResult::RejectedStale) << "\n";
}

int main(){
    ingest_basic_test();
    ingest_expired_test();
    return 0;
}