#ifndef AGILEDEV_BOWLING_BOWLING_GAME_H_
#define AGILEDEV_BOWLING_BOWLING_GAME_H_

#include <vector>

class BowlingGame {
 public:
  BowlingGame();
  ~BowlingGame() {};
  int GetScore() const;
  void Add(int pins);
  int GetScoreForFrame(int frame) const;
  void UpdateFrameNum(int pins);
  int GetCurrentFrame() const;

 private:
  int total_score_;
  int current_throw_;
  int current_frame_;
  bool first_throw_in_frame_;
  std::vector<int> throw_pins_vec_;
};

#endif // AGILEDEV_BOWLING_BOWLING_GAME_H_

