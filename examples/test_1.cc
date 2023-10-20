#include <cassert>
#include <iostream>
#include "leveldb/db.h"

int main(){
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    std::cout<< status.ToString() << '\n';
    status = db -> Put(leveldb::WriteOptions(), "key1", "val1");
    if(status.ok()) {
        std::string val;
        status = db -> Get(leveldb::ReadOptions(), "key1", &val);
        std::cout<< "Find value of \'key1\' From db:" << val << "\n";
    }
    if(status.ok()){
        std::string val;
        db -> Delete(leveldb::WriteOptions(), "key1");
        status = db -> Get(leveldb::ReadOptions(), "key1", &val);
        //Not find.
        std::cout<< status.ToString() <<'\n';
    }
    delete db;
}