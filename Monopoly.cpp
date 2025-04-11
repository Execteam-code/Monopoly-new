#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <vector>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <windows.h>
using namespace std;
class person {
public:
    string Name;
    int count_of_street;
    int position;
    int wallet;
    person() {
        Name = "Player";
        count_of_street = 0;
        position = 0;
        wallet = 1500;
    }
    person(string pname) {
        Name = pname;
        count_of_street = 0;
        position = 0;
        wallet = 1500;
    }
};
class street {
public:
    int number_of_buildings;
    int cost;
    int rent;
    string street_color;
    string area_color;
    string street_name;
    bool isOwner;
    string street_owner;
    street(int p_number_of_buildings, int p_cost, int p_rent, string p_street_color, string p_area_color, string p_street_name) {
        number_of_buildings = p_number_of_buildings;
        cost = p_cost;
        rent = p_rent;
        street_color = p_street_color;
        area_color = p_area_color;
        street_name = p_street_name;
        isOwner = false;
    }
};
class game {
public:
    vector<street> karta;
    vector<person> players;
    vector<string> getPlayerStreets(const string& playerName) {
        vector<string> playerStreets;
        for (int i = 0; i < karta.size(); i++) {
            if (karta[i].isOwner && karta[i].street_owner == playerName) {
                playerStreets.push_back(karta[i].street_name);
            }
        }
        return playerStreets;
    }
    void round(int number, int roundNumber) {
        system("cls");
        cout << "Раунд: " << roundNumber << endl;
        int kubik = rand() % 6 + 1;
        cout << "Игрок " << players[number - 1].Name << ", нажмите Enter, чтобы бросить кубик..." << endl;
        cin.ignore();
        cin.get();
        cout << "Игрок " << players[number - 1].Name << " бросает кубик: " << kubik << endl;
        int& position = players[number - 1].position;
        int oldPosition = position;
        position = (position + kubik) % karta.size();
        if (position < oldPosition) {
            players[number - 1].wallet += 200;
            cout << players[number - 1].Name << " прошел круг и получает 200!" << endl;
        }
        cout << players[number - 1].Name << " перемещается на позицию " << position << ": " << karta[position].street_name << endl;
        if (!karta[position].isOwner) {
            buy(players[number - 1], karta[position]);
        }
        else {
            if (karta[position].street_owner != players[number - 1].Name) {
                players[number - 1].wallet -= karta[position].rent;
                cout << players[number - 1].Name << " платит штраф " << karta[position].rent << " владельцу " << karta[position].street_owner << endl;
                for (int i = 0; i < players.size(); i++) {
                    if (players[i].Name == karta[position].street_owner) {
                        players[i].wallet += karta[position].rent;
                        break;
                    }
                }
            }
            else {
                cout << players[number - 1].Name << " не платит штраф, так как это его улица." << endl;
            }
        }
        Sleep(2000);
        if (players[number - 1].wallet < 0) {
            cout << players[number - 1].Name << " обанкротился!" << endl;
            players.erase(players.begin() + (number - 1));
        }
    }
    void buy(person& currentPlayer, street& currentStreet) {
        if (currentStreet.cost == 0) {
            cout << currentPlayer.Name << " не может купить стартовую улицу." << endl;
            return;
        }
        cout << "Хотите купить улицу " << currentStreet.street_name << " за " << currentStreet.cost << " ? (да/нет): ";
        string answer;
        cin >> answer;
        if (answer == "да" && currentPlayer.wallet >= currentStreet.cost) {
            currentPlayer.wallet -= currentStreet.cost;
            currentStreet.isOwner = true;
            currentStreet.street_owner = currentPlayer.Name;
            currentPlayer.count_of_street++;
            cout << currentPlayer.Name << " купил улицу: " << currentStreet.street_name << endl;
        }
        else if (answer == "да") {
            cout << "У " << currentPlayer.Name << " недостаточно денег для покупки " << currentStreet.street_name << endl;
        }
        else {
            cout << currentPlayer.Name << " решил не покупать улицу " << currentStreet.street_name << endl;
        }
    }
    void startGame() {
        int roundNumber = 1;
        while (players.size() > 1) {
            for (int i = 0; i < players.size(); i++) {
                round(i + 1, roundNumber);
                if (players.size() <= 1) {
                    break;
                }
                showMenu(players[i]);
            }
            roundNumber++;
        }
        if (players.size() == 1) {
            cout << players[0].Name << " выиграл игру!" << endl;
        }
    }
    void showMenu(person& currentPlayer) {
        int choice;
        cout << "Меню для " << currentPlayer.Name << ":" << endl;
        cout << "1. Посмотреть информацию об игроке" << endl;
        cout << "2. Продолжить игру" << endl;
        cout << "3. Выйти из игры" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << currentPlayer.Name << " | Позиция: " << currentPlayer.position << " | Баланс: " << currentPlayer.wallet << endl;
            vector<string> streets = getPlayerStreets(currentPlayer.Name);
            if (streets.size() > 0) {
                cout << "Улицы: ";
                for (int j = 0; j < streets.size(); j++) {
                    cout << streets[j];
                    if (j < streets.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << endl;
                cout << "Нажмите Enter для продолжения" << endl;
                cin.ignore();
                cin.get();
                cout << "Продолжаем...";
                Sleep(1000);
            }
            else {
                cout << "У игрока нет улиц" << endl;
            }
            Sleep(2000);
        }
        else if (choice == 2) {
            cout << "Нажмите Enter для продолжения" << endl;
            cin.ignore();
            cin.get();
            cout << "Продолжаем...";
            Sleep(1000);
        }
        else if (choice == 3) {
            cout << "Выход из игры..." << endl;
            exit(0);
        }
        else {
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            showMenu(currentPlayer);
        }
    }
    void setupGame() {
        karta.push_back(street(0, 0, 0, "Grey", "Grey", "Стартовая"));
        karta.push_back(street(0, 100, 12, "Pink", "Pink", "Житная"));
        karta.push_back(street(0, 120, 14, "Pink", "Pink", "Нагатинская"));
        karta.push_back(street(0, 140, 16, "Blue", "Blue", "Варшавское шосс"));
        karta.push_back(street(0, 160, 18, "Blue", "Blue", "Огарева"));
        karta.push_back(street(0, 180, 22, "Blue", "Blue", "Первая Парковая"));
        karta.push_back(street(0, 210, 26, "Purple", "Purple", "Полянка"));
        karta.push_back(street(0, 230, 30, "Purple", "Purple", "Сретенка"));
        karta.push_back(street(0, 250, 35, "Purple", "Purple", "Ростовская"));
        karta.push_back(street(0, 260, 48, "Orange", "Orange", "Рязанская"));
        karta.push_back(street(0, 280, 52, "Orange", "Orange", "Вавилова"));
        karta.push_back(street(0, 300, 54, "Orange", "Orange", "Рублевская"));
        karta.push_back(street(0, 310, 60, "Red", "Red", "Тверская"));
        karta.push_back(street(0, 320, 62, "Red", "Red", "Пушкинская"));
        karta.push_back(street(0, 330, 64, "Red", "Red", "Ленина"));
        karta.push_back(street(0, 340, 68, "Yellow", "Yellow", "Смоленская"));
        karta.push_back(street(0, 350, 70, "Yellow", "Yellow", "Карла Маркса"));
        karta.push_back(street(0, 360, 80, "Yellow", "Yellow", "Речная"));
        karta.push_back(street(0, 370, 83, "Green", "Green", "Винокурова"));
        karta.push_back(street(0, 380, 87, "Green", "Green", "Калинина"));
        karta.push_back(street(0, 390, 92, "Green", "Green", "Университетская"));
        karta.push_back(street(0, 400, 96, "Dark blue", "Dark blue", "Лебедева"));
        karta.push_back(street(0, 420, 100, "Dark blue", "Dark blue", "Пирогова"));
        karta.push_back(street(0, 450, 120, "Dark blue", "Dark blue", "Космонафтики"));
    }
    void addPlayer(string name) {
        players.push_back(person(name));
    }
    void menu() {
        int choice;
        cout << "==========================================================================================" << endl;
        cout << "           _____	      ______    _______    ______                          _____    " << endl;
        cout << "|\\    /|  /     \\  |      |  /      \\  |       |  /      \\      / \\      |    /|  /     |" << endl;
        cout << "| \\  / | |       | |      | |        | |       | |        |    /   \\     |   / | |      |" << endl;
        cout << "|  \\/  | |       | |______| |        | |       | |        |   /     \\    |  /  |  \\_____|" << endl;
        cout << "|      | |       | |      | |        | |       | |        |  /       \\   | /   |     /  |" << endl;
        cout << "|      |  \\_____/  |      |  \\______/  |       |  \\______/  /         \\  |/    |    /   |" << endl;
        cout << "========================================================================================== " << endl;

        cout << "Выберите команду: " << endl;
        cout << "1. Начать игру" << endl;
        cout << "2. Выйти из игры" << endl;
        cin >> choice;

        if (choice == 1) {
            int count_of_players;
            cout << "Введите количество игроков (2-6): ";
            cin >> count_of_players;

            for (int i = 0; i < count_of_players; i++) {
                string name;
                cout << "Введите имя для игрока №" << (i + 1) << ": ";
                cin >> name;
                addPlayer(name);
            }

            startGame();
        }
        else {
            cout << "Возвращайтесь снова!" << endl;
        }
    }
};
int main() {
    srand(time(NULL));
    system("chcp 1251>nul");
    setlocale(LC_ALL, "ru");

    game Game;
    Game.setupGame();
    Game.menu();

    return 0;
}
