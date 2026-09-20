#include<iostream>
#include<vector>
#include"OperatorConsole.h"
#include"OperatorCommand.h"

OperatorConsole::OperatorConsole(){

}

OperatorConsole::~OperatorConsole(){
    for(std::vector<OperatorCommand*>::iterator it = history.begin(); it != history.end; it++){
        delete *it;
    }

    history.clear();
}

void OperatorConsole::issueCommand(OperatorCommand* command){
    history.push_back(command);
    command -> execute();
}

OperatorCommand* OperatorConsole::getLastCommand() const{
    if(history.empty()){
        return nullptr;
    }

    return history.back();
}

std::size_t OperatorConsole::historySize() const{
    return history.size();
}
