#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>


using namespace std;

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
char temp_but;
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

char arr[17][20] = {
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','+',' ',' ',' ',' ','•',' ',' ',' ',' ',' ',' ',' ','+',' ',' ',' ','#'},
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
/*7.0 7.18*/



void audit_points() {
    //audit points
    d = 1;
    if (points == 120) {
        for (int i = 0; i < 100; i++) {
            this_thread::sleep_for(chrono::milliseconds(750));
            system("cls");

            switch (d)
            {
            case 1:
                system("color 1");
                ++d;
                break;
            case 2:
                system("color 2");
                ++d;
                break;
            case 3:
                system("color 3");
                ++d;
                break;
            case 4:
                system("color 4");
                ++d;
                break;
            case 5:
                system("color 5");
                ++d;
                break;
            case 6:
                system("color 6");
                d = 1;
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

    a = 1 + rand() % 4;

    switch (a)
    {
    case 1:

        arr[x_bot][y_bot] = ' ';
        x_bot -= 1;
        if (temp_number == 1) {
            arr[reserve_x_bot][reserve_y_bot] = '+';
            temp_number = 0;
        }
        // barrier # == 35
        if (int(arr[x_bot][y_bot]) == 35) {
            x_bot += 1;
            arr[x_bot][y_bot] = '%';
            if (arr[x_bot][y_bot] == arr[reserve_x_bot][reserve_y_bot]) {
                temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43 
        if (int(arr[x_bot][y_bot]) == 43) {

            reserve_x_bot = x_bot;
            reserve_y_bot = y_bot;
            temp_number = 1;

        }
        if (int(arr[x_bot][y_bot]) == pakmen) {
            heart--;
        }
        else {
            arr[x_bot][y_bot] = '%';
        }
        break;
    case 2:

        arr[x_bot][y_bot] = ' ';
        x_bot += 1;
        if (temp_number == 1) {
            arr[reserve_x_bot][reserve_y_bot] = '+';
            temp_number = 0;
        }
        //barrier # == 35
        if (int(arr[x_bot][y_bot]) == 35) {
            x_bot -= 1;
            arr[x_bot][y_bot] = '%';
            if (arr[x_bot][y_bot] == arr[reserve_x_bot][reserve_y_bot]) {
                temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43
        if (int(arr[x_bot][y_bot]) == 43) {

            reserve_x_bot = x_bot;
            reserve_y_bot = y_bot;
            temp_number = 1;

        }
        if (int(arr[x_bot][y_bot]) == pakmen) {
            heart--;


        }

        else {
            arr[x_bot][y_bot] = '%';
        }
        break;
    case 3:

        arr[x_bot][y_bot] = ' ';
        y_bot -= 1;
        if (temp_number == 1) {
            arr[reserve_x_bot][reserve_y_bot] = '+';
            temp_number = 0;
        }

        //barrier # == 35
        if (int(arr[x_bot][y_bot]) == 35) {
            y_bot += 1;
            arr[x_bot][y_bot] = '%';
            if (arr[x_bot][y_bot] == arr[reserve_x_bot][reserve_y_bot]) {
                temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43
        if (int(arr[x_bot][y_bot]) == 43) {
            reserve_x_bot = x_bot;
            reserve_y_bot = y_bot;
            temp_number = 1;
        }
        if (int(arr[x_bot][y_bot]) == pakmen) {
            heart--;


        }
        if (x == 7 && y == 0) {
            arr[x_bot][y_bot] = ' ';
            x = 7;
            y = 18;
            arr[x_bot][y_bot] = '%';
        }
        else {
            arr[x_bot][y_bot] = '%';
        }
        break;
    case 4:

        arr[x_bot][y_bot] = ' ';
        y_bot += 1;
        if (temp_number == 1) {
            arr[reserve_x_bot][reserve_y_bot] = '+';
            temp_number = 0;
        }

        //barrier # == 35
        if (int(arr[x_bot][y_bot]) == 35) {
            y_bot -= 1;
            arr[x_bot][y_bot] = '%';
            if (arr[x_bot][y_bot] == arr[reserve_x_bot][reserve_y_bot]) {
                temp_number = 1;
            }
            goto nazad;

        }
        // Points + == 43
        if (int(arr[x_bot][y_bot]) == 43) {
            reserve_x_bot = x_bot;
            reserve_y_bot = y_bot;
            temp_number = 1;
        }
        if (int(arr[x_bot][y_bot]) == pakmen) {
            heart--;


        }
        if (x == 7 && y == 18) {
            arr[x_bot][y_bot] = ' ';
            x = 7;
            y = 0;
            arr[x_bot][y_bot] = '%';

        }
        else {

            arr[x_bot][y_bot] = '%';
        }
        break;
    }
}

void management(char game) {
    // W go forward
    if (game == 'W' || game == 'w') {
        arr[x][y] = ' ';
        x -= 1;
        // Barrier # == 35
        if (int(arr[x][y]) == 35) {
            x += 1;
            arr[x][y] = pakmen;
        }
        // + == 43 points
        if (int(arr[x][y]) == 43) {
            points++;
            arr[x][y] = pakmen;

        }
        // @ == 37 Bot
        if (int(arr[x][y]) == 37) {
            heart--;


        }
        else {
            arr[x][y] = pakmen;

        }


    }
    // S go back
    else if (game == 's' || game == 'S') {
        arr[x][y] = ' ';
        x += 1;
        // Barrier # == 35
        if (int(arr[x][y]) == 35) {
            x -= 1;
            arr[x][y] = pakmen;
        }
        // + == 43 points
        if (int(arr[x][y]) == 43) {
            points++;
            arr[x][y] = pakmen;

        }
        // @ == 37 Bot
        if (int(arr[x][y]) == 37) {
            heart--;


        }
        else {
            arr[x][y] = pakmen;

        }

    }
    // A go left
    else if (game == 'a' || game == 'A') {
        arr[x][y] = ' ';
        y -= 1;
        // Barrier # == 35
        if (int(arr[x][y]) == 35) {
            y += 1;
            arr[x][y] = pakmen;
        }
        // + == 43 points
        if (int(arr[x][y]) == 43) {
            points++;
            arr[x][y] = pakmen;

        }
        // @ == 37 Bot
        if (int(arr[x][y]) == 37) {
            heart--;


        }
        if (x == 7 && y == -1) {
            arr[x][y] = ' ';
            x = 7;
            y = 18;
            arr[x][y] = pakmen;
        }
        else {
            arr[x][y] = pakmen;

        }
    }
    // D go right
    else if (game == 'd' || game == 'D') {
        arr[x][y] = ' ';
        y += 1;
        // Barrier # == 35
        if (int(arr[x][y]) == 35) {
            y -= 1;
            arr[x][y] = pakmen;
        }
        // + == 43 points
        if (int(arr[x][y]) == 43) {
            points++;
            arr[x][y] = pakmen;

        }
        // @ == 37 Bot
        if (int(arr[x][y]) == 37) {
            heart--;


        }
        if (x == 7 && y == 19) {
            arr[x][y] = ' ';
            x = 7;
            y = 0;
            arr[x][y] = pakmen;

        }
        else {
            arr[x][y] = pakmen;


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
            cout << "\t\t\t" << "    " << menu[i][j] << "    ";
            cout << endl;
        }
    }
    // Menu
    for (;;) {


        symbol = _getch();
        if (symbol == -32) {
            symbol = _getch();
            if ((int)symbol == 72 || (int)symbol == 224) {
                system("cls");
                PAC_MAN();
                temp_1 = 1;
                cout << "\t\t\t" << "<<< " << menu[temp_1][0] << " >>>" << endl;
                temp_1--;
                cout << "\t\t\t" << "    " << menu[temp_1][0] << "    " << endl;
                result_menu = 0;


            }
            else if ((int)symbol == 80 || (int)symbol == 224) {
                system("cls");
                PAC_MAN();
                temp_1 = 1;
                cout << "\t\t\t" << "    " << menu[temp_1][0] << "    " << endl;
                temp_1--;
                cout << "\t\t\t" << "<<< " << menu[temp_1][0] << " >>>" << endl;
                result_menu = 1;




            }
        }

        if (symbol == 13) {
            // Start
            if (result_menu == 0) {
                // Standart values
                heart = 3;
                points = 0;
                // Getting the first symbol to walk the character
                system("cls");
                cout << "\t\t\tPoints - " << points << " Heart - " << heart;
                for (int i = 0; i < 17; i++) {
                    cout << "\n\t\t";
                    for (int k = 0; k < 19; k++) {
                        cout << " ";
                        cout << arr[i][k];
                    }
                    cout << " ";
                }
                game = _getch();
                // Start of the main game
                for (int i = 0; i != 1;) {
                    system("cls");
                    audit_points();
                    cout << "\t\t\tPoints - " << points << " Heart - " << heart;
                    // Spawn the map
                    for (int i = 0; i < 17; i++) {
                        cout << "\n\t\t";
                        for (int k = 0; k < 19; k++) {
                            cout << " ";
                            cout << arr[i][k];
                        }
                        cout << " ";
                    }
                    // Checks vitals
                    if (heart < 1) {
                        system("cls");
                        cout << "\nGame Over\n";
                        cout << "Point - " << points;
                        cout << "\nPress the up or down arrow\n";
                        i = 1;
                    }
                    // Saves the value that will be changed later
                    temp_but = game;
                    // Checks if the user has pressed another button
                    if (_kbhit()) {
                        game = _getch();
                        if (int(game) == 119 || int(game) == 87) {
                            x -= 1;
                            if (int(arr[x][y]) == 35) { // If the new value = barrier, then it takes the previous value
                                game = temp_but;
                            }
                            x += 1;
                        }
                        // S go back
                        else if (int(game) == 83 || int(game) == 115) {
                            x += 1;
                            if (int(arr[x][y]) == 35) { // If the new value = barrier, then it takes the previous value
                                game = temp_but;
                            }
                            x -= 1;
                        }
                        // A go left
                        else if (int(game) == 97 || int(game) == 65) {
                            y -= 1;
                            if (int(arr[x][y]) == 35) { // If the new value = barrier, then it takes the previous value
                                game = temp_but;
                            }
                            y += 1;
                        }
                        // D go right
                        else if (int(game) == 100 || int(game) == 68) {
                            y += 1;
                            if (int(arr[x][y]) == 35) { // If the new value = barrier, then it takes the previous value
                                game = temp_but;
                            }
                            y -= 1;

                        }

                    }
                    else { // if there is no new value, then it continues to go in the direction the user chose last time
                        management(game); 
                        this_thread::sleep_for(chrono::milliseconds(350)); 
                    }
                    // BOT
                    Bot_managment();

                }
                continue;
            }
            // Exit
            else if (result_menu == 1) {
                return 0;
            }
            // Problem
            else {
                cout << "\nError\n";
            }
        }


    }

}
