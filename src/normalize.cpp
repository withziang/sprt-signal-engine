#include "internal/normalize.h"

namespace sse{
	[[nodiscard]] bool is_ingest_invalid(const IngestInput& input){
        return false; // STUB
    }

	std::optional<IngestInput>normalize(const IngestInput& raw){
		//return std::nullopt;
		return std::optional<IngestInput>(raw);
	};
}