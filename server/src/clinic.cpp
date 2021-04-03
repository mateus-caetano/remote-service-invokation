#include "../headers/clinic.h"

Clinic::Clinic()
{
    initDb(clientsList, &appointmentsList);
}

proto::MedicalAppointmentList Clinic::listMedicalAppointment(proto::Client client)
{
    proto::MedicalAppointmentList list;
    proto::MedicalAppointment *mAppointment;
    proto::Client mClient;
    std::string mDateTime;

    int count = appointmentsList.medical_appointments_size();

    for (size_t i = 0; i < count; i++)
    {
        mClient = appointmentsList.medical_appointments(i).client();
        if ((client.id() == mClient.id()) && (client.nome() == mClient.nome()))
        {
            mDateTime = appointmentsList.medical_appointments(i).date_time();
            mAppointment = list.add_medical_appointments();
            mAppointment->set_allocated_client(&mClient);
            mAppointment->set_allocated_date_time(&mDateTime);
        }
    }

    return list;
}

proto::MedicalAppointment Clinic::scheduleMedicalAppointment(proto::MedicalAppointment)
{
    proto::MedicalAppointment list;

    return list;
}

proto::MedicalAppointment Clinic::deleteMedicalAppointment(proto::MedicalAppointment)
{
    proto::MedicalAppointment list;

    return list;
}

void Clinic::initDb(proto::Client *clientsList, proto::MedicalAppointmentList *appointmentsList)
{
    proto::MedicalAppointment *appointment;
    int count;
    for (size_t i = 0; i < 5; i++)
    {
        clientsList[i].set_id(std::to_string(i));
        clientsList[i].set_nome("client" + std::to_string(i));

        appointment = appointmentsList->add_medical_appointments();
        appointment->set_allocated_client(&clientsList[i]);
        appointment->set_date_time("07/04/2021-18:00");

        appointment = appointmentsList->add_medical_appointments();
        appointment->set_allocated_client(&clientsList[i]);
        appointment->set_date_time("08/04/2021-18:30");
    }

    count = appointmentsList->medical_appointments_size();

    for (size_t i = 0; i < count; i++)
    {
        std::cout
            << "id: " << appointmentsList->medical_appointments(i).client().id()
            << ", nome: " << appointmentsList->medical_appointments(i).client().nome()
            << ", date: " << appointmentsList->medical_appointments(i).date_time() << std::endl;
    }
}