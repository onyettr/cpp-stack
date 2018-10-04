
#include "stack.h"
#include "gtest/gtest.h"

namespace {
class StackTest : public testing::Test {
   protected:

   virtual void SetUp() override {
      MyStack_.push(100);
  }

  Stack<int>  MyStack_;
};
   
TEST_F(StackTest, StackPushEmpty) {
  Stack<int> MyStack(5);

  // Test Empty Stack
  EXPECT_EQ(MyStack.StackSize(),0);
}

}
