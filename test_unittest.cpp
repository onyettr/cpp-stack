/**
 *	@file    test_unittest.cpp
 *	@brief   simple c++ stack test harness using googletest
 *	@author
 *	@note
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include "stack.h"
#include "gtest/gtest.h"

namespace {
class StackTest : public testing::Test {
   protected:

  //   virtual void SetUp() override {
  //      MyStack_.push(100);
  //  }

  //  Stack<int>  MyStack_;
};

static void Declaration(void)
{
  Stack<int> MyStack;        
}
  
/**
 * @brief StackTest SIZE
 */
TEST_F(StackTest, StackSizeIsZero) {
  try {
    Declaration();
  }
  catch (std::runtime_error& e) {
    EXPECT_EQ(e.what(), std::string("Stack<T> - Stack Size is 0"));
    cout << e.what() << endl;
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";
}

TEST_F(StackTest, StackIsEmpty) {
  Stack<int> MyStack(5);

  // Test Empty Stack
  EXPECT_TRUE(MyStack.isEmpty());
}

/**
 * @brief StackTest PEEK
 */
TEST_F(StackTest, PeekingWithSomethingThere)
{
  Stack<int> peekme(3);  

  peekme.push(2001);
  peekme.push(2002);
  peekme.push(2003);

  EXPECT_EQ(2003, peekme.peek());  
}

TEST_F(StackTest, PeekingWithNothingThere)
{
  Stack<int> peekmeFail(1);      

  try {
     peekmeFail.peek();
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";
}

/**
 * @brief StackTest PUSH
 */
TEST_F(StackTest, StackPushOneINTEGERItem) {
  Stack<int> MyStack(5);

  MyStack.push(100);
  EXPECT_EQ(1, MyStack.StackSize());
}

TEST_F(StackTest, StackPushOneCHARItem) {
  Stack<char> MyStack(5);

  MyStack.push('a');
  EXPECT_EQ(1, MyStack.StackSize());
}
  
TEST_F(StackTest, StackPushOneFLOATItem) {
  Stack<float> MyStack(5);

  MyStack.push(3.14);
  EXPECT_EQ(1, MyStack.StackSize());  
}

TEST_F(StackTest, StackPushOneDOUBLEItem) {
  Stack<double> MyStack(5);

  MyStack.push(3.1423);
  EXPECT_EQ(1, MyStack.StackSize());
}
  
TEST_F(StackTest, StackPushOneSTRINGItem) {
  Stack<string> MyStack(5);

  MyStack.push("hello");
  EXPECT_EQ(1, MyStack.StackSize());  
}

TEST_F(StackTest, StackPushOneBOOLEANItem) {
  Stack<bool> MyStack(5);

  MyStack.push(true);
  EXPECT_EQ(1, MyStack.StackSize());  
}
  
TEST_F(StackTest, StackPushToOverflow) {
  Stack<int> MyStack(5);

  try {
     MyStack.push(100);
     MyStack.push(101);
     MyStack.push(102);
     MyStack.push(103);
     MyStack.push(104);
     MyStack.push(105);
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";

}

/**
 * @brief StackTest POP
 */
TEST_F(StackTest, StackPopOneINTEGERItem) {
  Stack<int> MyStack(5);

  MyStack.push(100);
  EXPECT_EQ(100, MyStack.pop());
}

TEST_F(StackTest, StackPopOneFLOATItem) {
  Stack<float> MyStack(5);

  MyStack.push(3.14);
  EXPECT_FLOAT_EQ(3.14, MyStack.pop());  
}

TEST_F(StackTest, StackPopOneCHARItem) {
  Stack<char> MyStack(5);

  MyStack.push('a');
  EXPECT_EQ('a', MyStack.pop());  
}
  
TEST_F(StackTest, StackPopOneSTRINGItem) {
  Stack<string> MyStack(5);

  MyStack.push("hello");
  EXPECT_EQ("hello", MyStack.pop());  
}

TEST_F(StackTest, StackPopOneBOOLEANItem) {
  Stack<bool> MyStack(5);

  MyStack.push(true);
  EXPECT_TRUE(MyStack.pop());  
}
  
TEST_F(StackTest, StackPopUnderflow) {
  Stack<int> MyStack(5);

  try {
     MyStack.pop();
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";
}

}
