# C++ Testing
This project was made for fun to replicate a unit testing framework for c++.

# Example

## Code
```c++

int main() {
    auto tests = TestManager();

    tests.group("Test failures and successes", {
            {"This test will fail",   [](Assert &assert) {
                assert.equals(1, 2);
            }},
            {"This test will pass",   [](Assert &assert) {
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
            {"Test 4 is lower than 20", [](Assert &assert) {
                assert.isLowerThan(4, 20);
            }},
            {"Test 20 is greater than 4", [](Assert &assert) {
                assert.isGreaterThan(20, 4);
            }},
    });

    tests.run(TestManager::TestResultOutput::PRINT);

    return 0;
}
```

It is also possible to output the results to a file by using 

```c++
    tests.run(TestManager::TestResultOutput::PRINT);
```

## Output

Testing group: Test failures and successes with total of 2 tests

        1: Exception thrown at test This test will fail || exception= 1 doesn't match 2
        2: This test will pass passed the test

Group: Test failures and successes, results: passed 1/2


Testing group: Test equals and notEquals functions with total of 4 tests

        1: Test 20 equals 20 passed the test
        2: Test 4 not equals 20 passed the test
        3: Test hello is hello passed the test
        4: Test hello is not test passed the test

Group: Test equals and notEquals functions, results: passed 4/4


Testing group: Test isTrue and isFalse functions with total of 2 tests

        1: Test 4 == 4 passed the test
        2: Test 4 == 5 passed the test

Group: Test isTrue and isFalse functions, results: passed 2/2


Testing group: Test isLowerThan and isGreaterThan functions with total of 2 tests

        1: Test 20 is greater than 4 passed the test
        2: Test 4 is lower than 20 passed the test

Group: Test isLowerThan and isGreaterThan functions, results: passed 2/2


It took 0.0460274 seconds to complete 10 tests