#include <sse/ingest.h>
#include <sse/types.h>


namespace sse{
    IngestResult ingest_tick(const IngestInput& input){
        return IngestResult::Accepted;
    }
}