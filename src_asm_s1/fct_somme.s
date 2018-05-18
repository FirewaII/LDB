/*
uint8_t i, res;
uint8_t somme(void)
{
  res = 0;
  for (i = 1; i <= 10; i++) {
    res = res + i;
  }
  return res;
}*/

.data
.comm i,1
.comm res,1

.text
.globl somme

somme:
  enter $0, $0
  // res = 0;
  movb $0, res
  // i = 1;
  movb $1, i

for:
  // i <= 10
  cmpb $10, i
  jnbe end_for
  // res = res + i
  movb i, %al
  addb %al, res
  // i++
  addb $1, i
  jmp for

end_for:
  // return res
  movb res, %al
  leave
  ret
