#include <string>

namespace ProtocolLayer {

enum class CommandType {
    Get,
    Set,
    Contain,
    Remove
};

struct Command {
    CommandType type;
    std::string key;
    std::string value;
};

class Parser{
    public:
    static Command parse(std::string& message);
};
}