#pragma once

#include <vector>
#include <fstream>

#include "Cell.hpp"
#include "Room.hpp"

class Board {
 private:
  int m_cols{};
  int m_rows{};

  using Cells = std::vector<Cell>;
  using Rooms = std::vector<Room>;

  Cells m_cells{};
  Rooms m_rooms{};

 public:
   Board() = delete;
   Board(std::ifstream);


  private:
   void parseMap(std::ifstream map);

};
