//
// Created by 0 on 14.03.2023.
//

#include "Person.h"

Person::Person() {

}

Person::Person(std::string type, int account, double money): type(type), account_number(account), money(money){}

const std::string &Person::get_type() const {
    return type;
}

void Person::set_type(const std::string &type) {
    Person::type = type;
}

double Person::get_money() const {
    return money;
}

void Person::set_money(double money) {
    Person::money = money;
}

int Person::get_account_number() const {
    return account_number;
}

void Person::set_account_number(int account_number) {
    Person::account_number = account_number;
}



