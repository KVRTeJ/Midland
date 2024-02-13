#include "Leader.h"

int main() {
    
    struct Leader* lead = malloc(1*sizeof(struct Leader));
    
    addArc(&lead, 1, 2);
    addArc(&lead, 2, 3);
    excludeArc(&lead, 2, 3);
    print(lead);
    
    return 0;
}
