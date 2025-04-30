#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // initialize random number generator
    int player, computer;
    int your_score = 0, opponent_score = 0;
    int round = 0;

    printf("NOTICE: If you want to exit the game, press 'e'\n\n");
    printf("The game is simple:\n'r' --> Rock\n'p' --> Paper\n's' --> Scissor\n");
    printf("GAME BEGINS\n");

    char playerMove;
    while (1)
    {
        computer = rand() % 3;
        // rand() generates a number from 0 to... To set max limit using % and here % 3 used
        // so the max value is 3-1 = 2. And it will generate 0,1,and 2

        char input[10];
        printf("\n'r' 'p' 's'\n*** Choose one ***\n");
        scanf("%9s", input);
        playerMove = input[0];
        // this solves the problem to some extent i.e., on giving input rrrr,
        // it takes it as 'r','r','r','r' and loop run 4 times using r as input each time


        if (playerMove == 'r' || playerMove == 'R') {
            player = 0;
            printf("You chose Rock\n");
        }
        else if (playerMove == 'p' || playerMove == 'P') {
            player = 1;
            printf("You chose Paper\n");
        }
        else if (playerMove == 's' || playerMove == 'S') {
            player = 2;
            printf("You chose Scissor\n");
        }
        else if (playerMove == 'e' || playerMove == 'E') {
            printf("\nFinal Score:\nYou: %d\nComputer: %d\n", your_score, opponent_score);
            break; // Exit the loop
        }
        else {
            printf("Invalid input. Enter 'r' 'p' 's' or 'e' to exit the game\n");
            continue;
        }

        if (computer == 0)
            printf("Computer chose Rock\n");
        else if (computer == 1)
            printf("Computer chose Paper\n");
        else
            printf("Computer chose Scissor\n");

        round++; // Increment round after valid move

        // Game condition check
        if (player == computer) {
            printf("It's a Draw!\n");
        }
        else if ((player == 0 && computer == 2) ||
                 (player == 1 && computer == 0) ||
                 (player == 2 && computer == 1)) {
            printf("Victory!\n");
            your_score++;
        }
        else {
            printf("Better luck next time.\n");
            opponent_score++;
        }

        // Show score bar after each round
        printf("\n--- Round %d ---\n", round);
        printf("[You: %d]  vs  [Computer: %d]\n", your_score, opponent_score);
        printf("-------------------------\n");
    }

    return 0;
}