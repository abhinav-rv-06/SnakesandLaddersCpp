#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Aim - To use various concepts of OOPS and STL.
// The demonstration and VALIDATION of program to various edge cases has been given preference rather than efficiency.
// Even then, the time and space complexity have not exceeded O(n).

int die()
{
    srand(time(NULL));
    int dice = rand()%6 + 1;
    return dice;
}
class Player
{
    public:
        int pos;
        Player()
        {
            pos = 0;
        }

};
class Board
{
    protected:
        int length;
        int sn;
        int ln;
        int snakearr[2][100];
        int ladderarr[2][100];
    public:
        friend void playgamefinal(Board b);
        Board()
        {
            length = 100;
            sn = 8;
            ln = 7;
            int tsnakearr[2][100]= {{18,43,56,49,99,65,88,92},{5,23,26,33,35,44,63,71}};
            int tladderarr[2][100]= {{16,31,38,84,67,93,100},{6,9,19,28,52,72,80}};
            for(int i=0;i<sn;i++)
            {
                snakearr[0][i] = tsnakearr[0][i];
                snakearr[1][i] = tsnakearr[1][i];
            }
            for(int i=0;i<ln;i++)
            {
                ladderarr[0][i] = tladderarr[0][i];
                ladderarr[1][i] = tladderarr[1][i];
            }
        }
        Board(char c)
        {
            
            if(c == 'c')
            {
            int lengthcheck = 0;
            int snakecheck = 0;
            int laddercheck = 0;
            vector<int> slposarr;
            vector<int>::iterator it;
            int flag = 0;
            cout << "Enter length of the board between 10 to 500 : " << endl;
            while(lengthcheck!= 1)
                {
                int ltemp;
                cin >> ltemp;
                if (ltemp<10 || ltemp >500)
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    lengthcheck = 0;
                }
                else
                {
                    length = ltemp;
                    lengthcheck = 1;
                }
                }
            cout << "Enter number of Snakes : " << endl;
            while(snakecheck!= 1)
                {
                int stemp;
                cin >> stemp;
                if (stemp<0 || stemp >length/3)
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    snakecheck = 0;
                }
                else
                {
                    sn = stemp;
                    snakecheck = 1;
                }
                }
            cout << "Enter number of Ladders : " << endl;
            while(laddercheck!= 1)
                {
                int lltemp;
                cin >> lltemp;
                if (lltemp<0 || lltemp >length/3)
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    laddercheck = 0;
                }
                else
                {
                    ln = lltemp;
                    laddercheck = 1;
                }
                }
            for(int i=0;i<sn;i++)
            {
                int temp = 0;
                int temp2 = 0;

                cout << "Enter Snake head : " << endl;
                flag = 0;
                while(flag!= 1)
                {
                cin >> temp;
                it = find (slposarr.begin(), slposarr.end(), temp);
                if (it != slposarr.end() || temp>=length)
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    flag = 0;
                }
                else
                {
                    snakearr[0][i] = temp;
                    slposarr.push_back(temp);
                    flag = 1;
                }
                }
                cout << "Enter Snake tail : " << endl;
                flag = 0;
                while(flag!= 1)
                {
                cin >> temp2;
                it = find (slposarr.begin(), slposarr.end(), temp2);
                if ((it != slposarr.end()) || (temp2 > temp) || (temp2 >= length))
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    flag = 0;
                }
                else
                {
                    snakearr[1][i] = temp2;
                    slposarr.push_back(temp2);
                    flag = 1;
                }
                }
            }
            for(int i=0;i<ln;i++)
            {
                int temp = 0;
                int temp2 = 0;

                cout << "Enter Ladder head : " << endl;
                flag = 0;
                while(flag!= 1)
                {
                cin >> temp;
                it = find (slposarr.begin(), slposarr.end(), temp);
                if (it != slposarr.end() || temp>=length)
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    flag = 0;
                }
                else
                {
                    ladderarr[0][i] = temp;
                    slposarr.push_back(temp);
                    flag = 1;
                }
                }
                cout << "Enter Ladder tail : " << endl;
                flag = 0;
                while(flag!= 1)
                {
                cin >> temp2;
                it = find (slposarr.begin(), slposarr.end(), temp2);
                if ((it != slposarr.end()) || (temp2 > temp) || (temp2 >= length))
                {
                    cout << "INVALID!! Please try again! -- " << endl;
                    flag = 0;
                }
                else
                {
                    ladderarr[1][i] = temp2;
                    slposarr.push_back(temp2);
                    flag = 1;
                }
                }
            }
            }
        }
        void startgame()
        {
            cout << endl;
            cout <<endl;
            cout << "Welcome to snakes and Ladders !!" << endl;
            cout << "The first one to reach " << length << " wins!!!!!" << endl;
            cout << "The snakes are ------" << endl;
            for(int i=0;i<sn;i++)
            {
                cout << snakearr[0][i] << "-------->>>>" << snakearr[1][i] << endl;
            }
            cout << "The ladders are ------" << endl;
            for(int i=0;i<ln;i++)
            {
                cout << ladderarr[0][i] << "<<<<--------" << ladderarr[1][i] << endl;
            }
        }
        int playgamepos(int x,char y)
        {
            int firstx = x;
            int turn = 0;
            int a = die();
            cout << y << " rolled a " << a << endl;
            if(a == 6)
            {
                cout << "Rolling dice again" << endl;
                usleep(2000000);
                int b = die();
                cout << y << " rolled a " << b << endl;
                if(b == 6)
                {
                    cout << "Rolling dice again" << endl;
                    usleep(2000000);
                    int c = die();
                    cout << y << " rolled a " << c << endl;
                    if(c == 6)
                    {
                        cout << "Sorry, go to 0" << endl;
                        x = 0;
                        return x;
                    }
                    else
                    {
                        x += a+b+c;
                    }
                }
                else
                {
                    x += a+b;
                }
            }
            else
            {
                x += a;
            }
            if(x>length)
            {
                cout << "Betterluck next time" << endl;
                x = firstx;
                return x;
            }
            else
            {
            for(int i = 0;i<sn;i++)
            {
                if(snakearr[0][i] == x)
                {
                    cout << "You encountered a snake!!!" << endl;
                    x = snakearr[1][i];
                    break;
                }
            }
            for(int i = 0;i<ln;i++)
            {
                if(ladderarr[1][i] == x)
                {
                    cout << "You encountered a ladder !!" << endl;
                    x = ladderarr[0][i];
                    break;
                }
            }
            return x;
            }
        }
};
void posdisplay(int x, int y)
{
    cout << endl; 
    cout << "Player A position is " << x << endl;
    cout << "Player B position is " << y << endl;
}
void playgamefinal(Board b)
{
    Player A,B;
    b.startgame();
    usleep(4000000);
    int turn = 0;
    for(;;)
    {
        posdisplay(A.pos,B.pos);
        if(turn%2 == 0)
        {
            A.pos = b.playgamepos(A.pos,'A');
            usleep(3000000);
            turn++;
            if(A.pos == b.length)
            {
                cout << "A wins !!";
                break;
            }
        }
        else
        {
            B.pos = b.playgamepos(B.pos,'B');
            usleep(3000000);
            turn++;
            if(B.pos == b.length)
            {
                cout << "B wins !!";
                break;
            }
        }

    }
}
int main()
{
    char gamemode;
    cout << "Welcome to snakes and ladders - Choose Game Mode :" << endl;
    cout << "Enter - 'd' : for default board game" << endl;
    cout << "Enter - 'c' : for custom board game" << endl;
    for(;;)
    {
        char temp;
        cin >> temp;
        if((temp== 'c') || (temp== 'd'))
        {
            gamemode = temp;
            break;
            
        }
        else
        {
            cout << "Invalid gamemode please try again :" << endl;
        }
    }
    if(gamemode == 'd')
    {
        Board b;
        playgamefinal(b);
    }
    else
    {
        Board b('c');
        playgamefinal(b);
    }
    return 0;
}
