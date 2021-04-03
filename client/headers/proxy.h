#include <iostream>

#include "../../client.pb.h"
#include "../headers/client.h"

class Proxy
{
public:
    enum Method
    {
        LIST = 0,
        SCHEDULE,
        DELETE
    };
    proto::MedicalAppointmentList listMedicalAppointment(proto::Client);
    proto::MedicalAppointment scheduleMedicalAppointment(proto::MedicalAppointment);
    proto::MedicalAppointment deleteMedicalAppointment(proto::MedicalAppointment);
};