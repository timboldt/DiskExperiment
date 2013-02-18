/* 
 * File:   CachedBlockStore.h
 * Author: timboldt
 *
 * Created on February 16, 2013, 8:08 PM
 * 
 * This module implements a simple read-only block cache, using a combination of a 
 */

#ifndef CACHEDBLOCKSTORE_H
#define	CACHEDBLOCKSTORE_H

#include "AbstractBlockStore.h"



// TODO: implement this as a derived class of a block-oriented I/O class
class CachedBlockStore : public AbstractBlockStore {
public:
    CachedBlockStore(size_t blocksInCache);
    virtual ~CachedBlockStore();
    
    virtual Byte * getBlock(BlockId_t blockId);
    virtual void updateBlock(BlockId_t blockId, const Byte * data);
    virtual BlockId_t appendBlock(const Byte * data);

    bool hasBlock(BlockId_t blockId);

private:    
    Byte * loadBlock(BlockId_t blockId);
    
private:
    BlockList blockList;
    BlockMap blockMap;
    size_t maxBlocksInCache;
};

#endif	/* CACHEDBLOCKSTORE_H */

