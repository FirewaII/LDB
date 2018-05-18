/*
uint16_t age(uint16_t annee_naissance)
{
  uint16_t age;
  age = 2018 - annee_naissance;
  return age;
}
*/


.text
.globl age
// uint16_t age(uint16_t annee_naissance)
// annee_naissance : %di

age:
  // uint16_t age:
  enter $16, $0
  // age = 2018 - annee_naissance;
  movw $2018, %si
  subw %di, %si
  movw %si, %ax
  leave
  ret
