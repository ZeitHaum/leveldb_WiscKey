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
        Slice size_slice;
        char size_buf[11];
        uint64_t rec_size = 0;
        s = file_->SkipFromHead(vfile_offset);
        if(s.ok()) s = file_ -> Read(10, &size_slice, size_buf); // 先把Record 长度读出来, 最长10字节.
        if(s.ok()){
            if(GetVarint64(&size_slice, &rec_size) == false){
                return Status::Corruption("Failed to decode vlog record size.");
            }
            std::string rec;
            char* c_rec = new char[rec_size];
            //TODO: Should delete c_rec?
            rec.resize(rec_size);
            Slice rec_slice;
            s = file_->SkipFromHead(vfile_offset + (size_slice.data() - size_buf));
            if(!s.ok()) return s;
            s = file_-> Read(rec_size, &rec_slice, c_rec);
            if(!s.ok()) return s;
            rec = std::string(c_rec, rec_size);
            *record = std::move(std::string(rec));
        }
        return s;
    }
    Status VReader::ReadKV(uint64_t vfile_offset, std::string* key, std::string* val){
        std::string record_str;
        Status s = ReadRecord(vfile_offset, &record_str);
        if(s.ok()){
            Slice record = Slice(record_str);
            //File the val
            uint64_t key_size;
            bool decode_flag = true;
            decode_flag &= GetVarint64(&record, &key_size);
            if(decode_flag){
                *key = Slice(record.data(), key_size).ToString();
                record = Slice(record.data() + key_size, record.size() - key_size);
            }
            uint64_t val_size;
            decode_flag &= GetVarint64(&record, &val_size);
            if(decode_flag) *val = Slice(record.data(), val_size).ToString();
            if(!decode_flag || val->size() != record.size()){
                s = Status::Corruption("Failed to decode Record Read From vlog.");
            }
        }
        return s;
    }
}// namespace vlog.
}