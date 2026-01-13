#include <sse/ingest.h>
#include <sse/types.h>
#include <sse/engine_config.h>
#include "internal/log.h"
#include "internal/normalize.h"
#include "internal/signal_engine.h"
#include "algos/xsp.h"

#include <chrono>
#include <memory>

namespace {
    std::unique_ptr<sse::SignalEngine> signalEngine = []{ // Temporary solution -- move to public api
        auto se = std::make_unique<sse::SignalEngine>(sse::EngineConfig{});
        static sse::Xsp xsp_instance;
        se->subscribe(&xsp_instance);
        return se;
    }();
}

namespace sse{
    constexpr std::int64_t MAX_TIMESTAMP_STALE_TOLERANCE = 1000;

    [[nodiscard]] bool is_ingest_expired(std::int64_t timestamp){
        const auto now = std::chrono::system_clock::now(); // TO DO: change to time cache
        int64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()
        ).count();
        return timestamp + MAX_TIMESTAMP_STALE_TOLERANCE < now_ms;
    }

    IngestResult ingest_tick(const IngestInput& input) noexcept {
        if (__builtin_expect(is_ingest_expired(input.timestamp), 0)){
            return IngestResult::RejectedStale;
        }
        std::optional<IngestInput> normalized_input = normalize(input);
        if (__builtin_expect(normalized_input.has_value(), 1)){
            bool ingest_result = signalEngine->ingest_data(*normalized_input); // not used yet
            return IngestResult::Accepted;
        }else{
            return IngestResult::RejectedInvalid;
        }
    }
}