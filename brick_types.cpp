#include "brick.h"
#include "brick_types.h"
#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32

/**
 * This file defines all children of "Brick"
 */

/** BRICK 1 **/

Brick1::Brick1() : Brick() {}

Brick1::Brick1(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 1;
  m_points = 50;
  m_color = "white";
}

/** BRICK2 **/

Brick2::Brick2() : Brick() {}

Brick2::Brick2(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 2;
  m_points = 55;
  m_color = "green";
}

/** BRICK3 **/

Brick3::Brick3() : Brick() {}

Brick3::Brick3(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 3;
  m_points = 60;
  m_color = "yellow";
}

/** BRICK4 **/

Brick4::Brick4() : Brick() {}

Brick4::Brick4(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 4;
  m_points = 65;
  m_color = "cyan";
}

/** BRICK5 **/

Brick5::Brick5() : Brick() {}

Brick5::Brick5(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 5;
  m_points = 70;
  m_color = "blue-green";
}

/** BRICK6 **/

Brick6::Brick6() : Brick() {}

Brick6::Brick6(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 6;
  m_points = 75;
  m_color = "dark-green";
}

/** BRICK7 **/

Brick7::Brick7() : Brick() {}

Brick7::Brick7(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 7;
  m_points = 80;
  m_color = "blue";
}

/** BRICK8 **/

Brick8::Brick8() : Brick() {}

Brick8::Brick8(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 8;
  m_points = 85;
  m_color = "purple";
}

/** BRICK9 **/

Brick9::Brick9() : Brick() {}

Brick9::Brick9(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 9;
  m_points = 90;
  m_color = "orange";
}

/** BRICK10 **/

Brick10::Brick10() : Brick() {}

Brick10::Brick10(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 10;
  m_points = 95;
  m_color = "red";
}

/** BRICK11 **/

Brick11::Brick11() : Brick() {}

Brick11::Brick11(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 11;
  m_points = 100;
  m_color = "dark-red";
}

/** BRICK12 **/

Brick12::Brick12() : Brick() {}

Brick12::Brick12(int lives, int line, int col) : Brick(lives, line, col) {
  m_id = 12;
  m_points = 120;
  m_color = "dark-blue";
}

/** BRICK 13 **/

Brick13::Brick13() : Brick() {}

Brick13::Brick13(int lives, int line, int col) : Brick(lives, line, col) {
  m_lives = 2; // to increase with number of rounds
  m_id = 13;
  m_points = 150; // to increase with number of rounds
  m_color = "grey";
}

/** BRICK 14 **/

Brick14::Brick14() : Brick() {}

Brick14::Brick14(int lives, int line, int col) : Brick(lives, line, col) {
  m_lives = 10; // infinite
  m_id = 14;
  m_points = 0; // not meant to be destroyed
  m_color = "gold";
}