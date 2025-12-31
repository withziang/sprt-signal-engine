# Sport betting signal engine
A high-performance C++ library that ingests real-time sports betting market data and produces deterministic arbitrage signals with low latency and predictable behavior.

## Run tests for this library
- install cmake
- install g++ 17
- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake --build .`

## Build this library to dynamic runtime library
## API
- `IngestResult ingest_tick(const IngestInput& input) noexcept;`

## Data format
- IngestInput:
```
std::string website;
std::int64_t timestamp;
std::string league;
std::string game_name;
std::string team1;
std::string team2;
BetType bet_type;
double team1_line;
double team1_odd;
double team2_line;
double team2_odd;
```
- IngestResult:
```
Accepted,
RejectedInvalid,
RejectedStale
```

## Algos
- spread cross platform  -- XSP