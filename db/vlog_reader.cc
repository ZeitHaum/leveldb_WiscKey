// author ZeitHaum
#include <cstdint>
#include "db/vlog_reader.h"
#include "leveldb/slice.h"
#include "leveldb/env.h"
#include "util/coding.h"
namespace leveldb{
namespace vlog{
    VReader::VReader(SequentialFile* file)
        :file_(file){}
    Status VReader::ReadRecord(uint64_t vfile_offset, std::string* record){
        Status s;
        s = file_ -> SkipFromHead(vfile_offset);
        if(s.ok()){
            Slice size_slice;
            char size_buf[11];
            uint64_t rec_size = 0;
            s = file -> Read(10, &size_slice, size_buf); // 先把Record 长度读出来, 最长10字节.
            if(s.ok()){
                if(GetVarint64(&size_slice, &rec_size) == false){
                    return Status::Corruption("Failed to decode vlog record size.");
                }
                std::string rec;
                rec.resize(rec_size);
                Slice rec_slice;
                s = file_ -> SkipFromHead(size_slice.data() - size_buf + vfile_offset);
                if(!s.ok()) return s;
                s = file-> Read(rec_size, rec_slice, rec.c_str());
                if(!s.ok()) return s;
                record = &rec;
            }
        }
        return s;
    }
    Status VReader::ReadKV(uint64_t vfile_offset, std::string* key, std::string* val){
        Slice record = Slice();
        Status s = ReadRecord(vfile_offset, record);
        if(s.ok()){
            //File the val
            uint64_t key_size;
            bool decode_flag = true;
            decode_flag &= GetVarint64(&record, &key_size);
            key = &Slice(record.data(), key_size).ToString();
            record = Slice(record.data() + key_size, record.size() - key_size);
            uint64_t val_size;
            decode_flag &= GetVarint64(&record, &val_size);
            val = &Slice(record.data(), val_size).ToString();
            if(!decode_flag || val.size() != record.size()){
                s = Status::Corruption("Failed to decode Record Read From vlog.");
            }
        }
        return s;
    }
}// namespace vlog.
}