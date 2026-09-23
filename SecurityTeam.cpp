#include<iostream>
#include<string>
#include"SecurityTeam.h"

SecurityTeam::SecurityTeam(const std::string& name, IncidentMediator* mediator) : ResponseComponent(name, mediator), securedArea(""){

}

SecurityTeam::~SecurityTeam(){

}

void SecurityTeam::dispatch(const std::string& location){
    available = false;
    std::cout << "[Security]" << name << "rolling out to " << location << std::endl;
}

void SecurityTeam::secureArea(const std::string& area){
    securedArea = area;
    std::cout << "[Security]" << name << " has secured " << area << std::endl;
    notifyMediator("ZoneSecured", area);
}

void SecurityTeam::reopenArea(const std::string& area){
    if(securedArea == area){
        securedArea= "";
        std::cout << "[Security] " << name << " has reopened " << area << " (undo)" << std::endl;
    }
    else{
        std::cout << "[Security] " << name << " cannot reopen " << area << " it was not the area currently secured" << std::endl;
    }
}

std::string SecurityTeam::getType() const{
    return "Security";
}

