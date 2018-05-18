/*
void affichage(struct structure_t s)
{
    affiche(s.entier, s.ptr);
}
*/
    .text
    .globl affichage
    // void affichage(struct structure_t s)
    // s : %rdi:%rsi
affichage:
    enter $0, $0
    // affiche(s.entier, s.ptr);
    call affiche
    leave
    ret

/*
void modification(int64_t entier, char *ptr, struct structure_t *s)
{
    s->entier = entier;
    s->ptr = ptr;
}
*/
    .globl modification
    // void modification(int64_t e, char *p, struct structure_t *ps)
    // e : %rdi
    // p : %rsi
    // ps : %rdx
modification:
    enter $0, $0
    // ps->entier = e;
    movq %rdi, (%rdx)
    // ps->ptr = p;
    movq %rsi, 8(%rdx)
    leave
    ret

