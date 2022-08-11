#include <future>
#include <fstream>
#include <iostream>
#include "TestManager.h"


int totalTests(const std::vector<std::shared_ptr<Group>> &groups) {
    int total = 0;
    for (const auto &group: groups) {
        total += static_cast<int>(group->getTests().size());
    }
    return total;
}

void TestManager::group(const std::string_view &name,
                        const std::map<std::string_view, std::function<void(Assert &)>> &tests) {
    std::map<std::string_view, std::function<void(Assert &)>> nonConsts;
    for (auto const &x: tests) {
        nonConsts[x.first] = x.second;
    }
    this->groups.push_back(std::make_shared<Group>(name, nonConsts));
}

void TestManager::run(TestResultOutput testResult) const {
    const auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::shared_future<void>> asyncCalls;
    for (const auto &group: this->groups) {
        std::shared_future<void> call = std::async(std::launch::async, &Group::run, group);
        asyncCalls.push_back(call);
    }
    for (const auto &calls: asyncCalls) {
        calls.get();
    }
    if (testResult == TestResultOutput::FILE) {
        std::ofstream file("results.txt");
        remove("results.txt");

        if (!file.is_open()) {
            throw std::runtime_error("Can't open file");
        }

        for (const auto &group: groups) {
            group->printResults(file);
        }

        file.close();
    } else {
        for (const auto &group: groups) {
            group->printResults(std::cout);
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << "\n" << "It took " << duration.count() << " seconds to complete " << totalTests(this->groups)
              << " tests" << std::flush;
}
