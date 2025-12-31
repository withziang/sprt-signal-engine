#include "internal/signal_engine.h"

namespace sse{
	SignalEngine::SignalEngine(EngineConfig config) : _engineConfig(config){}

	bool SignalEngine::ingest_data(const IngestInput& input){
		return 1;
	}

	bool SignalEngine::send_orders(const std::vector<Order>& orders){
		return 1;
	};
}