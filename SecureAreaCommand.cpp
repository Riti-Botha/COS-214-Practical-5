#include<iostream>
#include"SecureAreaCommand.h"
#include"SecurityTeam.h"

SecureAreaCommand::SecureAreaCommand(Security* receiver, const std::string& area) : receiver(receiver), area(area), secured(false){

}

SecureAreaCommand::~SecureAreaCommand(){

}

void SecureAreaCommand::execute(){
    receiver -> secureArea(area);
    secured = true;
}

void SecureAreaCommand::undo(){
    if(secured){
        receiver -> reopenArea(area);
        secured = false;
    }
}

std::string SecureAreaCommand::getDescription() const{
    return " Secure area " + area;
}