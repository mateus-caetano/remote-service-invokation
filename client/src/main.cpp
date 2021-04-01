#include "../headers/proxy.h"
#include "../../client.pb.h"

int main()
{
    Proxy proxy;
    proto::Client client;

    client.set_id("i");
    client.set_nome("mateus");

    proxy.listMedicalAppointment(client);

    return 0;
}