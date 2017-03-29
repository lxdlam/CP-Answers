#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool isRow(int col, int *cells)
{
    int times[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 9; i++)
    {
        times[cells[i * 9 + col]]--;
        if (times[cells[i * 9 + col]] < 0)
            return false;
    }
    return col == 8 ? true : isRow(col + 1, cells);
}

bool isCol(int row, int *cells)
{
    int times[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 9; i++)
    {
        times[cells[row * 9 + i]]--;
        if (times[cells[row * 9 + i]] < 0)
            return false;
    }
    return row == 8 ? true : isCol(row + 1, cells);
}

bool isSection(int sec, int *cells)
{
    int times[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = sec / 3 * 3; i <= sec / 3 * 3 + 2; i++)
    {
        for (int j = sec % 3 * 3; j <= sec % 3 * 3 + 2; j++)
        {
            times[cells[i * 9 + j]]--;
            if (times[cells[i * 9 + j]] < 0)
                return false;
        }
    }
    return sec == 8 ? true : isSection(sec + 1, cells);
}

TEST_CASE("is work")
{
    int cells[81] = {5,
                     8,
                     1,
                     4,
                     9,
                     3,
                     7,
                     6,
                     2,
                     9,
                     6,
                     3,
                     7,
                     1,
                     2,
                     5,
                     8,
                     4,
                     2,
                     7,
                     4,
                     8,
                     6,
                     5,
                     9,
                     3,
                     1,
                     1,
                     2,
                     9,
                     5,
                     4,
                     6,
                     3,
                     7,
                     8,
                     4,
                     3,
                     6,
                     1,
                     8,
                     7,
                     2,
                     9,
                     5,
                     7,
                     5,
                     8,
                     3,
                     2,
                     9,
                     1,
                     4,
                     6,
                     8,
                     9,
                     2,
                     6,
                     7,
                     1,
                     4,
                     5,
                     3,
                     6,
                     1,
                     5,
                     9,
                     3,
                     4,
                     8,
                     2,
                     7,
                     3,
                     4,
                     7,
                     2,
                     5,
                     8,
                     6,
                     1,
                     9};

    REQUIRE(isRow(0, cells) == true);
    REQUIRE(isCol(0, cells) == true);
    REQUIRE(isSection(0, cells) == true);
}