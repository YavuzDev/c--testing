#ifndef KIRAGED_UNIT_TESTING_TESTRESULT_H
#define KIRAGED_UNIT_TESTING_TESTRESULT_H


#include <string>

class TestResult {

private:
    bool error;

    int index;

    std::string_view name;

    std::string_view exception;

public:

    TestResult(bool error, int index, std::string_view name, std::string_view exception);

    TestResult(bool error, int index, std::string_view name);

    [[nodiscard]] bool isError() const;

    void setError(bool error);

    [[nodiscard]] int getIndex() const;

    void setIndex(int index);

    [[nodiscard]] const std::string_view &getName() const;

    void setName(const std::string_view &name);

    [[nodiscard]] const std::string_view &getException() const;

    void setException(const std::string_view &exception);
};


#endif //KIRAGED_UNIT_TESTING_TESTRESULT_H
