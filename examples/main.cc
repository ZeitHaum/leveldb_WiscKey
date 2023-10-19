#include <cassert>
#include <iostream>

#include "leveldb/db.h"

#include "gtest/gtest.h"

TEST(Usage, InitDb) {
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/test_db", &db);

  std::cout << "db started, status: " << status.ToString() << std::endl;
  assert(status.ok());
  delete db;
}

int main(int argc, char** argv) {
  printf("Running main() from %s\n", __FILE__);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}