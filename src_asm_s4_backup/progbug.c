#include <inttypes.h>

struct cell_t {
    int64_t val;
    struct cell_t *suiv;
};

void bug1(void);

void bug2(void);

int main(void)
{
    //bug1();
    bug2();
    return 0;
}
