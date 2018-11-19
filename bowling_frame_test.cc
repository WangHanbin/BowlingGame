#include "bowling_frame.h"

#include <gtest/gtest.h>

TEST(BowlingFrameTest, GetScoreNoThrow) {
  BowlingFrame frame;
  EXPECT_EQ(0, frame.GetScore());
}

TEST(BowlingFrameTest, GetScoreOneThrow) {
  BowlingFrame frame;
  frame.Add(3);
  EXPECT_EQ(3, frame.GetScore());
}


