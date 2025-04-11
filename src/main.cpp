#include "vipgfx.h"
#include "engine.h"


int main() {
    InitGFXsystem(800, 600, false);
    SetGFXwindowPos(vscreen.width / 2, vscreen.height / 2);
    SetGFXwindowCaption("Pong");

    init();

    while (!keyboard[KEY_ESCAPE]) {
        
        FastFill(vscreen.data, vscreen.width * vscreen.height, 0xfffec2c8);
        
        DrawBarClip(vscreen, ((vscreen.width/2) - 2), 0, ((vscreen.width / 2) + 2), vscreen.height, 0xffffffff);

        update();
        draw();


        UpdateGFXsystem();
    }

    finish();
    FinishGFXsystem();

    return 0;
}
