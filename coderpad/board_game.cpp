// https://app.coderpad.io/94YXRXDY

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <tuple>

using namespace std;

class TilePosError : public std::runtime_error {
public:
    TilePosError() : std::runtime_error("Tile position error") {}
};

enum class Direction {
    UP = 0,
    UP_RIGHT = 1,
    RIGHT = 2,
    DOWN_RIGHT = 3,
    DOWN = 4,
    DOWN_LEFT = 5,
    LEFT = 6,
    UP_LEFT = 7
};

std::vector<Direction> ALL_DIRS = {
    Direction::UP, Direction::UP_RIGHT, Direction::RIGHT, Direction::DOWN_RIGHT,
    Direction::DOWN, Direction::DOWN_LEFT, Direction::LEFT, Direction::UP_LEFT
};

std::vector<Direction> CARDINAL_DIRS = {
    Direction::UP, Direction::RIGHT, Direction::DOWN, Direction::LEFT
};

std::vector<Direction> DIAGONAL_DIRS = {
    Direction::UP_RIGHT, Direction::DOWN_RIGHT, Direction::DOWN_LEFT, Direction::UP_LEFT
};

class Board;

class Tile {
public:
    Tile(char char_data = ' ') : char_data(char_data), adjacencies(8, nullptr) {}

    Tile* get_adjacent(Direction direction) {
        Tile* adj_tile = adjacencies[static_cast<int>(direction)];
        if (adj_tile == nullptr) {
            throw TilePosError();
        }
        return adj_tile;
    }

    void set_adjacencies(Board* board_owner, int x, int y);

    char char_data;
    std::vector<Tile*> adjacencies;
};

class Board {
public:
    Board(int width, int height) : width(width), height(height) {
        _tiles.resize(height, std::vector<Tile>(width));
        set_adjacencies();
    }

    Tile& get_tile(int x, int y) {
        if (x + _index_offset < 0 || x + _index_offset >= width || y + _index_offset < 0 || y + _index_offset >= height) {
            throw TilePosError();
        }
        return _tiles[y + _index_offset][x + _index_offset];
    }

    /**
     * \brief   Add a new Tile to the board adjacent to an existing tile
     * \throws  TilePosError if board has size but start tile does not exist
     * Tile at either must exist or the board must be empty,
     * in which case the board will be started with a new tile and its position is 0, 0
     */
    Tile* add_tile(int x, int y, Direction d, char data) {
      Tile* new_tile = nullptr;

      if (width == 0 && height == 0) {
        width = 1;
        height = 1;
        _index_offset = 0;
        _tiles.resize(height, vector<Tile>(width));
        _tiles[y][x].char_data = data;
        new_tile = &_tiles[y][x];
        set_adjacencies();
      } else if (x < width && y < height) {
        Tile& t = get_tile(x, y);
        bool expand{false};

        try {
          Tile* adj_tile = t.get_adjacent(d);
          adj_tile->char_data = data;
          new_tile = adj_tile;
        } catch(TilePosError&) {
          cerr << "TODO: Add to board and retry" << endl;
          expand = true;
        }

        if (expand) {
          cerr << "TODO: expand" << endl;
          //_tiles.insert(_tiles.begin(), vector<Tile>(width));
          _tiles.push_back(vector<Tile>(width));
          cerr << "  tiles.size: " << _tiles.size() << endl;

          for (auto& row : _tiles) {
            //row.insert(row.begin(), Tile());
            row.push_back(Tile());
            cerr << "  row.size: " << row.size() << endl;
          }
          width += 1;
          height += 1;
          //++_index_offset;
          set_adjacencies();
          return add_tile(x, y, d, data);
        }
      } else {
        throw TilePosError();
      }
      return new_tile;
    }

    std::string render() {
      cout << "width: " << width << ", height: " << height << endl;

        std::string str_rendered_board;
        //cerr << "rows.size: " << _tiles.size() << endl;
        for (int y = 0; y < height; ++y) {
          //cerr << "row[" << y << "].size: " << _tiles[y].size() << endl;
        
            for (int x = 0; x < width; ++x) {
                str_rendered_board += _tiles[y][x].char_data;
            }
            str_rendered_board += '\n';
        }
        return str_rendered_board;
    }

    Tile& operator()(int x, int y) {
        return get_tile(x, y);
    }


    void set_adjacencies() {
      for (int y = 0; y < height; ++y) {
          for (int x = 0; x < width; ++x) {
              _tiles[y][x].set_adjacencies(this, x, y);
          }
      }
    }

    int width, height;

private:
    int _index_offset{0}; //< as we expand negative, we want to keep 0 where it was
    std::vector<std::vector<Tile>> _tiles;
};

void Tile::set_adjacencies(Board* board_owner, int x, int y) {
    static const std::vector<std::tuple<Direction, int, int>> direction_offset_coords = {
        {Direction::UP, 0, -1}, {Direction::UP_RIGHT, 1, -1}, {Direction::RIGHT, 1, 0},
        {Direction::DOWN_RIGHT, 1, 1}, {Direction::DOWN, 0, 1}, {Direction::DOWN_LEFT, -1, 1},
        {Direction::LEFT, -1, 0}, {Direction::UP_LEFT, -1, -1}
    };

    for (const auto& [direc, offset_x, offset_y] : direction_offset_coords) {
        try {
            Tile& adj_tile = board_owner->get_tile(x + offset_x, y + offset_y);
            adjacencies[static_cast<int>(direc)] = &adj_tile;
        } catch (TilePosError&) {
            // pass
        }
    }
}

void test_chess() {
    Board chess_board(8, 8);
    chess_board(7, 2).char_data = 'B';
    chess_board(3, 4).char_data = 'Q';

    std::string arrows = "^/>\\|/<\\";
    for (size_t i = 0; i < ALL_DIRS.size(); ++i) {
        Direction direc = ALL_DIRS[i];
        char char_arrow = arrows[i];
        Tile* tile = &chess_board(3, 4);
        try {
            while (true) {
                tile = tile->get_adjacent(direc);
                tile->char_data = char_arrow;
            }
        } catch (TilePosError&) {
            // pass
        }
    }

    std::string render_reference =
        "   ^   /\n"
        "\\  ^  / \n"
        " \\ ^ / B\n"
        "  \\^/   \n"
        "<<<Q>>>>\n"
        "  /|\\   \n"
        " / | \\  \n"
        "/  |  \\ \n";
    std::string render_test = chess_board.render();
    std::cout << render_test;
    if (render_test == render_reference) {
        std::cout << "Render test passed!" << std::endl;
    } else {
        std::cout << "Render test failed!" << std::endl;
    }
}

void test_minesweeper() {
  const char MINE = '*';
  const string MINE_COUNTS = " 123456789";
  const int WIDTH = 9;
  const int HEIGHT = 9;

  Board mine_sweeper(WIDTH, HEIGHT);
  mine_sweeper(7, 0).char_data = MINE;
  mine_sweeper(0, 3).char_data = MINE;
  mine_sweeper(1, 3).char_data = MINE;
  mine_sweeper(1, 4).char_data = MINE;

  for (int x = 0; x < WIDTH; ++x) {
    for (int y = 0; y < HEIGHT; ++y) {
      Tile& t = mine_sweeper(x, y);
      if (t.char_data == ' ') {
        int adj_mine_count{0};
        for (Direction d : ALL_DIRS) {
          try {
            Tile* dt = t.get_adjacent(d);
            if (dt->char_data == MINE) {
              ++adj_mine_count;
            }
            t.char_data = MINE_COUNTS[adj_mine_count];
          } catch (TilePosError&) {
            // pass
          }
        }
      }
    }
  }

  string render_test = mine_sweeper.render();
  cout << render_test << endl;
}

void test_carcassonne() {
  Board carcassonne(0, 0);
  enum DataTypes {
    Land, Road, Castle
  };
  const string DATA_CHARS = "LRC";

  cout << carcassonne.render() << endl;

  carcassonne.add_tile(0, 0, Direction::DOWN, DATA_CHARS[DataTypes::Land]);
  cout << carcassonne.render() << endl;

  carcassonne.add_tile(0, 0, Direction::DOWN, DATA_CHARS[DataTypes::Land]);
  cout << carcassonne.render() << endl;

  //carcassonne.add_tile(0, 0, Direction::LEFT, DATA_CHARS[DataTypes::Castle]);
  //cout << carcassonne.render() << endl;

}

int main() {
  try {
    test_carcassonne();
  } catch (TilePosError& err) {
    cerr << err.what() << endl;
  }
  return 0;
}
