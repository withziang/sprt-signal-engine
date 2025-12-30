#pragma once
#include <sse/types.h>

#include <optional>

namespace sse{
	std::optional<IngestInput>normalize(const IngestInput& raw);
}