#include "bowling_frame.h"

BowlingFrame::BowlingFrame() {
  total_scores_ = 0;
}

int BowlingFrame::GetScore() const {
  return total_scores_;
}

void BowlingFrame::Add(int pins) {
  total_scores_ = total_scores_ + pins;
}
