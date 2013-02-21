/*
 * File:   KeyValueTest.cpp
 * Author: timboldt
 *
 * Created on Feb 16, 2013, 10:11:15 PM
 */

#include "KeyValueTest.h"

/*
CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

void newtestclass1::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass1::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}*/

/*
 * File:   KeyValueTest.cpp
 * Author: timboldt
 *
 * Created on Feb 16, 2013, 3:36:56 PM
 */

#include <exception>
#include <stdexcept>

#include "KeyValueTest.h"
#include "KeyValueDB.h"

std::string DB_FILE_NAME = "/tmp/kvdb.tmp";

CPPUNIT_TEST_SUITE_REGISTRATION(KeyValueTest);

KeyValueTest::KeyValueTest() {
}

KeyValueTest::~KeyValueTest() {
}

void KeyValueTest::setUp() {
}

void KeyValueTest::tearDown() {
}

void KeyValueTest::testOpen() {
    KeyValueDB keyValueDB(DB_FILE_NAME);
    keyValueDB.open();
    CPPUNIT_ASSERT_THROW( keyValueDB.open(), std::runtime_error );
    CPPUNIT_ASSERT(keyValueDB.isOpen() == true);
    keyValueDB.close();
}

void KeyValueTest::testClose() {
    KeyValueDB keyValueDB(DB_FILE_NAME);
    CPPUNIT_ASSERT(keyValueDB.isOpen() == false);
    keyValueDB.open();
    keyValueDB.close();
    CPPUNIT_ASSERT(keyValueDB.isOpen() == false);
    CPPUNIT_ASSERT_THROW( keyValueDB.close(), std::runtime_error );
}

void KeyValueTest::testGetPutDel() {
    KeyValueDB keyValueDB(DB_FILE_NAME);
    keyValueDB.open();
    keyValueDB.clearAll();
    CPPUNIT_ASSERT(keyValueDB.get("hello") == "");
    CPPUNIT_ASSERT(keyValueDB.get("") == "");
    keyValueDB.put("hello", "world");
    CPPUNIT_ASSERT(keyValueDB.get("hello") == "world");
    keyValueDB.del("hello");
    CPPUNIT_ASSERT(keyValueDB.get("hello") == "");
}

void KeyValueTest::testPersistence() {
    KeyValueDB keyValueDB(DB_FILE_NAME);
    keyValueDB.open();
    keyValueDB.clearAll();
    keyValueDB.put("hello", "world");
    keyValueDB.put("moon", "night");
    keyValueDB.put("sun", "day");
    CPPUNIT_ASSERT(keyValueDB.get("hello") == "world");
    CPPUNIT_ASSERT(keyValueDB.get("moon") == "night");
    CPPUNIT_ASSERT(keyValueDB.get("sun") == "day");
    keyValueDB.close();
    keyValueDB.open();
    CPPUNIT_ASSERT(keyValueDB.get("hello") == "world");
    CPPUNIT_ASSERT(keyValueDB.get("moon") == "night");
    CPPUNIT_ASSERT(keyValueDB.get("sun") == "day");    
}
