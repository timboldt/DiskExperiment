/*
 * File:   KeyValueTest.h
 * Author: timboldt
 *
 * Created on Feb 16, 2013, 10:11:15 PM
 */

#ifndef KEYVALUETEST_H
#define	KEYVALUETEST_H

#include <cppunit/extensions/HelperMacros.h>

/*
class newtestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass1);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass1();
    virtual ~newtestclass1();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};
*/

class KeyValueTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(KeyValueTest);

    CPPUNIT_TEST(testOpen);
    CPPUNIT_TEST(testClose);

    CPPUNIT_TEST(testGetPutDel);
    CPPUNIT_TEST(testPersistence);

    CPPUNIT_TEST_SUITE_END();

public:
    KeyValueTest();
    virtual ~KeyValueTest();
    void setUp();
    void tearDown();

private:
    void testOpen();
    void testClose();
    void testGetPutDel();
    void testPersistence();

};


#endif	/* KEYVALUETEST_H */

