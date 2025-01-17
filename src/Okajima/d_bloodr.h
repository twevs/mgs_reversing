#ifndef _D_BLOODR_H_
#define _D_BLOODR_H_

#include "libdg/libdg.h"
#include "libgv/libgv.h"

typedef struct _Actor_DBloodr
{
    GV_ACT   field_0_actor;
    DG_PRIM *field_20_prims;
    SVECTOR  field_24[16];
    SVECTOR  field_A4_positions[4];
    SVECTOR  field_C4_rotation;
    int      field_CC_map;
    char     field_D0_pad[0x4];
    int      field_D4_sequence;
    int      field_D8;
} Actor_DBloodr;

STATIC_ASSERT_SIZE(Actor_DBloodr, 0xDC);

void d_bloodr_act_80072C10(Actor_DBloodr *pActor);
void d_bloodr_kill_80072BD4(Actor_DBloodr *pActor);

void d_bloodr_loader_helper_helper_80072DE8(POLY_FT4 *pPolysA, POLY_FT4 *pPolysB, int count, DG_TEX *pTex);
int  d_bloodr_loader_helper_80072EFC(Actor_DBloodr *pActor);
int  d_bloodr_loader_800730EC(Actor_DBloodr *pActor, int map);

Actor_DBloodr * NewKetchap_r_80073148(int map);

#endif // _D_BLOODR_H_
