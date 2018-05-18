/*
uint64_t mult_simple(void)
{
  res = 0;
  while (y != 0) {
    res = res + x;
    y--;
  }
  return res;
}
*/

.data
.comm res, 4
.comm y, 4
.comm x, 4

.text
.globl mult_egypt
.globl mult_simple
.globl mult_native

mult_simple:
  enter $0, $0
  // res = 0;
  movq $0, res

while_s:
  // while (y != 0);
  je end_while_s
  // res = res + x
  movq x, %rax
  addq %rax, res
  // y--
  subq $1, y
  jmp while_s

end_while_s:
  // return res
  movq res, %rax
  leave
  ret



mult_egypt:
  enter $0, $0
  // res = 0;
  movq $0, res

while_e:
  // while (y != 0);
  je end_mult_egypt
  // if (y % 2 == 1)
  testq $1, y
  jz end_while_e
  //res = res + x
  movq x, %rax
  addq %rax, res

end_while_e:
  // x = x * 2
  shlq $1, x
  // y = y / 2
  shrq $1, y
  jmp while_e

end_mult_egypt:
  // return res
  movq res, %rax
  leave
  ret


mult_native:
  enter $0, $0
  // res = x * y
  movq y, %rax
  mulq x
  // return res
  movq res, %rax
  leave
  ret
