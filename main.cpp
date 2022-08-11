#include "test/TestManager.h"

int main() {
    auto tests = TestManager();

    tests.group("Test failures and successes", {
            {"This test will fail", [](Assert &assert) {
                assert.equals(1, 2);
            }},
            {"This test will pass", [](Assert &assert) {
                assert.equals(1, 1);
            }},
    });

    tests.group("Test equals and notEquals functions", {
            {"Test 4 not equals 20",   [](Assert &assert) {
                assert.notEquals(4, 20);
            }},
            {"Test 20 equals 20",      [](Assert &assert) {
                assert.equals(20, 20);
            }},
            {"Test hello is not test", [](Assert &assert) {
                assert.notEquals("hello", "test");
            }},
            {"Test hello is hello",    [](Assert &assert) {
                assert.equals("hello", "hello");
            }},
    });

    tests.group("Test isTrue and isFalse functions", {
            {"Test 4 == 4", [](Assert &assert) {
                assert.isTrue(4 == 4);
            }},
            {"Test 4 == 5", [](Assert &assert) {
                assert.isFalse(4 == 5);
            }},
    });

    tests.group("Test isLowerThan and isGreaterThan functions", {
            {"Test 4 is lower than 20",   [](Assert &assert) {
                assert.isLowerThan(4, 20);
            }},
            {"Test 20 is greater than 4", [](Assert &assert) {
                assert.isGreaterThan(20, 4);
            }},
    });

    tests.run(TestManager::TestResultOutput::PRINT);

    return 0;
}
