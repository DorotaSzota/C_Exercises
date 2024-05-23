/*
 Przygotuj program który pozwoli na zagranie w papier, kamień, nożyce. Natomiast program ma zapisywać wyniki oraz ruchy
 w poszczególnych rundach w tablicy oraz pozwalać na zwrócenie ich do terminala, po wpisaniu przez użytkownika
 odpowiedniej komendy jak na przykład scores czy analogicznej.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROUNDS 100

int getComputerMove() {
    return rand() % 3 + 1;
}

int getPlayerMove() {
    int move;
    printf("Choose your move:\n");
    printf("1 - paper\n");
    printf("2 - rock\n");
    printf("3 - scissors\n");
    scanf("%d", &move);
    return move;
}

void getMoveName(int move, char moveName[]) {
    switch (move) {
        case 1:
            strcpy(moveName, "paper");
            break;
        case 2:
            strcpy(moveName, "rock");
            break;
        case 3:
            strcpy(moveName, "scissors");
            break;
        default:
            strcpy(moveName, "unknown move");
            break;
    }
}

void printScores(int playerScore, int computerScore, int totalRounds) {
    printf("\nScores after %d rounds:\n", totalRounds);
    printf("Player: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);
}

int main() {
    srand(time(NULL)); // seed for random number generator based on current time. I was not able to find anything more
    // proper to generate a different random seed each time the game is launched.
    int playerScore = 0, computerScore = 0, totalRounds = 0;
    int rounds;

    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    while (totalRounds < rounds) {
        char input;
        int playerMove, computerMove;
        char playerMoveName[10], computerMoveName[10];

        printf("\nRound %d\n", totalRounds + 1);

        playerMove = getPlayerMove();
        computerMove = getComputerMove();

        getMoveName(playerMove, playerMoveName);
        getMoveName(computerMove, computerMoveName);

        printf("\nYour move: %s\n", playerMoveName);
        printf("Computer's move: %s\n", computerMoveName);

        if (playerMove == computerMove) {
            printf("It's a tie!\n");
        } else if ((playerMove == 1 && computerMove == 2) ||
                   (playerMove == 2 && computerMove == 3) ||
                   (playerMove == 3 && computerMove == 1)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }
        totalRounds++;

        printf("Score: Player %d - %d Computer\n", playerScore, computerScore);

        printf("Press 's' to see the scores, 'c' to continue playing, or any other key to quit: ");
        scanf(" %c", &input);

        if (input == 's' || input == 'S') {
            printScores(playerScore, computerScore, totalRounds);
        } else if (input != 'c' && input != 'C') {
            break;
        }
    }

    if (playerScore == rounds) {
        printf("Congratulations! You win the game!\n");
    } else if (computerScore == rounds) {
        printf("Computer wins the game. Try again!\n");
    } else {
        printf("\nGame over! Final scores:\n");
        printScores(playerScore, computerScore, totalRounds);
    }

    return 0;
}
