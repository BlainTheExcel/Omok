#include "pch.h"
#include "../omok/Game.h"
#include "../omok/Location.h"
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(ValidateLocation, Valid) {
	Game game;

	game.setRock(Location(1,2));
	//EXPECT_TRUE(game.validateLocation(Location(1,3)));
}

TEST(Turn, changeTurn) {
	Game game;

	EXPECT_TRUE(game.getTurn());
	game.changeTurn();
	EXPECT_FALSE(game.getTurn());
	game.changeTurn();
	EXPECT_TRUE(game.getTurn());

}