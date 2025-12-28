#include <sse/ingest.h>
#include <sse/types.h>

#include <iostream>
#include <cstdint>

int main(){
    const sse::IngestInput input{"website1", std::int64_t{1713123456789}, "league1", "game1",
                                    "team1", "team2", sse::BetType::Moneyline, 2.0, 123.23, 2.0, 213.2};
    sse::IngestResult output = sse::ingest_tick(input);

    switch (output){
        case sse::IngestResult::Accepted:
            std::cout << "Accepted\n";
            break;
        case sse::IngestResult::RejectedInvalid:
            std::cout << "Rejected due to invalid\n";
            break;
        case sse::IngestResult::RejectedStale:
            std::cout << "Rejected due to stale\n";
            break;
        case sse::IngestResult::Reject:
            std::cout << "Rejected\n";
            break;
    }
}