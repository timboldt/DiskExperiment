/*
 * File:   BlockIOTest.h
 * Author: timboldt
 *
 * Created on Feb 16, 2013, 10:10:28 PM
 */

#ifndef BLOCKIOTEST_H
#define	BLOCKIOTEST_H

#include <cppunit/extensions/HelperMacros.h>

class BlockIOTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BlockIOTest);

    CPPUNIT_TEST(testDirectBlockFile);
    CPPUNIT_TEST(testGetBlock);

    CPPUNIT_TEST_SUITE_END();

public:
    BlockIOTest();
    virtual ~BlockIOTest();
    void setUp();
    void tearDown();

private:
    void testDirectBlockFile();

    void testGetBlock();
};

#endif	/* BLOCKIOTEST_H */

