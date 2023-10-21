#include <cassert>
#include <iostream>
#include "leveldb/db.h"

int main(){
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    options.kvSepType = leveldb::kVSepBeforeMem;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    std::cout<< status.ToString() << '\n';
    std::string fill_str = "";
    // fill_str 4KB
    for(int i = 1; i<= 4096; i++){
        fill_str.push_back('%');
    }
    for(int i = 1E3; i>= 1; i--){
        status = db -> Put(leveldb::WriteOptions(), "key" + std::to_string(i), "val" + std::to_string(i) + fill_str);
    }
    if(status.ok()) {
        std::string val;
        status = db -> Get(leveldb::ReadOptions(), "key" + std::to_string(1), &val);
        if(status.ok()) std::cout<< "Find value of \'key1\' From db:" << val << "\n";
        status = db -> Get(leveldb::ReadOptions(), "key" + std::to_string(2), &val);
        if(status.ok()) std::cout<< "Find value of \'key2\' From db:" << val << "\n";
        status = db -> Get(leveldb::ReadOptions(), "key" + std::to_string(10), &val);
        if(status.ok()) std::cout<< "Find value of \'key10\' From db:" << val << "\n";
    }
    delete db;
}