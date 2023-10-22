// author ZeitHaum

#ifndef STORAGE_LEVELDB_DB_VLOG_CONVERTER_H_
#define STORAGE_LEVELDB_DB_VLOG_CONVERTER_H_

#include <cstdint>
#include "leveldb/slice.h"
#include "leveldb/status.h"
namespace leveldb{
namespace vlog{
    class VlogConverter{
    public:
        VlogConverter() = default;
        ~VlogConverter() = default;
        Slice GetVptr(uint64_t file_no, uint64_t file_offset, char* buf);
        Status DecodeVptr(uint64_t* file_no, uint64_t* file_offset, Slice* vptr);
    };
}// namespace vlog
}
#endif