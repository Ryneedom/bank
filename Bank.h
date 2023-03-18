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
    Bank(int bank_id, double all_money, double percent);

    void add_person(const Person& person);

    /**
     * Удалить клиента пользователя с определенным номером счета
     * @param acc_number Номер счета клиента
     */
    void delete_person(const int acc_number);

    int get_bank_id() const;

    double get_all_money() const;

    const std::vector<Person> &get_persons() const;

    int get_percent() const;

    void set_all_money(double allMoney);

    void set_persons(const std::vector<Person> &persons);

    Person& find_person_by_number(const int account_number);
};


#endif //UNTITLED_BANK_H
