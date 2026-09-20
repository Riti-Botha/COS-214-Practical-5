#include<iostream>
#include<string>
#include"IncidentCoordinator.h"
#include"SecurityTeam.h"
#include"MedicalTeam.h"
#include"FacilitiesTeam.h"

IncidentCoordinator::IncidentCoordinator() : security(nullptr), medical(nullptr), facilities(nullptr){

}

IncidentCoordinator::~IncidentCoordinator{

}

void IncidentCoordinator::registerComponent(ResponseComponent* component){
    components.push_back(component);
}
 
void IncidentCoordinator::setSecurityTeam(SecurityTeam* team){
    security = team;
}
 
void IncidentCoordinator::setMedicalTeam(MedicalTeam* team){
    medical = team;
}
 
void IncidentCoordinator::setFacilitiesTeam(FacilitiesTeam* team){
    facilities = team;
}

void IncidentCoordinator::notify(ResponseComponent* sender, const std::string& event, const std::string& location){
    std::cout << "[IncidentCoordinator] received " << event << " from " << sender -> getName() << " re: " << location << std::endl;
 
    if(event == "ZoneSecured"){
        if(facilities != nullptr){
            facilities  -> lockArea(location);
        }

        if(medical != nullptr){
            medical -> dispatch(location);
        }
    } 
    else if(event == "UnitRecalled"){
        std::cout << "[IncidentCoordinator] noted recall of " << sender -> getName() << std::endl;
    }
}