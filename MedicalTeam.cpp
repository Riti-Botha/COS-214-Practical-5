#include<iostream>
#include<string>
#include"MedicalTeam.h"

MedicalTeam::MedicalTeam(const std::string& name, IncidentMediator* mediator) : ResponseComponent(name, mediator){

}

MedicalTeam::~MedicalTeam(){

}

void MedicalTeam::dispatch(const std::string& location){
    available = false;
    std::cout << "[Medical] " << name << " responding to" << location << std::endl;
}

std::string MedicalTeam::getType() const{
    return "Medical";
}