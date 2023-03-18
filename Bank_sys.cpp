//
// Created by 0 on 18.03.2023.
//

#include "Bank_sys.h"
#include <algorithm>

Bank_sys::Bank_sys(): banks(){}
Bank_sys::Bank_sys(const std::vector<Bank> &banks) : banks(banks) {}

void Bank_sys::add_bank(const Bank& bank) {
    banks.push_back(bank);
}

void Bank_sys::del_bank(const int bank_id) {
    auto bank = std::find_if(banks.begin(), banks.end(),
                             [=](Bank b){return b.get_bank_id() == bank_id;});
    if(bank == banks.end()) {
        throw "Банка с таким номером не существует";
    }

    banks.erase(bank);
}

const std::vector<Bank> &Bank_sys::get_banks() const {
    return banks;
}

void Bank_sys::set_banks(const std::vector<Bank> &banks) {
    Bank_sys::banks = banks;
}

Bank& Bank_sys::find_bank_by_id(const int bank_id) {
    auto bank = std::find_if(banks.begin(), banks.end(),
                             [=](Bank b){return b.get_bank_id() == bank_id;});
    if(bank == banks.end()) {
        throw "Банка с таким номером не существует";
    } else {
        return *bank;
    }
}

void Bank_sys::transit(int pers, int to_pers, double sum) {
    //находим айди первого и второго банка
    int bank_id1 = pers / 100;
    int bank_id2 = to_pers / 100;

    //создаем ссылки на пользователей и банки
    Bank & bank1 = find_bank_by_id(bank_id1);
    Person & person1 = bank1.find_person_by_number(pers);
    Bank & bank2 = find_bank_by_id(bank_id2);
    Person & person2 = bank1.find_person_by_number(to_pers);

    if(person1.get_money() < sum + sum * bank1.get_percent()/100.0) { //делаем проверку на обнуление счета
        throw "Недостаточно средств";
    }
    if(bank_id1 == bank_id2) { //проверка на перевод внутри банка
        bank1.set_all_money(bank1.get_all_money() + sum * bank1.get_percent()/100.0);
        person1.set_money(person1.get_money() - sum + sum * bank1.get_percent()/100.0);
        person2.set_money(person2.get_money() + sum);
        return;
    }
    if(bank_id1 != bank_id2 && person1.get_type() != "legal") {
        throw "Для перевода в другой банк нужно быть юр. лицом";
    }
    else { //перевод между банками
        bank1.set_all_money(bank1.get_all_money() + sum * bank1.get_percent()/100.0 - sum);
        person1.set_money(person1.get_money() - sum + sum * bank1.get_percent()/100.0);
        person2.set_money(person2.get_money() + sum);
        bank2.set_all_money(bank2.get_all_money() + sum);
    }

}
