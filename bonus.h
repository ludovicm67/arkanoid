#ifndef BONUS_H
#define BONUS_H

#include <string>

#include "ball.h"
#include "brick.h"
#include "drawable.h"

class Game;

class Bonus : public Drawable {
public:
  Bonus();
  Bonus(Game *game);

  virtual void drawCallback();
  virtual void action();
  static void initTimer();
  static bool isTimeUp();

  static int bonusTimer;
  static bool activeBonus;

protected:
  int m_countAnim;
  Game *m_game;
};

/** BONUS TYPES **/

class BonusS : public Bonus {
public:
  BonusS(Game *game, Box pos);
  void action();
};

class BonusC : public Bonus {
public:
  BonusC(Game *game, Box pos);
  void action();
};

class BonusL : public Bonus {
public:
  BonusL(Game *game, Box pos);
  void action();
};

class BonusE : public Bonus {
public:
  BonusE(Game *game, Box pos);
  void action();
};

class BonusD : public Bonus {
public:
  BonusD(Game *game, Box pos);
  void action();
};

class BonusB : public Bonus {
public:
  BonusB(Game *game, Box pos);
  void action();
};

class BonusP : public Bonus {
public:
  BonusP(Game *game, Box pos);
  void action();
};

#endif // BONUS_H
