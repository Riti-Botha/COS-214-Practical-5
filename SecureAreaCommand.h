#ifndef SECUREAREACOMMAND_H
#define SECUREAREACOMMAND_H
#include<string>
#include"OperatorCommand.h"

class SecurityTeam;

class SecureAreaCommand : public OperatorCommand{
    private:
        SecurityTeam* receiver;
        std::string area;
        bool secured;

    public:
        SecureAreaCommand(SecurityTeam* receiver, const std::string& area);
        ~SecureAreaCommand() override;
        void execute() override;
        void undo() override;
        std::string getDescription() const override;

};

#endif