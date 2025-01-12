#include <cassert>
#include <iostream>
#include "leveldb/db.h"

int main(){
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    options.kvSepType = leveldb::kVSepBeforeSSD;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    std::cout<< status.ToString() << '\n';
    std::string fill_str = "";
    // fill_str 4KB
    for(int i = 1; i<= 4096; i++){
        fill_str.push_back('%');
    }
    for(int i = 1E5; i>= 1; i--){
        status = db -> Put(leveldb::WriteOptions(), "key" + std::to_string(i), "val" + std::to_string(i) + fill_str);
    }
    if(status.ok()) {
        std::string val;
        for(int i = 0; i< 1E5; i++){
            status = db -> Get(leveldb::ReadOptions(), "key" + std::to_string(i), &val);
            if(status.ok()) std::cout<< "Find value of \'key"<<i<<"\' From db:" << val << "\n";
        }
    }
    delete db;
}