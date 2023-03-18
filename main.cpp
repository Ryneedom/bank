#include <iostream>
#include <string>
#include "Bank_sys.h"

void print_menu() {
    std::cout << "1 - Вывести список команд\n";
    std::cout << "2 - Создать банк\n";
    std::cout << "3 - Вывести список пользователей банка\n";
    std::cout << "4 - Вывести список банков\n";
    std::cout << "5 - Добавть пользователя в банке\n";
    std::cout << "6 - Сделать перевод между пользователями\n";
    std::cout << "7 - Удалить пользователя из банка\n";
    std::cout << "8 - Удалить банк\n";
    std::cout << "9 - Выход\n";
}

void create_new_bank(Bank_sys& system) {
    std::cout << "Введите номер банка: ";
    int id;
    std::cin >> id;
    std::cout << "Введите количество денег банка: ";
    double money;
    std::cin >> money;
    std::cout << "Введите процент банка: ";
    double percent;
    std::cin >> percent;

    system.add_bank(Bank{id, money, percent});
    std::cout << "Банк успешно добавлен" << std::endl;
}

void create_new_client(Bank_sys& system) {
    std::cout << "Введите номер банка, в который собираетесь добавить пользователя: ";
    int bank_id;
    std::cin >> bank_id;
    try {
        auto bank = system.find_bank_by_id(bank_id);

        int num = 0;
        while(num != 1 && num != 2) {
            std::cout << "Введите тип пользователя: 1 - phys, 2 - legal";
            std::cin >> num;
        }
        int account;
        while(account / 100 != bank_id && account) {
            std::cout << "Введите номер счета пользователя(номер банка + две любые цифры): ";
            std::cin >> account;
        }
        std::cout << "Введите количество денег пользователя: ";
        double money;
        std::cin >> money;
        std::string type;
        if (num != 1) {
            type = "legal";
        } else {
            type = "phys";
        }
        bank.add_person(Person{type, account, money});
        std::cout << "Пользователь успешно добавлен" << std::endl;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return;
    }
}

void print_persons(Bank_sys& system) {
    std::cout << "Введите номер банка: ";
    int bank_id;
    std::cin >> bank_id;
    try {
        auto bank = system.find_bank_by_id(bank_id);
        std::cout << "Пользователи:" << std::endl;
        for(auto person: bank.get_persons()) {
            std::cout << "Тип пользователя: " << person.get_type() << ", Номер счета: " << person.get_account_number() << ", Количество денег: " << person.get_money() << std::endl;
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return;
    }
}

void print_banks(Bank_sys& system) {
    std::cout << "Банки:" << std::endl;
    for(auto bank: system.get_banks()) {
        std::cout << "Банк №: " << bank.get_bank_id() << ", Количество денег: " << bank.get_all_money() << ", Процент: " << bank.get_percent() << std::endl;
    }
}

void make_transit(Bank_sys& system) {
    std::cout << "Введите свой номер: ";
    int person1;
    std::cin >> person1;
    std::cout << "Введите номер на который хотите перевести: ";
    int person2;
    std::cin >> person2;
    std::cout << "Введите сумму перевода: ";
    int sum;
    std::cin >> sum;
    system.transit(person1, person2, sum);
}

void remove_person(Bank_sys& system) {
    std::cout << "Введите номер банка: ";
    int bank_id;
    std::cin >> bank_id;
    try {
        auto bank = system.find_bank_by_id(bank_id);
        std::cout << "Введите номер счета пользователя: ";
        int account;
        std::cin >> account;
        bank.delete_person(account);
        std::cout << "Пользователь был удален" << std::endl;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return;
    }
}

void remove_bank(Bank_sys& system) {
    std::cout << "Введите номер банка: ";
    int bank_id;
    std::cin >> bank_id;
    try {
        system.del_bank(bank_id);
        std::cout << "Пользователь был удален" << std::endl;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return;
    }
}

int main() {
    std::cout << "Банковская система" << std::endl;

    Bank_sys system;
    bool end = false;
    while (!end) {
        print_menu();
        std::cout << std::endl;
        std::cout << "Выберите действие: ";
        int doing;
        std::cin >> doing;
        switch (doing) {
            case 1:
                print_menu();
                break;
            case 2:
                create_new_bank(system);
                break;
            case 3:
                print_persons(system);
                break;
            case 4:
                print_banks(system);
                break;
            case 5:
                create_new_client(system);
                break;
            case 6:
                make_transit(system);
                break;
            case 7:
                remove_person(system);
                break;
            case 8:
                remove_bank(system);
                break;
            case 9:
                std::cout << "Выход из приложения" << std::endl;
                end = true;
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}
