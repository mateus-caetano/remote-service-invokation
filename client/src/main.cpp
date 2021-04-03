#include "../headers/proxy.h"
#include "../../client.pb.h"

int main()
{
    Proxy proxy;
    proto::Client client;
    proto::MedicalAppointmentList list;
    int count;

    client.set_id("0");
    client.set_nome("client0");

    list = proxy.listMedicalAppointment(client);

    count = list.medical_appointments_size();

    for (size_t i = 0; i < count; i++)
    {
        std::cout
            << "id: " << list.medical_appointments(i).client().id()
            << ", nome: " << list.medical_appointments(i).client().nome()
            << ", date: " << list.medical_appointments(i).date_time() << std::endl;
    }

    return 0;
}