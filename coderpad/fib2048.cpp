#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class The2048Bonacci {
public:
    The2048Bonacci(const std::vector<std::vector<int>>& game_area)
        : game_area(game_area),
          width(game_area[0].size()),
          height(game_area.size()),
          fib_cache({1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144}) {
    }

    /**
     * \return whether or not something moved
     */
    bool push(Direction d) {
      bool moved{false};

      clear_merged_map();

      switch (d) {
        case Direction::LEFT:
        case Direction::RIGHT:
          for (size_t row = 0; row < height; ++row) {
            bool row_moved = push_row(row, d);
            moved = moved || row_moved;
          }
          break;
        case Direction::UP:
        case Direction::DOWN:
          for (size_t col = 0; col < width; ++col) {
            bool col_moved = push_col(col, d);
            moved = moved || col_moved;
          }
          break;
        default:
          break;
      }

      return moved;
    }

    int get_tile(int x, int y) const {
        return game_area[y][x];
    }

    void set_tile(int x, int y, int fib_value) {
        game_area[y][x] = fib_value;
    }

    std::string get_description() const {
        std::ostringstream oss;
        for (const auto& line : game_area) {
            for (const auto& fib_val : line) {
                oss << " " << std::setw(2) << fib_val;
            }
            oss << "\n";
        }
        return oss.str();
    }

    /**
     * \brief   return the next fib value
     * Find the index of the fib, return the next fib (calculate if necissary)
     */
    int next_fib(int fib) {
      if (fib == 1) {
        return 2;
      }

      auto it = find(fib_cache.begin(), fib_cache.end(), fib);

      if (it == fib_cache.end()) {
        cerr << "next_fib fib: -1" << endl; // expected fib not found in cache
        return -1;
      }

      if (it + 1 == fib_cache.end()) {
        // compute next fib, cache, and return
        cerr << "next_fib ret: compute" << endl;
        return fib + 1; // fake for now
      }

      return *(it + 1);
    }


    /**
     * \brief   true if a and b are one away from each other in fib 
     * Brute force for now, O(n)
     */
    bool can_merge(int a, int b) {
      if (a == 1 && b == 1) {
        // special case 1
        return true;
      }

      auto a_it = find(fib_cache.begin(), fib_cache.end(), a);
      auto b_it = find(fib_cache.begin(), fib_cache.end(), b);
      int diff = abs(a_it - fib_cache.begin() - (b_it - fib_cache.begin()));
      return diff == 1;

    }


private:
    void clear_merged_map() {
      std::vector<int> empty_row;
      empty_row.assign(width, 0);
      merged_map.assign(height, empty_row);
    }

    /**
     * \brief   find the next number AFTER or BEFORE the start column
     * \return  the number's index or -1
     */
    int find_next_col(int row, int start, Direction d) {
      int inc_dir{1};

      if (d == Direction::RIGHT) {
        inc_dir = -1;
      }

      for (size_t col = start + inc_dir; col < width && col >= 0; col += inc_dir) {
        if (game_area[row][col] > 0) {
          return col;
        }
      }
      return -1;
    }

    bool push_row(int row, Direction d) {
      bool moved{false};

      size_t start_col{0};
      int inc_dir{1};

      if (d == Direction::RIGHT) {
        start_col = width - 1;
        inc_dir = -1;
      }

      for (size_t col{start_col}; col < width && col >= 0; /* inc in loop */) {        
        int cur_val = game_area[row][col];

        int next_col = find_next_col(row, col, d);
        //cout << "row: " << row << ", col: " << col << ", next_col: " << next_col << endl;

        if (next_col >= 0) {
          int next_val = game_area[row][next_col];
          //cout << "row: " << row << ", next_val: " << next_val << endl; 

          if (cur_val == 0) {
            // move next_col to here, repeat this col
            game_area[row][col] = next_val;
            game_area[row][next_col] = 0;
            moved = true;
          } else if (can_merge(cur_val, next_val)) {
            // merge next_col to here, continue
            game_area[row][col] = next_fib(max(cur_val, next_val));
            game_area[row][next_col] = 0;
            moved = true;
            col += inc_dir;
          } else {
            // next_col cannot move or be merged, continue
            col += inc_dir;
          }
        } else {
          col += inc_dir;
        }
      }

      return moved;
    }

    /**
     * \brief   find the next number AFTER or BEFORE the start row
     * \return  the number's index or -1
     */
    int find_next_row(int start, int col, Direction d) {
      int inc_dir{1};

      if (d == Direction::DOWN) {
        inc_dir = -1;
      }

      for (size_t row = start + inc_dir; row < height && row >= 0; row += inc_dir) {
        if (game_area[row][col] > 0) {
          return row;
        }
      }
      return -1;
    }

    bool push_col(int col, Direction d) {
      bool moved{false};

      size_t start_row{0};
      int inc_dir{1};

      if (d == Direction::DOWN) {
        start_row = height - 1;
        inc_dir = -1;
      }

      for (size_t row{start_row}; row < height && row >= 0; /* inc in loop */) {        
        int cur_val = game_area[row][col];

        int next_row = find_next_row(row, col, d);
        //cout << "row: " << row << ", col: " << col << ", next_row: " << next_row << endl;

        if (next_row >= 0) {
          int next_val = game_area[next_row][col];
          //cout << "row: " << row << ", next_val: " << next_val << endl; 

          if (cur_val == 0) {
            // move next_row to here, repeat this row
            game_area[row][col] = next_val;
            game_area[next_row][col] = 0;
            moved = true;
          } else if (can_merge(cur_val, next_val)) {
            // merge next_row to here, continue
            game_area[row][col] = next_fib(max(cur_val, next_val));
            game_area[next_row][col] = 0;
            moved = true;
            row += inc_dir;
          } else {
            // next_col cannot move or be merged, continue
            row += inc_dir;
          }
        } else {
          row += inc_dir;
        }
      }

      return moved;
    }

    std::vector<std::vector<int>> game_area;
    size_t width;
    size_t height;

    std::vector<std::vector<int>> merged_map;

    vector<int> fib_cache;
};

int main() {
    std::vector<std::vector<int>> game_area = {
        { 0, 1, 0, 0 },
        { 0, 0, 13, 0 },
        { 0, 1, 0, 1 },
        { 5, 2, 1, 0 }
    };

    The2048Bonacci game(game_area);

    /*
    cout << "can_merge(1, 1): " << game.can_merge(1, 1) << endl;
    cout << "can_merge(1, 2): " << game.can_merge(1, 2) << endl;
    cout << "can_merge(13, 8): " << game.can_merge(13, 8) << endl;
    cout << "can_merge(5, 13): " << game.can_merge(5, 13) << endl;
    */

    /*
    cout << "next_fib(1): " << game.next_fib(1) << endl;
    cout << "next_fib(2): " << game.next_fib(2) << endl;
    cout << "next_fib(3): " << game.next_fib(3) << endl;
    cout << "next_fib(5): " << game.next_fib(5) << endl;
    cout << "next_fib(8): " << game.next_fib(8) << endl;
    cout << "next_fib(13): " << game.next_fib(13) << endl;
    */
    
    std::cout << game.get_description() << std::endl;

    game.push(Direction::UP);
    std::cout << game.get_description() << std::endl;

    game.push(Direction::DOWN);
    std::cout << game.get_description() << std::endl;

    return 0;
}