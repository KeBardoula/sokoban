// header.h
#ifndef HEADER_H
#define HEADER_H

// Dimension du plateau
#define ROWS 10
#define COLS 10

// Symbole du jeux
#define EMPTY ' '  // Pour les cases vides
#define WALL '#' // Pour les murs du plateau
#define BOX 'X' // Pour la caisse
#define TARGET '.' // Emplacement où la caisse doit être placée
#define PLAYER 'o' // Pour le joueur

typedef struct {
    char board[ROWS][COLS];
    int player_x, player_y;
    int box_x, box_y;
    int target_x, target_y;
} GameState;

// Protype des fonctions
void init_game(GameState *game);
void display_board(GameState *game);
int move_player(GameState *game, char direction);
int is_game_won(GameState *game);
int is_box_stuck(GameState *game);

#endif // HEADER_H
 
