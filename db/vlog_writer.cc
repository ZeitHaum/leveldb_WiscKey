// author: ZeitHaum

#include <cstdint>
#include "db/vlog_writer.h"
#include "leveldb/slice.h"
#include "leveldb/env.h"
#include "util/coding.h"
namespace leveldb{
namespace vlog{
    VWriter::VWriter(WritableFile* vlogfile):vlogfile_(vlogfile){}
    VWriter::~VWriter() = default;
    Status VWriter::AddRecord(const Slice& slice, int& write_size){
        //append slice length.
        write_size = slice.size();
        char buf[10]; // Used for Convert int64 to char.
        char* end_byte = EncodeVarint64(buf, slice.size());
        write_size += end_byte - buf;
        Status s = vlogfile_->Append(Slice(buf, end_byte - buf));
        //append slice
        if(s.ok()) s = vlogfile_->Append(slice);
        return s;
    }
    Status VWriter::Flush(){
        return vlogfile_->Flush();
    }
}// namespace vlog
}