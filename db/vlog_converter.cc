// author ZeitHaum

#include "util/coding.h"
#include "db/vlog_converter.h"
namespace leveldb{
namespace vlog{
    Slice VlogConverter::GetVptr(uint64_t file_no, uint64_t file_offset, char* buf){
        char* vfileno_end = EncodeVarint64(buf, file_no);
        char* vfileoff_end = EncodeVarint64(vfileno_end, file_offset);
        return Slice(buf, vfileoff_end - buf);
    }
    Status VlogConverter::DecodeVptr(uint64_t* file_no, uint64_t* file_offset, Slice* vptr){
        bool decoded_status = true;
        decoded_status &= GetVarint64(vptr, file_no);
        decoded_status &= GetVarint64(vptr, file_offset);
        if(!decoded_status) return Status::Corruption("Can not Decode vptr from Read Bytes.");
        else return Status::OK();
    }
}// namespace vlog
}