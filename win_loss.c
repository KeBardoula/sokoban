#include "header.h"

// Vérifier si la partie est gagnée (caisse sur la cible)
int is_game_won(GameState *game){
    return game->box_x == game->target_x && game->box_y == game->target_y;
}

// Vérifier si la caisse est coincée
int is_box_stuck(GameState *game){
    int x = game->box_x;
    int y = game->box_y;
    
    // Si la caisse est bloquée par deux murs opposés
    if ((game->board[x-1][y] == WALL || game->board[x+1][y] == WALL) && (game->board[x][y-1] == WALL || game->board[x][y+1] == WALL)){
        return 1;
    }
    return 0;
}
