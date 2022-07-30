#include <iostream>
#include <Windows.h>

using namespace std;

struct prog {
    string menu;
    char game;
    //Player
    char pakmen = char(2);
    //points and heart
    int points = 0,heart = 3;
    //position players
    int x = 2, y = 2;
    int d = 0, a = 0;

    int x_bot = 5, y_bot = 5;

    int number = 10;
    int rand_number_x,rand_number_y;

    char arr[17][19] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ','#','#',' ','#','#',' ','#',' ','#','#','#','#'},
        {' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' '},
        {'#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','#'},
        {'#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},
        {'#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };


}Game;

void audit_points() {
    //audit points
    if (Game.points == 120) {
        for (int i = 0; i < 100; i++) {
            Sleep(750);
            system("cls");
            Game.d = rand() % 6 + 1;
            switch (Game.d)
            {
            case 1:
                system("color 1");
                break;
            case 2:
                system("color 2");
                break;
            case 3:
                system("color 3");
                break;
            case 4:
                system("color 4");
                break;
            case 5:
                system("color 5");
                break;
            case 6:
                system("color 6");
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

void spawn_map() {
    for (int i = 0; i < 17; i++) {
        cout << "\n";
        for (int k = 0; k < 19; k++) {
            cout << " ";
            cout << Game.arr[i][k];
        }
        cout << " ";
    }

}

void spawn_points() {
    for (int i = 0; i < 17, Game.number != 0; i++) {
        for (int j = 0; j < 19,Game.number != 0; j++) {
            if ((int)Game.arr[i][j] == 32) {
                Game.rand_number_x = rand() % 16 + 1;
                Game.rand_number_y = rand() % 18 + 1;
                if ((int)Game.arr[Game.rand_number_x][Game.rand_number_y] != 35) {
                    Game.arr[Game.rand_number_x][Game.rand_number_y] = 43;
                    Game.number--;
                }
               
               
            }
        }
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


void Bot_managment() {
nazad:

    Game.a = 1 + rand() % 4;

    switch (Game.a)
    {
    case 1:

        Game.arr[Game.x_bot][Game.y_bot] = '+';
        Game.x_bot -= 1;
        // barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.x_bot += 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            goto nazad;

        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    case 2:

        Game.arr[Game.x_bot][Game.y_bot] = '+';
        Game.x_bot += 1;
        //barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.x_bot -= 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            goto nazad;

        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    case 3:

        Game.arr[Game.x_bot][Game.y_bot] = '+';
        Game.y_bot -= 1;
        //barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.y_bot += 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            goto nazad;

        }
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == Game.pakmen) {
            Game.heart--;


        }
        else {
            Game.arr[Game.x_bot][Game.y_bot] = '%';
        }
        break;
    case 4:

        Game.arr[Game.x_bot][Game.y_bot] = '+';
        Game.y_bot += 1;
        //barrier # == 35
        if (int(Game.arr[Game.x_bot][Game.y_bot]) == 35) {
            Game.y_bot -= 1;
            Game.arr[Game.x_bot][Game.y_bot] = '%';
            goto nazad;

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

void str_PAC_MAN() {

    cout << " ____    __       ___                 _    _       __      _____       " << endl;
    cout << "( _  \\  / _\\     / __)    _____      / \\__/ \\     / _\\    /  _  \\  " << endl;
    cout << " ) __/ /    \\   ( (__    |_____|    /  ____  \\   /    \\  /  / \\  \\" << endl;
    cout << "(__)   \\_/\\_/    \\___)             /__/    \\__\\  \\_/\\_/  |__| |__|" << endl;

}

int main()
{

    srand(time(NULL));
    for (; int(Game.arr[Game.x][Game.y]) == 35;) {
        Game.x = rand() % 16 + 1;
        Game.y = rand() % 18 + 1;
    }
    for (; int(Game.arr[Game.x_bot][Game.y_bot]) == 35;) {
        Game.x_bot = rand() % 16 + 1;
        Game.y_bot = rand() % 18 + 1;
    }
    Game.arr[Game.x][Game.y] = Game.pakmen;
    Game.arr[Game.x_bot][Game.y_bot] = '%';

    cout << "\tCommands\nStart - start game \n Exit - leave game\n";

    Sleep(2000);
    system("cls");
    system("color 6");
    str_PAC_MAN();
    Sleep(2000);
    system("cls");
    system("color 9");
menu_1:
    cout << "Commands:";
    cin >> Game.menu;
    if (Game.menu == "start" || Game.menu == "Start") {
        system("cls");
        spawn_points();
        for (int i = 0; i < 100000; i++) {
            system("cls");
            str_PAC_MAN();
            cout << "Points - " << Game.points << " Heart - " << Game.heart;
            spawn_map();
            if (Game.heart < 1) {
                system("cls");
                cout << "\nGame Over\n";
                cout << "Point - " << Game.points;
                return 0;
            }
            audit_points();
            cin >> Game.game;
            management(Game.game);
            Bot_managment();

        }
    }
    else if (Game.menu == "Setting" || Game.menu == "setting") {
        cout << "1 - the number of spawn points\n2 - exit\n";
        cin >> Game.menu;
        if (Game.menu == "1") {
            cout << "write how many points you want to accumulate:";
            cin >> Game.number;
            goto menu_1;
        }
        else {
            goto menu_1;
        }
    }
    else if (Game.menu == "Exit" || Game.menu == "exit") {
        return 0;
    }
    else {
        cout << "Error";

    }
}

