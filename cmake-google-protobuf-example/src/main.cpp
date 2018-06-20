#include <iostream>
#include "msg.pb.h"
#include "include/test_proto.h"

using namespace std;

Test_proto::Test_proto() {}
Test_proto::~Test_proto() {}

int main(int argc, char** argv)
{
    Test_proto a;
    demo::str_list sl;
    sl.has_elements();
    return 0;
}
