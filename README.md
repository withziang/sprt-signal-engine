# Sport betting signal generator engine
## Getting started
- install cmake
- install g++ 17
- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake --build .`

## Ingest data format
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

## Algos
- spread cross platform  -- XSP