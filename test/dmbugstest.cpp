
#include "dmbugs.h"

int main( int argc, char* argv[] ) {

    Idmbugs* module = dmbugsGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
