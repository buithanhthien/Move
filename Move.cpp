#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<string>
using namespace std;

int Level_1(char key, int &size, int life, int &score,int turn,
            int x, int y, int a, int b, int c, int d, int e, int f)
{
    turn = 20;
    score = 0;
    life = 3;
    size = 8;
    x = rand() % 8; 
    y = rand() % 8;
    e = rand() % 8;
    f = rand() % 8;
    while(1)
    {
        a = rand() % 8;
        b = rand() % 8;
        c = rand() % 8;
        d = rand() % 8;
        
        cout << "Life: " << life << " " << "Score: " << score << " " << "Turn: " << turn << endl;   

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(x == i && y == j)
                {
                    cout << "0 ";
                }
                else if(a == i && b == j)
                {
                    cout << "D ";
                }
                else if(c == i && d == j)
                {
                    cout << "U ";
                }
                else if(e == i && f == j)
                {
                    cout << "W ";
                }
                else if(e == i && f == i && c == i && d == i)
                {
                    continue;
                }
                else
                {
                    cout << "* ";
                }
            }
            cout << endl;
        }
        cout << "Move: ";
        cin >> key;

        switch(key)
        {
            case 'w': x = x - 1; break;
            case 's': x = x + 1; break;
            case 'a': y = y - 1; break;
            case 'd': y = y + 1; break;
            default: cout << "What! I can't see!" << endl; break;

        }

            if(x < 0)
            {
                x = x + 1;
            }
            if(x >= size)
            {
                x = x - 1;
            }
            if(y < 0)
            {
                y = y + 1;
            }
            if(y >= size)
            {
                y = y - 1;
            }

        system("clear");

        turn--;

        if(a == x && b == y)
        {
            cout << "Life-" << endl;
            life--;
            if(life == 0)
            {
                break;
            }
        }
        else if(c == x && d == y)
        {
            size++;
            cout << "Size+" << endl;
        }
        else if(e == x && f == y)
        {
            score++;
            turn += 3;
            e = rand() % 8;
            f = rand() % 8;
        }
        else if(turn == 0)
        {
            break;
        }
    }
}


int Rule(int something)
{
    cout << "\t\t [I have some rules you need to know]" << endl;
    cout << "1.'Y' is you...read continue." << endl;
    cout << "2.Can you see 'D', it random on the map, if you touch it your life will lost and your size too!!!" << endl;
    cout << "3.Oh i have this for you, a 'U', the size will add." << endl;
    cout << "4.You can up your score with 'W'.";
    cout << "5.Life and Score I don't want to say\n  but Turn is different if you eat a 'W' the Turn will up only 3 points." << endl;
    cout << "\t\t\t *Thanks for read*" << endl;
}

int LeaderBoard(string name, int max, int STT[10], int score)
{
    max = score;
    STT[0] = max;
    cout << "-Leader Board-";
    for(int i = 1; i <= 10; i++)
    {
        if(STT[i] > max)
        {
            max = STT[i];
        }
        cout << i << ". " << name;
    }
}

int main()
{
    system("clear");
    char key;
    int max,STT[10];
    int choose, size, life, score, turn;
    int y,x; //You
    int a,b; //Lose
    int c,d; //Add size
    int e,f; //Win
    srand(time(NULL));

    cout << "Your name is: ";
    string name;
    getline(cin,name);

    system("clear");

    cout << "1.Something" << endl;
    cout << "2.Play Game" << endl;
    cout << "3.Leader Board" << endl;
    cout << "You choose: ";
    cin >> choose;

    switch(choose)
    {
        case 1: 
            Rule(1);
        break;
        case 2: 
            Level_1(key, size, life, score, turn, x, y, a, b, c, d, e, f);
            cout << "Game Over!!!" << endl;
            cout << "Your Score: " << score << endl;
            cout << "Your Size: " << size << endl;
            cout << "Weldone! " << name << "!";
        break;
        case 3:
            //LeaderBoard(name,max,STT, score);
        break;
    }
    
    return 0;
}