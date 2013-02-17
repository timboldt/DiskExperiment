/*
 * File:   BlockIOTest.cpp
 * Author: timboldt
 *
 * Created on Feb 16, 2013, 10:10:29 PM
 */

#include <string>
#include "BlockIOTest.h"
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

void BlockIOTest::testGetBlock() {
    CachedBlockStore cache;
    
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
    cache.getBlock(500);
    CPPUNIT_ASSERT(cache.hasBlock(12345) == true);
    cache.getBlock(1000);
    CPPUNIT_ASSERT(cache.hasBlock(12345) == false);
}

