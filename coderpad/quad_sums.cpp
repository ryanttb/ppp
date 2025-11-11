#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>

std::vector<int> find_quadruplet_sum(const std::vector<int>& numbers, int target) {
    for (int a : numbers) {
        for (int b : numbers) {
            for (int c : numbers) {
                for (int d : numbers) {
                    if (a + b + c + d == target) {
                        return {a, b, c, d};
                    }
                }
            }
        }
    }
    return {};
}

std::vector<int> find_quadruplet_sum_fast(const std::vector<int>& numbers, int target) {
    // TODO: Implement a faster version of the function

    std::set<int> singleCache;

    for (int d : numbers) {
      singleCache.insert(d);
    }

    for (int a : numbers) {
        for (int b : numbers) {
            for (int c : numbers) {
              int cur = a + b + c;
              if (singleCache.contains(target - cur)) {
                return {a, b, c, target - cur};
              }
            }
        }
    }
    return {};
}

void run_testcase(const std::vector<int>& numbers, int target, const std::string& testcase_name) {
    std::cout << testcase_name << " - ";
    std::cout.flush();
    clock_t t0 = clock();
    std::vector<int> result = find_quadruplet_sum_fast(numbers, target);
    double elapsed = static_cast<double>(clock() - t0) / CLOCKS_PER_SEC;

    if (result.size() != 4) {
        std::cout << "FAILED: the result has " << result.size() << " elements, not 4" << std::endl;
        std::exit(1);
    }

    int sum = std::accumulate(result.begin(), result.end(), 0);

    if (sum != target) {
        std::cout << "FAILED: the sum of {";
        for (int r : result) std::cout << r << ", ";
        std::cout << "} is " << sum << ", not " << target << std::endl;
        std::exit(1);
    }

    for (int r : result) {
        if (std::find(numbers.begin(), numbers.end(), r) == numbers.end()) {
            std::cout << "FAILED: one of the numbers is not in the list" << std::endl;
            std::exit(1);
        }
    }

    std::cout << "PASSED" << std::endl;
}

int main() {
    run_testcase({5, 4, 3, 2, 1, 0}, 11, "Small testcase");
    run_testcase({54, 3, 42, 16, 4, 24}, 90, "Solution with duplicates");
    run_testcase({89, -62, -92, -37, 28, 29}, -7, "With negative numbers");
    run_testcase({39, -57, -53, -79, 83, -6, 27, -97}, 0, "Target is zero");

    for (int i = 1; i <= 5; ++i) {
        std::vector<int> numbers(1000);
        std::generate(numbers.begin(), numbers.end(), []() { return rand() % 200000000 - 100000000; });
        int target = std::accumulate(numbers.end() - 4, numbers.end(), 0);
        std::random_shuffle(numbers.begin(), numbers.end());
        run_testcase(numbers, target, "Large test #" + std::to_string(i));
    }

    std::cout << "Congratulations. You passed all testcases!" << std::endl;
    return 0;
}