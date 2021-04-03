#include <iostream>
#include <string>
#include <google/protobuf/repeated_field.h>

#include "../../client.pb.h"

using namespace google::protobuf;

class Clinic
{

public:
    Clinic();
    proto::MedicalAppointmentList listMedicalAppointment(proto::Client);
    proto::MedicalAppointment scheduleMedicalAppointment(proto::MedicalAppointment);
    proto::MedicalAppointment deleteMedicalAppointment(proto::MedicalAppointment);

private:
    proto::Client clientsList[5];
    proto::MedicalAppointmentList appointmentsList;
    void initDb(proto::Client *clientsList, proto::MedicalAppointmentList *appointmentsList);
};