#include <string>

namespace ProtocolLayer{
    enum class ResponseType {
    Ok,
    Value,
    NotFound,
    Error
};

struct Response {
    ResponseType type;
    std::string data;
};

class Serializer{
    public:
    std::string serialize(Response& response);
};
}