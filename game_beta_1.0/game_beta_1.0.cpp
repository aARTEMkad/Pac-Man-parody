#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    srand(time(NULL));
    char game;
    //Player
    char pakmen = char(1);
    //points and heart
    int points = 110, heart = 3;
    //position player
    int x = 2, y = 2;
    x = rand() % 16 + 1;
    y = rand() % 18 + 1;
    
    int a = 0,d = 0;
    int x_bot = 5, y_bot = 5;
    x_bot = rand() % 16 + 1;
    y_bot = rand() % 18 + 1;
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
    arr[x][y] = pakmen;
    arr[x_bot][y_bot] = '%';
    
    
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
//a = 97 s = 115 d = 100
  //W = 87 S = 83 A = 65 D = 68


        //Каджі 10 кроків спавнить додаткові міни і points
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


            //Создає points
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
            // Barrier # == 35
            if (int(arr[game.x][game.y]) == 35) {
                game.x += 1;
                arr[game.x][game.y] = game.pakmen;
            }
            // + == 43 points
            if (int(arr[game.x][game.y]) == 43) {
                game.points++;
                arr[game.x][game.y] = game.pakmen;
                game. 
            }
            // * == 37 Bot
            if (int(arr[game.x][game.y]) == 37) {
                game.heart--;
                arr[game.x][game.y] = game.pakmen;
                game. 
            }
            else {
                arr[game.x][game.y] = game.pakmen;
                game. 
            }


/*
          ____      __      ___                 __    __
         (  _ \    / _\    / __)    _____      /  \__/  \
          ) __/   /    \  ( (__    |_____|    /   ____   \
         (__)     \_/\_/   \___)             /___/    \___\
*/
/*


                ____    __      ___                 _    _       __      _____     
               ( _  \  / _\    / __)    _____      / \__/ \     / _\    /  _  \  
                ) __/ /    \  ( (__    |_____|    /  ____  \   /    \  /  / \  \
               (__)   \_/\_/   \___)             /__/    \__\  \_/\_/  |__| |__|
*/
