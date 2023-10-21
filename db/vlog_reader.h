// author： ZeitHaum

#ifndef STORAGE_LEVELDB_DB_LOG_READER_H_
#define STORAGE_LEVELDB_DB_LOG_READER_H_

#include <cstdint>
#include "leveldb/slice.h"
#include "leveldb/status.h"
#include "port/port.h"

namespace leveldb {

class SequentialFile;

namespace vlog {
    class VReader {
    //TODO: Consider the Cocurrency.
    public:
        explicit VReader(SequentialFile* file);
        Status ReadRecord(uint64_t vfile_offset, Slice& record);
        Status ReadValue(uint64_t vfile_offset, Slice& val);
    private: 
        SequentialFile* file_;
    };
} // namespace vlog
}
#endif