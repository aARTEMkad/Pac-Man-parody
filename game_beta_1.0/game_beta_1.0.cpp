
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	string menu;
    char game;
    //Player
    char pakmen = char(2);
    //points and heart
    int points = 0, heart = 3;
    //position player
    int x = 2, y = 2;


    int a = 0, d = 0;
    int x_bot = 5, y_bot = 5;

    const int COL = 17;
    const int ROW = 19;
    char arr[COL][ROW] = {
         {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','+','+','+','+','+','+','+','+','+','+','+','+','+','+','+','+','+','#'},
        {'#','+','#','#','+','#','+','#','#','#','#','#','+','#','+','#','#','+','#'},
        {'#','+','+','+','+','#','+','+','+','#','+','+','+','#','+','+','+','+','#'},
        {'#','#','#','#','+','#','#','#','+','#','+','#','#','#','+','#','#','#','#'},
        {'#','#','#','#','+','#','+','+','+','+','+','+','+','#','+','#','#','#','#'},
        {'#','#','#','#','+','#','+','#','#',' ','#','#','+','#','+','#','#','#','#'},
        {'+','+','+','+','+','+','+','#',' ',' ',' ','#','+','+','+','+','+','+','+'},
        {'#','#','#','#','+','#','+','#','#','#','#','#','+','#','+','#','#','#','#'},
        {'#','#','#','#','+','#','+','+','+','+','+','+','+','#','+','#','#','#','#'},
        {'#','#','#','#','+','#','+','#','#','#','#','#','+','#','+','#','#','#','#'},
        {'#','+','+','+','+','+','+','+','+','#','+','+','+','+','+','+','+','+','#'},
        {'#','+','#','#','+','#','#','#','+','#','+','#','#','#','+','#','#','+','#'},
        {'#','+','+','#','+','+','+','+','+','+','+','+','+','+','+','#','+','+','#'},
        {'#','#','+','#','+','#','+','#','#','#','#','#','+','#','+','#','+','#','#'},
        {'#','+','+','+','+','#','+','+','+','#','+','+','+','#','+','+','+','+','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };
    for (; int(arr[x][y]) == 35;) {
        x = rand() % 16 + 1;
        y = rand() % 18 + 1;
    }
    for (; int(arr[x_bot][y_bot]) == 35;) {
        x_bot = rand() % 16 + 1;
        y_bot = rand() % 18 + 1;
    }
    system("color 8");
    arr[x][y] = pakmen;
    arr[x_bot][y_bot] = '%';
    system("color 4");

	cout << "\tCommands\nStart - start game \n Exit - leave game\n";
	
    Sleep(2000);
	system("cls");
    system("color 6");

    cout << " ____    __       ___                 _    _       __      _____       " << endl;
    cout << "( _  \\  / _\\     / __)    _____      / \\__/ \\     / _\\    /  _  \\  " << endl;
    cout << " ) __/ /    \\   ( (__    |_____|    /  ____  \\   /    \\  /  / \\  \\" << endl;
    cout << "(__)   \\_/\\_/    \\___)             /__/    \\__\\  \\_/\\_/  |__| |__|" << endl;
    
    Sleep(2000);
	system("cls");
    system("color 9");
    menu_1:
    cout << "Commands:";
	cin >> menu;
	if (menu == "start" || menu == "Start") {
		system("cls");
        //management
        for (int game_1 = 0; game_1 < 1000000; game_1++) {
            system("cls");
            cout << " ____    __       ___                 _    _       __      _____       " << endl;
            cout << "( _  \\  / _\\     / __)    _____      / \\__/ \\     / _\\    /  _  \\  " << endl;
            cout << " ) __/ /    \\   ( (__    |_____|    /  ____  \\   /    \\  /  / \\  \\" << endl;
            cout << "(__)   \\_/\\_/    \\___)             /__/    \\__\\  \\_/\\_/  |__| |__|" << endl;

            cout << "Points - " << points << " Heart - " << heart;
            //Spawn map
            for (int i = 0; i < COL; i++) {
                cout << "\n";
                for (int k = 0; k < ROW; k++) {
                    cout << " ";
                    cout << arr[i][k];
                }
                cout << " ";
            }

            //audit vital
            if (heart < 1) {
                system("cls");
                cout << "\nGame Over\n";
                cout << "Point - " << points;
                return 0;
            }
            //audit points
            if (points == 120) {
                for (int i = 0; i < 100; i++) {
                    Sleep(750);
                    system("cls");
                    d = rand() % 6 + 1;
                    switch (d)
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
            //--------------------------BOT--------------------------

        nazad:

            a = 1 + rand() % 4;

            switch (a)
            {
            case 1:

                arr[x_bot][y_bot] = '+';
                x_bot -= 1;
                // barrier # == 35
                if (int(arr[x_bot][y_bot]) == 35) {
                    x_bot += 1;
                    arr[x_bot][y_bot] = '%';
                    goto nazad;

                }
                if (int(arr[x_bot][y_bot]) == pakmen) {
                    heart--;


                }
                else {
                    arr[x_bot][y_bot] = '%';
                }
                break;
            case 2:

                arr[x_bot][y_bot] = '+';
                x_bot += 1;
                //barrier # == 35
                if (int(arr[x_bot][y_bot]) == 35) {
                    x_bot -= 1;
                    arr[x_bot][y_bot] = '%';
                    goto nazad;

                }
                if (int(arr[x_bot][y_bot]) == pakmen) {
                    heart--;


                }
                else {
                    arr[x_bot][y_bot] = '%';
                }
                break;
            case 3:

                arr[x_bot][y_bot] = '+';
                y_bot -= 1;
                //barrier # == 35
                if (int(arr[x_bot][y_bot]) == 35) {
                    y_bot += 1;
                    arr[x_bot][y_bot] = '%';
                    goto nazad;

                }
                if (int(arr[x_bot][y_bot]) == pakmen) {
                    heart--;


                }
                else {
                    arr[x_bot][y_bot] = '%';
                }
                break;
            case 4:

                arr[x_bot][y_bot] = '+';
                y_bot += 1;
                //barrier # == 35
                if (int(arr[x_bot][y_bot]) == 35) {
                    y_bot -= 1;
                    arr[x_bot][y_bot] = '%';
                    goto nazad;

                }
                if (int(arr[x_bot][y_bot]) == pakmen) {
                    heart--;


                }
                else {
                    arr[x_bot][y_bot] = '%';
                }
                break;
            }
            //----------------------------------------Player---------------------------------

            cin >> game;

            // W go forward
            if (int(game) == 119 || int(game) == 87) {
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
            else if (int(game) == 83 || int(game) == 115) {
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
            else if (int(game) == 97 || int(game) == 65) {
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
                else {
                    arr[x][y] = pakmen;

                }
            }
            // D go right
            else if (int(game) == 100 || int(game) == 68) {
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
                else {
                    arr[x][y] = pakmen;


                }
            }







        }



	}
	else if (menu == "Exit" || menu == "exit") {
		return 0;
	}
	else {
		cout << "Error";

	}
		

}
/*for (int i = 0; i < 100; i++) {
        Sleep(750);
        system("cls");
        d = rand() % 6 + 1;
        switch (d)
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
    }*/
