#pragma once

#include <cstdint>

enum class CellType {
  FREE,  //0
  CHAIR, //1
  BED,   //2
  TABLE, //3
  TV,    //4
  PLANT, //5
};

// Use bits to represent the existance of walls
enum Wall: uint8_t { LEFT = 1<<0, TOP = 1<<1, RIGHT = 1<<2, BOTTOM = 1 << 3};

class Cell {
 private:
  using Walls = uint8_t;
  Walls m_walls{};
  CellType m_type{CellType::FREE};

 public:
  Cell() = default;
  explicit Cell(const Walls walls, const CellType type)
      : m_walls{walls}, m_type{type} {}

  bool isFree() {
    switch (m_type) {
      case CellType::FREE:
      case CellType::CHAIR:
      case CellType::BED:
        return true;
      default:
        return false;
    }
  }

  bool hasWall(Wall wall) const {
      return (m_walls & wall) != 0;
  }

  Walls getWalls() { return m_walls; }
};
