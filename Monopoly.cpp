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
#include<windows.h>

using namespace std;

class person {
public:
    string Name;
    int count_of_street;
    int position;
    int wallet;
    int number_of_player;
    person() {
        Name = "Player";
        count_of_street = 0;
        position = 0;
        wallet = 1500;
        number_of_player = 0;
    }
    person(string pname) {
        Name = pname;
        count_of_street = 0;
        position = 0;
        wallet = 1500;
        number_of_player = 0;
    }
    void input_name() {
        cin >> Name;
    }
};

person player_1("None");
person player_2("None");
person player_3("None");
person player_4("None");
person player_5("None");
person player_6("None");


class street {
public:
    int number_of_buildings; //количество строений
    int cost;//стоимость
    int rent;//штраф
    string street_color;//цвет улицы
    string area_color;//цвет района
    string street_name;//название улицы
    int number_street;//номер улицы
    string street_owner;//владелец улицы
    bool isOwner;

    street(int p_number_of_buildings, int p_cost, int p_rent, string p_street_color, string p_area_color, string p_street_name, int p_number_street)
    {
        number_of_buildings = p_number_of_buildings; //количество строений
        cost = p_cost;//стоимость
        rent = p_rent;//штраф
        street_color = p_street_color;//цвет улицы
        area_color = p_area_color;//цвет района
        street_name = p_street_name;//название улицы
        number_street = p_number_street;//номер улицы
        isOwner = 0;
    }
};


/*class cube {
public:
    int min;
    int max;
    int result;
    cube() {
        min = 1;
        max = 12;
        result = 0;
    }

    void cub() {
        int min = 1;
        int max = 12;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max);
        result = distrib(gen);
        cout << "Выпало число : " << result;
    }
};*/

class game {
public:
    int move = 0;
    int countPlayers = 0;
    vector<street>karta;

    void round(int number) {
        int kubik = rand() % 6 + 1;
        position(number, kubik);
    }
    bool state() {
        if (countPlayers == 2) {
            cout << "Игрок 1:" << player_1.position << endl;;
            //характеристики
            cout << "Игрок 2:" << player_2.position << endl;;
            //характеристики
            map(); // полностью сделать 
            system("pause");
            round(1);
            round(2);
        }
        return state();

    }
    void position(int number, int rand) {
        if (number == 1) {
            if (player_1.position + rand > 24) {
                //если чел стоит на 24улице и ему выпадает 4 то он переходит на 4 улицу а не на 1 
            }
            else {
                player_1.position = player_1.position + rand;
            }
        }
        else if (number == 2) {
            player_2.position = player_2.position + rand;
        }
        if (karta.at(player_2.position).isOwner == 0) {
            buy();
        }

    }
    void buy() {
    }
    int menu() {
        int buff;
        while (true) {
            cout << "Выбери команду: " << endl;
            cout << "1.Начать игру" << endl;
            cout << "2.Выйти из игры" << endl;
            cin >> buff;
            if (buff == 1 or buff == 2) {
                break;
            }
            else {
                cout << "Введи корректное значение! " << endl;
            }
        }
        Sleep(1000);
        return buff;
    }
    void map() {
        for (int i = 0; i < 3; i++) {
            cout << "Название:" << karta.at(i).street_name << endl;
        }

    }

};



int main() {
    srand(time(NULL));
    game Game;
    if (true) {//улицы
        street myStreetZero(0, 100, 12, "Grey", "Grey", "Стартовая!", 0);
        Game.karta.push_back(myStreetZero);
        street myStreetOne(0, 100, 12, "Pink", "Pink", "Житная. ул", 1);
        Game.karta.push_back(myStreetOne);
        street myStreetTwo(0, 120, 14, "Pink", "Pink", "Нагатинская. ул", 2);
        Game.karta.push_back(myStreetTwo);
        street myStreetThree(0, 140, 16, "Blue", "Blue", "Варшавское шоссе. ул", 3);
        Game.karta.push_back(myStreetThree);
        street myStreetFour(0, 160, 18, "Blue", "Blue", "Огарева. ул", 4);
        Game.karta.push_back(myStreetFour);
        street myStreetFive(0, 180, 22, "Blue", "Blue", "Первая Парковая. ул", 5);
        Game.karta.push_back(myStreetFive);
        street myStreetSix(0, 210, 26, "Purple", "Purple", "Полянка.ул", 6);
        Game.karta.push_back(myStreetSix);
        street myStreetSeven(0, 230, 30, "Purple", "Purple", "Сретенка.ул", 7);
        Game.karta.push_back(myStreetSeven);
        street myStreetEeight(0, 250, 35, "Purple", "Purple", "Ростовская.ул", 8);
        Game.karta.push_back(myStreetEeight);
        street myStreetNine(0, 260, 48, "Orange", "Orange", "Рязанский. пр", 9);
        Game.karta.push_back(myStreetNine);
        street myStreetTen(0, 280, 52, "Orange", "Orange", "ул. Вавилова", 10);
        Game.karta.push_back(myStreetTen);
        street myStreetEleven(0, 300, 54, "Orange", "Orange", "Рублевское шоссе", 11);
        Game.karta.push_back(myStreetEleven);
        street myStreetTwelve(0, 310, 60, "Red", "Red", "ул. Тверская", 12);
        Game.karta.push_back(myStreetTwelve);
        street myStreetThirteen(0, 320, 62, "Red", "Red", "ул. Пушкинская", 13);
        Game.karta.push_back(myStreetThirteen);
        street myStreetFifteen(0, 330, 64, "Red", "Red", "Площадь Маяковского", 14);
        Game.karta.push_back(myStreetFifteen);
        street myStreetSixteen(0, 340, 68, "Yellow", "Yellow", "Смоленская.ул", 15);
        Game.karta.push_back(myStreetSixteen);
        street myStreetSeventeen(0, 350, 70, "Yellow", "Yellow", "ул. Эдварда грига", 16);
        Game.karta.push_back(myStreetSeventeen);
        street myStreetEighteen(0, 360, 80, "Yellow", "Yellow", "Парк Волкого", 17);
        Game.karta.push_back(myStreetEighteen);
        street myStreetNineteen(0, 370, 83, "Green", "Green", "Красная Площадь", 18);
        Game.karta.push_back(myStreetNineteen);
        street myStreetTwenty(0, 380, 87, "Green", "Green", "Белые озера", 19);
        Game.karta.push_back(myStreetTwenty);
        street myStreetTwentyOne(0, 390, 92, "Green", "Green", "Метро Сколково", 20);
        Game.karta.push_back(myStreetTwentyOne);
        street myStreetTwentyTwo(0, 400, 96, "Dark blue", "Dark blue", "ВДНХ", 21);
        Game.karta.push_back(myStreetTwentyTwo);
        street myStreetTwentyThree(0, 420, 100, "Dark blue", "Dark blue", "Парк Победы", 22);
        Game.karta.push_back(myStreetTwentyThree);
        street myStreetTwentyFour(0, 450, 120, "Dark blue", "Dark blue", "ул.Космонафтики", 23);
        Game.karta.push_back(myStreetTwentyFour);

    }
    system("chcp 1251>nul");
    setlocale(LC_ALL, "ru");
    int count_of_players = 0;
    string name;
    if (Game.menu() == 1) {
        cout << "Добро пожаловать в Монополию..." << endl;
        Sleep(1000);
        cin >> count_of_players;
        if (count_of_players == 2) {
            cin.ignore();
            cout << "Введите имя для игрока №1: " << endl;
            getline(cin, name);
            player_1.Name = name;
            cout << "Введите имя для игрока №2: " << endl;
            getline(cin, name);
            player_2.Name = name;
            Game.countPlayers = count_of_players;
            Game.state();
        }
        /*else if (count_of_players == 3) {
            cin.ignore();
            cout << "Введите имя для игрока №1: " << endl;
            getline(cin, name);
            person player_1(name);
            cout << "Введите имя для игрока №2: " << endl;
            getline(cin, name);
            person player_2(name);
            cout << "Введите имя для игрока №3: " << endl;
            getline(cin, name);
            person player_3(name);
        }
        else if (count_of_players == 4) {
            cin.ignore();
            cout << "Введите имя для игрока №1: " << endl;
            getline(cin, name);
            person player_1(name);
            cout << "Введите имя для игрока №2: " << endl;
            getline(cin, name);
            person player_2(name);
            cout << "Введите имя для игрока №3: " << endl;
            getline(cin, name);
            person player_3(name);
            cout << "Введите имя для игрока №4: " << endl;
            getline(cin, name);
            person player_4(name);
        }
        else if (count_of_players == 5) {
            cin.ignore();
            cout << "Введите имя для игрока №1: " << endl;
            getline(cin, name);
            person player_1(name);
            cout << "Введите имя для игрока №2: " << endl;
            getline(cin, name);
            person player_2(name);
            cout << "Введите имя для игрока №3: " << endl;
            getline(cin, name);
            person player_3(name);
            cout << "Введите имя для игрока №4: " << endl;
            getline(cin, name);
            person player_4(name);
            cout << "Введите имя для игрока №5: " << endl;
            getline(cin, name);
            person player_5(name);
        }
        else if (count_of_players == 6) {
            cin.ignore();
            cout << "Введите имя для игрока №1: " << endl;
            getline(cin, name);
            person player_1(name);
            cout << "Введите имя для игрока №2: " << endl;
            getline(cin, name);
            person player_2(name);
            cout << "Введите имя для игрока №3: " << endl;
            getline(cin, name);
            person player_3(name);
            cout << "Введите имя для игрока №4: " << endl;
            getline(cin, name);
            person player_4(name);
            cout << "Введите имя для игрока №5: " << endl;
            getline(cin, name);
            person player_5(name);
            cout << "Введите имя для игрока №6: " << endl;
            getline(cin, name);
            person player_6(name);
        }*/

    }
    else {
        cout << "Возвращайтесь снова!" << endl;
    }



};

// comit test 2

