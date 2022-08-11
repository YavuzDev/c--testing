#ifndef KIRAGED_UNIT_TESTING_ASSERT_H
#define KIRAGED_UNIT_TESTING_ASSERT_H


#include <exception>
#include <stdexcept>
#include <sstream>
#include <functional>
#include <iostream>

class Assert {

private:
    template<typename T, typename S>
    std::string printFirstAndSecond(T first, const std::string &message, S second) {
        std::stringstream ss;
        ss << first;
        ss << message;
        ss << second;
        return ss.str();
    }

    template<typename T>
    std::string printFirst(T first, const std::string &message) {
        std::stringstream ss;
        ss << first;
        ss << message;
        return ss.str();
    }

public:

    template<typename T, typename S>
    bool equals(const T actual, const S expected) {
        if (actual != expected) {
            std::cout << "here" << std::endl;
            throw std::runtime_error(printFirstAndSecond(actual, " doesn't match ", expected));
        }
        return true;
    }

    template<typename T, typename S>
    bool notEquals(const T actual, const S expected) {
        if (actual == expected) {
            throw std::runtime_error(printFirstAndSecond(actual, " matches ", expected));
        }
        return true;
    }

    template<typename T, typename S>
    bool isGreaterThan(const T value, const S toBeGreaterThan) {
        if (value <= toBeGreaterThan) {
            throw std::runtime_error(printFirstAndSecond(value, " isn't greater than ", toBeGreaterThan));
        }
        return true;
    }

    template<typename T, typename S>
    bool isGreaterThanEquals(const T value, const S toBeGreaterThanEquals) {
        if (value < toBeGreaterThanEquals) {
            throw std::runtime_error(
                    printFirstAndSecond(value, " isn't greater than or equals ", toBeGreaterThanEquals));
        }
        return true;
    }

    template<typename T, typename S>
    bool isLowerThan(const T value, const S tobeLowerThan) {
        if (value >= tobeLowerThan) {
            throw std::runtime_error(printFirstAndSecond(value, " isn't lower than ", tobeLowerThan));
        }
        return true;
    }

    template<typename T, typename S>
    bool isLowerThanEquals(const T value, const S tobeLowerThanEquals) {
        if (value > tobeLowerThanEquals) {
            throw std::runtime_error(printFirstAndSecond(value, " isn't lower than or equals", tobeLowerThanEquals));
        }
        return true;
    }

    template<typename T>
    bool isNotNull(const T value) {
        if (value == nullptr) {
            throw std::runtime_error(printFirst(value, " is null "));
        }
        return true;
    }

    template<typename T>
    bool isNull(const T value) {
        if (value != nullptr) {
            throw std::runtime_error(printFirst(value, " is not null "));
        }
        return true;
    }

    bool isTrue(const bool value) {
        if (!value) {
            throw std::runtime_error(printFirst(value, " is false "));
        }
        return true;
    }

    bool isFalse(const bool value) {
        if (value) {
            throw std::runtime_error(printFirst(value, " is true "));
        }
        return true;
    }
};


#endif //KIRAGED_UNIT_TESTING_ASSERT_H
