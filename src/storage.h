#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> DataContainer;

class Storage
{
    DataContainer data;

    public:

    int get(std::string key, std::string& value);
    int set(std::string key, std::string value);
    int contain(std::string key);
    int remove(std::string key);
    DataContainer& getData();
};