#ifndef CANCELCOMMAND_H
#define CANCELCOMMAND_H
#include"OperatorCommand.h"


class CancelCommand : public OperatorCommand{
    private:
        OperatorCommand* target; 
        
    public:
        explicit CancelCommand(OperatorCommand* target);
        ~CancelCommand() override;
        void execute() override;
        std::string getDescription() const override;

};

#endif 