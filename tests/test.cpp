#include <gtest/gtest.h>

#include "../src/storage.h"

TEST(Storage, Contains)
{
    Storage storage;
    storage.set("Name", "Michak");
    EXPECT_EQ(0, storage.contain("Name"));
}

TEST(Storage, Get)
{
    Storage storage;
    storage.set("Name", "Michak");

    std::string gotName;

    EXPECT_EQ(0, storage.get("Name", gotName));
    EXPECT_EQ(gotName, "Michak");
}

TEST(Storage, Remove)
{
    Storage storage;
    storage.set("Name", "Michak");

    EXPECT_EQ(0, storage.remove("Name"));
    EXPECT_EQ(-1, storage.remove("Name"));
}