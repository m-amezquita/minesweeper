
#include <minesweeper/grid.hpp>

int main() {
    Grid grid{ 12, 9, 65.0f };

    grid.generate(2, 3);

    return 0;
}
