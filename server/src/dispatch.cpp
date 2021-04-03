#include "../headers/dispatch.h"

std::string Dispatch::invoke(std::string params, std::string method)
{
    std::string result;

    if (method == "0")
    {
        proto::Client client;
        proto::MedicalAppointmentList list;
        client.ParseFromString(params);

        list = clinic.listMedicalAppointment(client);
        list.SerializeToString(&result);
    }
    else if (method == "1")
    {
        proto::MedicalAppointment appointment;
        appointment.ParseFromString(method);

        appointment = clinic.scheduleMedicalAppointment(appointment);
        appointment.SerializeToString(&result);
    }
    else if (method == "2")
    {
        proto::MedicalAppointment appointment;
        appointment.ParseFromString(method);

        appointment = clinic.deleteMedicalAppointment(appointment);
        appointment.SerializeToString(&result);
    }

    return result;
}