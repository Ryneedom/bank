//
// Created by 0 on 14.03.2023.
//

#ifndef UNTITLED_BANK_H
#define UNTITLED_BANK_H


#include <string>
#include <vector>
#include "Person.h"



class Bank {
private:
    int bank_id;
    double all_money;
    std::vector<Person> persons;
    int percent;
public:
    Bank();
    void add_person();
    void delete_person();

    int get_bank_id() const;

    double get_all_money() const;

    const std::vector<Person> &get_persons() const;

    int get_percent() const;

    void set_all_money(double allMoney);

    void set_persons(const std::vector<Person> &persons);


};


#endif //UNTITLED_BANK_H
