#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H
#include<string>
#include<vector>
#include"IncidentMediator.h"

class SecurityTeam;
class MedicalTeam;
class FacilitiesTeam;

class IncidentCoordinator : public IncidentMediator{
    private:
        std::vector<ResponseComponent*> components;
        SecurityTeam* security;   
        MedicalTeam* medical;    
        FacilitiesTeam* facilities;

    public:
        IncidentCoordinator();
        ~IncidentCoordinator();
        void registerComponent(ResponseComponent* component) override;
        void notify(ResponseComponent* sender, const std::string& event, const std::string& location) override;
        void setSecurityTeam(SecurityTeam* team);
        void setMedicalTeam(MedicalTeam* team);
        void setFacilitiesTeam(FacilitiesTeam* team);
};

#endif