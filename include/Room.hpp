#pragma once

#include <vector>

#include "Cell.hpp"

class Room {
 private:
  std::vector<Cell> m_cells{};

 public:
   explicit Room(Cell cells): m_cells{cells} {};
};
