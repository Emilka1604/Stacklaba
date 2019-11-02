#include "gtest.h"
#include "stack.h"



TEST(test_case_name, test_name) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(Stack, can_create_stack_with_standart_lenght) {
	ASSERT_NO_THROW(Stack<int> v);
}
TEST(Stack, can_push_element) {
	Stack<int> st;
	st.push(3);
	EXPECT_EQ(st.top(), 3);
}
TEST(Stack, can_copied_stack) {
	Stack<int> st;
	ASSERT_NO_THROW(Stack<int> st1(st));
}
TEST(Stack, copied_stack_is_equal_to_source_one) {
	Stack<int> st;
	st.push(2);
	Stack<int> st1(st);
	EXPECT_TRUE(st == st1);
}
TEST(Stack, copied_stack_has_its_own_memory) {
	Stack<int> st;
	st.push(4);
	Stack<int> st1(st);
	st1.push(5);
	EXPECT_FALSE(st.top() == st1.top());
}
TEST(Stack, can_get_size) {
	Stack<int> st;
	st.push(6);
	EXPECT_EQ(st.size(), 1);
}
TEST(Stack, throws_when_set_element_from_empty_stack) {
	Stack<int> st;
	ASSERT_ANY_THROW(st.top());
}
TEST(Stack, can_pop_element) {
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.pop();
	EXPECT_EQ(st.top(), 1);
}
TEST(Stack, throws_when_delete_element_from_empty_stack) {
	Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

