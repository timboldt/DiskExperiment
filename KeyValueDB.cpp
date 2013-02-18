/*
 * KeyValueDB.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: timboldt
 */

#include <map>
#include <iostream>
#include <fstream>
#include <string>

#include "KeyValueDB.h"

KeyValueDB::KeyValueDB(std::string fileName) {
    openFlag = false;
    dbFileName = fileName;
}

KeyValueDB::~KeyValueDB() {
    if (openFlag == true) {
        this->close();
    }
}

void KeyValueDB::open() {
    if (openFlag == true) {
        // TODO: replace with proper exception
        throw std::string("Invalid operation: DB already open");
    }
    kvMap.clear();
    
    // TODO: replace with proper block-based I/O and serialization structure
    std::ifstream dbFile;
    dbFile.open(dbFileName.c_str(), std::ifstream::in);
    while (dbFile.good()) {
        std::string key;
        std::getline(dbFile, key);
        std::string value;
        std::getline(dbFile, value);
        kvMap[key] = value;
    }
    dbFile.close();

    openFlag = true;
}

void KeyValueDB::close() {
    if (openFlag == false) {
        // TODO: replace with proper exception
        throw std::string("Invalid operation: DB is not open");
    }

    // TODO: replace with proper block-based I/O and serialization structure
    std::ofstream dbFile;
    dbFile.open(dbFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
    for (std::map<std::string, std::string>::const_iterator itr = kvMap.begin(); itr != kvMap.end(); ++itr) {
        dbFile << (*itr).first << std::endl << (*itr).second << std::endl;
    }
    dbFile.close();

    openFlag = false;
    kvMap.clear();
}

bool KeyValueDB::isOpen() {
    return openFlag;
}

std::string KeyValueDB::get(std::string key) {
    if (openFlag == false) {
        // TODO: replace with proper exception
        throw std::string("Invalid operation: DB is not open");
    }
    
    //TODO: don't assume block containing key is in RAM
    
    return this->kvMap[key];
}

void KeyValueDB::put(std::string key, std::string value) {
    if (openFlag == false) {
        // TODO: replace with proper exception
        throw std::string("Invalid operation: DB is not open");
    }

    //TODO: don't assume the all the data can be kept in RAM

    this->kvMap[key] = value;
}

void KeyValueDB::del(std::string key) {
    if (openFlag == false) {
        // TODO: replace with proper exception
        throw std::string("Invalid operation: DB is not open");
    }

    //TODO: don't assume block containing key is in RAM
    this->kvMap.erase(key);
}

void KeyValueDB::clearAll() {
    if (openFlag == false) {
        // TODO: replace with proper exception
        throw std::string("Invalid operation: DB is not open");
    }
    this->kvMap.clear();
}