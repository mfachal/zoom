#include <math.h>
#include <stdio.h>

#define PLAYERS 2

double speeds [PLAYERS];
double times [PLAYERS];
int played [PLAYERS];

double inverselorentzfactor(double speed) {
  //speed is a factor of c
  return sqrt(1 - (speed * speed));
  
}

/* int allplayed() { */
/*   int i = 0; */
/*   for (i = 0; i < PLAYERS; i++) { */
/*     if (playertimes >= 1.0d) return 0; */
    
/*   } */
/*   return 1; */
/* } */

void wait(int player) {
  times[player] += inverselorentzfactor(speeds[player]);
  played[player] = 1;
}

void play(int player) {
  if (played[player]) {
    printf("player %i can't play, he's already played!\n", player);
  } else {
    if (times[player] < 1.0d) {
      printf("player %i tried to play but is slowed down, so his turn isn't yet due\n", player);
      wait(player);
    } else {    
      printf("player %i played\n", player);
      times[player] -= 1.0d;
      played[player] = 1;
    }
  }
}

void print_pf(int player){
  printf("player %i stats: \n", player);
  printf("speed: %f\n", speeds[player]);
  printf("factor: %f\n", inverselorentzfactor(speeds[player]));
  printf("turn counter: %f\n", times[player]);
}

void wait_all() {

  played[0] = 0;
  played[1] = 0;
  /* for (int i = 0; i < PLAYERS; i++) { */
  /*   wait(i); */
  /* } */
}

int main() {

  speeds[0] = 0.0d;
  speeds[1] = 0.7d;
  played[0] = 0;
  played[1] = 0;
  
  while (1) {
    print_pf(0);
    print_pf(1);
    
    char pressed = getchar();
    
    if (pressed == 'a') play(0);
    else if (pressed == 'j') play(1);
    else if (pressed == ' ') {
      wait_all();
    }

  }

  return 0;
  
}

