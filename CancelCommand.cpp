#include<iostream>
#include"CancelCommand.h"

CancelCommand::CancelCommand(OperatorCommand* target) : target(target){

}

CancelCommand::~CancelCommand(){

}

void CancelCommand::execute(){
    if(target != nullptr){
        std::cout << "[CancelCommand] cancelling: " << target -> getDescription() << std::endl;
        target -> undo();
    }
}

std::string CancelCommand::getDescription() const{
    if(target != nullptr){
        return "Cancel (" + target -> getDescription() + ")";
    }

    return "Cancel (no target)";
}