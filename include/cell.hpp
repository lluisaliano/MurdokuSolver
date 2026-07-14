#include <array>

enum class CellType {
  FREE,
  CHAIR,
  BED,
  TABLE,
  TV,
  PLANT,
};

enum Wall { LEFT, TOP, RIGHT, BOTTOM, NUM_WALLS };

using Walls = std::array<bool, NUM_WALLS>;

class Cell {
 private:
  CellType m_type{CellType::FREE};
  Walls m_walls{false, false, false, false};

 public:
  Cell() = default;
  explicit Cell(const CellType type, const Walls& walls)
      : m_type{type}, m_walls{walls} {};

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

  Walls getWalls() { return m_walls; }
};
