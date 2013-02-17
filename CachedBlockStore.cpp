/* 
 * File:   CachedBlockStore.cpp
 * Author: timboldt
 * 
 * Created on February 16, 2013, 8:08 PM
 */

#include "CachedBlockStore.h"

#include <cstdio>
#include <cstring>

CachedBlockStore::CachedBlockStore() {
}

CachedBlockStore::~CachedBlockStore() {
}

const Byte * CachedBlockStore::getBlock(BlockId_t blockId)
{
    BlockMapIterator iter = blockMap.find(blockId);
    if (iter == blockMap.end()) {
        return loadBlock(blockId);
    }
    else {
        BlockInfo * blockInfo = iter->second;
        
        // Put the block at the head of the list
        blockList.remove(blockInfo);
        blockList.push_front(blockInfo);
        
        return blockInfo->blockPtr;
    }
}

bool CachedBlockStore::hasBlock(BlockId_t blockId)
{
    BlockMapIterator iter = blockMap.find(blockId);
    return (iter != blockMap.end());
}

const Byte * CachedBlockStore::loadBlock(BlockId_t blockId)
{    
    // Eject a block to make room in the cache
    while (blockList.size() >= MAX_BLOCKS_IN_CACHE) {
        
        // Remove the last block in the list
        BlockInfo * blockInfo = blockList.back();        
        blockList.pop_back();

        // Remove it from the map as well
        blockMap.erase(blockInfo->blockId);
        
        // Delete the block content
        delete [] blockInfo->blockPtr;
        delete blockInfo;
    }

    // Simulate a block read and mark it with the block id for verification purposes
    Byte * data = new Byte[BLOCK_SIZE];    
    memset(data, '*', BLOCK_SIZE);
    sprintf((char *)data, "%lld", blockId);

    // Add the new block to the cache
    BlockInfo * blockInfo = new BlockInfo(blockId, data);
    blockMap[blockId] = blockInfo;
    blockList.push_front(blockInfo);
      
    return blockInfo->blockPtr;
}