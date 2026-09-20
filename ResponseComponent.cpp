#include<iostream>
#include<string>
#include"ResponseComponent.h"
#include"IncidentMediator.h"

ResponseComponent::ResponseComponent(const std::string& name, IncidentMediator* mediator) : name(name), available(true), mediator(mediator){

}

ResponseComponent::~ResponseComponent(){

}

void ResponseComponent::dispatch(const std::string& location){
    available = false;
    std::cout << "[" << getType() << "] " << name << " dispatched to " << location << std::endl;
}

void ResponseComponent::recall(){
    available = true;
    std::cout << "[" << getType() << "] " << name << " recalled and back on standby" << std::endl;
    notifyMediator("UnitRecalled", name);
}

std::string ResponseComponent::getName() const{
    return name;
}

bool ResponseComponent::isAvailable() const{
    return available;
}

void ResponseComponent::notifyMediator(const std::string& event, const std::string& location){
    if(mediator != nullptr){
        mediator -> notify(this, event, location);
    }
}