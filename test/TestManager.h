#ifndef KIRAGED_UNIT_TESTING_TESTMANAGER_H
#define KIRAGED_UNIT_TESTING_TESTMANAGER_H


#include "Group.h"


class TestManager {

private:
    std::vector<std::shared_ptr<Group>> groups;

public:

    enum TestResultOutput {
        PRINT,
        FILE,
    };

    void group(const std::string_view &name, const std::map<std::string_view, std::function<void(Assert &)>> &tests);

    void run(TestResultOutput testResult) const;

};


#endif //KIRAGED_UNIT_TESTING_TESTMANAGER_H
