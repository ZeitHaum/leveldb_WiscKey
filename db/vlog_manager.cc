// author ZeitHaum
#include "db/vlog_manager.h"

namespace leveldb{
namespace vlog{
    void VlogManager::AddVlogFile(uint64_t vlogfile_number, RandomAccessFile* file){
        if(log_table_.find(vlogfile_number) == log_table_.end()){
            log_table_[vlogfile_number] = file;
        }
        else{
            //Do Nothing
        }
    }
    RandomAccessFile* VlogManager::GetVlogFile(uint64_t vlogfile_number){
        auto it = log_table_.find(vlogfile_number);
        if(it != log_table_.end()){
            return it.second;
        }
        else return nullptr;
    }
}// namespace vlog
}