#include "zmq.hpp"

int main()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);


}
