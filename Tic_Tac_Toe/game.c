#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[5][5];               // The game board
const char PLAYER_1 = 'X';      // Symbol for player 1
const char PLAYER_2 = 'O';      // Symbol for player 2
const char AI_PLAYER = 'A';     // Symbol for AI player

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove(char currentPlayer);
void aiMove();
char checkWinner();
void printWinner(char winner);
void displayMenu();
void updateScore(char winner);
void printScore();

int player1Score = 0;
int player2Score = 0;
char response = ' ';

int main()
{
    char winner = ' ';

    srand(time(NULL));

    do
    {
        winner = ' ';
        resetBoard();

        displayMenu();

        if (response == '1')
        {
            while (winner == ' ' && checkFreeSpaces() != 0)
            {
                printBoard();

                playerMove(PLAYER_1);
                winner = checkWinner();
                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }

                printBoard();

                playerMove(PLAYER_2);
                winner = checkWinner();
            }
        }
        else if (response == '2')
        {
            while (winner == ' ' && checkFreeSpaces() != 0)
            {
                printBoard();

                playerMove(PLAYER_1);
                winner = checkWinner();
                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }

                printBoard();

                aiMove();
                winner = checkWinner();
            }
        }

        printBoard();
        printWinner(winner);
        updateScore(winner);
        printScore();

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

void resetBoard()
{
    int i, j;

    // Reset each cell of the game board to an empty space
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf("\n");
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %c ", board[i][j]);
            if (j != 4)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != 4)
        {
            printf("---+---+---+---+---\n");
        }
    }
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 0;
    int i, j;

    // Count the number of empty spaces on the game board
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (board[i][j] == ' ')
            {
                freeSpaces++;
            }
        }
    }
    return freeSpaces;
}

void playerMove(char currentPlayer)
{
    int x, y;

    do
    {
        printf("Player %c's turn\n", currentPlayer);
        printf("Enter row #(1-5): ");
        scanf("%d", &x);
        x--;

        printf("Enter column #(1-5): ");
        scanf("%d", &y);
        y--;

        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            printf("Invalid move! Please enter valid row and column numbers.\n");
        }
        else if (board[x][y] != ' ')
        {
            printf("Invalid move! That cell is already occupied.\n");
        }
        else
        {
            board[x][y] = currentPlayer;
            break;
        }
    } while (1);
}

void aiMove()
{
    int x, y;

    printf("AI Player's turn\n");

    do
    {
        x = rand() % 5;
        y = rand() % 5;

        if (board[x][y] == ' ')
        {
            board[x][y] = AI_PLAYER;
            break;
        }
    } while (1);
}

char checkWinner()
{
    // Check rows for a winning pattern
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')
            {
                return board[i][j];  // Return the winning symbol (PLAYER_1, PLAYER_2, or AI_PLAYER)
            }
        }
    }

    // Check columns for a winning pattern
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] != ' ')
            {
                return board[i][j];  // Return the winning symbol (PLAYER_1, PLAYER_2, or AI_PLAYER)
            }
        }
    }

    // Check diagonals for a winning pattern
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            //Here's the continuation of the updated code with the remaining part of the `checkWinner` function:
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ')
            {
                return board[i][j];  // Return the winning symbol (PLAYER_1, PLAYER_2, or AI_PLAYER)
            }
            if (board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i + 2][j] && board[i][j + 2] != ' ')
            {
                return board[i][j + 2];  // Return the winning symbol (PLAYER_1, PLAYER_2, or AI_PLAYER)
            }
        }
    }

    return ' ';  // Return a space if there is no winner
}

void printWinner(char winner)
{
    if (winner == PLAYER_1)
    {
        printf("\nPlayer 1 won the game.\n");
    }
    else if (winner == PLAYER_2)
    {
        printf("\nPlayer 2 won the game.\n");
    }
    else if (winner == AI_PLAYER)
    {
        printf("\nAI Player won the game.\n");
    }
    else
    {
        printf("\nIt's a tie!\n");
    }
}

void displayMenu()
{
    int choice;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Rules of the game are:\n");
    printf("a. Choose either you play with the AI or another user.\n");
    printf("b. Whoever makes straight line of 3 elements(row, column or diagonal) wins and gets a point added to the score. \n\n");
    printf("LETS START!! \n");
    printf("Enter your choice (1-2): \n");
    printf("1. 2 Players Mode\n");
    printf("2. Single Player Mode\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\n--- Two Players Mode ---\n");
        response = '1';
    }
    else if (choice == 2)
    {
        printf("\n--- Single Player Mode ---\n");
        response = '2';
    }
    else
    {
        printf("\nInvalid choice. Starting in 2 Players Mode.\n");
        response = '1';
    }
}

void updateScore(char winner)
{
    if (winner == PLAYER_1)
    {
        player1Score++;
    }
    else if (winner == PLAYER_2 || winner == AI_PLAYER)
    {
        player2Score++;
    }
}

void printScore()
{
    printf("\nScore:\n");
    printf("Player 1: %d\n", player1Score);
    if (response == '1')
    {
        printf("Player 2: %d\n", player2Score);
    }
    else if (response == '2')
    {
        printf("AI Player: %d\n", player2Score);
    }
}


