#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H
#include<string>
#include"ResponseComponent.h"

class MedicalTeam : public ResponseComponent{
    public:
        MedicalTeam(const std::string& name, IncidentMediator* mediator);
        ~MedicalTeam() override;
        void dispatch(const std::string& location) override;
        std::string getType() const override;
};

#endif