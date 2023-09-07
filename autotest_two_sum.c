#include <check.h>
#include "two_sum.h"

START_TEST(test_addition) {
    ck_assert_int_eq(two_sum(2, 3), 5);
    ck_assert_int_eq(two_sum(-1, 1), 0);
    ck_assert_int_eq(two_sum(0, 0), 0);
} END_TEST

Suite *addition_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("two_sum");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_addition);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int failed = 0;
    Suite *s;
    SRunner *runner;

    s = addition_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (failed == 0) ? 0 : 1;
}

