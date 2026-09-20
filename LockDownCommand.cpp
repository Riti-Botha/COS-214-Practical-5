#include<iostream>
#include"LockDownCommand.h"
#include"FacilitiesTeam.h"

LockDownCommand::LockDownCommand(FacilitiesTeam* receiver, const std::string& area) : receiver(receiver), area(area), locked(false){

}

LockDownCommand::~LockDownCommand(){

}

void LockDownCommand::execute(){
    receiver -> lockArea(area);
    locked = true;
}

void LockDownCommand::undo(){
    if(locked){
        receiver -> unlockArea(area);
        locked = false;
    }
}

std::string LockDownCommand::getDescription() const{
    return "Lockdown area" + area;
}