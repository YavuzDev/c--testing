#ifndef KIRAGED_UNIT_TESTING_GROUP_H
#define KIRAGED_UNIT_TESTING_GROUP_H


#include <map>
#include <memory>
#include "Assert.h"
#include "TestResult.h"

class Group {

private:
    std::string_view name;

    std::map<std::string_view, std::function<void(Assert &)>> tests;

    int passed = 0;

    int count = 0;

    std::map<int, std::shared_ptr<TestResult>> results;

public:
    Group(std::string_view name, std::map<std::string_view, std::function<void(Assert &)>> tests);

    void run();

    void printResults(std::ostream &stream);

    [[nodiscard]] const std::map<std::string_view, std::function<void(Assert &)>> &getTests() const;
};


#endif //KIRAGED_UNIT_TESTING_GROUP_H
