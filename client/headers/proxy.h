#include <iostream>

#include "../../client.pb.h"
#include "../headers/client.h"

class Proxy
{

public:
    proto::MedicalAppointmentList listMedicalAppointment(proto::Client);
    proto::MedicalAppointment scheduleMedicalAppointment(proto::MedicalAppointment);
    proto::MedicalAppointment deleteMedicalAppointment(proto::MedicalAppointment);

private:
};