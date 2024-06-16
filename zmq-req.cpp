#include "zmq.hpp"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

using namespace std;
using namespace zmq;
using namespace rapidjson;

int main()
{
    context_t context(1);
    socket_t socket(context, ZMQ_REQ);
    socket.connect("tcp://localhost:5555");

    Document d;
    d.SetObject();
    d.AddMember("Name", "Ibrahim", d.GetAllocator());
    d.AddMember("Age", 27, d.GetAllocator());
    d.AddMember("Country", "Lebanon", d.GetAllocator());

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    string json_string = buffer.GetString();
    printf("The string is %s\n", json_string.c_str());

    socket.send(message_t(json_string), send_flags::dontwait);
}
