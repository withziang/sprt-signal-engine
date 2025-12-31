#include <sse/ingest.h>
#include <sse/types.h>
#include "internal/log.h"

#include <chrono>
#include <cstdint>

namespace sse{
    constexpr std::int64_t MAX_TIMESTAMP_STALE_TOLERANCE = 1000;

    [[nodiscard]] bool is_ingest_invalid(const IngestInput& input){
        return false; // STUB
    }

    [[nodiscard]] bool is_ingest_expired(std::int64_t timestamp){
        const auto now = std::chrono::system_clock::now(); // TO DO: change to time cache
        int64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()
        ).count();
        return timestamp + MAX_TIMESTAMP_STALE_TOLERANCE < now_ms;
    }

    IngestResult ingest_tick(const IngestInput& input) noexcept {
        if (__builtin_expect(is_ingest_invalid(input), 0)){
            return IngestResult::RejectedInvalid;
        }
        if (__builtin_expect(is_ingest_expired(input.timestamp), 0)){
            return IngestResult::RejectedStale;
        }
        return IngestResult::Accepted;
    }
}