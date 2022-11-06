//
// Created by ic on 2022/11/06.
//

#include <Commander.h>

#include "gtest/gtest.h"

TEST(CommanderTestSuite, getHP){
    Commander* commander = new Commander("Jack");

    EXPECT_EQ(commander->getDamage(),24);
    commander->receiveDamage(5);
    EXPECT_EQ(commander->getDamage(),34);
    EXPECT_EQ(commander->getHP(),500);

}