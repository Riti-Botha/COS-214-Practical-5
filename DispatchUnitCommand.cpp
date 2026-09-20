#include<iostream>
#include"DispatchUnitCommand.h"
#include"ResponseComponent.h"

DispatchUnitCommand::DispatchUnitCommand(ResponseComponent* receiver, const std::string& location) : receiver(receiver), location(location), dispatched(false){

}

DispatchUnitCommand::~DispatchUnitCommand(){
   
}

void DispatchUnitCommand::execute(){
    receiver -> dispatch(location);
    dispatched = true;
}

void DispatchUnitCommand::undo(){
    if(dispatched){
        receiver -> recall();
        dispatched = false;
    }
}

std::string DispatchUnitCommand::getDescription() const{
    return "Dispatch " + receiver -> getName() + " to " + location;
}