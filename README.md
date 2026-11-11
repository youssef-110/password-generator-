# Password Generator

A small C++ command-line tool that prints strong random passwords from letters, digits
and symbols. It uses `std::random_device` (the operating system's entropy source), not
`rand()`, so the output cannot be predicted from the time it ran.

## Build and run

```bash
g++ -std=c++17 -O2 -o password_generator password_generator.cpp
./password_generator          # one 16-character password
./password_generator 24 5     # five 24-character passwords
```
