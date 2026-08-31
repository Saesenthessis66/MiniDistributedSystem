#ifndef STORAGE_H
#define STORAGE_H
    
#include "storage.h"

int Storage::get(std::string key, std::string& value)
{
    auto it = data.find(key);
    if(it != data.end())
    {
        value = (*it).second;
        return 0;
    }
    return -1;
}

int Storage::set(std::string key, std::string value)
{
    data[key] = value;
    return 0;
}

int Storage::contain(std::string key)
{
    if(data.contains(key))
    {
        return 0;
    }
    return -1;
}

int Storage::remove(std::string key)
{
    if(data.erase(key) > 0)
    {
        return 0;
    }
    return -1;
}

DataContainer& Storage::getData()
{
    return data;
}

#endif