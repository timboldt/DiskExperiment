/* 
 * File:   DirectBlockFile.h
 * Author: timboldt
 *
 * Created on February 17, 2013, 6:33 PM
 */

#ifndef DIRECTBLOCKFILE_H
#define	DIRECTBLOCKFILE_H

#include "AbstractBlockStore.h"


class DirectBlockFile : public AbstractBlockStore {
public:
    DirectBlockFile();
    DirectBlockFile(const DirectBlockFile& orig);
    virtual ~DirectBlockFile();
    
    virtual void openFile(std::string fileName, bool createNew);
    virtual void closeFile();
    
    virtual Byte * getBlock(BlockId_t blockId);
    virtual void updateBlock(BlockId_t blockId, const Byte * data);
    virtual BlockId_t appendBlock(const Byte * data);

    
private:
    std::string getFileErrorMessage(const char * operation, int errNumber);

    std::string fileName;
    int fileId;
};

#endif	/* DIRECTBLOCKFILE_H */

