/*
 * KeyValueDB.h
 *
 *  Created on: Feb 16, 2013
 *      Author: timboldt
 */

#ifndef KEYVALUEDB_H_
#define KEYVALUEDB_H_

class KeyValueDB {
public:
    KeyValueDB(std::string fileName);
    virtual ~KeyValueDB();

    virtual void open();
    virtual void close();
    virtual bool isOpen();

    virtual std::string get(std::string key);
    virtual void put(std::string key, std::string value);
    virtual void del(std::string key);
        
    virtual void clearAll();
private:
    bool openFlag;
    std::string dbFileName;
    std::map <std::string, std::string> kvMap;
};

#endif /* KEYVALUEDB_H_ */
