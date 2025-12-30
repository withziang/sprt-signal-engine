#pragma once
#include <sse/engine_config.h>

namespace sse{
	class SignalEngine{
	public:
		explicit SignalEngine(EngineConfig config);
	private:
		EngineConfig _engineConfig;
	}
}
