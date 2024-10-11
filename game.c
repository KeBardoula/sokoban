// game.c
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour générer une position aléatoire sur le plateau
void randomPosition(int *x, int *y) {
    *x = rand() % (ROWS - 2) + 1; // Eviter les murs
    *y = rand() % (COLS - 2) + 1;
}

void init_game(GameState *game) {
    // Définir le plateau de départ avec les murs serrés
    char initial_board[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, // Mur supérieur serré
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // Lignes espacées
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}  // Mur inférieur serré
    };

    // Copier ce plateau initial dans le plateau du jeu (structure GameState)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game->board[i][j] = initial_board[i][j];
        }
    }

    // Générer des positions aléatoires pour le joueur, la caisse et la cible
    srand(time(NULL));

    // Assurez-vous que les positions sont dans des cases vides
    randomPosition(&game->player_x, &game->player_y);
    game->board[game->player_x][game->player_y] = PLAYER;

    randomPosition(&game->box_x, &game->box_y);
    game->board[game->box_x][game->box_y] = BOX;

    randomPosition(&game->target_x, &game->target_y);
    game->board[game->target_x][game->target_y] = TARGET;
}

// Fonction pour afficher le plateau
void display_board(GameState *game) {  // <- Définie ici
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", game->board[i][j]);
        }
        printf("\n");
    }
}
