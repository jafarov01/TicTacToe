/* 
*   Copyright (C) 2021-01?? Makhlug Jafarov
*
*   This code is made by Me, just as simple as shown below. You can freely take this code and modify if necessary. Glad this code will help you. Regards!
    
    //github.com/jafarov01
    //https://www.linkedin.com/in/jafarov01/
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void playArea(char play_area[3][3]);
int winner_check(char play_area[3][3]);
void player_x(char play_area[3][3], int choose);
void player_o(char play_area[3][3], int choose);

int main()
{
    int chosenSquare;

    char boardArray[3][3] = { '0','1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' };
    bool check_input[9]{ 0,0, 0, 0, 0, 0, 0, 0, 0 };

    playArea(boardArray);

    while (1)
    {
        cout << "Player X: Enter a number between  0 and 8: ";
        cin >> chosenSquare;
        if (chosenSquare < 0 || chosenSquare > 9 || check_input[chosenSquare] == true)
        {
            do
            {
                cout << "Not a valid choice. Try again. \nPlayer X : Enter a number between  0 and 8 : ";
                cin >> chosenSquare;
            } while (chosenSquare < 0 || chosenSquare > 9 || check_input[chosenSquare] == true);
        }
        check_input[chosenSquare] = true;
        player_x(boardArray, chosenSquare);

        playArea(boardArray);

        if (winner_check(boardArray) == 1)
        {
            cout << "\n\t\t\tPlayer X WON!\n";
            break;
        }
        else if (winner_check(boardArray) == 0)
        {
            cout << "\n\t\t\tNO ONE WON! TRY AGAIN!\n";
            break;
        }

        cout << "Player O: Enter a number between  0 and 8: ";
        cin >> chosenSquare;
        if (chosenSquare < 0 || chosenSquare > 9 || check_input[chosenSquare] == true)
        {
            do
            {
                cout << "Not a valid choice. Try again. \nPlayer O : Enter a number between  0 and 8 : ";
                cin >> chosenSquare;
            } while (chosenSquare < 0 || chosenSquare > 9 || check_input[chosenSquare] == true);
        }
        check_input[chosenSquare] = true;
        player_o(boardArray, chosenSquare);

        playArea(boardArray);

        if (winner_check(boardArray) == 1)
        {
            cout << "\n\t\t\tPlayer O WON!\n";
            break;
        }
        else if (winner_check(boardArray) == 0)
        {
            cout << "\n\t\t\tNO ONE WON! TRY AGAIN!\n";
            break;
        }
    }

    return 0;
}



void playArea(char play_area[3][3])
{
    system("CLS");
    cout << "\n\tCurrent board state: " << endl;

    cout << "\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "\t" << char(186) << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << play_area[i][j] << " " << char(186) << " ";
        }
        cout << endl;
    }
    cout << "\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;
    cout << endl;
}

int winner_check(char play_area[3][3])
{
    if (play_area[0][0] == play_area[0][1] && play_area[0][1] == play_area[0][2])
    {
        return 1;
    }
    else if (play_area[1][0] == play_area[1][1] && play_area[1][1] == play_area[1][2])
    {
        return 1;
    }
    else if (play_area[2][0] == play_area[2][1] && play_area[2][1] == play_area[2][2])
    {
        return 1;
    }
    else if (play_area[0][0] == play_area[1][0] && play_area[1][0] == play_area[2][0])
    {
        return 1;
    }
    else if (play_area[0][1] == play_area[1][1] && play_area[1][1] == play_area[2][1])
    {
        return 1;;
    }
    else if (play_area[0][2] == play_area[1][2] && play_area[1][2] == play_area[2][2])
    {
        return 1;
    }
    else if (play_area[0][0] == play_area[1][1] && play_area[1][1] == play_area[2][2])
    {
        return 1;
    }
    else if (play_area[0][2] == play_area[1][1] && play_area[1][1] == play_area[2][0])
    {
        return 1;
    }
    else if (play_area[0][0] != '0' && play_area[0][1] != '1' && play_area[0][2] != '2'
        && play_area[1][0] != '3' && play_area[1][1] != '4' && play_area[1][2] != '5'
        && play_area[2][0] != '6' && play_area[2][1] != '7' && play_area[2][2] != '8')
    {
        return 0;
    }
    else
        return -1;

}

void player_x(char play_area[3][3], int choose)
{
    const char PLAYER_X = 'X';
    if (choose == 0)
        play_area[0][0] = PLAYER_X;
    else if (choose == 1)
        play_area[0][1] = PLAYER_X;
    else if (choose == 2)
        play_area[0][2] = PLAYER_X;
    else if (choose == 3)
        play_area[1][0] = PLAYER_X;
    else if (choose == 4)
        play_area[1][1] = PLAYER_X;
    else if (choose == 5)
        play_area[1][2] = PLAYER_X;
    else if (choose == 6)
        play_area[2][0] = PLAYER_X;
    else if (choose == 7)
        play_area[2][1] = PLAYER_X;
    else if (choose == 8)
        play_area[2][2] = PLAYER_X;

}

void player_o(char play_area[3][3], int choose)
{
    const char PLAYER_O = 'O';
    if (choose == 0)
        play_area[0][0] = PLAYER_O;
    else if (choose == 1)
        play_area[0][1] = PLAYER_O;
    else if (choose == 2)
        play_area[0][2] = PLAYER_O;
    else if (choose == 3)
        play_area[1][0] = PLAYER_O;
    else if (choose == 4)
        play_area[1][1] = PLAYER_O;
    else if (choose == 5)
        play_area[1][2] = PLAYER_O;
    else if (choose == 6)
        play_area[2][0] = PLAYER_O;
    else if (choose == 7)
        play_area[2][1] = PLAYER_O;
    else if (choose == 8)
        play_area[2][2] = PLAYER_O;
}
