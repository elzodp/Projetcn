#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "queens.c"

static void test_same_diagonal(void **state) {
   //same diagonal
   assert_true(check_same_diagonal(1,1,2,2));
   assert_true(check_same_diagonal(3,1,1,3));
   assert_true(check_same_diagonal(3,0,0,3));
   //not same diagonal
   assert_false(check_same_diagonal(2,1,1,3));
   assert_false(check_same_diagonal(1,2,3,3));
   assert_false(check_same_diagonal(3,1,0,3));
}


static void test_check_column_ok(void **state) {
    
    int q1[4] = {1,3,0,2};
    int q2[5] = {4,1,3,0,2};

    assert_true(check_column_ok(4,4,q1));
    assert_true(check_column_ok(3,2,q1));
    assert_true(check_column_ok(3,0,q2));
    assert_true(check_column_ok(4,2,q2));

    assert_false(check_column_ok(4,3,q1));
    assert_false(check_column_ok(3,1,q1));
    assert_false(check_column_ok(5,2,q2));
    assert_false(check_column_ok(5,1,q2));
}

static void test_find_available(void **state) {
  bool t1[4] = {true, true, true, true};
  bool t2[4] = {false, false, false, false};
  bool t3[4] = {false, false, false, true};
  
  assert_true(find_available(3,4,t1));
  assert_true(find_available(0,4,t2) == -1);
  assert_true(find_available(1,4,t3));
}

static void test_find_solution(void**state){
    int q1[4] = {-1,-1,-1,-1};

    assert_true(find_solution(4,q1));
    assert_true(find_solution(5,q1));
    assert_false(find_solution(3,q1));
    assert_false(find_solution(2,q1));
    
    
    
}

int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
    
    cmocka_unit_test(test_same_diagonal),
    cmocka_unit_test(test_check_column_ok),
    cmocka_unit_test(test_find_available),
    cmocka_unit_test(test_find_solution),
      
  };

  result |= cmocka_run_group_tests_name("queens", tests, NULL, NULL);

  return result;
}



