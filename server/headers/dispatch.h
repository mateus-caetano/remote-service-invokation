#include <iostream>

#include "../../client.pb.h"
#include "./clinic.h"

class Dispatch
{
public:
    std::string invoke(std::string params, std::string method);

    // private:
    Clinic clinic;
};