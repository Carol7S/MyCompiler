#include "scan.h"
#include "parse.h"
#include "TAC.h"
#include "optimize_TAC.h"
#include "asm.h"

int main() {
    printf(">>> scan     =====================================\n");
    scan();
    printf("\n\n>>> ast     =====================================\n");
    parse();
    printf("\n\n>>> tac     =====================================\n");
    tac();
    printf("\n\n>>>after optimize     =====================================\n");
    printf("\nafter optimize\n\n");
    start_optimize();
    printf("\n\n>>> asm     =====================================\n");
    start_asm();
    return 0;
}
