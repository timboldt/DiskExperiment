/* 
 * File:   AbstractBlockStore.h
 * Author: timboldt
 *
 * Created on February 17, 2013, 7:35 PM
 */

#ifndef ABSTRACTBLOCKSTORE_H
#define	ABSTRACTBLOCKSTORE_H

#include <list>
#include <tr1/unordered_map>
#include <vector>


typedef unsigned char Byte;
typedef int64_t BlockId_t;

class BlockInfo {
public:
    BlockInfo(BlockId_t blockId_p, Byte * blockPtr_p) {
        blockId = blockId_p;
        blockPtr = blockPtr_p;
    }
    
    BlockId_t blockId;
    Byte * blockPtr;
};
typedef std::tr1::unordered_map <BlockId_t, BlockInfo *> BlockMap;
typedef std::tr1::unordered_map <BlockId_t, BlockInfo *>::iterator BlockMapIterator;
typedef std::list <BlockInfo *> BlockList;

//TODO: Ownership of block pointer is not very clear; find a way to do this in a safer way without
//      sacrificing efficiency.
class AbstractBlockStore {
public:
    AbstractBlockStore();
    virtual ~AbstractBlockStore();
    
    virtual Byte * getBlock(BlockId_t blockId) = 0;
    virtual void updateBlock(BlockId_t blockId, const Byte * data) = 0;
    virtual BlockId_t appendBlock(const Byte * data) = 0;

    static const size_t BLOCK_SIZE = 4096;
    
private:
    AbstractBlockStore( const AbstractBlockStore& rhs );
    AbstractBlockStore& operator=( const AbstractBlockStore& rhs );

};

#endif	/* ABSTRACTBLOCKSTORE_H */

