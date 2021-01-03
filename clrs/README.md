# Introduction to Algorithms - CLRS #

This contains section-wise problems for each chapter in CLRS

## How to run ##

- RUN ALL TESTS: make test
- CREATE TEST BINARY: make -f makefile.test
- RUN TESTS FROM BINARY: make -f makefile.test && ./testall
- RUN SPECIFIC TESTS: --Refer Below--

## Googletest - Running a Subset of the Tests ##

By default, a googletest program runs all tests the user has defined. Sometimes, you want to run only a subset of the tests (e.g. for debugging or quickly verifying a change). If you set the GTEST_FILTER environment variable or the --gtest_filter flag to a filter string, googletest will only run the tests whose full names (in the form of TestSuiteName.TestName) match the filter.

A pattern may contain '*' (matches any string) or '?' (matches any single character). For convenience, the filter '*-NegativePatterns' can be also written as '-NegativePatterns'.

For example:

    ./foo_test Has no flag, and thus runs all its tests.
    ./foo_test --gtest_filter=* Also runs everything, due to the single match-everything * value.
    ./foo_test --gtest_filter=FooTest.* Runs everything in test suite FooTest .
    ./foo_test --gtest_filter=*Null*:*Constructor* Runs any test whose full name contains either "Null" or "Constructor" .
    ./foo_test --gtest_filter=-*DeathTest.* Runs all non-death tests.
    ./foo_test --gtest_filter=FooTest.*-FooTest.Bar Runs everything in test suite FooTest except FooTest.Bar.
    ./foo_test --gtest_filter=FooTest.*:BarTest.*-FooTest.Bar:BarTest.Foo Runs everything in test suite FooTest except FooTest.Bar and everything in test suite BarTest except BarTest.Foo.


