#include<iostream>
#include<string>
#include"FacilitiesTeam.h"

FacilitiesTeam::FacilitiesTeam(const std::string& name, IncidentMediator* mediator) : ResponseComponent(name, mediator), lockedArea(""){

}

FacilitiesTeam::~FacilitiesTeam(){

}

void FacilitiesTeam::dispatch(const std::string& location){
    available = false;
    std::cout << "[Facilities] " << name << " deployed to " << location << std::endl;
}

void FacilitiesTeam::lockArea(const std::string& area){
    lockedArea = area;
    std::cout << "[Facilities] " << name << " has locked down " << area << std::endl;
}

void FacilitiesTeam::unlockArea(const std::string& area){
    if(lockedArea_ == area){
        lockedArea = "";
        std::cout << "[Facilities] " << name << " has unlocked " << area << std::endl;
    } 
    else{
        std::cout << "[Facilities] " << name << " cannot unlock " << area << " it is not currently locked" << std::endl;
    }
}

bool FacilitiesTeam::isAreaLocked(const std::string& area) const{
    return lockedArea == area;
}

std::string FacilitiesTeam::getType() const{
    return "Facilities";
}