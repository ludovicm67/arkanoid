#include <cmath>
#include <SDL2/SDL.h>
#include <iostream>

#include "graphicmanager.h"
#include "bonus.h"

Bonus::Bonus()
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {0, 0, BRICK_WIDTH, BRICK_HEIGHT}) {}

/** BONUS TYPES **/
BonusS::BonusS() : Bonus() {
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_S);
}
