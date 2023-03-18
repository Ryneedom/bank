//
// Created by 0 on 14.03.2023.
//

#include "Bank.h"
#include <algorithm>


Bank::Bank() {

}

Bank::Bank(int bank_id, double all_money, double percent): bank_id(bank_id), all_money(all_money), percent(percent){}

void Bank::add_person(const Person& person) {
    persons.push_back(person);
}

Person& Bank::find_person_by_number(const int acc_number) {
    auto person = std::find_if(persons.begin(), persons.end(),
                               [=](Person p){return p.get_account_number() == acc_number;});
    if (person == persons.end()) {
        throw "Пользователя с таким номером счета не существует";
    } else {
        return *person;
    }
}

void Bank::delete_person(const int acc_number) {
    auto person = std::find_if(persons.begin(), persons.end(),
                               [=](Person p){return p.get_account_number() == acc_number;});
    if (person == persons.end()) {
        throw "Пользователя с таким номером счета не существует";
    }
    persons.erase(person);
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


