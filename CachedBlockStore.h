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

const size_t BLOCK_SIZE = 4096;

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

// TODO: implement this as a derived class of a block-oriented I/O class
class CachedBlockStore {
public:
    CachedBlockStore(size_t blocksInCache);
    virtual ~CachedBlockStore();
    
    const Byte * getBlock(BlockId_t blockId);
    bool hasBlock(BlockId_t blockId);

private:    
    const Byte * loadBlock(BlockId_t blockId);
    
private:
    BlockList blockList;
    BlockMap blockMap;
    size_t maxBlocksInCache;
};

#endif	/* CACHEDBLOCKSTORE_H */

