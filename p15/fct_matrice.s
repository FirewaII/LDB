/*
void ecrire(int16_t mat[nbr_lig][nbr_col], uint32_t lig, uint32_t col, int16_t val)
{
    mat[lig][col] = val;
}
*/

.text
// int16_t mat[nbr_lig][nbr_col] => 8(%ebp)
// int16_t val => 12(%ebp)

/*
ecrire:
    // enter $0, $0
    pushl %ebp
    movl %esp, %ebp
    subl $0, %esp
    // recup lig
    movl 12(%ebp), %eax
    // lig*nbr_col
    mull nbr_col
    movl %eax, %ecx
    // %eax = col
    movl 16(%ebp), %eax
	addl %ecx, %eax

	// mat[lig][col] = val
	movl 8(%ebp), %ecx
	movl 20(%ebp), %edx
	movl %edx, (%ecx, %eax, 2)
	leave
	ret
*/

/* CORRECTION */
// mat %ebp+8
// lig %ebp+12
// col %ebp+16
// val %ebp+20
ecrire:
	enter $0, $0
	// mat[lig][col] = val
	movl 12(%ebp), %eax
	mull nbr_col
	addl 16(%ebp), %eax
	movl 8(%ebp), %edx
	movl 20(%ebp), %ecx // ou movw 20(%ebp), %cx
	movw %cx, (%edx, %ecx, 2)
	leave
	ret

/*
void init(int16_t mat[nbr_lig][nbr_col])
{
    srandom(time(NULL));
    for (uint32_t lig = 0; lig < nbr_lig; lig++) {
        for (uint32_t col = 0; col < nbr_col; col++) {
            ecrire(mat, lig, col, random() % 19 - 9);
    	}
    }
}
*/
.globl init

init:
	//enter $0, $0
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	// srandom(time(NULL));
	movl $0, %edx
	push %edx
	call time
	push %eax
	call srandom
	// uint32_t lig = 0;
	movl $0, -4(%ebp)
	jmp for1

	for1:
		//restore lig
		movl -4(%ebp), %edx
		//lig < nbr_lig
		cmpl nbr_lig, %edx
		jnb fin_for1
		// uint32_t col = 0;
		movl $0, -8(%ebp)
		jmp for2

		for2:
			// col < nbr_col
			movl -8(%ebp), %edx
			cmpl nbr_col, %edx
			jnb fin_for2
			// ecrire(mat, lig, col, random() % 19 - 9);
			// random() % 19
			call random
			movl $0, %edx
			movl $19, %ecx
			divl %ecx
			// random() % 19 - 9
			subl $9, %edx
			pushl %edx
			movl -8(%ebp), %edx
			push %edx
			movl -4(%ebp), %edx
			pushl %edx
			movl 8(%ebp), %edx
			pushl %edx

			call ecrire

			movl -8(%ebp), %edx
			addl $1, %edx
			movl %edx, -8(%ebp)
			jmp for2
		
		fin_for2:
			movl -4(%ebp), %edx
			addl $1, %edx
			movl %edx, -4(%ebp)
			jmp for1
	
	fin_for1:
		leave
		ret

.globl somme

/*
int16_t somme(int16_t *mat, uint32_t nbr_cases)
{
	int16_t som = 0;
	for (uint32_t ix = 0; ix < nbr_cases; ix++) {
		som += *(mat + ix);
	}
	return som;
}
*/

somme:
	//enter $0, $0
	pushl %ebp
	movl %esp, %ebp
	subl $8, %esp
	// uint16_t som = 0;
	movl $0, -4(%ebp)
	// uint32_t ix = 0;
	movl $0, -8(%ebp)
	jmp for_somme

for_somme:
	// ix < nbr_cases
	movl -8(%ebp), %edx
	movl 12(%ebp), %ecx
	cmpl %ecx, %edx
	jnb fin_for_somme
	// som += *(mat+ix) <=> som+= mat[ix]
	movl 8(%ebp), %edx
	movl -8(%ebp), %ecx
	movl (%edx, %ecx, 2), %edx
	movl -4(%ebp), %ecx
	addl %edx, %ecx
	movl %ecx, -4(%ebp)
	/*movl 8(%ebp), %edx
	addl -8(%ebp), %edx
	movl (%edx), %edx
	movl -4(%ebp), %ecx
	addl %edx, %ecx
	movl %ecx, -4(%ebp)*/
	// ix++
	movl -8(%ebp), %edx
	addl $1, %edx
	movl %edx, -8(%ebp)
	jmp for_somme

fin_for_somme:
	// return som
	movl -4(%ebp), %eax
	pushl %eax
	leave
	ret