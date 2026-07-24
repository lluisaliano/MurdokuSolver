#include "Board.hpp"

#include <cstdint>
#include <cstdio>
#include <fstream>
#include <print>

#include "Cell.hpp"

Board::Board(std::ifstream map) {
  m_cells.reserve(static_cast<std::size_t>(m_rows * m_cols));
  parseMap(std::move(map));
}

void Board::parseMap(std::ifstream map) {
  int rows{0};
  int cols{1};  // Start from one as we will count spaces as cols

  char c{};
  bool wallRead{false};  // First we will always read wall and once it is done
                         // we will add the cell
  int walls{};
  bool formatError{false};
  bool rowHasContent{false};
  while (map.get(c)) {
    if (c == '\n') {
      if (wallRead) { // If we read wall but not the cellType and we found a '\n', we have a formatting error
        formatError = true;
        break;
      }
      if (rowHasContent) {
        ++rows;
      }
      rowHasContent = false;  // Reset to false when starting a new row
      continue;
    };
    if (c == ' ') {
      if (wallRead) { // If we read wall but not the cellType and we found a '\n', we have a formatting error
        formatError = true;
        break;
      }
      // Set columns for the first time
      if (rows == 0) {
        ++cols;  // TODO USER SHOULD INPUT THIS INSTEAD OF COUNTING IT, OR WE
                 // MAY FAIL ON NOT QUADRICULAR MAPS
      }
      continue;
    };

    if (!wallRead) {
      if (c >= '0' && c <= '9') {
        walls = c - '0';  // We get the wall number because ascii subtracting
                          // works good for one digit
      } else if (c >= 'A' && c <= 'F') {
        walls = 10 + (c - 'A');  // If We have A until F, we subtract to get
                                 // the unit and then add 10
      } else {
        formatError = true;
        break;
      }
      wallRead = true;
    } else {
      if (c >= '0' && c <= '5') {
        CellType cellType{static_cast<CellType>(c - '0')};  // Same here
        m_cells.push_back(Cell{static_cast<uint8_t>(walls), cellType});
        wallRead = false;
        rowHasContent =
            true;  // Track that this row has content to add one to the counter
      } else {
        formatError = true;
        break;
      }
    }
  }
  if (map.eof() &&
      !wallRead) {  // If we are at the ond of stream and wallRead is set to
                    // false, meaning that we read last Celltype
    m_cols = cols;
    m_rows = rows;
    if (rowHasContent) {
      ++m_rows;
    }  // If map did not have a final \n, and ended on a char, we just add one
       // row more to count that line
    std::println("Map parsed correctly");
  } else {
    if (formatError) {
      std::println(stderr, "Some error on parsing ocurred");
    } else {
      std::println(stderr, "Some error with input file ocurred");
    }
  }
}
