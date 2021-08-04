#include <iostream>

#define GAP '\t'

void clearCinState();

char arr[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int turn = 1;
int winner = 0;
void board()
{
    std::cout << GAP << "  Tic Tac Toe" << std::endl
              << std::endl;
    std::cout << GAP << arr[0] << "   |   " << arr[1] << "  |   " << arr[2] << std::endl;
    std::cout << "     -----------------------" << std::endl;
    std::cout << GAP << arr[3] << "   |   " << arr[4] << "  |   " << arr[5] << std::endl;
    std::cout << "     -----------------------" << std::endl;
    std::cout << GAP << arr[6] << "   |   " << arr[7] << "  |   " << arr[8] << std::endl;
    std::cout << std::endl;

    std::cout << GAP << "Player 1: " << 'O';
    std::cout << std::endl;
    std::cout << GAP << "Player 2: " << 'X';
    std::cout << std::endl;
    std::cout << std::endl;
}
int getIndex()
{
    int num;
start:
    try
    {
        if (std::cin >> num)
        {
            goto end;
        }
        else
        {
            clearCinState();
            throw(-1);
        }
    }
    catch (...)
    {
        std::cout << "Please try again with valid option" << std::endl;
        if (turn == 1)
            std::cout << "Player 1 turn: ";
        if (turn == 2)
            std::cout << "Player 2 turn: ";
        // clearCinState();
        goto start;
    }
end:
    return num;
}
void play()
{
    int index;
    if (turn == 1)
    {
    start:
        std::cout << "Player 1 turn: ";
        index = getIndex();

        if (index < 1 || index > 9)
        {
            std::cout << "Please try again with valid option.\n";
            goto start;
        }
        if (arr[(index - 1)] == 'X' || arr[(index - 1)] == 'O')
        {
            std::cout << "Already filled, Please try again with different option." << std::endl;
            goto start;
        }
        arr[index - 1] = 'O';
        turn = 2;
    }
    else if (turn == 2)
    {
    again:
        std::cout << "Player 2 turn: ";
        index = getIndex();
        if (index < 1 || index > 9)
        {
            std::cout << "Please try again with valid option. \n";
            goto start;
        }
        if (arr[(index - 1)] == 'X' || arr[(index - 1)] == 'O')
        {
            std::cout << "Already filled, Please try again with different option." << std::endl;
            goto again;
        }
        arr[index - 1] = 'X';
        turn = 1;
    }
}
bool Full()
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
            return false;
    }
    return true;
}

bool win()
{
    if (arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X' || arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X' || arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X')
    {
        // std::cout << "Player 2 wins. " << std::endl;
        winner = 2;
        return true;
    }
    if (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X' || arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X' || arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X')
    {
        // std::cout << "Player 2 wins. " << std::endl;
        winner = 2;
        return true;
    }
    if (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X' || arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')
    {
        winner = 2;
        return true;
    }
    if (arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O' || arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O' || arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O')
    {
        // std::cout << "Player 1 wins. " << std::endl;
        winner = 1;
        return true;
    }
    if (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O' || arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O' || arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O')
    {
        // std::cout << "Player 1 wins. " << std::endl;
        winner = 1;
        return true;
    }
    if (arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O' || arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O')
    {
        winner = 1;
        return true;
    }
    return false;
}

void clearCinState()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    // std::cin.get();
}

int main()
{
    system("clear");

    while (!Full())
    {
        board();
        play();
        if (win())
        {
            system("clear");
            board();
            if (winner == 1)
                std::cout << "Player 1 won The Game." << std::endl;
            else if (winner == 2)
                std::cout << "Player 2 won The Game." << std::endl;
            clearCinState();
            // std::cin.get();
            return 0;
        }
        system("clear");
    }
    board();
    std::cout << "Game Draw" << std::endl;
    clearCinState();
    // std::cin.get();

    return 0;
}