#ifndef POLISH_H
#define POLISH_H
#include <queue>
#include <string>

class Polish
{
    public:
    Polish(std::string s);
    int take_indicator();
    char take_op();
    int take_num();
    int calculate(int count);
    void string_handle(std::string s);
    private:
    std :: queue <int> indicator;
    std:: queue <char> op;
    std:: queue <int> operand;
};
#endif