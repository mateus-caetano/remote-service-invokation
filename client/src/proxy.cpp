#include "../headers/proxy.h"

proto::MedicalAppointmentList Proxy::listMedicalAppointment(proto::Client client)
{
    proto::MedicalAppointmentList list;
    Client udp;

    std::string serial_msg;
    client.SerializeToString(&serial_msg);

    udp.sendRequest(serial_msg);

    return list;
}