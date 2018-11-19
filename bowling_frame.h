#ifndef AGILEDEV_BOWLING_BOWLING_FRAME_H_
#define AGILEDEV_BOWLING_BOWLING_FRAME_H_

class BowlingFrame {
 public:
  BowlingFrame(); 
  ~BowlingFrame() {};
  int GetScore() const;
  void Add(int pins);

 private:
  int total_scores_;
};

#endif  // AGILEDEV_BOWLING_BOWLING_FRAME_H_
