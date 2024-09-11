#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>


#define DELAY 30000 //velocidade da cobra

// define adireção
enum Direction {UP, DOWN, LEFT, RIGHT};

// estruct paraa posição x,y
typedef struct {
     int x, y;
} Position;

// define as variáveis globais
Position food, snake[100];
int snake_length = 5; // tamanho inicial 
enum Direction  dir = RIGHT;
int max_x, max_y;

// iniciar o ncurses e config o terminal
void init_game(){
      initscr();
      noecho();
      curs_set(FALSE);
      keypad(stdscr, TRUE);
      timeout(100); // controla a velocidade
      getmaxyx(stdscr, max_y, max_x);// tamanho máximo da janela
      food.x = rand() % max_x;
      food.y = rand() % max_y;
      for (int i = 0; i < snake_length; i++){
          
          snake[i].x = max_x / 2 -i;
          snake[i].y = max_y/ 2;
      }
 }

// Tela de Game over
void game_over() {

      clear();
      mvprintw(max_y / 2, (max_x / 2) - 5, " GAME OVER! ");
      mvprintw(max_y / 2 + 1, (max_x / 2) - 10, " Press 'q' to quit or 'r' to restart " ); 
      refresh();

      int ch;
      while ((ch = getch()) != 'q') {
          if (ch == 'r') {
              snake_length = 5;
              init_game();
              break;
          }
      }
     endwin();
     exit(0);
 }  

// interface de pontuação
void draw_score(){
      mvprintw(0, (max_x / 2) - 5,"  Score: %d  ", snake_length - 5);  
 }

// desenho das bordas
void draw_borders(){
      //bordas superior e inferior
      for (int x = 0; x < max_x; x++) {
           mvprintw(0, x, "#");
           mvprintw(max_y - 1, x, "#");  
      }
      // bordas esquerda e direita
      for (int y = 0; y < max_y; y++) {
           mvprintw(y, 0, "#");
           mvprintw(y, max_x - 1, "#");
      }
 }

// desenho da cobrinha e a comida dela e a tela

void draw_game(){
      
      clear(); // limpa a tela
      draw_borders(); // desenha as bordas da tela
      draw_score(); // pontuação
      mvprintw(food.y, food.x, "*"); // desenho da comida

      for (int i = 0; i < snake_length; i++) {  // desenha a cobra   
          mvprintw(snake[i].y, snake[i].x, "X");
      }
    refresh();
 }
// mover a cobra deacordo com a direção
 
 void move_snake() {
      
      Position next = snake[0];

      switch (dir){
          case UP:    next.y--; break;
          case DOWN:  next.y++; break;
          case LEFT:  next.x--; break;
          case RIGHT: next.x++; break;
      }
   // verificar colisão com a parede

      if ( next.x < 0 || next.x >= max_x || next.y < 0 || next.y >= max_y ) {
       game_over(); // chamando a função game_over

       }
  // Verificar colisão com o própio corpo
      for (int i = 0; i < snake_length; i++) {
          if (next.x == snake[i].x && next.y == snake[i].y) {
              endwin();
              printf( " Game over! You hit yourself.\n" );
              exit(0);
          }
      }
  // movendo a cobrinha
      for (int i = snake_length - 1; i > 0; i--) {
           snake[i] = snake[i - 1];
      }
      snake[0] = next;

  // verificar se a cobra comeu a comida
      if (snake[0].x == food.x && snake[0].y == food.y) {
          snake_length++;
          food.x = rand() % max_x;
          food.y = rand() % max_y;
      }
  }   

  // Lidando com a entrada do usuário
 void handle_input() {
      int ch = getch();
      switch (ch) {
          case KEY_UP:    if (dir != DOWN) dir = UP; break;
          case KEY_DOWN:  if (dir != UP) dir = DOWN; break;
          case KEY_LEFT:  if (dir != RIGHT) dir = LEFT; break;
          case KEY_RIGHT: if (dir != LEFT) dir =  RIGHT; break;
      }
 }

 int main(){
     
      init_game();

      while (1) {
           handle_input();
           move_snake();
           draw_game();
           usleep(DELAY);
     }
     endwin();
     return 0;
}
























