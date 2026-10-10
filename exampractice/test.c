#include <stdio.h>


#define Box(T) struct{ \
  T value; \
} 

#define Box_set(box , value) do {\
  static_assert(__builtin_types_compatible_p(__typeof__((box).value),__typeof__(value)), "type mismatch");\
  (box).value=value;\
} while (0)
  

int main(int argc, char *argv[])
{
Box(int) a;
Box_set(a,10);

 
  return 0;
}
