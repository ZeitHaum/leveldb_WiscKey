// author ZeitHaum
#include "db/vlog_manager.h"

namespace leveldb{
namespace vlog{
    void VlogManager::AddVlogFile(uint64_t vlogfile_number, RandomAccessFile* file){
        if(vlog_table_.find(vlogfile_number) == vlog_table_.end()){
            vlog_table_[vlogfile_number] = file;
        }
        else{
            //Do Nothing
        }
    }
    RandomAccessFile* VlogManager::GetVlogFile(uint64_t vlogfile_number){
        auto it = vlog_table_.find(vlogfile_number);
        if(it != vlog_table_.end()){
            return it->second;
        }
        else return nullptr;
    }
    bool VlogManager::IsEmpty(){
        return vlog_table_.size() == 0;
    }
}// namespace vlog
}