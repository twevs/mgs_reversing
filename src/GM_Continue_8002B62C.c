#include "linker.h"
#include "Script_tbl_map_8002BB44.h"

// force GP
int SECTION(".sdata") gFlags_800AB3D0;
extern int gFlags_800AB3D0;

extern GameState_800B4D98 gGameState_800B4D98;

void GM_CallSystemCallbackProc_8002B570(int id, int arg);
void GCL_80021488(void);
void sub_8002B600(int);

void GM_Continue_8002B62C()
{
    int field_AE_total_continues; // $s2
    int field_0C_current_stage;   // $s1

    GM_CallSystemCallbackProc_8002B570(1, 0);
    field_AE_total_continues = gGameState_800B4D98.field_AE_total_continues;
    field_0C_current_stage = gGameState_800B4D98.field_0C_current_stage;
    GCL_80021488();
    if (gGameState_800B4D98.field_0C_current_stage != field_0C_current_stage)
    {
        gFlags_800AB3D0 = 1;
    }
    else
    {
        sub_8002B600(-1);
    }

    gGameState_800B4D98.field_AE_total_continues = field_AE_total_continues + 1;

    // Set the bomb to no less than 10 seconds to prevent instant death
    // note: casting needed to produce sltiu and lhu vs lh
    if ((unsigned int)(unsigned short)gGameState_800B4D98.field_4A_item_states[18] - 1 < 9)
    {
        gGameState_800B4D98.field_4A_item_states[18] = 10;
    }
}