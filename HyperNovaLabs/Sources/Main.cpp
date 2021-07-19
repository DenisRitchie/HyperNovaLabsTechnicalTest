#include <stdio.h>
#include <emscripten.h>

EM_JS(void, two_alerts, (),
{
    alert('hai');
    alert('bai');
});

int main()
{
    two_alerts();
    return 0;
}