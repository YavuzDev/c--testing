#include "TestResult.h"


TestResult::TestResult(bool error, int index, std::string_view name, std::string_view exception) : error(error),
                                                                                                   index(index),
                                                                                                   name(name),
                                                                                                   exception(
                                                                                                           exception) {}

TestResult::TestResult(bool error, int index, std::string_view name) : error(error), index(index), name(name) {}


bool TestResult::isError() const {
    return error;
}

void TestResult::setError(bool error) {
    TestResult::error = error;
}

int TestResult::getIndex() const {
    return index;
}

void TestResult::setIndex(int index) {
    TestResult::index = index;
}

const std::string_view &TestResult::getName() const {
    return name;
}

void TestResult::setName(const std::string_view &name) {
    TestResult::name = name;
}

const std::string_view &TestResult::getException() const {
    return exception;
}

void TestResult::setException(const std::string_view &exception) {
    TestResult::exception = exception;
}

