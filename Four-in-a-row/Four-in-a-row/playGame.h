#pragma once
#include "utilities.h"
bool playerTurn(Board b, Tile t = RED);
bool machineTurn(Board b, int choice, Tile t = YELLOW);
void play();
