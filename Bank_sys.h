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
    Bank_sys();
    explicit Bank_sys(const std::vector<Bank> &banks);
    void add_bank(const Bank& new_bank);
    void del_bank(const int bank_id);
    const std::vector<Bank> &get_banks() const;
    void set_banks(const std::vector<Bank> &banks);

    Bank& find_bank_by_id(const int bank_id);

    void transit(int, int, double);


};


#endif //UNTITLED_BANK_SYS_H
