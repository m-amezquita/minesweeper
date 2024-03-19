
#include <catch2/catch_test_macros.hpp>
#include <minesweeper/grid.hpp>

SCENARIO("Player play the first cell", "[Grid]")
{
    GIVEN("A grid 10x10 with 50% bomb rate")
    {
        Grid grid{10, 10, 50.0};

        WHEN("Generate with the cell 5,5")
        {
            grid.generate(5, 5);

            THEN("In the cell 5,5 there's no bomb")
            {
                REQUIRE(grid.cell(5, 5) != CellType::bomb);
            }
        }

        WHEN("Generate with the cell 0,0")
        {
            grid.generate(0, 0);

            THEN("In the cell 0,0 there's no bomb")
            {
                REQUIRE(grid.cell(0, 0) != CellType::bomb);
            }
        }

        WHEN("Generate with the cell 9,9")
        {
            grid.generate(9, 9);

            THEN("In the cell 9,9 there's no bomb")
            {
                REQUIRE(grid.cell(9, 9) != CellType::bomb);
            }
        }
    }
}

SCENARIO("Grid bomb rate setted is real", "[Grid]")
{
    GIVEN("A grid 10x10 with 50% bomb rate")
    {
        Grid grid{10, 10, 50.0};

        WHEN("Generate the bombs")
        {
            grid.generate(5, 5);

            THEN("Bomb count must be 50")
            {
                REQUIRE(grid.bomb_count() == 50);
            }
        }
    }

    GIVEN("A grid 10x10 with 50% bomb rate")
    {
        Grid grid{10, 10, 90.0};

        WHEN("Generate the bombs")
        {
            grid.generate(9, 9);

            THEN("Bomb count must be 90")
            {
                REQUIRE(grid.bomb_count() == 90);
            }
        }
    }
}

SCENARIO("", "[Grid]") {
     
}