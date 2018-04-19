#if !defined(__TRAP_H__)
#define __TRAP_H__

typedef enum stack_exception {
  e_stackoverflow        = 100,
  e_stackunderflow       = 200,
  e_stackoutofmemory     = 300,
  e_stacksizeisnegative  = 400
} stack_exception_t;

void Thrower(stack_exception_t exp);

#endif
