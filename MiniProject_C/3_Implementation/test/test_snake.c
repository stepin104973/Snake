#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include<snake.h>
#define PROJECT_NAME    "Snake"

/* Prototypes for all the test functions */
void test_Plot(void);
void test_UserInput(void);
void test_KeyResponse(void);


/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "Plot", test_Plot);
  CU_add_test(suite, "UserInput", test_UserInput);
  CU_add_test(suite, "KeyResponse", test_KeyResponse);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */
void test_Plot(void) {
  CU_ASSERT(40 == Plot());

  /* Dummy fail*/
  CU_ASSERT(2 == Plot());
}

void test_UserInput(void) {
  CU_ASSERT(1 == UserInput());

  /* Dummy fail*/
  CU_ASSERT(0 == UserInput());
}

void test_KeyResponse(void) {
  CU_ASSERT(100 == KeyResponse());

  /* Dummy fail*/
  CU_ASSERT(0 == KeyResponse());
}


