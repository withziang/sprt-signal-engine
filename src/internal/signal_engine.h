#pragma once
#include <sse/engine_config.h>
#include "internal/types.h"
#include <sse/types.h>

#include <vector>
#include <unordered_map>

namespace sse{
	class SignalEngine{
	public:
		explicit SignalEngine(EngineConfig config);
		bool ingest_data(const IngestInput& input);
		bool send_orders(const std::vector<Order>& orders);
	private:
		EngineConfig _engineConfig;
		std::vector<Order> trigger_run_all_algos();
		std::unordered_map<MarketKey, Price> marketKey2Price;
	};
}
