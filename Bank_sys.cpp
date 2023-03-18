//
// Created by 0 on 18.03.2023.
//

#include "Bank_sys.h"

Bank_sys::Bank_sys(const std::vector<Bank> &banks) : banks(banks) {}

void Bank_sys::add_bank(int) {

}

void Bank_sys::del_bank(int) {

}

const std::vector<Bank> &Bank_sys::get_banks() const {
    return banks;
}

void Bank_sys::set_banks(const std::vector<Bank> &banks) {
    Bank_sys::banks = banks;
}

void Bank_sys::transit(int pers, int to_pers, double sum) {
    int bank_id1 = pers / 100;
    int num_pers = pers % 100;
    int bank_id2 = to_pers / 100;
    int num_to_pers = to_pers % 100;

    Bank bank1 = *new Bank();
    for(int i = 0; i < banks.size(); i++) {
        if(banks[i].get_bank_id() == bank_id1) {

        }

    }

}
