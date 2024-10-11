// move.c
#include "header.h"
#include <stdio.h>

int move_player(GameState *game, char direction) {
    // Variables pour la nouvelle position du joueur
    int new_x = game->player_x;
    int new_y = game->player_y;
    
    // Déterminer la nouvelle position en fonction de la direction
    switch (direction) {
        case 'w': // Haut
            new_x--;
            break;
        case 's': // Bas
            new_x++;
            break;
        case 'a': // Gauche
            new_y--;
            break;
        case 'd': // Droite
            new_y++;
            break;
        default:
            return 0; // Si la direction est invalide, ne rien faire
    }

    // Vérifier si le joueur rencontre un mur
    if (game->board[new_x][new_y] == WALL) {
        return 0; // Mouvement impossible, il y a un mur
    }

    // Vérifier si le joueur rencontre la boîte
    if (game->board[new_x][new_y] == BOX) {
        // Calculer la position derrière la boîte
        int box_new_x = new_x + (new_x - game->player_x);
        int box_new_y = new_y + (new_y - game->player_y);
        
        // Vérifier si la boîte peut être poussée
        if (game->board[box_new_x][box_new_y] == EMPTY || game->board[box_new_x][box_new_y] == TARGET) {
            // Déplacer la boîte
            game->board[box_new_x][box_new_y] = BOX;
            game->board[new_x][new_y] = PLAYER;  // Déplacer le joueur
            game->board[game->player_x][game->player_y] = EMPTY;  // Ancienne position du joueur devient vide
            
            // Mettre à jour la position du joueur et de la boîte
            game->player_x = new_x;
            game->player_y = new_y;
            game->box_x = box_new_x;
            game->box_y = box_new_y;
            return 1; // Mouvement réussi
        } else {
            return 0; // Mouvement impossible, la boîte est bloquée
        }
    }

    // Si la case est vide ou la cible, déplacer simplement le joueur
    if (game->board[new_x][new_y] == EMPTY || game->board[new_x][new_y] == TARGET) {
        game->board[new_x][new_y] = PLAYER;
        game->board[game->player_x][game->player_y] = EMPTY;
        game->player_x = new_x;
        game->player_y = new_y;
        return 1; // Mouvement réussi
    }

    return 0; // Mouvement impossible
}
