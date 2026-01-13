#include "internal/signal_engine.h"

namespace sse{
	SignalEngine::SignalEngine(EngineConfig config) : _engineConfig(config){}

	bool SignalEngine::ingest_data(const IngestInput& input){
		return 1;
	}

	bool SignalEngine::send_orders(const std::vector<Order>& orders){
		return 1;
	}

	std::vector<Order> SignalEngine::trigger_run_all_algos(){
		return {};
	}

	bool Dispatcher::subscribe(Algo* algo){
		subscribers.push_back(algo);
		return true;
	}

	bool SignalEngine::subscribe(Algo* algo){
		return dispatcher.subscribe(algo);
	}
}