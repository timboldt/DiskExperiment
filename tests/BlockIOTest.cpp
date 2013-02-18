/*
 * File:   BlockIOTest.cpp
 * Author: timboldt
 *
 * Created on Feb 16, 2013, 10:10:29 PM
 */

#include <cstdio>
#include <cstring>
#include <cstddef>
#include <list>
#include <string>
#include <tr1/unordered_map>
#include <vector>

#include "BlockIOTest.h"
#include "DirectBlockFile.h"
#include "CachedBlockStore.h"


CPPUNIT_TEST_SUITE_REGISTRATION(BlockIOTest);

BlockIOTest::BlockIOTest() {
}

BlockIOTest::~BlockIOTest() {
}

void BlockIOTest::setUp() {
}

void BlockIOTest::tearDown() {
}

void BlockIOTest::testDirectBlockFile()
{
    const char * tmpFileName = "/tmp/testDirectBlockFile";
    
    DirectBlockFile blockFile;
    remove(tmpFileName);
    blockFile.openFile(tmpFileName, true);
    
    Byte data[DirectBlockFile::BLOCK_SIZE];    
    BlockId_t blockId = 999;
    
    sprintf((char *)data, "Block zero");
    blockId = blockFile.appendBlock(data);
    CPPUNIT_ASSERT(blockId == 0);
    sprintf((char *)data, "Block one");
    blockId = blockFile.appendBlock(data);
    CPPUNIT_ASSERT(blockId == 1);
    
    Byte * input = NULL;

    input = blockFile.getBlock(0);
    CPPUNIT_ASSERT(strcmp((const char *)input, "Block zero") == 0);
    delete [] input;

    input = blockFile.getBlock(1);
    CPPUNIT_ASSERT(strcmp((const char *)input, "Block one") == 0);
    delete [] input;    
}

void BlockIOTest::testGetBlock() {
    const int MAX_BLOCKS_IN_CACHE = 100;
    CachedBlockStore cache(MAX_BLOCKS_IN_CACHE);
    
    const Byte * block;
    
    CPPUNIT_ASSERT(cache.hasBlock(12345) == false);
    block = cache.getBlock(12345);
    CPPUNIT_ASSERT(std::string("12345").compare((const char *)block) == 0);
    CPPUNIT_ASSERT(cache.hasBlock(12345) == true);

    CPPUNIT_ASSERT(cache.hasBlock(9999) == false);
    block = cache.getBlock(9999);
    CPPUNIT_ASSERT(std::string("9999").compare((const char *)block) == 0);
    CPPUNIT_ASSERT(cache.hasBlock(9999) == true);

    block = cache.getBlock(12345);
    CPPUNIT_ASSERT(std::string("12345").compare((const char *)block) == 0);
    CPPUNIT_ASSERT(cache.hasBlock(12345) == true);
    
    for (BlockId_t i = 0; i < MAX_BLOCKS_IN_CACHE - 1; i++) {
        cache.getBlock(i);
    }
    CPPUNIT_ASSERT(cache.hasBlock(12345) == true);
    CPPUNIT_ASSERT(cache.hasBlock(9999) == false);
    cache.getBlock(MAX_BLOCKS_IN_CACHE/2);
    CPPUNIT_ASSERT(cache.hasBlock(12345) == true);
    cache.getBlock(MAX_BLOCKS_IN_CACHE);
    CPPUNIT_ASSERT(cache.hasBlock(12345) == false);
}

