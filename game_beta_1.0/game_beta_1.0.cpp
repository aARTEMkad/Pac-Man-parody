#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>


using namespace std;

struct prog {
    // check symbol
    char symbol = 0;
    // temp number
    int temp_1, result_menu = 0;
    // Menu
    string menu[2][1] = {
        {"Exit"},
        {"Start"},
    };
    char game;
    //Player
    char pakmen = char(2);
    //points and heart
    int points = 0, heart = 3;
    //position players
    int x = 2, y = 1;
    int d = 0, a = 0;

    int x_bot = 5, y_bot = 5;
    int reserve_x_bot = 0, reserve_y_bot = 0;
    int temp_number = 0;

    int rand_number_x, rand_number_y;

    char arr[17][19] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','+',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','+',' ',' ',' ','#'},
        {'#',' ','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ','#',' ','+',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#','+','#','#','#',' ','#',' ','#','#','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#','+',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ','#','#',' ','#','#',' ','#',' ','#','#','#','#'},
        {' ',' ',' ',' ','+',' ',' ','#',' ',' ',' ','#',' ',' ','+',' ',' ',' ',' '},
        {'#','#','#','#',' ','#','+','#','#','#','#','#',' ','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#'},
        {'#',' ',' ',' ','+',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ','+',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},
        {'#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };


}Game;

void audit_points() {
    //audit points
    Game.d = 1;
    if (Game.points == 120) {
        for (int i = 0; i < 100; i++) {
            this_thread::sleep_for(chrono::milliseconds(750));
            system("cls");
            
            switch (Game.d)
            {
            case 1:
                system("color 1");
                ++Game.d;
                break;
            case 2:
                system("color 2");
                ++Game.d;
                break;
            case 3:
                system("color 3");
                ++Game.d;
                break;
            case 4:
                system("color 4");
                ++Game.d;
                break;
            case 5:
                system("color 5");
                ++Game.d;
                break;
            case 6:
                system("color 6");
                Game.d = 1;
                break;
            default:
                break;
            }
            cout << " ____    __       ___                 _    _       __      _____       " << endl;
            cout << "( _  \\  / _\\     / __)    _____      / \\__/ \\     / _\\    /  _  \\  " << endl;
            cout << " ) __/ /    \\   ( (__    |_____|    /  ____  \\   /    \\  /  / \\  \\" << endl;
            cout << "(__)   \\_/\\_/    \\___)             /__/    \\__\\  \\_/\\_/  |__| |__|" << endl;
        }
    }

}

void PAC_MAN() {
    cout << " ____    __       ___                 _    _       __      _____       " << endl;
    cout << "( _  \\  / _\\     / __)    _____      / \\__/ \\     / _\\    /  _  \\  " << endl;
    cout << " ) __/ /    \\   ( (__    |_____|    /  ____  \\   /    \\  /  / \\  \\" << endl;
    cout << "(__)   \\_/\\_/    \\___)             /__/    \\__\\  \\_/\\_/  |__| |__|" << endl;
}

void Bot_managment() {
nazad:

    Game.a = 1 + rand() % 4;
 
    switch (Game.a)
    {
    case 1:

        Game.arr[Game.x_bot][Game.y_bot] = ' ';
        Game.x_bot -= 1;
        if (Game.temp_number == 1) {
            Game.arr[Game.reserve_x_bot][Game.reserve_y_bot] = '+';
            Game.temp_number = 0;
        }
        // barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.x_bot += 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            if (Game.arr[Game.x_bot][Game.y_bot] == Game.arr[Game.reserve_x_bot][Game.reserve_y_bot]) {
                Game.temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43 
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 43) {
            
            Game.reserve_x_bot = Game.x_bot;
            Game.reserve_y_bot = Game.y_bot;
            Game.temp_number = 1;

        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    case 2:

        Game.arr[Game.x_bot][Game.y_bot] = ' ';
        Game.x_bot += 1;
        if (Game.temp_number == 1) {
            Game.arr[Game.reserve_x_bot][Game.reserve_y_bot] = '+';
            Game.temp_number = 0;
        }
        //barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.x_bot -= 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            if (Game.arr[Game.x_bot][Game.y_bot] == Game.arr[Game.reserve_x_bot][Game.reserve_y_bot]) {
                Game.temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 43) {

            Game.reserve_x_bot = Game.x_bot;
            Game.reserve_y_bot = Game.y_bot;
            Game.temp_number = 1;

        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
       
        else {
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    case 3:

        Game.arr[Game.x_bot][Game.y_bot] = ' ';
        Game.y_bot -= 1;
        if (Game.temp_number == 1) {
            Game.arr[Game.reserve_x_bot][Game.reserve_y_bot] = '+';
            Game.temp_number = 0;
        }
        
        //barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.y_bot += 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            if (Game.arr[Game.x_bot][Game.y_bot] == Game.arr[Game.reserve_x_bot][Game.reserve_y_bot]) {
                Game.temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 43) {
            Game.reserve_x_bot = Game.x_bot;
            Game.reserve_y_bot = Game.y_bot;
            Game.temp_number = 1;
        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    case 4:

        Game.arr[Game.x_bot][Game.y_bot] = ' ';
        Game.y_bot += 1;
        if (Game.temp_number == 1) {
            Game.arr[Game.reserve_x_bot][Game.reserve_y_bot] = '+';
            Game.temp_number = 0;
        }
        
        //barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.y_bot -= 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            if (Game.arr[Game.x_bot][Game.y_bot] == Game.arr[Game.reserve_x_bot][Game.reserve_y_bot]) {
                Game.temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 43) {
            Game.reserve_x_bot = Game.x_bot;
            Game.reserve_y_bot = Game.y_bot;
            Game.temp_number = 1;
        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
        else {
         
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    }
}

void management(char game) {
    // W go forward
    if (int(game) == 119 || int(game) == 87) {
        Game.arr[Game.x][Game.y] = ' ';
        Game.x -= 1;
        // Barrier # == 35
        if (int(Game.arr[Game.x][Game.y]) == 35) {
            Game.x += 1;
            Game.arr[Game.x][Game.y] = Game.pakmen;
        }
        // + == 43 points
        if (int(Game.arr[Game.x][Game.y]) == 43) {
            Game.points++;
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }
        // @ == 37 Bot
        if (int(Game.arr[Game.x][Game.y]) == 37) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }


    }
    // S go back
    else if (int(game) == 83 || int(game) == 115) {
        Game.arr[Game.x][Game.y] = ' ';
        Game.x += 1;
        // Barrier # == 35
        if (int(Game.arr[Game.x][Game.y]) == 35) {
            Game.x -= 1;
            Game.arr[Game.x][Game.y] = Game.pakmen;
        }
        // + == 43 points
        if (int(Game.arr[Game.x][Game.y]) == 43) {
            Game.points++;
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }
        // @ == 37 Bot
        if (int(Game.arr[Game.x][Game.y]) == 37) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }

    }
    // A go left
    else if (int(game) == 97 || int(game) == 65) {
        Game.arr[Game.x][Game.y] = ' ';
        Game.y -= 1;
        // Barrier # == 35
        if (int(Game.arr[Game.x][Game.y]) == 35) {
            Game.y += 1;
            Game.arr[Game.x][Game.y] = Game.pakmen;
        }
        // + == 43 points
        if (int(Game.arr[Game.x][Game.y]) == 43) {
            Game.points++;
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }
        // @ == 37 Bot
        if (int(Game.arr[Game.x][Game.y]) == 37) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }
    }
    // D go right
    else if (int(game) == 100 || int(game) == 68) {
        Game.arr[Game.x][Game.y] = ' ';
        Game.y += 1;
        // Barrier # == 35
        if (int(Game.arr[Game.x][Game.y]) == 35) {
            Game.y -= 1;
            Game.arr[Game.x][Game.y] = Game.pakmen;
        }
        // + == 43 points
        if (int(Game.arr[Game.x][Game.y]) == 43) {
            Game.points++;
            Game.arr[Game.x][Game.y] = Game.pakmen;

        }
        // @ == 37 Bot
        if (int(Game.arr[Game.x][Game.y]) == 37) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x][Game.y] = Game.pakmen;


        }
    }

}

int main()
{
    
    srand(time(NULL));
    system("mode con cols=71 lines=25");
    PAC_MAN();

    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < 1; j++) {
            cout << "\t\t\t" << "    " << Game.menu[i][j] << "    ";
            cout << endl;
        }
    }

    for (int menu_1 = 0; menu_1 < 1000; menu_1++) {


        Game.symbol = _getch();
        if (Game.symbol == -32) {
            Game.symbol = _getch();
            if ((int)Game.symbol == 72 || (int)Game.symbol == 224) {
                system("cls");
                PAC_MAN();
                Game.temp_1 = 1;
                cout << "\t\t\t" << "<<< " << Game.menu[Game.temp_1][0] << " >>>" << endl;
                Game.temp_1--;
                cout << "\t\t\t" << "    " << Game.menu[Game.temp_1][0] << "    " << endl;
                Game.result_menu = 0;


            }
            else if ((int)Game.symbol == 80 || (int)Game.symbol == 224) {
                system("cls");
                PAC_MAN();
                Game.temp_1 = 1;
                cout << "\t\t\t" << "    " << Game.menu[Game.temp_1][0] << "    " << endl;
                Game.temp_1--;
                cout << "\t\t\t" << "<<< " << Game.menu[Game.temp_1][0] << " >>>" << endl;
                Game.result_menu = 1;




            }
        }

        if (Game.symbol == 13) {
            // Start
            if (Game.result_menu == 0) {
                Game.heart = 3;
                Game.points = 0;
                for (int i = 0; i != 1;) {
                    system("cls");
                    
                    cout << "\t\t\tPoints - " << Game.points << " Heart - " << Game.heart;
                    for (int i = 0; i < 17; i++) {
                        cout << "\n\t\t";
                        for (int k = 0; k < 19; k++) {
                            cout << " ";
                            cout << Game.arr[i][k];
                        }
                        cout << " ";
                    }
                    if (Game.heart < 1) {
                        system("cls");
                        cout << "\nGame Over\n";
                        cout << "Point - " << Game.points;
                        cout << "\nPress the up or down arrow\n";
                        i = 1;
                    }
                    audit_points();
                    Game.game = _getch();
                    management(Game.game);
                    Bot_managment();

                }
                continue;
            }
            // Exit
            else if (Game.result_menu == 1) {
                return 0;
            }
            // Problem
            else {
                cout << "\nError\n";
            }
        }


    }


}
