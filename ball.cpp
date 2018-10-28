#include "ball.h"
#include "game.h"
#include <iostream>

#define BALL_SIZE 12
#define PLAYER_HEIGHT 32

Ball::Ball()
    : m_ball({0, 0, BALL_SIZE, BALL_SIZE}), m_speedX(5), m_speedY(7),
      m_windowX(0), m_windowY(0), m_src({50, 68, BALL_SIZE, BALL_SIZE}),
      m_is_moving(false) {}
Ball::Ball(Game *game)
    : m_game(game), m_speedX(5), m_speedY(7),
      m_src({50, 68, BALL_SIZE, BALL_SIZE}), m_is_moving(false) {
  m_windowX = game->getWindowManager()->getWindowWidth();
  m_windowY = game->getWindowManager()->getWindowHeight();
  m_ball = {m_windowX / 2, m_windowY - PLAYER_HEIGHT - BALL_SIZE, BALL_SIZE,
            BALL_SIZE};
}

SDL_Rect Ball::getRect() const { return m_ball; }
SDL_Rect Ball::getSrc() const { return m_src; }

/**
 * When function is called, the ball starts to move
 */
void Ball::set_moving() { m_is_moving = true; }

void Ball::move(Player &player) {
  int playerPosition = player.get_x();
  int playerWidth = player.getRect().w;

  bool cylinderModeEnabled = m_game->getCylinderMode();

  if (m_is_moving) {
    // deplacement
    m_ball.x += m_speedX;
    m_ball.y += m_speedY;

    if (m_ball.x < 1) { // collision bord gauche
      if (cylinderModeEnabled) {
        m_ball.x = m_windowX - BALL_SIZE;
      } else {
        m_speedX *= -1;
        if (m_ball.x < 0)
          m_ball.x = 0;
      }
    } else if (m_ball.y < 1) { // collision bord haut
      m_speedY *= -1;
      if (m_ball.y < 0)
        m_ball.y = 0;
    } else if (m_ball.x > m_windowX - BALL_SIZE) { // collision bord droit
      if (cylinderModeEnabled) {
        m_ball.x = 0;
      } else {
        m_ball.x = -m_ball.x + (2 * (m_windowX - BALL_SIZE));
        m_speedX *= -1;
      }
    } else if (m_ball.y > m_windowY - BALL_SIZE) { // collsion bord bas
      m_ball.y = -m_ball.y + (2 * (m_windowY - BALL_SIZE));
      m_speedY *= -1;

      player.loose_life();
      m_is_moving = false;
      m_ball.y = m_windowY - PLAYER_HEIGHT - BALL_SIZE;
    }

    // collision vaisseau
    if ((m_ball.x > playerPosition) &&
        (m_ball.x < playerPosition + playerWidth) &&
        (m_ball.y > m_windowY - PLAYER_HEIGHT - BALL_SIZE)) {

      // allows the player to choose the direction of the ball
      float positionOnPlayer =
          (float)((float)(m_ball.x - playerPosition) / (float)playerWidth);
      // speed between -10 et 10 (range of 20), using the ball position
      m_speedX = positionOnPlayer * 20 - 10;

      m_speedY *= -1;
    }

  } else { // the ball sticks on the player
    m_ball.x = playerPosition + (playerWidth / 2) - (BALL_SIZE / 2);
  }
}

void Ball::collisionLeftRight() { m_speedX *= -1; }

void Ball::collisionTopBottom() { m_speedY *= -1; }
