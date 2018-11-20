#include "bowling_game.h"

BowlingGame::BowlingGame() {
  total_score_ = 0;
  first_throw_in_frame_ = true;
  current_throw_ = 0;
  current_frame_ = 1;
  throw_pins_vec_.resize(21, 0);
}

int BowlingGame::GetScore() const {
  //if (first_throw_in_frame_) {
    return GetScoreForFrame(current_frame_ - 1);
  //} else {
  //  return GetScoreForFrame(current_frame_) + throw_pins_vec_[current_throw_];
  //}
}

void BowlingGame::Add(int pins) {
  throw_pins_vec_[current_throw_++] = pins;
  total_score_ = total_score_ + pins;
  UpdateFrameNum(pins);
}

int BowlingGame::GetScoreForFrame(int frame) const {
  int throw_index = 0;
  int result_score = 0;
  for (int i = 0; i < frame; ++i) {
    int first_throw_score = throw_pins_vec_[throw_index];
    if (first_throw_score == 10) {
      result_score = result_score + first_throw_score + throw_pins_vec_[throw_index + 1] + throw_pins_vec_[throw_index + 2];
      throw_index += 1;
    } else {
      int frame_score = first_throw_score + throw_pins_vec_[throw_index + 1];
      // spare bonus
      if (frame_score == 10) {
        result_score = result_score + frame_score + throw_pins_vec_[throw_index + 2];
      } else {
        result_score = result_score + frame_score;
      }   
        throw_index += 2;
    }
  }
  return result_score;
}

void BowlingGame::UpdateFrameNum(int pins) {
  if (first_throw_in_frame_) {
    if (pins == 10) {
        current_frame_++;
    } else { 
        first_throw_in_frame_ = false;
    }
  } else {
    current_frame_++;
    first_throw_in_frame_ = true;
  }
  current_frame_ = std::min(11, current_frame_);
}

int BowlingGame::GetCurrentFrame() const {
  return current_frame_;
}
