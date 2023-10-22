// author ZeitHaum
#ifndef STORAGE_LEVELDB_DB_VLOG_MANAGER_H_
#define STORAGE_LEVELDB_DB_VLOG_MANAGER_H_
#include <unordered_map>
#include <cstdint>
#include "leveldb/env.h"
namespace leveldb{
class RandomAccessFile;
namespace vlog{
class  VlogManager{
    public:
    VlogManager() = default;
    ~VlogManager() = default;
    //Add a vlog file, vlog file is already exist.
    void AddVlogFile(uint64_t vlogfile_number, RandomAccessFile* file);
    RandomAccessFile* GetVlogFile(uint64_t vlogfile_number);
    bool IsEmpty();
    private:
    std::unordered_map<uint64_t, RandomAccessFile*> vlog_table_;
};   
}// namespace vlog
}
#endif
