#include <iostream>
#include <Windows.h>

using namespace std;
struct Games {
   
    char game;
    //Персонаж
    char pakmen = char(1);
    //Балли і жизні і кількість ходів
    int ochki = 0, heart = 3, hod = 0;
    //Позиція ігрока
    int x = 2, y = 2;
    //Рандом для бомб і баллів
    int rand_1 = 0, rand_2 = 0;


}game;


int main()
{
    setlocale(LC_ALL, "ukr");
    srand(time(NULL));
    const int COL = 20;
    const int ROW = 30;
    char arr[COL][ROW];
    
    //Создає карту
    for (int i = 0; i < COL; i++) {
        for (int k = 0; k < ROW; k++) {
            arr[i][0] = '#';
            arr[i][k] = ' ';
            arr[0][k] = '#';
            arr[19][k] = '#';
            arr[i][29] = '#';

        }
    }


   
    
    //Создає бомби
    for (int i = 0; i < 10; i++) {
        game.rand_1 = 1 + rand() % 19;//COL
        game.rand_2 = 1 + rand() % 29;//ROW
        if (game.x == game.rand_1 && game.y == game.rand_2) {
            game.rand_1 = 1 + rand() % 19;//COL
            game.rand_2 = 1 + rand() % 29;//ROW
        }
        arr[game.rand_1][game.rand_2] = '*';// '*'  бомби

    }


    //Создає очки
    for (int i = 0; i < 15; i++) {
        game.rand_1 = 1 + rand() % 19;//COL
        game.rand_2 = 1 + rand() % 29;;//ROW
        if (game.x == game.rand_1 && game.y == game.rand_2) {
            game.rand_1 = 1 + rand() % 19;//COL
            game.rand_2 = 1 + rand() % 29;;//ROW
        }
        arr[game.rand_1][game.rand_2] = '+';// '+' балли

    }
    arr[game.x][game.y] = game.pakmen;
    


    //Керування 
    for (int game_1 = 0; game_1 < 10000; game_1++) {
        system("cls");
        cout << "Балли - " << game.ochki << " Жизнi - " << game.heart << " Крокiв - " << game.hod;
        for (int i = 0; i < COL; i++) {
            cout << "\n";
            for (int k = 0; k < ROW; k++) {
                cout << "|";
                cout << arr[i][k];
            }
            cout << "|";
        }
        //Провірка жизні
        if (game.heart < 1) {
            cout << "\nGame Over\n";
            cout << "Балли - " << game.ochki  << "\nКрокiв - " << game.hod;
            return 0;
        }
        cin >> game.game;
        

       

        
        // W ідти вперед
        if (int(game.game) == 119 || int(game.game) == 87) {
            arr[game.x][game.y] = ' ';
            game.x -= 1;
            // Бар'єр # == 35
            if (int(arr[game.x][game.y]) == 35) {
                game.x += 1;
                arr[game.x][game.y] = game.pakmen;
            }
            // + == 43 очки
            if (int(arr[game.x][game.y]) == 43) {
                game.ochki++;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            // * == 42 бомби
            if (int(arr[game.x][game.y]) == 42) {
                game.heart--;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            else {
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }

          
        }
     
        // S ідти назад
        else if (int(game.game) == 83 || int(game.game) == 115) {
            arr[game.x][game.y] = ' ';
            game.x += 1;
            // Бар'єр # == 35
            if (int(arr[game.x][game.y]) == 35) {
                game.x -= 1;
                arr[game.x][game.y] = game.pakmen;
            }
            // + == 43 очки
            if (int(arr[game.x][game.y]) == 43) {
                game.ochki++;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            // * == 42 бомби
            if (int(arr[game.x][game.y]) == 42) {
                game.heart--;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            else {
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }

        }
        // A ідти вліво
        else if (int(game.game) == 97 || int(game.game) == 65) {
            arr[game.x][game.y] = ' ';
            game.y -= 1;
            // Бар'єр # == 35
            if (int(arr[game.x][game.y]) == 35) {
                game.y += 1;
                arr[game.x][game.y] = game.pakmen;
            }
            // + == 43 очки
            if (int(arr[game.x][game.y]) == 43) {
                game.ochki++;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            // * == 42 бомби
            if (int(arr[game.x][game.y]) == 42) {
                game.heart--;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            else {
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
        }
        // D ідти вправо
        else if (int(game.game) == 100 || int(game.game) == 68) {
            arr[game.x][game.y] = ' ';
            game.y += 1;
            // Бар'єр # == 35
            if (int(arr[game.x][game.y]) == 35) {
                game.y -= 1;
                arr[game.x][game.y] = game.pakmen;
            }
            // + == 43 очки
            if (int(arr[game.x][game.y]) == 43) {
                game.ochki++;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            // * == 42 бомби
            if (int(arr[game.x][game.y]) == 42) {
                game.heart--;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            else {
                arr[game.x][game.y] = game.pakmen;
                game.hod++;

            }
        }

    }


}
//a = 97 s = 115 d = 100
  //W = 87 S = 83 A = 65 D = 68


        //Каджі 10 кроків спавнить додаткові міни і очки
        /*if (game.hod % 10 == 0) {
            for (int i = 0; i < 5; i++) {
                game.rand_1 = 1 + rand() % 4;
                game.rand_2 = 1 + rand() % 8;
                if (game.x == game.rand_1 && game.y == game.rand_2) {
                    game.rand_1 = 1 + rand() % 4;
                    game.rand_2 = 1 + rand() % 8;
                }
                arr[game.rand_1][game.rand_2] = '*';

            }


            //Создає очки
            for (int i = 0; i < 3; i++) {
                game.rand_1 = 1 + rand() % 4;
                game.rand_2 = 1 + rand() % 8;
                if (game.x == game.rand_1 && game.y == game.rand_2) {
                    game.rand_1 = 1 + rand() % 4;
                    game.rand_2 = 1 + rand() % 8;
                }
                arr[game.rand_1][game.rand_2] = '+';

            }
        }*/



/*
ОСНОВА КЕРУВАННЯ

        // W ідти вперед
        if (int(game.game) == 119 || int(game.game) == 87) {
            arr[game.x][game.y] = ' ';
            game.x -= 1;
            // Бар'єр # == 35
            if (int(arr[game.x][game.y]) == 35) {
                game.x += 1;
                arr[game.x][game.y] = game.pakmen;
            }
            // + == 43 очки
            if (int(arr[game.x][game.y]) == 43) {
                game.ochki++;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            // * == 42 бомби
            if (int(arr[game.x][game.y]) == 42) {
                game.heart--;
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }
            else {
                arr[game.x][game.y] = game.pakmen;
                game.hod++;
            }


        }
         {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
*/