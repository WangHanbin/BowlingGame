cc_library(
    name = "bowling_frame",
    srcs = ["bowling_frame.cc"],
    hdrs = ["bowling_frame.h"],
)

cc_library(
    name = "bowling_game",
    srcs = ["bowling_game.cc"],
    hdrs = ["bowling_game.h"],
)

cc_test(
    name = "bowling_frame_test",
    srcs = ["bowling_frame_test.cc"],
    deps = [
                ":bowling_frame",
                "@gtest//:gtest",
                "@gtest//:gtest_main" # Only if hello_test.cc has no main()
           ],
)

cc_test(
    name = "bowling_game_test",
    srcs = ["bowling_game_test.cc"],
    deps = [
               ":bowling_game",
               "@gtest//:gtest",
               "@gtest//:gtest_main",
           ],
)
