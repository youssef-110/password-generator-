// Password generator: prints strong random passwords.
// Usage: password_generator [length] [count]   (defaults: 16 characters, 1 password)

#include <iostream>
#include <random>
#include <string>

int main(int argc, char* argv[])
{
    const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "~`!@#$%^&*()_+-={}|[]:>?<;.,";

    int length = argc > 1 ? std::atoi(argv[1]) : 16;
    int count = argc > 2 ? std::atoi(argv[2]) : 1;
    if (length < 4 || length > 256 || count < 1 || count > 100) {
        std::cerr << "Usage: password_generator [length 4-256] [count 1-100]\n";
        return 1;
    }

    // random_device draws from the OS entropy source, unlike rand(), which is predictable.
    std::random_device rd;
    std::uniform_int_distribution<std::size_t> pick(0, chars.size() - 1);

    for (int n = 0; n < count; ++n) {
        std::string password;
        for (int i = 0; i < length; ++i) password += chars[pick(rd)];
        std::cout << password << '\n';
    }
    return 0;
}
