//
// Created by 0 on 18.03.2023.
//

#ifndef UNTITLED_BANK_SYS_H
#define UNTITLED_BANK_SYS_H


#include <vector>
#include "Bank.h"

class Bank_sys {
private:
    std::vector<Bank> banks;
public:
    explicit Bank_sys(const std::vector<Bank> &banks);
    void add_bank(int);
    void del_bank(int);
    const std::vector<Bank> &get_banks() const;
    void set_banks(const std::vector<Bank> &banks);

    void transit(int, int, double);


};


#endif //UNTITLED_BANK_SYS_H
