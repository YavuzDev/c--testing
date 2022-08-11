#include "Group.h"

Group::Group(std::string_view name, std::map<std::string_view, std::function<void(Assert &)>> tests) : name(name),
                                                                                                       tests(std::move(
                                                                                                               tests)) {}

void Group::run() {
    for (const auto &x: this->tests) {
        this->count++;
        Assert assert;
        try {
            x.second(assert);
            results[count] = std::make_shared<TestResult>(false, count, x.first);
            this->passed++;
        } catch (std::exception &e) {
            results[count] = std::make_shared<TestResult>(true, count, x.first, e.what());
        }
    }
}

void Group::printResults(std::ostream &stream) {
    stream << "\nTesting group: " << this->name << " with total of " << this->tests.size() << " tests \n\n";

    for (const auto &result: this->results) {
        if (result.second->isError()) {
            stream << "\t" << result.first << ": " "Exception thrown at test " << result.second->getName()
                   << " || exception= "
                   << std::flush;
            stream << result.second->getException() << "\n";
        } else {
            stream << "\t" << result.first << ": " << result.second->getName() << " passed the test " << "\n";
        }
    }

    const auto passedTests = std::count_if(this->results.begin(), this->results.end(), [](const auto &result) {
        return !result.second->isError();
    });

    stream << "\nGroup: " << this->name << ", results: passed " << passedTests << "/"
           << this->tests.size() << "\n\n";
}

const std::map<std::string_view, std::function<void(Assert &)>> &Group::getTests() const {
    return tests;
}
