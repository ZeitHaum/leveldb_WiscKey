// author: ZeitHaum

#ifndef STORAGE_LEVELDB_DB_VLOG_WRITER_H_
#define STORAGE_LEVELDB_DB_VLOG_WRITER_H_

#include <cstdint>
#include "leveldb/slice.h"
#include "leveldb/status.h"

// format: [size, key, vptr, value].
namespace leveldb{
class WritableFile;
namespace vlog{
    class VWriter{
    public:
        explicit VWriter(WritableFile* vlogfile);
        ~VWriter();
        Status AddRecord(const Slice& slice, int& write_size);
        VWriter(const VWriter&) = delete;
        VWriter& operator=(const VWriter&) = delete;
    private:
        WritableFile* vlogfile_;
    };
}// namespace vlog
}

#endif 