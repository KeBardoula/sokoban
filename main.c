#include "header.h"
#include <stdio.h>

int main(){
    GameState game;
    char input;
    int game_won = 0;
    int game_lost = 0;
    
    // Initialiser le jeu
    init_game(&game);
    
    // Boucle principale du jeu
    do {
        display_board(&game);
        
        // Demander au joueur de saisir une direction
        printf("Choisissez un mouvement : haut(w) bas(s) gauche(a) droite(d)");
        scanf(" %c", &input);
        
        // Déplacer le joueur en fonction du mouvement choisis
        move_player(&game, input);
        
        // Vérifier les conditions de victoire ou de défaite
        game_won = is_game_won(&game);
        game_lost = is_box_stuck(&game);
        
        if (game_won){
            printf("Vous avez gagné !\n");
        } else if (game_lost){
            printf("La caisse est bloquée, vous avez perdu !\n");
        }
    }while(!game_won && !game_lost);
    
    return 0;
}
