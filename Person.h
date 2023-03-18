//
// Created by 0 on 14.03.2023.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
#include <string>

class Person {
    private:
        std::string type;
        int account_number;
        double money;
    public:
        Person();

        const std::string &get_type() const;

        void set_type(const std::string &type);

        int get_account_number() const;

        void set_account_number(int account_number);

        double get_money() const;

        void set_money(double money);

};


#endif //UNTITLED_PERSON_H
