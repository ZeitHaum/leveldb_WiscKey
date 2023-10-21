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
    Status VWriter::AddRecord(const Slice& slice){
        //append slice length.
        char buf[10]; // Used for Convert int64 to char.
        char* end_byte = EncodeVarint64(buf, slice.size());
        Status s = vlogfile_->Append(Slice(buf, end_byte - buf));
        //append slice
        if(s.ok()) vlogfile_->Append(slice);
        // Don't flush for performance.
        return s;
    }
}// namespace vlog
}