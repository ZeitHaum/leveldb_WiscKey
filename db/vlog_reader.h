// author： ZeitHaum

#ifndef STORAGE_LEVELDB_DB_VLOG_READER_H_
#define STORAGE_LEVELDB_DB_VLOG_READER_H_

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
        ~VReader() = default;
        Status ReadRecord(uint64_t vfile_offset, std::string* record);
        Status ReadKV(uint64_t vfile_offset, std::string* key ,std::string* val);
    private: 
        SequentialFile* file_;
    };
} // namespace vlog
}
#endif