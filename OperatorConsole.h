#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H
#include<vector>

class OperatorCommand;

class OperatorConsole{
    private:
        std::vector<OperatorCommand*> history;

    public:
        OperatorConsole();
        ~OperatorConsole();
        void issueCommand(OperatorCommand* command);
        OperatorCommand* getLastCommand() const;
        std::size_t historySize() const;

};

#endif 