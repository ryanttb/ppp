#include <stdexcept>

void do_it(int var) {
    if (var <= 0) {
        throw std::runtime_error("var");
    }
}

int main() {

    do_it(0);

    /* MacOS
     *
     * [200~libc++abi: terminating with uncaught exception of type std::runtime_error: var
     * zsh: abort      ./tt63-x
     */

    return 0;
}
