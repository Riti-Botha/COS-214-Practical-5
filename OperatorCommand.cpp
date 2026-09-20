#include<iostream>
#include"OperatorCommand.h"

OperatorCommand::~OperatorCommand(){

}

void OperatorCommand::undo(){
    std::cout << "[OperatorCommand] " << getDescription() << " cannot be undone" << std::endl;
}