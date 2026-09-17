#ifndef LOCKDOWNCOMMAND_H
#define LOCKDOWNCOMMAND_H
#include<string>
#include"OperatorCommand.h"

class FacilitiesTeam;

class LockDownCommand : public OperatorCommand{
    private:
        FacilitiesTeam* receiver; 
        std::string area;
        bool locked;

    public:
        LockDownCommand(FacilitiesTeam* receiver, const std::string& area);
        ~LockDownCommand() override;
        void execute() override;
        void undo() override;
        std::string getDescription() const override;

};

#endif 