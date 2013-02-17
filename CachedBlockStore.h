/* 
 * File:   CachedBlockStore.h
 * Author: timboldt
 *
 * Created on February 16, 2013, 8:08 PM
 */

#ifndef CACHEDBLOCKSTORE_H
#define	CACHEDBLOCKSTORE_H

#include <list>
#include <map>
#include <vector>

const size_t BLOCK_SIZE = 4096;
const size_t MAX_BLOCKS_IN_CACHE = 1000;

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
typedef std::map <BlockId_t, BlockInfo *> BlockMap;
typedef std::map <BlockId_t, BlockInfo *>::iterator BlockMapIterator;

typedef std::list <BlockInfo *> BlockList;

class CachedBlockStore {
public:
    CachedBlockStore();
    virtual ~CachedBlockStore();
    
    const Byte * getBlock(BlockId_t blockId);
    bool hasBlock(BlockId_t blockId);

private:    
    const Byte * loadBlock(BlockId_t blockId);
    
private:
    BlockList blockList;
    BlockMap blockMap;
};

#endif	/* CACHEDBLOCKSTORE_H */

