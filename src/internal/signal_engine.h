#pragma once
#include <sse/engine_config.h>
#include "internal/types.h"
#include <sse/types.h>
#include "algos/algo.h"

#include <vector>
#include <unordered_map>
#include <functional>

namespace std{
	template<>
	struct hash<sse::MarketKey>{
		size_t operator()(const sse::MarketKey& k) const noexcept{
			return 0; 	
		}
	};
}

namespace sse{
	class Dispatcher{
	public:
		bool subscribe(Algo* algo);
	private:
		std::vector<Algo*> subscribers;
	};

	class SignalEngine{
	public:
		explicit SignalEngine(EngineConfig config);
		bool ingest_data(const IngestInput& input);
		bool send_orders(const std::vector<Order>& orders);
		bool subscribe(Algo* algo);
	private:
		Dispatcher dispatcher;
		EngineConfig _engineConfig;
		std::vector<Order> trigger_run_all_algos();
		std::unordered_map<MarketKey, Price> marketKey2Price; // missing a hash function
	};
}
