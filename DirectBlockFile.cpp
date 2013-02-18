/* 
 * File:   DirectBlockFile.cpp
 * Author: timboldt
 * 
 * Created on February 17, 2013, 6:33 PM
 */

#include <errno.h>
#include <fcntl.h>
#include <sstream>

#include "DirectBlockFile.h"

DirectBlockFile::DirectBlockFile() {
}

DirectBlockFile::DirectBlockFile(const DirectBlockFile& orig) {
}

DirectBlockFile::~DirectBlockFile() {
}

void DirectBlockFile::openFile(std::string nameOfFileToOpen, bool createNew) {
    fileName = nameOfFileToOpen;

    int fileFlags = O_RDWR;
    if (createNew) {
        fileFlags |= O_CREAT;
    }

    // TODO: Make this code portable to Linux by using O_DIRECT there
    fileId = open(fileName.c_str(), fileFlags);
    if (fileId <= 0) {
        fileId = 0;
        throw new std::string(getFileErrorMessage("Failed to open file.", errno));
    }
    int res = fcntl(fileId, F_NOCACHE, 1);
    if (res < 0) {
        throw new std::string(getFileErrorMessage("fcntl failed.", errno));
    }
}

void DirectBlockFile::closeFile() {
    if (fileId > 0) {
        int res = close(fileId);
        fileId = 0;

        if (res < 0) {
            throw new std::string(getFileErrorMessage("Failed to close file.", errno));
        }
    }
}

Byte * DirectBlockFile::getBlock(BlockId_t blockId) {
    Byte * data = NULL;

    off_t offset = lseek(fileId, blockId * BLOCK_SIZE, SEEK_SET);
    if (offset < 0) {
        throw new std::string(getFileErrorMessage("Seek failed.", errno));
    }
    
    data = new Byte[BLOCK_SIZE];
    ssize_t bytesRead = read(fileId, data, BLOCK_SIZE);
    if (bytesRead <= 0) {
        delete [] data;
        data = NULL;
        throw new std::string(getFileErrorMessage("Read failed.", errno));
    }
 
    return data;
}

void DirectBlockFile::updateBlock(BlockId_t blockId, const Byte * data) {
    off_t offset = lseek(fileId, blockId * BLOCK_SIZE, SEEK_SET);
    if (offset < 0) {
        throw new std::string(getFileErrorMessage("Seek failed.", errno));
    }
    
    //TODO: write
}

BlockId_t DirectBlockFile::appendBlock(const Byte * data) {
    off_t offset = lseek(fileId, 0, SEEK_END);
    if (offset < 0) {
        throw new std::string(getFileErrorMessage("Seek failed.", errno));
    }
    
    ssize_t written = write(fileId, data, BLOCK_SIZE);
    if (written < 0) {
        throw new std::string(getFileErrorMessage("Write (append) failed.", errno));
    }
    
    return offset / BLOCK_SIZE;
}

std::string DirectBlockFile::getFileErrorMessage(const char * message, int errNumber) {
    std::ostringstream stringStream;
    stringStream << message << " Filename: " << this->fileName << " Error: " << strerror(errNumber);
    //************
    std::string s = stringStream.str().c_str();
    //************
    return std::string(stringStream.str());
}
