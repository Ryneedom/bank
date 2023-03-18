//
// Created by 0 on 14.03.2023.
//

#include "Bank.h"


Bank::Bank() {

}

void Bank::add_person() {

}

void Bank::delete_person() {

}

const std::string &Bank::get_bank_id() const {
    return bank_id;
}

double Bank::get_all_money() const {
    return all_money;
}

const std::vector<Person> &Bank::get_persons() const {
    return persons;
}

int Bank::get_percent() const {
    return percent;
}

void Bank::set_all_money(double allMoney) {
    all_money = allMoney;
}

void Bank::set_persons(const std::vector<Person> &persons) {
    Bank::persons = persons;
}

int Bank::get_bank_id() const {
    return bank_id;
}


