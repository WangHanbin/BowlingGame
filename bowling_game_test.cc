#include "bowling_game.h"

#include <gtest/gtest.h>

class GameTest : public ::testing::Test {
 protected:
  BowlingGame game_;
  void SetUp() override {
    
  }

};

TEST_F(GameTest, GetScoreNoThrow) {
  EXPECT_EQ(0, game_.GetScore());
  EXPECT_EQ(1, game_.GetCurrentFrame());
}

TEST_F(GameTest, GetScoreOneThrow) {
  game_.Add(3);
  EXPECT_EQ(1, game_.GetCurrentFrame());
}

TEST_F(GameTest, GetScoreTwoThrow) {
  game_.Add(1);
  game_.Add(5);
  EXPECT_EQ(6, game_.GetScore());
  EXPECT_EQ(2, game_.GetCurrentFrame());
}


TEST_F(GameTest, GetScoreFrameWithoutBonus) {
  // spare or strike can get bonuses
  game_.Add(1);
  game_.Add(3);
  game_.Add(5);
  game_.Add(3);
  EXPECT_EQ(12, game_.GetScoreForFrame(2));
}

TEST_F(GameTest, GetScoreForSpare) {
  game_.Add(2);
  game_.Add(8);  // spare
  game_.Add(6);
  EXPECT_EQ(16, game_.GetScoreForFrame(1));
}

// can't pass this test now
TEST_F(GameTest, GetScoreForStrike) {
  game_.Add(10);
  game_.Add(3);
  game_.Add(4);
  EXPECT_EQ(17, game_.GetScoreForFrame(1));
  EXPECT_EQ(24, game_.GetScore());
  EXPECT_EQ(3, game_.GetCurrentFrame());
}
