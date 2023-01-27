#include "linker.h"
#include "data.h"

#include "data/rdata/rdata.h"
#include "libfs/libfs.h"
#include "libgv/libgv.h"
#include "libgcl/gcl.h"
#include "Menu/menuman.h"
#include "libdg/libdg.h"
#include "libdg/dgd.h"
#include "Thing/door.h"
#include "mts/mts_new.h"
#include "Game/game.h"
#include "Game/GM_Control.h"
#include "chara/snake/sna_init.h"
#include "Equip/bodyarm.h"
#include "Equip/gasmask.h"
#include "Equip/box.h"
#include "Equip/bandana.h"
#include "Anime/animeconv/anime.h"
#include "libgcl/hash.h"
#include "Menu/menuman.h"
#include "Menu/radio.h"
#include "Bullet/blast.h"
#include "Weapon/aam.h"
#include "Equip/jpegcam.h"

// sdata
extern const char *aCigs[];
extern const char *aSocom[];
extern const char *aFamas_800AB5BC[];
extern const char *aGrenade_800AB5B4[];
extern const char *aNikita_800AB5AC[];
extern const char *aStinger_800AB5A4[];
extern const char *aClaymore[];
extern const char *aC4_800AB5A0[];
extern const char *aStunG[];
extern const char *aChaffG[];
extern const char *aPsg1[];

extern const char *aScope[];
extern const char *aCBoxA[];
extern const char *aCBoxB[];
extern const char *aCBoxC[];
extern const char *aNVG[];
extern const char *aThermG[];
extern const char *aGasmask[];
extern const char *aBArmor[];
extern const char *aKetchup[];
extern const char *aStealth[];
extern const char *aBandana[];
extern const char *aCamera[];
extern const char *aRation[];
extern const char *aMedicine[];
extern const char *aDiazepam[];
extern const char *aPalKey[];
extern const char *aCard[];
extern const char *aTimerB[];
extern const char *aMineD[];
extern const char *aDisc[];
extern const char *aRope[];
extern const char *aScarf[];
extern const char *aSuppr[];

extern const char  aLife[];
extern const char  aO2[];
extern const char *aError[];
extern const char *aComplete[];
extern const char *dword_800AB728[];
extern const char *dword_800AB724[];
extern const char *dword_800AB720[];
extern const char *aEx[];
extern const char *aMemoryCard1[];
extern const char *aMemoryCard2[];
extern const char *dword_800AB754[];
extern const char *aNo[];
extern const char *dword_800122D8[];
extern const char *dword_800122CC[];
extern const char *dword_800122C0[];
extern const char *dword_800122B4[];
extern const char *dword_800122A8[];
extern const char *aSaveData[];
extern const char  aSnaChest1[];
extern const char  aSnaChest2[];
extern const char  aSnaChest3[];
extern const char  aSnaHip1[];
extern const char  aSnaArmer1[];
extern const char  aSnaArmer2[];
extern const char  aSnaArmer3[];
extern const char  aSnaArmer4[];
extern const char  aCbBox11[];
extern const char  aCbBox12[];
extern const char  aCbBox41[];
extern const char  aCbBox42[];
extern const char  aCbBox21[];
extern const char  aCbBox22[];
extern const char  aCbBox41[];
extern const char  aCbBox42[];
extern const char  aSnaFace[];
extern const char  aSnaFace2[];
extern const char  aSnaFace3[];
extern const char  aSnaMf1[];
extern const char  aSnaMf2[];
extern const char  aSnaMf3[];

GCL_ActorTableEntry SECTION(".data") MainCharacterEntries_8009D2DC[] = {
    {CHARA_SNAKE, (TGCL_ActorCreateFn)0x8005B650}, // sna_init.c
    {CHARA_ITEM, (TGCL_ActorCreateFn)0x800344F8},
    {CHARA_DOOR, (TGCL_ActorCreateFn)&NewDoor_8006FD00},
    {0, 0}};

const char *SECTION(".data") MGS_DiskName_8009D2FC[] = {aSlpm86247, aSlpm86248, 0};

struct PauseKill SECTION(".data") gPauseKills_8009D308[9] = {{0, 7},  {0, 7},  {9, 4}, {9, 4}, {15, 4},
                                                             {15, 4}, {15, 4}, {9, 4}, {0, 7}};

short SECTION(".data") key_table_8009D32C[] = {0x0000, 0x0800, 0x0400, 0x0600, 0x0000, 0x0000, 0x0200, 0x0000,
                                               0x0C00, 0x0A00, 0x0000, 0x0000, 0x0E00, 0x0000, 0x0000, 0x0000};

VECTOR SECTION(".data") vector_8009D34C = {0, -4096, 0, 0};

void DG_Screen_Chanl_8001CEE0(DG_CHNL *pOt, int idx);
void DG_BoundChanl_800189A4(DG_CHNL *pOt, int idx);
void DG_Trans_Chanl_8001E3C0(DG_CHNL *pOt, int idx);
void DG_Shade_Chanl_8001D324(DG_CHNL *pOt, int idx);
void DG_PrimChanl_8001B66C(DG_CHNL *pOt, int idx);
void DG_DivideChanl_80019D44(DG_CHNL *pOt, int idx);
void DG_Sort_Chanl_8001D5C8(DG_CHNL *pOt, int idx);

// rendering stack ? gLibDg_FuncPtrs_off_6500E0
TChanl_Fn SECTION(".data") off_8009D35C[] = {DG_Screen_Chanl_8001CEE0, DG_BoundChanl_800189A4, DG_Trans_Chanl_8001E3C0,
                                             DG_Shade_Chanl_8001D324,  DG_PrimChanl_8001B66C,  DG_DivideChanl_80019D44,
                                             DG_Sort_Chanl_8001D5C8};

DG_TEX SECTION(".data") DG_UnknownTexture_8009D378 = {0, {.s = 0}, 0, 0, 0, 0, 0, 0};

MATRIX SECTION(".data") DG_LightMatrix_8009D384 = {
    {{0x0000, 0x0000, 0x1000}, {0x0000, 0x0000, 0x0000}, {0x0000, 0x0000, 0x0000}}, {0, 0, 0}};

MATRIX SECTION(".data") DG_ColorMatrix_8009D3A4 = {
    {{0x1000, 0x1000, 0x1000}, {0x1000, 0x1000, 0x1000}, {0x1000, 0x1000, 0x1000}}, {0, 0, 0}};

int SECTION(".data") dword_8009D3C4[] = {0, 0, 0};

//	DG_PRIM_LINE_FT2, DG_PRIM_LINE_GT2,
//	DG_PRIM_FREE
// DG_PRIM_TILE_1  DG_PRIM_TILE_8, DG_PRIM_TILE_16

//  int psize, int verts, int voffset, int vstep ??

struct DG_Rec_Unknown SECTION(".data") stru_8009D3D0[24] = {{16, 2, 8, 4},  // LINE_F2 DG_PRIM_LINE_FT2
                                                            {24, 3, 8, 4},  // LINE_F3
                                                            {28, 4, 8, 4},  // LINE_F4
                                                            {20, 2, 8, 8},  // LINE_G2
                                                            {32, 3, 8, 8},  // LINE_G3
                                                            {40, 4, 8, 8},  // LINE_G4
                                                            {20, 1, 8, 0},  // SPRT
                                                            {16, 1, 8, 0},  // SPRT_16  ?
                                                            {16, 1, 8, 0},  // SPRT_8  ?
                                                            {16, 1, 8, 0},  // TILE ?
                                                            {12, 1, 8, 0},  // TILE_16  ?
                                                            {12, 1, 8, 0},  // TILE_8 ?
                                                            {12, 1, 8, 0},  // TILE_1 ?
                                                            {20, 3, 8, 4},  // POLY_F3 DG_PRIM_POLY_F3
                                                            {24, 4, 8, 4},  // POLY_F4 DG_PRIM_POLY_F4
                                                            {28, 3, 8, 8},  // POLY_G3 DG_PRIM_POLY_G3
                                                            {36, 4, 8, 8},  // POLY_G4 DG_PRIM_POLY_G4
                                                            {32, 3, 8, 8},  // POLY_FT3 DG_PRIM_POLY_FT3
                                                            {40, 4, 8, 8},  // POLY_FT4 DG_PRIM_POLY_FT4
                                                            {40, 3, 8, 12}, // POLY_GT3 DG_PRIM_POLY_GT3
                                                            {52, 4, 8, 12}, // POLY_GT4 DG_PRIM_POLY_GT4
                                                            {40, 2, 8, 8},  {52, 2, 8, 12}, {12, 1, 8, 0}};

MATRIX SECTION(".data") DG_ZeroMatrix_8009D430 = {
    {{0x1000, 0x0000, 0x0000}, {0x0000, 0x1000, 0x0000}, {0x0000, 0x0000, 0x1000}}, {0, 0, 0}};

DG_TEX SECTION(".data") dword_8009D450 = {};
int    SECTION(".data") DG_FrameRate_8009D45C = 2;
int    SECTION(".data") DG_HikituriFlag_8009D460 = 0;
int    SECTION(".data") DG_HikituriFlagOld_8009D464 = 0;
int    SECTION(".data") dword_8009D468 = -1;

int GCL_Command_if_80020274(char *top);
int GCL_Command_eval_80020318(unsigned char *pScript);
int GCL_Cmd_Return_80020404(void);
int GCL_Command_foreach_8002033C(unsigned char *pScript);

// kVertexIndexingOrder_8009D46C provides the indexing order for referencing the transformed vertex sections
unsigned char kVertexIndexingOrder_8009D46C[] = {0, 1, 3, 2};

GCL_COMMANDLIST SECTION(".data") commlist_8009D470[] = {{HASH_CMD_if, (TGCL_CommandFn)&GCL_Command_if_80020274},
                                                        {HASH_CMD_eval, &GCL_Command_eval_80020318},
                                                        {HASH_CMD_return, (TGCL_CommandFn)&GCL_Cmd_Return_80020404},
                                                        {HASH_CMD_foreach, &GCL_Command_foreach_8002033C}};

GCL_COMMANDDEF SECTION(".data") builtin_commands_8009D490 = {0, COUNTOF(commlist_8009D470), commlist_8009D470};

FS_FILE_INFO_8009D49C SECTION(".data") gDirFiles_8009D49C[] = {
    {aStageDir, 0}, {aRadioDat, 0}, {aFaceDat, 0}, {aZmovieStr, 0}, {aVoxDat, 0}, {aDemoDat, 0}, {aBrfDat, 0}, {0, 0}};

int SECTION(".data") dword_8009D4DC = -1;
int SECTION(".data") dword_8009D4E0 = 0;
int SECTION(".data") dword_cdbios_stop_8009D4E4 = 0;

FS_FILE_TABLE SECTION(".data") fs_file_table_8009D4E8 = {0, 0, 0, 0};

int   SECTION(".data") dword_8009D4F8 = 0;
int   SECTION(".data") dword_8009D4FC = 0;
int   SECTION(".data") dword_8009D500 = 0;
short SECTION(".data") word_8009D504 = 0;
short SECTION(".data") word_8009D506 = 0;
short SECTION(".data") word_8009D508 = 0;

FS_MOVIE_FILE_TABLE *SECTION(".data") fs_movie_file_table_8009D50C = 0;

int SECTION(".data") fs_stream_tick_start_8009D510 = -1;
int SECTION(".data") fs_dword_8009D514 = 0;
int SECTION(".data") fs_stream_is_force_stop_8009D518 = 0;
int SECTION(".data") fs_stream_end_flag_8009D51C = 1;
int SECTION(".data") fs_dword_8009D520 = 0;
int SECTION(".data") gmem_card_system_inited_8009D524 = 0;

int SECTION(".data") dword_8009D528[] = {0x8000000, 0x4000555, 0x2AA0333, 0x2000249,
                                         0x19901C7, 0x1550174, 0x124013B, 0x1000111};
int SECTION(".data") dword_8009D548[] = {0, 0x20, 0x40, 8, 0x800, 0x10000, 0x20000, 0x1000, 4, 1};
int SECTION(".data") dword_8009D570[] = {0x20, 0x80, 0x40, 0x10};

int SECTION(".data") GM_WeaponTypes_8009D580[] = {0x90420110, 0x414C9043, 0x222020C0, 0x41104110, 0x414C414C, 0x9220};
unsigned short SECTION(".data") GM_ItemTypes_8009D598[] = {
    0x0000, 0x8000, 0x8003, 0x8001, 0x8001, 0x8001, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8003, 0x2000, 0x2000,
    0x2000, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int GCL_Command_mesg_8002C138(int argc, char **argv);
int GCL_Command_trap_8002BD34(int argc, char **argv);
int GCL_Command_chara_8002C1B0(int argc, char **argv);
int GCL_Command_map_8002BB44(int argc, char **argv);
int GCL_Command_hzd_8002BD04(int argc, char **argv);
int GCL_Command_camera_8002B8F0(int argc, char **argv);
int GCL_Command_light_8002B854(int argc, char **argv);
int GCL_Command_start_8002C22C(int argc, char **argv);
int GCL_Command_load_8002C308(int argc, char **argv);
int GCL_Command_radio_8002C4A8(int argc, char **argv);
int GCL_Command_strstatus_8002C6A4(int argc, char **argv);
int GCL_Command_demo_8002C890(int argc, char **argv);
int GCL_Command_ntrap_8002BE20(int argc, char **argv);
int GCL_Command_delay_8002C074(int argc, char **argv);
int GCL_Command_pad_8002C988(int argc, char **argv);
int GCL_Command_varsave_8002C72C(int argc, char **argv);
int GCL_Command_system_8002C7C8(void);
int GCL_Command_sound_8002CA28(int argc, char **argv);
int GCL_Command_menu_8002CAAC(void);
int GCL_Command_rand_8002CD94(int argc, char **argv);
int GCL_Command_unknown1_8002CDF4(int argc, char **argv);
int GCL_Command_unknown2_8002CFBC(int argc, char **argv);
int GCL_Command_print_8002D0E4(int argc, char **argv);
int GCL_Command_jimaku_8002D188(int argc, char **argv);

GCL_COMMANDLIST SECTION(".data") Commands_8009D5CC[] = {
    {HASH_CMD_mesg, (TGCL_CommandFn)&GCL_Command_mesg_8002C138},
    {HASH_CMD_trap, (TGCL_CommandFn)&GCL_Command_trap_8002BD34},
    {HASH_CMD_chara, (TGCL_CommandFn)&GCL_Command_chara_8002C1B0},
    {HASH_CMD_map, (TGCL_CommandFn)&GCL_Command_map_8002BB44},
    {HASH_CMD_hzd, (TGCL_CommandFn)&GCL_Command_hzd_8002BD04},
    {HASH_CMD_camera, (TGCL_CommandFn)&GCL_Command_camera_8002B8F0},
    {HASH_CMD_light, (TGCL_CommandFn)&GCL_Command_light_8002B854},
    {HASH_CMD_start, (TGCL_CommandFn)&GCL_Command_start_8002C22C},
    {HASH_CMD_load, (TGCL_CommandFn)&GCL_Command_load_8002C308},
    {HASH_CMD_radio, (TGCL_CommandFn)&GCL_Command_radio_8002C4A8},
    {HASH_CMD_str_status, (TGCL_CommandFn)&GCL_Command_strstatus_8002C6A4},
    {HASH_CMD_demo, (TGCL_CommandFn)&GCL_Command_demo_8002C890},
    {HASH_CMD_ntrap, (TGCL_CommandFn)&GCL_Command_ntrap_8002BE20},
    {HASH_CMD_delay, (TGCL_CommandFn)&GCL_Command_delay_8002C074},
    {HASH_CMD_pad, (TGCL_CommandFn)&GCL_Command_pad_8002C988},
    {HASH_CMD_varsave, (TGCL_CommandFn)&GCL_Command_varsave_8002C72C},
    {HASH_CMD_system, (TGCL_CommandFn)&GCL_Command_system_8002C7C8},
    {HASH_CMD_sound, (TGCL_CommandFn)&GCL_Command_sound_8002CA28},
    {HASH_CMD_menu, (TGCL_CommandFn)&GCL_Command_menu_8002CAAC},
    {HASH_CMD_rand, (TGCL_CommandFn)&GCL_Command_rand_8002CD94},
    {HASH_CMD_unk1, (TGCL_CommandFn)&GCL_Command_unknown1_8002CDF4}, // ??
    {HASH_CMD_unk2, (TGCL_CommandFn)&GCL_Command_unknown2_8002CFBC}, // ?? not in pc ver, demo thread related ??
    {HASH_CMD_print, (TGCL_CommandFn)&GCL_Command_print_8002D0E4},
    {HASH_CMD_jimaku, (TGCL_CommandFn)&GCL_Command_jimaku_8002D188}};

GCL_COMMANDDEF SECTION(".data") script_commands_8009D68C = {0, COUNTOF(Commands_8009D5CC), Commands_8009D5CC};

char SECTION(".data") byte_8009D698[] = {0x00, 0x00, 0x01, 0x02};

int SECTION(".data") dword_8009D69C[] = {
    0x42801EE, 0x666056E, 0x7DA072E, 0x8F4086E, 0x9DA096C, 0xA9A0A3E, 0xB3E0AEE, 0xBCE0B88, 0xC4C0C0E, 0xCBC0C86,
    0xD200CEF, 0xD780D4E, 0xDC80DA2, 0xE100DEE, 0xE520E32, 0xE8C0E6F, 0xEC00EA6, 0xEEF0ED8, 0xF190F04, 0xF3F0F2C,
    0xF600F50, 0xF7E0F6F, 0xF980F8B, 0xFAE0FA3, 0xFC20FB8, 0xFD20FCA, 0xFE00FD9, 0xFEB0FE6, 0xFF30FEF, 0xFFA0FF7,
    0xFFE0FFC, 0xFFF0FFF, 0x28800B2, 0x4C003C6, 0x6440590, 0x77406E4, 0x86C07F6, 0x94008DA, 0x9F809A0, 0xA9A0A4C,
    0xB280AE2, 0xBA80B6A, 0xC1C0BE4, 0xC860C52, 0xCE40CB6, 0xD3A0D10, 0xD8A0D62, 0xDD10DAE, 0xE130DF2, 0xE4F0E32,
    0xE860E6B, 0xEB80E9F, 0xEE50ECF, 0xF0E0EFA, 0xF340F22, 0xF560F46, 0xF750F66, 0xF900F83, 0xFA90F9D, 0xFBE0FB4,
    0xFD10FC8, 0xFE20FDA, 0xFF00FE9, 0xFFC0FF6, 0x196005C, 0x3740298, 0x4E00434, 0x60C057C, 0x70A0690, 0x7E6077C,
    0x8AA084A, 0x9580902, 0x9F409A8, 0xA840A3E, 0xB060AC6, 0xB7C0B42, 0xBEA0BB4, 0xC4E0C1D, 0xCAC0C7E, 0xD020CD7,
    0xD510D2A, 0xD9A0D76, 0xDDF0DBE, 0xE1E0E00, 0xE590E3C, 0xE900E75, 0xEC20EAA, 0xEF10EDA, 0xF1C0F07, 0xF440F30,
    0xF690F57, 0xF8B0F7A, 0xFAA0F9A, 0xFC60FB8, 0xFE00FD3, 0xFF70FEC, 0x1100038, 0x28401D2, 0x3BE0326, 0x4D0044C,
    0x5C2054C, 0x69C0632, 0x7600700, 0x81407BC, 0x8BA0868, 0x9520906, 0x9DE099A, 0xA620A20, 0xADC0AA0, 0xB4C0B14,
    0xBB80B83, 0xC1B0BEA, 0xC780C4A, 0xCD00CA6, 0xD230CFA, 0xD710D4A, 0xDBA0D96, 0xDFE0DDD, 0xE400E20, 0xE7C0E5E,
    0xEB60E9A, 0xEEC0ED1, 0xF1F0F06, 0xF4E0F37, 0xF7C0F65, 0xFA60F91, 0xFCD0FBA, 0xFF20FE0, 0xC00026,  0x1DC0152,
    0x2DE0260, 0x3CA0356, 0x4A4043A, 0x56E050C, 0x62C05CE, 0x6DC0684, 0x7800730, 0x81C07D0, 0x8AE0866, 0x93A08F6,
    0x9BC097C, 0xA3A09FC, 0xAAF0A74, 0xB200AE8, 0xB8A0B56, 0xBF00BBE, 0xC500C20, 0xCAC0C7F, 0xD040CD9, 0xD580D2F,
    0xDA80D81, 0xDF60DD0, 0xE3E0E1A, 0xE840E62, 0xEC80EA6, 0xF080EE8, 0xF440F26, 0xF7F0F62, 0xFB60F9B, 0xFEC0FD2,
    0x8C001C,  0x16600FA, 0x23401CE, 0x2F80298, 0x3B40358, 0x4680410, 0x51404BE, 0x5B80568, 0x6560608, 0x6EE06A4,
    0x7820738, 0x80E07C8, 0x8960852, 0x91808D8, 0x9960958, 0xA1009D4, 0xA860A4C, 0xAF80AC0, 0xB660B2F, 0xBD00B9C,
    0xC360C04, 0xC9A0C69, 0xCFB0CCB, 0xD580D2A, 0xDB30D86, 0xE0A0DE0, 0xE600E36, 0xEB20E8A, 0xF020EDA, 0xF500F2A,
    0xF9C0F76, 0xFE40FC0, 0x680014,  0x11000BC, 0x1B20162, 0x2520204, 0x2F002A2, 0x38A033C, 0x42003D4, 0x4B4046A,
    0x54404FC, 0x5D2058C, 0x65E0618, 0x6E806A4, 0x76E072A, 0x7F207B0, 0x8740832, 0x8F208B4, 0x9700932, 0x9EC09AE,
    0xA640A28, 0xADA0AA0, 0xB500B16, 0xBC20B8A, 0xC340BFA, 0xCA20C6A, 0xD100CD8, 0xD7A0D46, 0xDE40DB0, 0xE4C0E18,
    0xEB20E80, 0xF160EE4, 0xF7A0F48, 0xFDB0FAA, 0x4F000F,  0xCF008F,  0x14F010F, 0x1CF018F, 0x24F020F, 0x2CF028F,
    0x34F030F, 0x3CF038F, 0x44F040F, 0x4CF048F, 0x54F050F, 0x5CF058F, 0x64F060F, 0x6CF068F, 0x74F070F, 0x7CF078F,
    0x84F080F, 0x8CF088F, 0x94F090F, 0x9CF098F, 0xA4F0A0F, 0xACF0A8F, 0xB4F0B0F, 0xBCF0B8F, 0xC4F0C0F, 0xCCF0C8F,
    0xD4F0D0F, 0xDCF0D8F, 0xE4F0E0F, 0xECF0E8F, 0xF4F0F0F, 0xFCF0F8F, 0x3C000C,  0x9E006C,  0x10000CE, 0x1660132,
    0x1CC0198, 0x2340200, 0x29E0269, 0x30A02D4, 0x3780340, 0x3E803B0, 0x4580420, 0x4CC0492, 0x5400506, 0x5B8057C,
    0x63205F4, 0x6AE066F, 0x72A06EC, 0x7AA076A, 0x82C07EC, 0x8B2086E, 0x93808F4, 0x9C2097E, 0xA4E0A08, 0xADE0A96,
    0xB700B26, 0xC040BB8, 0xC9A0C4E, 0xD360CE8, 0xDD20D84, 0xE740E22, 0xF180EC6, 0xFC00F6C, 0x2C0008,  0x760050,
    0xC2009C,  0x11000E8, 0x1600138, 0x1B4018A, 0x20A01DE, 0x2620235, 0x2BD028F, 0x31C02EC, 0x37C034C, 0x3E003AE,
    0x4480414, 0x4B4047E, 0x52204EA, 0x596055C, 0x60C05D0, 0x6860648, 0x70606C6, 0x78A0748, 0x81207CE, 0x8A0085A,
    0x93408EA, 0x9CE0980, 0xA6E0A1E, 0xB140AC0, 0xBC20B6A, 0xC780C1C, 0xD360CD6, 0xDFC0D98, 0xECE0E64, 0xFAA0F3A,
    0x200006,  0x56003A,  0x8E0072,  0xC900AB,  0x10700E8, 0x1480127, 0x18B0169, 0x1D201AE, 0x21C01F6, 0x26A0242,
    0x2BA0292, 0x31002E4, 0x368033C, 0x3C60396, 0x42803F6, 0x48E045A, 0x4FA04C4, 0x56C0532, 0x5E405A6, 0x6620622,
    0x6E606A2, 0x772072C, 0x80807BC, 0x8A60856, 0x94E08F8, 0xA0009A6, 0xAC00A5E, 0xB8E0B26, 0xC6C0BFC, 0xD5E0CE4,
    0xE660DE0, 0xF8A0EF4, 0x160004,  0x3B0028,  0x64004F,  0x8E0078,  0xBC00A4,  0xEC00D4,  0x1200106, 0x157013B,
    0x1910174, 0x1CF01B0, 0x21001EF, 0x2560233, 0x2A0027B, 0x2F002C8, 0x3440318, 0x39C036F, 0x3FC03CC, 0x460042E,
    0x4CD0496, 0x5400506, 0x5BC057E, 0x64205FE, 0x6D20688, 0x76C071E, 0x81607C0, 0x8CC086E, 0x9960930, 0xA760A04,
    0xB700AEE, 0xC8A0BF8, 0xDD20D28, 0xF560E8A, 0xD0002,   0x250019,  0x400032,  0x5C004E,  0x7C006C,  0x9F008D,
    0xC400B1,  0xED00D8,  0x1190102, 0x1480130, 0x17C0162, 0x1B40198, 0x1F001D1, 0x230020F, 0x2760252, 0x2C1029A,
    0x31202E8, 0x36A033D, 0x3C80398, 0x42F03FA, 0x49E0466, 0x51804DA, 0x59E055A, 0x62E05E4, 0x6D0067E, 0x7840728,
    0x84C07E4, 0x93008BA, 0xA3809B0, 0xB720ACE, 0xCF40C28, 0xEFC0DE2, 0x60001,   0x12000C,  0x210019,  0x320029,
    0x46003C,  0x5C0050,  0x750068,  0x920083,  0xB100A1,  0xD400C2,  0xFA00E6,  0x124010F, 0x153013B, 0x186016C,
    0x1BE01A2, 0x1FC01DC, 0x23E021C, 0x2880262, 0x2D802B0, 0x3310304, 0x3920360, 0x3FE03C6, 0x4740438, 0x4F804B4,
    0x58C0540, 0x63205DC, 0x6F0068E, 0x7CC075A, 0x8D00848, 0xA100968, 0xBB40AD2, 0xE420CCC, 0,         0x20001,
    0x70004,   0xD000A,   0x170012,  0x22001C,  0x310029,  0x420039,  0x56004C,  0x6D0061,  0x88007A,  0xA60097,
    0xC900B7,  0xF000DC,  0x11B0105, 0x14B0132, 0x1810166, 0x1BC019E, 0x1FF01DD, 0x2490223, 0x29B0271, 0x2F602C8,
    0x35D0328, 0x3D00394, 0x4520410, 0x4E6049A, 0x5920538, 0x65A05F2, 0x74A06CC, 0x87807D8, 0xA0C0930, 0xCB80B24};

int SECTION(".data") dword_8009DE1C[] = {0x10000, 0x10000, 0x8000, 0x5555, 0x4000, 0x3333, 0x2AAA, 0x2492,
                                         0x2000,  0x1C71,  0x1999, 0x1745, 0x1555, 0x13B1, 0x1249, 0x1111};

int SECTION(".data") dword_8009DE5C[] = {0x8001000, 0x4000555, 0x2AA0333, 0x2000249,
                                         0x19901C7, 0x1550174, 0x124013B, 0x1000111};
int SECTION(".data") dword_8009DE7C = 0;
int SECTION(".data") dword_8009DE80 = 0;
int SECTION(".data") dword_8009DE84 = 0;
int SECTION(".data") dword_8009DE88 = 0;
int SECTION(".data") dword_8009DE8C[] = {0, 0, 0, 0};
int SECTION(".data") dword_8009DE9C = 0;
int SECTION(".data") dword_8009DEA0 = 0;
int SECTION(".data") dword_8009DEA4 = 0;
int SECTION(".data") dword_8009DEA8 = 0;
int SECTION(".data") dword_8009DEAC[] = {0, 0, 0, 0};

short SECTION(".data") game_over_lines_8009DEBC[] = {
    120, // table length
    37,  88,  25,  104, 25,  104, 31,  121, 31,  121, 40,  121, 40,  121, 32,  135,
    32,  135, 42,  135, 69,  88,  37,  88,  64,  96,  41,  96,  41,  96,  35,  104,
    35,  104, 38,  113, 38,  113, 45,  113, 62,  100, 45,  100, 45,  100, 40,  108,
    40,  108, 48,  108, 48,  108, 45,  113, 69,  88,  64,  96,  55,  121, 65,  121,
    74,  88,  84,  88,  67,  100, 85,  100, 69,  96,  85,  96,  67,  100, 55,  121,
    69,  96,  74,  88,  84,  88,  85,  96,  85,  100, 87,  121, 87,  121, 78,  121,
    73,  108, 77,  108, 78,  121, 77,  108, 73,  108, 65,  121, 62,  100, 42,  135,
    89,  121, 98,  121, 97,  88,  108, 88,  118, 88,  130, 88,  122, 121, 113, 121,
    113, 121, 117, 104, 117, 104, 108, 121, 108, 121, 103, 121, 103, 121, 102, 104,
    102, 104, 98,  121, 95,  96,  108, 96,  114, 96,  128, 96,  94,  100, 108, 100,
    112, 100, 127, 100, 97,  88,  95,  96,  94,  100, 89,  121, 108, 88,  108, 96,
    108, 100, 108, 108, 112, 100, 108, 108, 114, 96,  118, 88,  127, 100, 122, 121,
    128, 96,  130, 88,  134, 88,  156, 88,  126, 121, 148, 121, 132, 96,  154, 96,
    131, 100, 153, 100, 138, 107, 151, 107, 138, 107, 137, 113, 150, 113, 137, 113,
    134, 88,  132, 96,  131, 100, 126, 121, 150, 113, 148, 121, 151, 107, 153, 100,
    154, 96,  156, 88,  173, 121, 199, 121, 181, 88,  207, 88,  179, 96,  205, 96,
    187, 100, 184, 113, 184, 113, 192, 113, 195, 100, 192, 113, 207, 88,  205, 96,
    204, 100, 199, 121, 181, 88,  179, 96,  178, 100, 173, 121, 178, 100, 187, 100,
    195, 100, 204, 100, 213, 121, 224, 121, 241, 88,  231, 88,  210, 88,  219, 88,
    211, 96,  220, 96,  211, 100, 220, 100, 225, 100, 235, 100, 227, 96,  237, 96,
    225, 100, 221, 108, 231, 88,  227, 96,  235, 100, 224, 121, 237, 96,  241, 88,
    211, 100, 213, 121, 210, 88,  211, 96,  219, 88,  220, 96,  220, 100, 221, 108,
    244, 88,  266, 88,  236, 121, 258, 121, 242, 96,  264, 96,  241, 100, 263, 100,
    247, 113, 260, 113, 248, 108, 261, 108, 248, 108, 247, 113, 244, 88,  242, 96,
    241, 100, 236, 121, 263, 100, 261, 108, 260, 113, 258, 121, 266, 88,  264, 96,
    270, 88,  292, 88,  268, 96,  286, 96,  292, 88,  295, 97,  267, 100, 282, 100,
    275, 107, 277, 107, 262, 121, 272, 121, 275, 107, 272, 121, 277, 107, 285, 135,
    285, 135, 295, 135, 286, 106, 295, 135, 286, 106, 288, 106, 288, 106, 295, 97,
    282, 100, 286, 96,  267, 100, 262, 121, 268, 96,  270, 88,  67,  100, 55,  121,
    53,  125, 47,  135, 53,  125, 279, 125, 282, 135, 47,  135, 282, 135, 279, 125};

int SECTION(".data") str_sector_8009E280 = 0;
int SECTION(".data") str_gcl_proc_8009E284 = 0;
int SECTION(".data") str_8009E288 = 0;
int SECTION(".data") dword_8009E28C = 0;

/* For menu code reversing help
enum
{
    MENU_LIFE = 0,
    MENU_WEAPON,
    MENU_ITEM,
    MENU_RADAR,
    MENU_RADIO,
    MENU_CARD,
    MENU_JIMAKU,

    MENU_VIEWER,

    MENU_MODULE_MAX
};


typedef struct {
    char type;
    char res;
    char x;
    char y;
    unsigned short clut[ 1 ];
} TPK_CLUT;

typedef struct {
    char x;
    char y;
    char w;
    char h;
    unsigned short data[ 1 ];
} TPK_DATA;



typedef struct {
    short id;
    short num;
    short pos;
    short current;
} PANEL;

typedef struct PANEL_TEXTURE {
    // TODO: Missing data
    //ed
    char bufid;
    signed char xofs;
    signed char yofs;
    char pad;
    unsigned long uvclut;
    short w;
    short h;
}PANEL_TEXTURE;


typedef struct {
    DR_ENV dr_env[ 2 ];
    RECT clip_rect;
    DR_ENV org_env[ 2 ];
    short pos_x;
    short pos_y;
    char display_flag;
    char prev_mode;
    short counter;
} RADAR_T;

typedef struct {
    PANEL current;
    PANEL_CONF *panel_conf;
}; // TODO Missing data
*/

TInitKillFn SECTION(".data") gMenuInitFns_8009E290[] = {(TInitKillFn)0x8003CC94, // ??
                                                        (TInitKillFn)0x8003B474, // radar
                                                        (TInitKillFn)0x80042700, // menu_radio_init_80042700
                                                        (TInitKillFn)0x8003CBF0, // invent left
                                                        (TInitKillFn)0x8003EC2C, // invent right
                                                        (TInitKillFn)0x8003F7E0, // bars
                                                        (TInitKillFn)0x80042848, // menu_number_init_80042848
                                                        (TInitKillFn)0x800494C4, // menu_jimaku_init_800494C4
                                                        0};

TInitKillFn SECTION(".data") gMenuKillFns_8009E2B4[] = {(TInitKillFn)0x8003B554,
                                                        (TInitKillFn)0x8004271C, // menu_radio_kill_8004271C
                                                        (TInitKillFn)0x8003CC74,
                                                        (TInitKillFn)0x8003ECAC,
                                                        (TInitKillFn)0x8003F838,
                                                        (TInitKillFn)0x80042980, // menu_number_kill_80042980
                                                        0};

MenuGlue SECTION(".data") gMenuPrimBuffer_8009E2D0 = {{0, 0, 0}, {0, 0}};

TextConfig SECTION(".data") gMenuTextConfig_8009E2E4 = {0, 0, 0, 0x64808080};

int SECTION(".data") dword_8009E2F4[] = {0x808000, 0x100000, 0xA0, 0x10, 0xA0A0, 0x808};

int   SECTION(".data") dword_8009E30C = 0xC1C5080;
int   SECTION(".data") dword_8009E310[] = {0x72C5C80, 0xC1C509C, 0x73A6380, 0xC1C50B8,
                                           0x72C5CB4, 0xC3A6A8A, 0x73A768A}; //, 0xCB632403 };
char  SECTION(".data") byte_8009E32C[] = {0xBC, 0x63, 0x24, 3};
int   SECTION(".data") dword_8009E330 = 0x100A6A80;
char  SECTION(".data") byte_8009E334[] = {0xC4, 0x66, 0x1C, 0x16};
short SECTION(".data") word_8009E338[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xC210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xC210,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xC210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xC210};
int SECTION(".data") dword_8009E3B8[] = {0x182589, 0x184789, 0x182589, 0x338918};

int SECTION(".data") dword_8009E3C8[] = {0x1371D07, 0x1373207, 0x2032E21};
int SECTION(".data") dword_8009E3D4[] = {0x48A000, 0x6E6E, 0xDE, 0x181800};
int SECTION(".data") dword_8009E3E4[] = {0x800115CC, 0x8001158C, 0x80011558, 0x80011524, 0x800114F8, 0x80011494,
                                         0x80011434, 0x800113D0, 0x80011378, 0x80011330, 0x800112D4, 0x8001127C,
                                         0x80011224, 0x800111B0, 0x80011150, 0x800110E8, 0x800110AC, 0x80011060,
                                         0x8001101C, 0x80010FD0, 0x80010F84, 0x80010F50, 0x80010F08, 0x80010EAC};
int SECTION(".data") dword_8009E444 = 0x80011644;
int SECTION(".data") dword_8009E448 = 0x80011614;
int SECTION(".data") dword_8009E44C[] = {0x6A9014B0, 0x6C906B90, 0x6E906D90, 0x7C8015D0, 0x44524148,
                                         0x5845202C, 0x4D455254, 0xD0428220, 0x81298206, 0x902F8127,
                                         0x81499048, 0x810D8127, 0xD004812A, 3};

menu_weapon_rpk_info SECTION(".data") gMenuItemRpkInfo_8009E484[] = {
    {(char *)aCigs, 0xE},    {(char *)aScope, 0x1E},   {(char *)aCBoxA, 0x11},    {(char *)aCBoxB, 0x11},
    {(char *)aCBoxC, 0x11},  {(char *)aNVG, 0xF},      {(char *)aThermG, 0x10},   {(char *)aGasmask, 0x13},
    {(char *)aBArmor, 0x12}, {(char *)aKetchup, 0x19}, {(char *)aStealth, 0x20},  {(char *)aBandana, 0x1F},
    {(char *)aCamera, 0xC},  {(char *)aRation, 0x16},  {(char *)aMedicine, 0x15}, {(char *)aDiazepam, 0x15},
    {(char *)aPalKey, 0x17}, {(char *)aCard, 0x1B},    {(char *)aTimerB, 0x1A},   {(char *)aMineD, 0x14},
    {(char *)aDisc, 0x1C},   {(char *)aRope, 0x18},    {(char *)aScarf, 0x1D},    {(char *)aSuppr, 0xD}};

struct menu_8009E544 SECTION(".data") stru_8009E544[2] = {
    {16, 184, 1, 24576, 36864, (void *)0x8003D64C, (void *)0x8003D594, 0},
    {256, 184, 2, 12288, 49152, (void *)0x8003D594, (void *)0x8003D5F0, 0}};

menu_weapon_rpk_info SECTION(".data") gMenuWeaponRpkInfo_8009E57C[] = {{(char *)aSocom, 1},
                                                                       {(char *)aFamas_800AB5BC, 3},
                                                                       {(char *)aGrenade_800AB5B4, 5},
                                                                       {(char *)aNikita_800AB5AC, 10},
                                                                       {(char *)aStinger_800AB5A4, 9},
                                                                       {(char *)aClaymore, 8},
                                                                       {(char *)aC4_800AB5A0, 7},
                                                                       {(char *)aStunG, 6},
                                                                       {(char *)aChaffG, 11},
                                                                       {(char *)aPsg1, 4}};

int SECTION(".data") dword_8009E5CC[] = {0x80011A8C, 0x80011A30, 0x800119C0, 0x80011954, 0x800118DC,
                                         0x8001187C, 0x80011838, 0x800117C4, 0x80011750, 0x800116E8};

BarConfig SECTION(".data") gSnakeLifeBarConfig_8009E5F4 = {aLife, {16u, 143u, 127u}, {31u, 223u, 63u}, 0};
BarConfig SECTION(".data") gSnakeO2BarConfig_8009E600 = {aO2, {31u, 63u, 192u}, {31u, 127u, 255u}, 1};

int SECTION(".data") dword_8009E60C[] = {0x6D5D2477, 0x257B6B2E, 0x6F7F};
int SECTION(".data") dword_8009E618[] = {0x2070001, 0x7020100, 0x7020107, 0x2070701, 0x7020900, 0x7020907, 0x2070F01};
int SECTION(".data") dword_8009E634 = 0x3D472E;
int SECTION(".data") dword_8009E638 = 0x3D472E;
int SECTION(".data") dword_8009E63C[] = {0x2050001, 0x6020100, 0x6020105, 0x2050601, 0x6020800, 0x6020805, 0x2050D01};
int SECTION(".data") dword_8009E658 = 0x3D472E;
int SECTION(".data") dword_8009E65C = 0x3D472E;
int SECTION(".data") dword_8009E660 = 0xC0F0A0A;
int SECTION(".data") dword_8009E664[] = {
    0x30503A78, 0x601A1F13, 0x2053774, 0x60293020, 0x20537C7, 0x60293020, 0x2056B74, 0x60293020, 0x2056BC7, 0x60293020,
    0x14E3779,  0x60293020, 0x14E6C79, 0x60293020, 0xA3E2681, 0x601A1F13, 0xA3E7581, 0x601A1F13, 0xB194C5A, 0x601A1F13,
    0xB194CCD,  0x601A1F13, 0x12B2654, 0x601A1F13, 0x12B26C1, 0x601A1F13, 0x12B7E54, 0x601A1F13, 0x12B7EC1, 0x601A1F13,
    0x1242E5B,  0x601A1F13, 0x1242EC1, 0x601A1F13, 0x124765B, 0x601A1F13, 0x12476C1, 0x601A1F13};
int               SECTION(".data") dword_8009E6FC[] = {0x4DD651DE, 0x516255D6, 0x556A4D6A};
RadioIncomingCall SECTION(".data") gRadioIncomingCall_8009E708 = {0, 0, -1, 0};
int   SECTION(".data") dword_8009E714[] = {0x240022E, 0x45F023A, 0x63F0221, 0x62D062B, 0x62A062F, 0x37D037B, 0};
int   SECTION(".data") dword_8009E730[] = {0x80043678, 0x80043A24, 0x80043FD0, 0x800442E4, 0x800445F8};
int   SECTION(".data") dword_8009E744[] = {0x800AB6A4, 0x800AB6A0, 0x800AB69C, 0x800AB698, 0x800AB694, 0x800AB690};
void *SECTION(".data") dword_8009E75C[] = {NULL, NULL, NULL, NULL};
int   SECTION(".data") dword_8009E76C[] = {0x100FF, 0xFF000100};
int   SECTION(".data") dword_8009E774[] = {
      0x24A51421, 0x45AD3529, 0x88A5631,  0x217414EF, 0x363929D6, 0x10750C13, 0x195A14D8, 0xEEB19BC,  0x12211,
      0xEA00310,  0x20000000, 0xEC00331,  0x23210012, 0xEB20243,  0x33332213, 0xEA10134,  0x44422233, 0xEA10123,
      0x34322343, 0xED11212,  0x24444443, 0xEE02221,  0x24444343, 0xEE30132,  0x23444233, 0xEE00133,  0x22334301,
      0xEB00123,  0x21224420, 0xD000113,  0x22100100, 0xA100202,  0x32112344, 0x1100201,  0x23233200, 0x1000200,
      0x2212222,  0x1000220,  0,          0,          0x24A51421, 0x45AD3529, 0x88A5631,  0x217414EF, 0x363929D6,
      0x10750C13, 0x195A14D8, 0xEEB19BC,  0x11124444, 0x2221131,  0x21000134, 0x2210222,  0x1114,     0x1230,
      0x10000124, 0x241,      0x11123234, 0x20234,    0x43334444, 0x10234,    0x44444444, 0x221233,   0x44444444,
      0x1011133,  0x34444444, 0x2100123,  0x34444334, 0x1110023,  0x33444421, 0x1000012,  0x33433443, 0x100002,
      0x23320211, 0xB001001,  0x13333233, 0xAC10000,  0x1333322,  0xCB10100,  0,          0,          0x24A51421,
      0x45AD3529, 0x88A5631,  0x217414EF, 0x363929D6, 0x10750C13, 0x195A14D8, 0xEEB19BC,  0x1343023,  0x1102021,
      0x13444312, 0x1001020,  0x3444301,  0x120,      0x22343113, 0x10021,    0x32211213, 0x10012,    0x33334433,
      0x21002,    0x24444433, 0x1002002,  0x24444334, 0x2210001,  0x23444314, 0xB100010,  0x12444302, 0xDA10011,
      0x22344421, 0xEBA0002,  0x22212333, 0xEEC1001,  0x21310100, 0xEC10100,  0x12132344, 0xC312200,  0x2112222,
      0x4233101,  0,          0,          0x2CA51C21, 0x456B3908, 0x5E3151CE, 0x217414EF, 0x363929D6, 0x10550C13,
      0x151814B7, 0x19BC195A, 0x34455555, 0xFA12022,  0x255300,   0xFA12300,  0x241CD,    0xFA12240,  0x21000BDA,
      0xFA11234,  0x445521CD, 0xFB11223,  0x34455300, 0xFDA1123,  0x33445552, 0xFFA1122,  0x33445551, 0xFFA1112,
      0x12344551, 0xFFB1221,  0x31344551, 0xFFDA122,  0x31334451, 0xFFFA112,  0x22014451, 0xFFFB012,  0x24213451,
      0xFFFB111,  0x22313441, 0xFFFB201,  0x22312341, 0xFFFA310,  0,          0,          0x14A90425, 0x35B1252D,
      0x88A4635,  0x217414EF, 0x363929D6, 0x49035844, 0x2A4139A2, 0x1E8316E0, 0x10013444, 0xE021020,  0x12221234,
      0xA010031,  0x12224,    0x32,       0x10001224, 0x200030,   0x10022324, 0x410332,   0x32233434, 0x210333,
      0x44444444, 0x110233,   0x44444444, 0xA010133,  0x44444434, 0xCA10133,  0x34444432, 0xECBA023,  0x34433443,
      0xEEDD013,  0x33421211, 0xEEED102,  0x23333222, 0xEEEC101,  0x12334310, 0xEED0100,  0x1233444,  0xEEA1002,
      0,          0,          0x14A90425, 0x35B1252D, 0x88A4635,  0x217414EF, 0x363929D6, 0x44693427, 0x60CD508B,
      0x64896CEF, 0x11001123, 0xED00210,  0x10000003, 0xEB01100,  0x11201013, 0xB200210,  0x12212124, 0xB020221,
      0x22322234, 0xC211123,  0x44322144, 0xDB10123,  0x33321234, 0xEC01012,  0x23211023, 0xEEB0112,  0x22122102,
      0xEED1121,  0x21222332, 0xEED2122,  0x10121100, 0xEEC0122,  0x10123433, 0xEEA0021,  0x12222100, 0xEC00021,
      0x1221111,  0xEA00102,  0x22222333, 0xB000301,  0,          0};
char SECTION(".data") aBislpm99999[] = "BISLPM-99999        ";
int  SECTION(".data") dword_8009EB4C[] = {0x800AB6F8, 0x8001203C, 0x80012020, 0x80012008, 0x80011FEC, 0x80011FC4,
                                          0x80011FB0, 0x80011F90, 0x80011F6C, 0x80011F5C, 0x80011F34, 0x80011F18};
int  SECTION(".data") dword_8009EB7C[] = {0x800AB6F8, 0x800120B4, 0x80012098, 0x80012008, 0x80012078, 0x80011FC4,
                                          0x80012064, 0x80011F90, 0x80011F6C, 0x80012054, 0x80011F34, 0x80011F18};
int  SECTION(".data") dword_8009EBAC[] = {0x800120E4, 0x800120CC};
int  SECTION(".data") dword_8009EBB4[] = {0x8001210C, 0x80012100};
int  SECTION(".data") dword_8009EBBC = 0;
int  SECTION(".data") dword_8009EBC0[] = {0, (int)aComplete};
int  SECTION(".data") dword_8009EBC8[] = {0, (int)aError};
int  SECTION(".data") dword_8009EBD0[] = {0x4F009B, 0x4A00A0, 0x4F00A5, 0x80808080};
int  SECTION(".data") dword_8009EBE0[] = {0xB8009C, 0xBC00A0, 0xB800A4, 0x80808080};
int  SECTION(".data") off_8009EBF0[] = {(int)dword_800AB728, (int)dword_800AB724, (int)dword_800AB720, (int)aEx};
int  SECTION(".data") off_8009EC00[] = {(int)aMemoryCard1, (int)aMemoryCard2};
int  SECTION(".data") off_8009EC08[] = {(int)dword_800AB754, (int)aNo};
int  SECTION(".data") dword_8009EC10[] = {0x8F826382, 0x8B828382, 0};
int  SECTION(".data") off_8009EC1C[] = {(int)dword_800122D8, (int)dword_800122CC, (int)dword_800122C0,
                                        (int)dword_800122B4, (int)dword_800122A8};
char SECTION(".data") byte_8009EC30[] = {0x47, 0, 0, 1};
int  SECTION(".data") dword_8009EC34[] = {(int)aSaveData, 0x8004D008, 0x8004D14C, 0x8004D1D0};

Menu_Triangle SECTION(".data") stru_8009EC44 = {155, 125, 160, 120, 165, 125, 0x80808080};
Menu_Triangle SECTION(".data") stru_8009EC54 = {156, 212, 160, 216, 164, 212, 0x80808080};

Sna_E2 SECTION(".data") e2_8009EC64 = {12u, 82u, 19u, 23u, 24u, 29u, 30u, 12u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009EC70 = {10u, 8u, 17u, 23u, 24u, 27u, 28u, 80u, 106u, 107u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009EC7C = {11u, 9u, 18u, 23u, 24u, 27u, 28u, 73u, 110u, 111u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009EC88 = {75u, 77u, 79u, 23u, 24u, 27u, 28u, 75u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009EC94 = {92u, 91u, 93u, 23u, 24u, 29u, 30u, 92u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ECA0 = {97u, 96u, 98u, 101u, 24u, 29u, 30u, 97u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ECAC = {104u, 103u, 19u, 23u, 24u, 29u, 30u, 104u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ECB8 = {63u, 65u, 67u, 68u, 69u, 70u, 71u, 72u, 66u, 123u, 130u, 131u};
Sna_E2 SECTION(".data") e2_8009ECC4 = {61u, 64u, 67u, 68u, 69u, 70u, 71u, 72u, 66u, 123u, 130u, 131u};
Sna_E2 SECTION(".data") e2_8009ECD0 = {62u, 83u, 67u, 68u, 69u, 70u, 71u, 72u, 66u, 123u, 130u, 131u};
Sna_E2 SECTION(".data") e2_8009ECDC = {136u, 136u, 35u, 136u, 36u, 37u, 38u, 39u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ECE8 = {42u, 51u, 35u, 45u, 47u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ECF4 = {5u, 52u, 34u, 46u, 48u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ED00 = {74u, 136u, 136u, 136u, 105u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};

Sna_E2 SECTION(".data") e2_8009ED0C = {74u, 136u, 34u, 46u, 81u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ED18 = {43u, 136u, 35u, 136u, 53u, 55u, 49u, 54u, 56u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ED24 = {57u, 136u, 35u, 136u, 58u, 59u, 0u, 0u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ED30 = {60u, 136u, 35u, 136u, 50u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
Sna_E2 SECTION(".data") e2_8009ED3C = {44u, 136u, 136u, 136u, 136u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};

Sna_E6 SECTION(".data") e6_8009ED48 = {115u, 133u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED4C = {112u, 133u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED50 = {113u, 133u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED54 = {136u, 136u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED58 = {114u, 132u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED5C = {116u, 133u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED60 = {117u, 133u, 0u, 0u};
Sna_E6 SECTION(".data") e6_8009ED64 = {118u, 133u, 0u, 0u};

Sna_E1 SECTION(".data") e7_8009ED68 = {7u, 13u, 4u, 14u, 32u, 119u, 124u, 0u};

extern Sna_E1 e1_800AB78C;
extern Sna_E1 e1_800AB7C4;
extern Sna_E1 e1_800AB794;
extern Sna_E1 e1_800AB79C;
extern Sna_E1 e1_800AB7BC;
extern Sna_E1 e1_800AB7AC;
extern Sna_E1 e1_800AB7A4;
extern Sna_E1 e1_800AB7B4;

Sna_ActionTable SECTION(".data") actions_no_weapon_8009ED70 = {&e1_800AB78C, &e2_8009EC64, &e1_800AB7C4, &e2_8009ECB8,
                                                               &e2_8009ECDC, &e6_8009ED48, &e7_8009ED68};

Sna_ActionTable SECTION(".data") weapon_actions_8009ED8C[10] = {
    {&e1_800AB794, &e2_8009EC70, &e1_800AB7C4, &e2_8009ECC4, &e2_8009ECE8, &e6_8009ED4C, &e7_8009ED68},
    {&e1_800AB79C, &e2_8009EC7C, &e1_800AB7C4, &e2_8009ECD0, &e2_8009ECF4, &e6_8009ED50, &e7_8009ED68},
    {&e1_800AB7A4, &e2_8009ECAC, &e1_800AB7C4, &e2_8009ECB8, &e2_8009ED30, &e6_8009ED64, &e7_8009ED68},
    {&e1_800AB7B4, &e2_8009EC88, &e1_800AB7C4, &e2_8009ECD0, &e2_8009ED0C, &e6_8009ED58, &e7_8009ED68},
    {&e1_800AB79C, &e2_8009EC7C, &e1_800AB7C4, &e2_8009ECD0, &e2_8009ED00, &e6_8009ED54, &e7_8009ED68},
    {&e1_800AB7BC, &e2_8009ECA0, &e1_800AB7C4, &e2_8009ECB8, &e2_8009ED24, &e6_8009ED60, &e7_8009ED68},
    {&e1_800AB7AC, &e2_8009EC94, &e1_800AB7C4, &e2_8009ECB8, &e2_8009ED18, &e6_8009ED5C, &e7_8009ED68},
    {&e1_800AB7A4, &e2_8009ECAC, &e1_800AB7C4, &e2_8009ECB8, &e2_8009ED30, &e6_8009ED64, &e7_8009ED68},
    {&e1_800AB7A4, &e2_8009ECAC, &e1_800AB7C4, &e2_8009ECB8, &e2_8009ED30, &e6_8009ED64, &e7_8009ED68},
    {&e1_800AB78C, NULL, &e1_800AB7C4, &e2_8009ECB8, &e2_8009ED3C, &e6_8009ED54, &e7_8009ED68}};

int SECTION(".data") dword_8009EEA4[] = {
    0x8005275C, // sna_init_anim_idle_8005275C
    0x800527DC, // sna_init_anim_crouch_800527DC
    0x800528BC  // sna_init_anim_prone_idle_800528BC
};

int SECTION(".data") dword_8009EEB0[] = {
    0x80052A5C, // sna_init_anim_wall_idle_and_c4_80052A5C
    0x80052CCC  // sna_init_anim_wall_crouch_80052CCC
};

int SECTION(".data") dword_8009EEB8[] = {
    0x8005292C, // sna_init_anim_run_8005292C
    0x8005292C, // sna_init_anim_run_8005292C
    0x800529C0  // sna_init_anim_prone_move_800529C0
};

int SECTION(".data") dword_8009EEC4[] = {0xFA02EE, 0xFA};
int SECTION(".data") dword_8009EECC[] = {0x1F0044C, 0x88};
int SECTION(".data") dword_8009EED4 = 0x47F;
int SECTION(".data") dword_8009EED8[] = {0x2FF01E1, 0};
int SECTION(".data") dword_8009EEE0 = 0x67F;
int SECTION(".data") dword_8009EEE4[] = {0x4FF01E1, 0x84B02E1, 0};
int SECTION(".data") dword_8009EEF0 = 0x17F;
int SECTION(".data") dword_8009EEF4 = 0x39B;
int SECTION(".data") dword_8009EEF8[] = {0x27F0200, 0};
int SECTION(".data") dword_8009EF00[] = {0x650048C, 0};
int SECTION(".data") dword_8009EF08[] = {0x27F0A00, 0};
int SECTION(".data") dword_8009EF10[] = {0x8320250, 0x650048C, 0};
int SECTION(".data") dword_8009EF1C = 0x4C4;
int SECTION(".data") dword_8009EF20 = 0x494;
int SECTION(".data") dword_8009EF24[] = {0x27F0200, 0};

/*
// TODO: Converting this entry de-syncs data
int SECTION(".data") dword_8009EF2C[] = {0x4C8023C, 0x228};
WeaponCreateEntry kSnakeNoWeapon = {0, sna_init_anim_chokethrow_begin1_80054210};
*/

int SECTION(".data") dword_8009EF2C[] = {0x4C8023C, 0x228, 0, 0x80054210};

WeaponCreateEntry SECTION(".data") gSnakeWeapons_8009EF3C[] = {
    {NewSOCOM_80065D74, sna_init_gun_800540D0},
    {famas_create_80066374, sna_init_gun_800540D0},
    {grenade_create_80066A4C, sna_init_anim_grenade_80058470},
    {NewRCM_80066FF0, sna_init_gun_800540D0},
    {NewAAM_80067480, sna_init_anim_stinger_800570C0},
    {mine_init_800677BC, sna_init_anim_claymore_80057474},
    {NewBomb_80067B20, sna_init_bomb_800541A8},
    {NewStanGrenade_80066A74, sna_init_anim_grenade_80058470},
    {NewChaffGrenade_80066AA0, sna_init_anim_grenade_80058470},
    {NewRifle_80068214, sna_init_anim_psg1_80056DDC}};

void *SECTION(".data") gSnakeEquips_8009EF8C[] = {(void *)0x80062274, // tabako
                                                  (void *)0x80063508, // scope
                                                  NewBox_80061C7C,       NewBox_80061C7C,       NewBox_80061C7C,
                                                  (void *)0x8007781C, // goggle
                                                  (void *)0x80078E6C, // goggleir
                                                  gasmask_init_80060C14, bodyarm_init_80060940,
                                                  (void *)0x80072B60,                         // d_blood
                                                  (void *)0x800615FC,                         // kogaku2 - camera ??
                                                  NewBandana_80061E40,   (void *)0x80065118}; // jpegcam

short SECTION(".data") word_8009EFC0[10] = {0, 500, 0, 320, 400, 320, 400, 32, 32, 0};

SVECTOR SECTION(".data") stru_8009EFD4 = {-100, 200, 200, 0};
SVECTOR SECTION(".data") stru_8009EFDC = {-150, 18, 200, 0};

Target_Data SECTION(".data") stru_8009EFE4 = {{0, 0, 300, 0}, {400, 600, 400, 0}, 0, 0, 64, 0};
Target_Data SECTION(".data") stru_8009F004 = {{-400, 0, 600, 0}, {400, 600, 400, 0}, 0, 0, 36, 5};
Target_Data SECTION(".data") stru_8009F024 = {{400, 0, 600, 0}, {400, 600, 400, 0}, 0, 0, 36, 5};
Target_Data SECTION(".data") stru_8009F044 = {{0, 0, 0, 0}, {501, 600, 501, 0}, 0, 0, 7, 0};

MATRIX SECTION(".data") stru_8009F064 = {{{-200, 200, 600}, {0, 400, 200}, {400, 0, 5}}, {50, 0, 1}};
MATRIX SECTION(".data") stru_8009F084 = {{{200, 200, 600}, {0, 400, 200}, {400, 0, -5}}, {50, 0, 1}};
MATRIX SECTION(".data") stru_8009F0A4 = {{{0, 200, 600}, {0, 500, 250}, {500, 0, 0}}, {100, 0, 3}};

short SECTION(".data") word_8009F0C4[8] = {0, 0, 0, 0, -1, 0, 0, 0}; // TODO: some padding likely

struct Anim_Data SECTION(".data") stru_8009F0D4 = {-8302, 2, 262146, 1, 0, 5, 50, 50, 250, 0, (void *)0x800124A8};
struct Anim_Data SECTION(".data") stru_8009F0F0 = {20781, 8, 1966084, 1, 300, 1, 400, 400, 32, 0, (void *)0x8001253C};
struct Anim_Data SECTION(".data") stru_8009F10C = {-6964, 2, 262146, 1, 300, 1, 400, 400, 128, 0, (void *)0x800125CC};
struct Anim_Data SECTION(".data") stru_8009F128 = {-6964, 2, 262146, 1, 300, 1, 1400, 1400, 128, 0, (void *)0x800125F4};
struct Anim_Data SECTION(".data") stru_8009F144 = {-6964, 2, 262146, 1, 300, 1, 400, 400, 128, 0, (void *)0x8001261C};
struct Anim_Data SECTION(".data") stru_8009F160 = {-370, 2, 196610, 1, 300, 1, 600, 600, 100, 0, (void *)0x80012628};
struct Anim_Data SECTION(".data") stru_8009F17C = {32332, 2, 262146, 1, 200, 5, 100, 100, 128, 0, (void *)0x80012634};
struct Anim_Data SECTION(".data") stru_8009F198 = {20781, 8, 1966084, 8, 0, 3, 2200, 2200, 77, 0, (void *)0x80012708};
struct Anim_Data SECTION(".data") stru_8009F1B4 = {20781, 8, 1966084, 1, 0, 1, 1000, 1000, 77, 0, (void *)0x80012728};
struct Anim_Data SECTION(".data") stru_8009F1D0 = {20781, 8, 1966084, 4, 0, 1, 2200, 2200, 128, 0, (void *)0x80012750};
struct Anim_Data SECTION(".data") stru_8009F1EC = {20781, 8, 1966084, 1, 1000, 3, 400, 400, 128, 0, (void *)0x800127A4};
struct Anim_Data SECTION(".data") stru_8009F208 = {20781, 8, 1966084, 1, 1000, 3, 30, 30, 10, 0, (void *)0x800127D0};

int SECTION(".data") dword_8009F224 = 0;

TAnimeVMFn SECTION(".data") anime_fn_table_8009F228[] = {
    (void *)0x8005EC1C, (void *)0x8005ED0C, (void *)0x8005ED74, (void *)0x8005EDDC, (void *)0x8005EE44,
    (void *)0x8005EEA4, (void *)0x8005EF04, (void *)0x8005EFF8, (void *)0x8005F0F0, (void *)0x8005F180,
    (void *)0x8005F288, (void *)0x8005F2F4, (void *)0x8005F37C, (void *)0x8005F408, (void *)0x8005F438};

// TODO: Warning without const, but can't be const else would end up in rdata section?
const char *SECTION(".data") off_8009F264[4] = {aSnaChest1, aSnaChest2, aSnaChest3, aSnaHip1};
const char *SECTION(".data") off_8009F274[4] = {aSnaArmer1, aSnaArmer2, aSnaArmer3, aSnaArmer4};

int SECTION(".data") dword_8009F284 = 0;

const char *SECTION(".data") off_8009F288[8] = {aCbBox11, aCbBox12, aCbBox41, aCbBox42, aCbBox21, aCbBox22, aCbBox41, aCbBox42};

// TODO: Ditto const stuff
const char *SECTION(".data") off_8009F2A8[3] = {aSnaFace, aSnaFace2, aSnaFace3};
const char *SECTION(".data") off_8009F2B4[3] = {aSnaMf1, aSnaMf2, aSnaMf3};

int     SECTION(".data") dword_8009F2C0 = 0;
short   SECTION(".data") scope_created_8009F2C4 = 0;
SVECTOR SECTION(".data") svec_8009F2C8 = {0, 0, 0, 0};
int     SECTION(".data") dword_8009F2D0[] = {0, 0xC80};
char    SECTION(".data") byte_8009F2D8[] = {0x43, 4, 0, 2};
int     SECTION(".data") dword_8009F2DC[] = {0x800129D4, 0x80063704, 0x80063888, 0x800638B4};
char    SECTION(".data") byte_8009F2EC[] = {0, 1, 8, 0x10};
int     SECTION(".data") dword_8009F2F0[] = {0xA030209,  0x19201811, 0x5040B12,  0x211A130C, 0x22293028,
                                             0x60D141B,  0x1C150E07, 0x38312A23, 0x242B3239, 0x170F161D,
                                             0x332C251E, 0x2D343B3A, 0x2E271F26, 0x363D3C35, 0x3F3E372F};
int     SECTION(".data") dword_8009F32C[] = {0x16131002, 0x221D1B1A, 0x18161010, 0x25221D1B, 0x1B1A1613, 0x2622221D,
                                             0x1B1A1616, 0x2825221D, 0x1D1B1A16, 0x30282320, 0x201D1B1A, 0x3A302823,
                                             0x221D1B1A, 0x45382E26, 0x26231D1B, 0x5345382E};
TMat8x8B SECTION(".data") gJpegcamMatrix1_8009F36C = {
    {0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D},
    {0x3F, 0x35, 0x23, 0x0C, 0xF4, 0xDD, 0xCB, 0xC1},
    {0x3B, 0x18, 0xE8, 0xC5, 0xC5, 0xE8, 0x18, 0x3B},
    {0x35, 0xF4, 0xC1, 0xDD, 0x23, 0x3F, 0x0C, 0xCB},
    {0x2D, 0xD3, 0xD3, 0x2D, 0x2D, 0xD3, 0xD3, 0x2D},
    {0x23, 0xC1, 0x0C, 0x35, 0xCB, 0xF4, 0x3F, 0xDD},
    {0x18, 0xC5, 0x3B, 0xE8, 0xE8, 0x3B, 0xC5, 0x18},
    {0x0C, 0xDD, 0x35, 0xC1, 0x3F, 0xCB, 0x23, 0xF4}
};
SVECTOR SECTION(".data") dword_8009F3AC = {0, 0, 0, 0};
SVECTOR SECTION(".data") stru_8009F3B4[2] = {{0, 0, 3200, 0}, {20, -370, 60, 0}};
SVECTOR SECTION(".data") stru_8009F3C4[2] = {{0, -215, 32, 0}, {0, -10455, 32, 0}};
SVECTOR SECTION(".data") stru_8009F3D4[2] = {{0, 600, 32, 0}, {0, -9640, 32, 0}};

int        SECTION(".data") dword_8009F3E4[] = {0x7A643B88, 0xF83D7A64};
int        SECTION(".data") dword_8009F3EC[] = {0x800000, 0x96};
int        SECTION(".data") dword_8009F3F4[] = {0x320000, 0xC8};
int        SECTION(".data") dword_8009F3FC[] = {0x200000, 0x20, 0x1180000, 0x50};

char       SECTION(".data") byte_8009F40C[] = {0, 2, 127, 4, 0};
char       SECTION(".data") byte_8009F414[] = {145, 4, 75, 10, 0};

SVECTOR    SECTION(".data") dword_8009F41C[2] = {{0, 0, 0, 0}, {0, 0, 3000, 0}};
int        SECTION(".data") used_counter_8009F42C = 0;
int        SECTION(".data") dword_8009F430 = 0;
int        SECTION(".data") dword_8009F434 = 0;
SVECTOR    SECTION(".data") svector_8009F438 = {3072, 0, 0, 0};
int        SECTION(".data") dword_8009F440 = 0;
int        SECTION(".data") dword_8009F444 = 0;
int        SECTION(".data") counter_8009F448 = 0;
SVECTOR    SECTION(".data") svec_8009F44C = {0xFD8F, 0xFF06, 0x2EE, 0};
SVECTOR    SECTION(".data") svec_8009F454 = {0xFE0C, 0xFF06, 0x2EE, 0};
SVECTOR    SECTION(".data") svec_8009F45C = {0x1F4, 0xC8, 0x1F4, 0};
SVECTOR    SECTION(".data") svec_8009F464 = {0x12C, 0xC8, 0x12C, 0};
int        SECTION(".data") dword_8009F46C = 0;
int        SECTION(".data") dword_8009F470 = 0;
int        SECTION(".data") dword_8009F474 = 0;
SVECTOR    SECTION(".data") svector_8009F478 = {0, 0, 0, 0};
int        SECTION(".data") dword_8009F480 = 0;
short      SECTION(".data") Nik_Blast_8009F484 = 0;
SVECTOR    SECTION(".data") svector_8009F488 = {100, 100, 100, 0};
int        SECTION(".data") dword_8009F490 = 0;
SVECTOR    SECTION(".data") svector_8009F494 = {0, 0, 0, 0};
int        SECTION(".data") dword_8009F49C = 0;
SVECTOR    SECTION(".data") svector_8009F4A0 = {0, -800, 0, 0};
SVECTOR    SECTION(".data") svector_8009F4A8 = {0, -350, 0, 0};
SVECTOR    SECTION(".data") svector_8009F4B0 = {0, -100, -70, 0};
int        SECTION(".data") dword_8009F4B8[] = {0x100, 5, 0x3E8, 0x7D0, 2};

Blast_Data SECTION(".data") blast_data_8009F4CC = {0x100, 5, 0x3E8, 0x7D0, 6};
Blast_Data SECTION(".data") blast_data_8009F4E0 = {0x100, 5, 0x3E8, 0x7D0, 5};
Blast_Data SECTION(".data") blast_data_8009F4F4 = {0x100, 5, 0x3E8, 0x7D0, 4};
Blast_Data SECTION(".data") blast_data_8009F508 = {0x100, 5, 0x3E8, 0x7D0, 3};
int        SECTION(".data") dword_8009F51C[] = {0x100, 5, 0x3E8, 0x7D0, 0xFFFFFFFF};
int        SECTION(".data") dword_8009F530[] = {0x400, 5, 0x3E8, 0x7D0, 0xA};
Blast_Data SECTION(".data") blast_data_8009F544 = {0, 0, 1, 1, 0xFFFFFFFF};

SVECTOR SECTION(".data") svector_8009F558[2] = {{100, 0, 0, 0}, {2000, 2000, 4000, 4000}};

Anim_Data SECTION(".data") stru_8009F568 = {-21358, 4, 1048580, 1, 2000, 1, 1000, 1000, 128, NULL, (void *)0x80012BAC};
Anim_Data SECTION(".data") stru_8009F584 = {-21358, 4, 1048580, 1, 2000, 1, 1000, 1000, 128, NULL, (void *)0x80012BEC};
Anim_Data SECTION(".data") stru_8009F5A0 = {-21358, 4, 1048580, 1, 2000, 1, 500, 500, 128, NULL, (void *)0x80012C2C};
Anim_Data SECTION(".data") stru_8009F5BC = {-21358, 4, 1048580, 1, 2000, 1, 200, 200, 128, NULL, (void *)0x80012C6C};
Anim_Data SECTION(".data") stru_8009F5D8 = {-21358, 4, 1048580, 1, 2000, 1, 1000, 1000, 128, NULL, (void *)0x80012CAC};

int SECTION(".data") door_where_8009F5F4 = 0;

char  SECTION(".data") byte_8009F5F8[] = {0, 0, 0, 0};
short SECTION(".data") word_8009F5FC = 1;
int   SECTION(".data") dword_8009F600 = 0;
int   SECTION(".data") dword_8009F604 = 0xFFFFFFFF;
int   SECTION(".data") dword_8009F608 = 0;

RECT SECTION(".data") a22dd_8009F60C = {50, 50, 100, 100};

Anim_Data SECTION(".data") stru_8009F614 = {31572, 1, 65537, 1, 500, 3, 300, 300, 200, NULL, (void *)0x80012E84};

SVECTOR SECTION(".data") stru_8009F630[4] = {{20, 0, 0, 0}, {-20, 0, 0, 0}, {0, 20, 0, 0}, {0, -20, 0, 0}};

SVECTOR SECTION(".data") stru_8009F650[2] = {{0, 0, 200, 0}, {0, 0, 10000, 0}};

SVECTOR SECTION(".data") stru_8009F660 = {100, 100, 100, 0};

int SECTION(".data") gSparkRandomTableIndex_8009F668 = 0xFFFFFFFF;
int SECTION(".data") dword_8009F66C = 0;

struct Anim_Data SECTION(".data") stru_8009F670 = {
    19692, 1, 65537, 1, 500, 3, 800, 800, 128, 0, (void *)dword_80012F2C};
struct Anim_Data SECTION(".data") stru_8009F68C = {
    21926, 1, 65537, 1, 500, 3, 600, 600, 180, 0, (void *)dword_80012F50};

int     SECTION(".data") dword_8009F6A8 = 0;
SVECTOR SECTION(".data") svec_8009F6AC = {0, 0, 0, 0};
short   SECTION(".data") word_8009F6B4[] = {0, 0, 0, 0, 0, 0};
short   SECTION(".data") word_8009F6C0[] = {0, 0, 0, 0};
short   SECTION(".data") word_8009F6C8[] = {0, 0};
SVECTOR SECTION(".data") svec_8009F6CC = {0, 400, 0, 0};
int     SECTION(".data") dword_8009F6D4 = 0;
int     SECTION(".data") dword_8009F6D8[] = {0, 0, 0};
int     SECTION(".data") dword_8009F6E4[] = {0xD8F00000, 0};
int     SECTION(".data") aDdd_8009F6EC[] = {0x640064, 0x64};
short   SECTION(".data") word_8009F6F4[] = {0, 0, 0, 0};
SVECTOR SECTION(".data") svec_8009F6FC = {0, 400, 0, 0};
RECT    SECTION(".data") rect_8009F704 = {768, 226, 256, 2};
RECT    SECTION(".data") rect_8009F70C = {768, 196, 256, 2};
short   SECTION(".data") word_8009F714[] = {0, 0};
RECT    SECTION(".data") rect_8009F718 = {768, 226, 256, 2};
RECT    SECTION(".data") rect_8009F720 = {768, 196, 256, 2};
int     SECTION(".data") dword_8009F728 = 0;
RECT    SECTION(".data") rect_8009F72C = {768, 226, 256, 2};
RECT    SECTION(".data") rect_8009F734 = {768, 196, 256, 2};

Anim_Data SECTION(".data") stru_8009F73C = {20781, 8, 1966084, 1, 1000, 3, 500, 500, 255, NULL, (void *)0x8001345C};
Anim_Data SECTION(".data") stru_8009F758 = {20781, 8, 1966084, 3, 0, 1, 1000, 1000, 64, NULL, (void *)0x80013488};
Anim_Data SECTION(".data") stru_8009F774 = {20781, 8, 1966084, 8, 0, 3, 2200, 2200, 255, NULL, (void *)0x800134DC};
Anim_Data SECTION(".data") stru_8009F790 = {9287, 2, 262146, 1, 300, 1, 5000, 5000, 128, NULL, (void *)0x80013510};

SVECTOR SECTION(".data") stru_8009F7AC = {0, 255, 0, 0};

// SD data start

int SECTION(".data") dword_8009F7B4 = 0xFFFFFFFF;

void no_cmd_80087A80(void);
void tempo_set_800873CC(void);
void tempo_move_800873E4(void);
void SD_MDX_D2_sno_set_80086E38(void);
void svl_set_80086E78(void);
void svp_set_80086EB8(void);
void vol_chg_8008756C(void);
void SD_MDX_D6_vol_move_8008758C(void);
void SD_MDX_D7_80087904(void);
void SD_MDX_D8_srs_set_8008798C(void);
void SD_MDX_D9_800879E4(void);
void SD_pan_set_80086F00(void);
void SD_MDX_DE_pan_move_80086F50(void);
void trans_set_8008750C(void);
void SD_MDX_E0_detune_set_80087730(void);
void SD_MDX_E1_vib_set_80087018(void);
void SD_MDX_E2_vib_change_80087120(void);
void SD_MDX_E3_rdm_set_8008716C(void);
void swp_set_8008774C(void);
void sws_set_800876D4(void);
void SD_MDX_E6_por_set_80087670(void);
void SD_MDX_E7_lp1_start_800871B4(void);
void SD_MDX_E8_800871E0(void);
void SD_MDX_E9_lp2_start_800872C0(void);
void SD_MDX_EA_lp2_end_800872EC(void);
void SD_MDX_EB_l3s_set_8008736C(void);
void SD_MDX_EC_l3e_set_80087384(void);
void SD_MDX_ED_kakko_start_80087834(void);
void SD_MDX_EE_kakko_end_80087854(void);
void use_set_80086EF8(void);
void SD_MDX_F2_rest_set_80086D18(void);
void tie_set_80086D9C(void);
void echo_set1_80087754(void);
void echo_set2_8008775C(void);
void SD_MDX_F6_80087764(void);
void SD_MDX_F7_800877CC(void);
void SD_MDX_FF_block_end_80087A58(void);

int SECTION(".data") dword_8009F7B8 = 0;

void *SECTION(".data") gMdxTable_8009F7BC[] = {no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               tempo_set_800873CC,
                                               tempo_move_800873E4,
                                               SD_MDX_D2_sno_set_80086E38,
                                               svl_set_80086E78,
                                               svp_set_80086EB8,
                                               vol_chg_8008756C,
                                               SD_MDX_D6_vol_move_8008758C,
                                               SD_MDX_D7_80087904,
                                               SD_MDX_D8_srs_set_8008798C,
                                               SD_MDX_D9_800879E4,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               SD_pan_set_80086F00,
                                               SD_MDX_DE_pan_move_80086F50,
                                               trans_set_8008750C,
                                               SD_MDX_E0_detune_set_80087730,
                                               SD_MDX_E1_vib_set_80087018,
                                               SD_MDX_E2_vib_change_80087120,
                                               SD_MDX_E3_rdm_set_8008716C,
                                               swp_set_8008774C,
                                               sws_set_800876D4,
                                               SD_MDX_E6_por_set_80087670,
                                               SD_MDX_E7_lp1_start_800871B4,
                                               SD_MDX_E8_800871E0,
                                               SD_MDX_E9_lp2_start_800872C0,
                                               SD_MDX_EA_lp2_end_800872EC,
                                               SD_MDX_EB_l3s_set_8008736C,
                                               SD_MDX_EC_l3e_set_80087384,
                                               SD_MDX_ED_kakko_start_80087834,
                                               SD_MDX_EE_kakko_end_80087854,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               use_set_80086EF8,
                                               SD_MDX_F2_rest_set_80086D18,
                                               tie_set_80086D9C,
                                               echo_set1_80087754,
                                               echo_set2_8008775C,
                                               SD_MDX_F6_80087764,
                                               SD_MDX_F7_800877CC,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               no_cmd_80087A80,
                                               SD_MDX_FF_block_end_80087A58};

unsigned char SECTION(".data") rdm_tbl_8009F9BC[129] = {
    159u, 60u,  178u, 82u,  175u, 69u,  199u, 137u, 16u,  127u, 224u, 157u, 220u, 31u,  97u,  22u,  57u,  201u, 156u,
    235u, 87u,  8u,   102u, 248u, 90u,  36u,  191u, 14u,  62u,  21u,  75u,  219u, 171u, 245u, 49u,  12u,  67u,  2u,
    85u,  222u, 65u,  218u, 189u, 174u, 25u,  176u, 72u,  87u,  186u, 163u, 54u,  11u,  249u, 223u, 23u,  168u, 4u,
    12u,  224u, 145u, 24u,  93u,  221u, 211u, 40u,  138u, 242u, 17u,  89u,  111u, 6u,   10u,  52u,  42u,  121u, 172u,
    94u,  167u, 131u, 198u, 57u,  193u, 180u, 58u,  63u,  254u, 79u,  239u, 31u,  0u,   48u,  153u, 76u,  40u,  131u,
    237u, 138u, 47u,  44u,  102u, 63u,  214u, 108u, 183u, 73u,  34u,  188u, 101u, 250u, 207u, 2u,   177u, 70u,  240u,
    154u, 215u, 226u, 15u,  17u,  197u, 116u, 246u, 122u, 44u,  143u, 251u, 25u,  106u, 229u};

unsigned char SECTION(".data") VIBX_TBL_8009FA40[32] = {
    0u,   32u,  56u,  80u,  104u, 128u, 144u, 160u, 176u, 192u, 208u, 224u, 232u, 240u, 240u, 248u,
    255u, 248u, 244u, 240u, 232u, 224u, 208u, 192u, 176u, 160u, 144u, 128u, 104u, 80u,  56u,  32u};

int SECTION(".data") pant_8009FA60[41] = {0,   2,   4,   7,   10,  13,  16,  20,  24,  28,  32,  36,  40,  45,
                                          50,  55,  60,  65,  70,  75,  80,  84,  88,  92,  96,  100, 104, 107,
                                          110, 112, 114, 116, 118, 120, 122, 123, 124, 125, 126, 127, 127};

int SECTION(".data") se_pant_8009FB04[65] = {
    0,   2,   4,   6,   8,   10,  14,  18,  22,  28,  34,  40,  46,  52,  58,  64,  70,  76,  82,  88,  94,  100,
    106, 112, 118, 124, 130, 136, 142, 148, 154, 160, 166, 172, 178, 183, 188, 193, 198, 203, 208, 213, 217, 221,
    224, 227, 230, 233, 236, 238, 240, 242, 244, 246, 248, 249, 250, 251, 252, 253, 254, 254, 255, 255, 255};

int SECTION(".data") freq_tbl_8009FC08[108] = {
    0x10B,  0x11B,  0x12C,  0x13E,  0x151,  0x165,  0x17A,  0x191,  0x1A9,  0x1C2,  0x1DD,  0x1F9,  0x217,  0x237,
    0x259,  0x27D,  0x2A3,  0x2CB,  0x2F5,  0x322,  0x352,  0x385,  0x3BA,  0x3F3,  0x42F,  0x46F,  0x4B2,  0x4FA,
    0x546,  0x596,  0x5EB,  0x645,  0x6A5,  0x70A,  0x775,  0x7E6,  0x85F,  0x8DE,  0x965,  0x9F4,  0xA8C,  0xB2C,
    0xBD6,  0xC8B,  0xD4A,  0xE14,  0xEEA,  0xFCD,  0x10BE, 0x11BD, 0x12CB, 0x13E9, 0x1518, 0x1659, 0x17AD, 0x1916,
    0x1A94, 0x1C28, 0x1DD5, 0x1F9B, 0x217C, 0x237A, 0x2596, 0x27D2, 0x2A30, 0x2CB2, 0x2F5A, 0x322C, 0x3528, 0x3850,
    0x3BAC, 0x3F36, 0x21,   0x23,   0x26,   0x28,   0x2A,   0x2D,   0x2F,   0x32,   0x35,   0x38,   0x3C,   0x3F,
    0x42,   0x46,   0x4B,   0x4F,   0x54,   0x59,   0x5E,   0x64,   0x6A,   0x70,   0x77,   0x7E,   0x85,   0x8D,
    0x96,   0x9F,   0xA8,   0xB2,   0xBD,   0xC8,   0xD4,   0xE1,   0xEE,   0xFC};

int SECTION(".data") dword_8009FDB8[] = {
    0xD0780000, 0xD5FF0000, 0xD2290000, 0xD77F0F08, 0xD8440000, 0xD9100000, 0x2B095A40, 0xFFFE0000, 0xD0780000,
    0xD5FF0000, 0xD22A0000, 0xD77F0F08, 0xD8440000, 0xD9100000, 0x2B095A40, 0xFFFE0000, 0xD0FF0000, 0xD5C00000,
    0xD22B0000, 0xD77F000F, 0xD8000000, 0xD9140000, 0x170C3C7F, 0xFFFE0000, 0xD0FF0100, 0xD57F0000, 0xD2280000,
    0xD77F000F, 0xD8000000, 0xD9140000, 0x210C5A57, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD2180000, 0xD77F000F,
    0xD8000000, 0xD9100000, 0x1F09501E, 0x25095032, 0x2B095046, 0x3130145A, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xD2170000, 0xD77F0F08, 0xD8400000, 0xD9120000, 0x25095028, 0x2B095050, 0x31095064, 0x37301478, 0xFFFE0000,
    0xD0FF0100, 0xD5FF0000, 0xD24900FF, 0xD77F000F, 0xD8000000, 0xD91A0000, 0x29020114, 0xD24A0000, 0xD77F0F08,
    0xD8200000, 0xD9170000, 0x18040140, 0xD2220000, 0xD77F0F08, 0xD8200000, 0xD9170000, 0x303C0120, 0xFFFE0000,
    0xD0FF0100, 0xD57F0000, 0xD2260000, 0xDF00000F, 0xD77F0E08, 0xD8400000, 0xD91F0000, 0x43060A7F, 0x3703237F,
    0xD2171430, 0xD77F0E08, 0xD8400000, 0xD91F0000, 0x450C1440, 0xFFFE0000, 0xD0FF0100, 0xD5E00000, 0xD2400000,
    0xD77F000F, 0xD8000000, 0xD91F0000, 0x21065A50, 0xD2040000, 0xD77F000F, 0xD8000000, 0xD91F0000, 0x34010130,
    0x21065060, 0xE4010210, 0xD9122040, 0x1A182020, 0xE4000209, 0xFFFE0000, 0xD0FF0000, 0xD57F0000, 0xD2260000,
    0xD77F000F, 0xD8000000, 0xD91F0000, 0x2803017F, 0xD9180000, 0x4503017F, 0x2F12017F, 0xFFFE0000, 0xD0FF0000,
    0xD5C00000, 0xD226000F, 0xD77F000F, 0xD8000000, 0xD9180000, 0x37090154, 0x2E120154, 0xFFFE0000, 0xD0FF0100,
    0xD57F0000, 0xD2260000, 0xDF00000F, 0xD77F000F, 0xD8000000, 0xD91F0000, 0x4004017F, 0xD20D1430, 0xD77F0E08,
    0xD8400000, 0xD91F0000, 0x450C147F, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD2040000, 0xD75C000F, 0xD8000000,
    0xD9140000, 0x1C0C147F, 0xE4000C04, 0xD77F0F0F, 0xD8360000, 0xD9110000, 0x3C303254, 0xE4000C02, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xD2040000, 0xDF000F0F, 0xD77F000F, 0x1008287F, 0xE4000804, 0x406287F,  0xD2262854,
    0x28102868, 0xE4000604, 0xFFFE0000, 0xD0FF0000, 0xD57F0000, 0xD204507F, 0xD77F000F, 0xD8000000, 0xD9180000,
    0x47030168, 0x23030168, 0xE7060140, 0x3B015A68, 0x3A015A68, 0xE803009D, 0xD91F0000, 0xE7060140, 0x20015A40,
    0x21015A40, 0xE820FCD8, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD203507F, 0xD752000F, 0xD8000000, 0xD9180000,
    0x1312327F, 0xE4030909, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD2040000, 0xD77F000F, 0xC052854,  0xE4000C07,
    0xD210507F, 0xD77F000F, 0xD8000000, 0xD9180000, 0xE7060140, 0x2B015A40, 0x2C015A30, 0xE802E000, 0xE7060140,
    0x34015A20, 0x3A025A18, 0xE808FC00, 0xFFFE0000, 0xD0FF0000, 0xD57F0000, 0xD204507F, 0xD75E000F, 0xD8000000,
    0xD9180000, 0x43080154, 0x44090140, 0x42080154, 0x3C090140, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD2000000,
    0xD77F000F, 0xD8000000, 0xD9000000, 0xE3000000, 0xC06637F,  0x3C076330, 0xE4000607, 0xE3FF0FFF, 0xD77F0F0C,
    0xD8405A64, 0xD9115A64, 0x1530287F, 0xE4006007, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xD24900FF, 0xD77F000F,
    0xD8000000, 0xD91A0000, 0x29020114, 0xD21000FF, 0xD77F0F06, 0xD8000000, 0xD9180000, 0x32090A50, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xD20000FF, 0xD753000F, 0xD8480000, 0xD9100000, 0x3009637F, 0xE4000618, 0x1809637F,
    0xE400060C, 0xD58C01FF, 0xD22601FF, 0xD77F000F, 0xD8400000, 0xD9100000, 0xE7010120, 0x40016404, 0xE80A0400,
    0xE7010120, 0x40016430, 0xE830FFFD, 0xF2020000, 0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xD204507F, 0xD7570F07,
    0xD8000000, 0xD9180000, 0xE7060140, 0x40055A2C, 0x45045A40, 0xE804F0D0, 0xFFFE0000, 0xD0FF0000, 0xD5C00000,
    0xD202637F, 0xD7520808, 0xD8480C0C, 0xD911637F, 0x46302840, 0xE4000645, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF607507F, 0xD207507F, 0xD77F000F, 0xD8000000, 0xD9180000, 0xDD000018, 0xDF0C3218, 0x43062814, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xD203637F, 0xD75A0808, 0xD8480C0C, 0xD911637F, 0x47182828, 0xE4000645, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xD204507F, 0xD760000F, 0xD8000000, 0xD9180000, 0x4030A7F,  0x90C0A7F,  0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xD24000FF, 0xD77F000F, 0xD8000000, 0xD9180000, 0x1F093C48, 0xD20400FF, 0xD75C000F,
    0xD8000000, 0xD9180000, 0x2606632C, 0xE400060C, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF6020000, 0xD2020000,
    0xD77F0F0F, 0xD8000000, 0xD9000000, 0x402A0450, 0xE4010C46, 0xE00A0A3C, 0x402E0458, 0xE4010C46, 0x40270450,
    0xE4010C46, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF6170000, 0xD2170000, 0xD77F0F0F, 0xD8000000, 0xD9140000,
    0x1301640A, 0x1903641E, 0x1F036432, 0x25036446, 0x2B03645A, 0x3103646E, 0xD77F0F03, 0xD840FF10, 0x34243C7F,
    0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF6170000, 0xD2170000, 0xD77F000F, 0xD8000000, 0xD9140000, 0x1903640A,
    0x1F03641E, 0x25036432, 0x2B036446, 0x3103645A, 0x3703646E, 0xD77F0F03, 0xD848FF10, 0xE128FF10, 0x3A481E7F,
    0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF6170000, 0xD2170000, 0xD77F000F, 0xD8000000, 0xD9140000, 0x1602640A,
    0x1C03641E, 0x22036432, 0x28036446, 0x2E03645A, 0x3403646E, 0xD77F000F, 0xD8480F0F, 0xE128FF20, 0x37481E7F,
    0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF60E507F, 0xD20E507F, 0xD77F080C, 0xD8000000, 0xD9110000, 0xE7065040,
    0x3E045020, 0x42035018, 0xE8040000, 0xE7065040, 0x3E045009, 0x42035006, 0xE8020000, 0xE7065040, 0x3E045020,
    0x42035018, 0xE8040000, 0xE7065040, 0x3E045009, 0x42035006, 0xE8030000, 0xFFFE0000, 0xD0780000, 0xF7FF0000,
    0xD5FF0000, 0xD2410000, 0xDF00000F, 0xD77F000F, 0xD8000000, 0xD91F0000, 0x181A6364, 0xFFFE0000, 0xD0780000,
    0xF7FF0000, 0xD5FF0000, 0xD2400000, 0xDF00000F, 0xD77F000F, 0xD8000000, 0xD9130000, 0x18181E64, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xF713507F, 0xD213507F, 0xD758080C, 0xD8400000, 0xD9120000, 0x37180A7F, 0xE404083E,
    0x37180A30, 0xE404083E, 0x37180A18, 0xE404083E, 0xFFFE0000, 0xD0FF0000, 0xF6FF0000, 0xD5FF0000, 0xD213507F,
    0xD7550802, 0xD8000000, 0xD9110000, 0x26066470, 0xE400061A, 0x1A262870, 0xE400203E, 0xFFFE0000, 0xD0FF0000,
    0xF7FF0000, 0xD5FF0000, 0xD241507F, 0xD77F000F, 0xD8000000, 0xD9110000, 0x24066360, 0xD242507F, 0xD77F000F,
    0xD8000000, 0xD9110000, 0x181C6360, 0xD213507F, 0xD7550802, 0xD8000000, 0xD9110000, 0x26066420, 0xE400061A,
    0x1A262820, 0xE400203E, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF713507F, 0xD213507F, 0xD77F0905, 0xD8000000,
    0xD9110000, 0x3912017F, 0xFFFE0000, 0xD0780000, 0xF7FF0000, 0xD5FF0000, 0xD23F0000, 0xDF00000F, 0xD77F000F,
    0xD8000000, 0xD91F0000, 0x1D2C6350, 0xE4061811, 0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xF738507F, 0xD238507F,
    0xD77F000F, 0xD8000000, 0xD9120000, 0x17126368, 0xE4000C15, 0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xD239507F,
    0xD77F000F, 0xD8000000, 0xD9100000, 0x18185058, 0xE4000C15, 0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xF63D507F,
    0xD23D507F, 0xD77F000F, 0xD8000000, 0xD9110000, 0x16283C78, 0x16283C40, 0x16283C20, 0x16283C10, 0x16283C08,
    0xFFFE0000, 0xD0780000, 0xF7FF0000, 0xD5FF0000, 0xD2270000, 0xDF00000F, 0xD77F000F, 0xD8000000, 0xD91F0000,
    0x1B326350, 0xE403180F, 0xFFFE0000, 0xD0780000, 0xF7FF0000, 0xD5FF0000, 0xD2270000, 0xDF00000F, 0xD77F000F,
    0xD8000000, 0xD91F0000, 0x1D206350, 0xFFFE0000, 0xD0800000, 0xD5DF0000, 0xF73C507F, 0xD23C507F, 0xD77F000F,
    0xD8000000, 0xD9100000, 0x18285048, 0xFFFE0000, 0xD0FF0100, 0xD5A80000, 0xF7040000, 0xD24A0000, 0xD77F000F,
    0xD8002854, 0xD9182854, 0x1C045A30, 0xD22A507F, 0xD77F000F, 0xD8000000, 0xD9180000, 0x2B065A40, 0xD229507F,
    0xD77F000F, 0xD8000000, 0xD9180000, 0x2B0C5A40, 0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xF6800000, 0xD2430000,
    0xD77F0F08, 0xD840647F, 0xD90F647F, 0x1A18507F, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6060118, 0xD20A0130,
    0xD7620F06, 0xD8441430, 0xD9181430, 0x3C0C5068, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6060118, 0xD2050130,
    0xD74E0C08, 0xD8451430, 0xD9121430, 0xDD000430, 0xDF061430, 0x47601428, 0xE400201B, 0xFFFE0000, 0xD0FF0100,
    0xD5FF0000, 0xF6060118, 0xD20A0130, 0xD74E0C08, 0xD8451430, 0xD9111430, 0xDD000050, 0x2D600A64, 0xFFFE0000,
    0xD0FF0100, 0xD5FF0000, 0xF6060118, 0xD2370130, 0xD74E0C08, 0xD8451430, 0xD9111430, 0xDD00FC20, 0x39600D3C,
    0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6060118, 0xD2370130, 0xD7520E04, 0xD8441430, 0xD9101430, 0xDD00FC30,
    0x37603C23, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6060118, 0xD2260130, 0xD7500F03, 0xD8441430, 0xD9161430,
    0xDD000440, 0x43600A20, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF613507F, 0xD213507F, 0xD7560808, 0xD8400000,
    0xD9120000, 0x37180A7F, 0xE404083E, 0x37180A30, 0xE404083E, 0x37180A18, 0xE404083E, 0xFFFE0000, 0xD0FF0000,
    0xD5FF0000, 0xF716507F, 0xD216507F, 0xD7560806, 0xD8400000, 0xD9120000, 0x2B180A20, 0xE4040832, 0xFFFE0000,
    0xD0800000, 0xD5FF0000, 0xD242507F, 0xD77F000F, 0xD8400000, 0xD9120000, 0x1C050A40, 0x26180A40, 0xFFFE0000,
    0xD0FF0100, 0xD5FF0000, 0xD2250000, 0xD77F000F, 0xD8480000, 0xD9140000, 0x18060118, 0xD2220000, 0xD77F000F,
    0xD8480000, 0xD9130000, 0xC180130,  0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xD2250000, 0xD77F000F, 0xD8480000,
    0xD9140000, 0x18060120, 0xD2240000, 0xD77F000F, 0xD8480000, 0xD9130000, 0xC180120,  0xFFFE0000, 0xD0FF0100,
    0xD5FF0000, 0xF7260000, 0xD2320000, 0xD760000F, 0xD8400000, 0xD9100000, 0xC070A30,  0x1060037F, 0xFFFE0000,
    0xD0FF0100, 0xD5FF0000, 0xF7260000, 0xD21E0000, 0xD77F000F, 0xD8000000, 0xD9140000, 0x15060A40, 0xD2240000,
    0xD77F000F, 0xD8400000, 0xD9110000, 0x13401430, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF7260000, 0xD24B0000,
    0xD7500F0D, 0xD8400000, 0xD9100000, 0x284C0A30, 0xE4000329, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF7260000,
    0xD2320000, 0xD74E000F, 0xD8400000, 0xD9100000, 0x11903C7F, 0xFFFE0000, 0xD0FF0130, 0xD5FF0130, 0xF6160130,
    0xD2130130, 0xD77F000F, 0xD8001430, 0xD91C1430, 0x390C5030, 0xFFFE0000, 0xD0FF0000, 0xD5A80000, 0xF60E507F,
    0xD202507F, 0xD77F080C, 0xD8000000, 0xD9110000, 0xE7065040, 0x32045050, 0x36035040, 0xE8040000, 0xE7065040,
    0x32045012, 0x3603500C, 0xE8020000, 0xE7065040, 0x32045050, 0x36035040, 0xE8040000, 0xE7065040, 0x32045012,
    0x3603500C, 0xE8030000, 0xFFFE0000, 0xD0800100, 0xD5FF0000, 0xF7000000, 0xD2420130, 0xD77F000F, 0xD8001430,
    0xD9181430, 0x260C0140, 0xFFFE0000, 0xD0FF0000, 0xD5C00000, 0xD23F0100, 0xD77F000F, 0xD8000000, 0xD9000000,
    0x24036330, 0xE4000707, 0xD2470FFF, 0xD77F0F0C, 0xD8405A64, 0xD9115A64, 0x15062860, 0x1A182860, 0xFFFE0000,
    0xD0FF0100, 0xD5A00000, 0xF7260000, 0xD2260000, 0xD77F000F, 0xD8000000, 0xD9130000, 0x34015A60, 0x28015A60,
    0x34015A60, 0x28015A60, 0xD2280000, 0xD77F000F, 0xD8000000, 0xD9130000, 0x28185A40, 0xFFFE0000, 0xD0FF0100,
    0xD5B00000, 0xD2400000, 0xD77F000F, 0xD8000000, 0xD91F0000, 0x1B095A7F, 0xD77F0F01, 0xD9132040, 0x13205060,
    0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF7040000, 0xD23F0000, 0xD77F000F, 0xD8000000, 0xD9000000, 0x1106637F,
    0x1806637F, 0xD23F0000, 0xDF10000F, 0xD77F000F, 0xD8000000, 0xD9000000, 0xC07647F,  0xE4000705, 0xD77F0F0C,
    0xD8405A64, 0xD9105A64, 0x890467F,  0xE4009000, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD210507F, 0xD77F000F,
    0xD8000000, 0xD9180000, 0x26030140, 0xE4000328, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD210507F, 0xD77F000F,
    0xD8000000, 0xD9180000, 0x26030140, 0xE4000328, 0xD210507F, 0xD77F000F, 0xD8000000, 0xD9140000, 0x150C0A40,
    0xE4000C21, 0x150C0A20, 0xE4000C21, 0x150C0A10, 0xE4000C21, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD20D507F,
    0xD77F0F08, 0xD8000000, 0xD91F0000, 0x280C1E30, 0x281C6330, 0xFFFE0000, 0xD0FF0000, 0xD5600000, 0xD204507F,
    0xD77F000F, 0xD8000000, 0xD9180000, 0x47030168, 0x23030168, 0xE7060140, 0x3B015A60, 0x3A015A60, 0xE803009D,
    0x47030158, 0x23030158, 0xE7060140, 0x3B015A50, 0x3A015A50, 0xE803009D, 0xFFFE0000, 0xD0FF0000, 0xD5C00000,
    0xD241507F, 0xD77F000F, 0xD8000000, 0xD9180000, 0x3C01647F, 0x240E507F, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF707507F, 0xD23F507F, 0xD77F000F, 0xD8000000, 0xD90F0000, 0x15056360, 0x9056332,  0x405637F,  0x10FF6360,
    0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF707507F, 0xD204507F, 0xD77F000F, 0xD800507F, 0xD914507F, 0x1805017F,
    0xC050150,  0xD204507F, 0xD77F0008, 0xD87F0000, 0xD9100000, 0x13F637F,  0xD77F0004, 0x3C02830,  0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xF707507F, 0xD242507F, 0xD77F000F, 0xD8000000, 0xD9190000, 0x24090140, 0x2B0C0120,
    0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF7260000, 0xD21E0000, 0xD77F000F, 0xD8480000, 0xD9140000, 0x18060130,
    0xD2320000, 0xD77F000F, 0xD8420000, 0xD9130000, 0xC303C60,  0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF7260000,
    0xD2320000, 0xD74A000F, 0xD8400000, 0xD9100000, 0x17905A7F, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF707507F,
    0xD229507F, 0xD75E000F, 0xD8000000, 0xD9120000, 0x2D0A0148, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF707507F,
    0xD22A507F, 0xD75E000F, 0xD8000000, 0xD9120000, 0x2E0A0148, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF607507F,
    0xE3FF00FF, 0xD226507F, 0xD74C0608, 0xD8000000, 0xD9100000, 0xE5004006, 0x70C6430,  0xE70C6446, 0xF30C6446,
    0xE8000000, 0xF3600100, 0xE4006002, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF607507F, 0xD232507F, 0xD750000F,
    0xD8000000, 0xD90A0000, 0xE500070C, 0x12103260, 0xD753000F, 0xE5000100, 0x18203C40, 0xD219507F, 0xD742000F,
    0xD8000000, 0xD9110000, 0x390C6403, 0xE7C06446, 0xF30C6446, 0xE8000000, 0xF3180100, 0xE4001835, 0xD232507F,
    0xD750000F, 0xD8000000, 0xD9100000, 0xE5000803, 0x12153260, 0x18303C40, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF607507F, 0xD24B507F, 0xD742000F, 0xD8000000, 0xD9110000, 0x1D0C6410, 0xE7605A32, 0xF30C6432, 0xE8000000,
    0xF318017F, 0xD203507F, 0xD74A0808, 0xD83C0000, 0xD9100000, 0x2B603218, 0xE4006010, 0xFFFE0000, 0xD0FF0000,
    0xD5C80000, 0xF625507F, 0xD225507F, 0xD760000F, 0xD8000000, 0xD91B0000, 0x39030120, 0xD9170000, 0x3A05017F,
    0xD91A0000, 0x38030120, 0xD9160000, 0x39060178, 0xD91B0000, 0x37030120, 0xD9160000, 0x3804016F, 0xD91A0000,
    0x38030120, 0xD9170000, 0x39060166, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF704507F, 0xD229507F, 0xD760000F,
    0xD8000000, 0xD90F0000, 0x2D06637F, 0xD22A507F, 0xD760000F, 0x2803637F, 0xD227507F, 0xD74F0A0F, 0xD8000000,
    0xD91E0000, 0x350C5A40, 0xD7440A0F, 0x37125A50, 0xFFFE0000, 0xD09B0000, 0xD5B40000, 0xF607507F, 0xD20D507F,
    0xD75C000F, 0xD8360000, 0xD9100000, 0xE106FF10, 0xE5000604, 0x22301434, 0x210E630C, 0xFFFE0000, 0xD0FF0000,
    0xD5A80000, 0xF707507F, 0xD204507F, 0xD75D000F, 0xD8000000, 0xD9150000, 0x23060A40, 0x200C0A40, 0xD229507F,
    0xD75D000F, 0xD8000000, 0xD90F0000, 0x2D0C6340, 0xD75D000F, 0x28086320, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF7420000, 0xD2420000, 0xD77F000F, 0xD8000000, 0xD91F0000, 0x1F040160, 0xD9180000, 0x24040160, 0x21205040,
    0xFFFE0000, 0xD0800000, 0xD5C00000, 0xF6800000, 0xD2440000, 0xD77F000F, 0xD8466350, 0xD9106350, 0xDD00F250,
    0x1C0E3C40, 0xDD000E50, 0x1A303C10, 0xFFFE0000, 0xD0FF0000, 0xD5800000, 0xF607507F, 0xD23F507F, 0xD77F000F,
    0xD8000000, 0xD9140000, 0x39035A40, 0xE4000321, 0xD246507F, 0xD77F000F, 0xD8000000, 0xD9140000, 0x24065A40,
    0x260C5A40, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD245507F, 0xD77F000F, 0xD8000000, 0xD9130000, 0x1F245A50,
    0xE4081022, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD248507F, 0xD757000F, 0xD8000000, 0xD9190000, 0xE5001208,
    0x29185A50, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD248507F, 0xD757000F, 0xD8000000, 0xD9190000, 0xE5001208,
    0x21185A50, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD23F507F, 0xD77F0F07, 0xD8440000, 0xD9190000, 0x1C035040,
    0xD247507F, 0xD77F0F0A, 0xD8000000, 0xD9120000, 0x18200A60, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xD247507F,
    0xD77F0F0A, 0xD8000000, 0xD9120000, 0x1A205050, 0xE4061815, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF707507F,
    0xD209507F, 0xD7550A08, 0xD84A0000, 0xD90F0000, 0xE100FF0F, 0x3C303214, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF604507F, 0xD213507F, 0xD7560C06, 0xD8480000, 0xD9110000, 0xE5001224, 0x32240A20, 0xFFFE0000, 0xD0FF0000,
    0xD5FF0000, 0xF604507F, 0xD208507F, 0xD7540C06, 0xD8480000, 0xD9110000, 0xE5001218, 0x45240A0C, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xF605507F, 0xD204507F, 0xD7580F0A, 0xD8000000, 0xD91C0000, 0x2D105A18, 0xD207507F,
    0xD7560C06, 0xD8480000, 0xD9110000, 0xE50012F4, 0x39240A10, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF705507F,
    0xD20A507F, 0xD77F000F, 0xD8000000, 0xD91C0000, 0x2F0C5A12, 0xF613507F, 0xD213507F, 0xD7560C08, 0xD8480000,
    0xD9110000, 0xE50012F4, 0x34240A20, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6000000, 0xD2130130, 0xD77F000F,
    0xD8001430, 0xD91C1430, 0x3C060130, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF61B507F, 0xD203507F, 0xD755000F,
    0xD8000000, 0xD9110000, 0xE5002418, 0x45245030, 0xFFFE0000, 0xD0FF0100, 0xD5A00000, 0xF6000000, 0xD20A0130,
    0xD77F000F, 0xD8001430, 0xD91A1430, 0x3C0C1430, 0xFFFE0000, 0xD0FF0100, 0xD5A00000, 0xF6000000, 0xD2130130,
    0xD77F000F, 0xD84D1430, 0xD91C1430, 0x39035030, 0xD2160130, 0xD77F000F, 0xD8001430, 0xD91A1430, 0x390C0A12,
    0x390C0A04, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF70E507F, 0xD213507F, 0xD77F000F, 0xD8000000, 0xD9160000,
    0xE7065040, 0x3C010118, 0x3C010118, 0xE8080000, 0xF3080140, 0xE4000837, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF70E507F, 0xD217507F, 0xD77F000F, 0xD8000000, 0xD9140000, 0x46183C07, 0xE4100835, 0xFFFE0000, 0xD0FF0000,
    0xD5C00000, 0xF613507F, 0xD20A507F, 0xD77F0F08, 0xD8480000, 0xD9140000, 0x2B06017F, 0xE4030339, 0x37060140,
    0xE4030339, 0x37060130, 0xE4030339, 0x37060120, 0xE4030339, 0x37060118, 0xE4030339, 0x3706010C, 0xE4030339,
    0x37060106, 0xE4030339, 0xFFFE0000, 0xD0FF0000, 0xD5400000, 0xF613507F, 0xD211507F, 0xD760000F, 0xD8000000,
    0xD9120000, 0x2F060140, 0x36060160, 0x3B06017F, 0x42060130, 0x47060140, 0x42060118, 0x47060120, 0xFFFE0000,
    0xD0FF0000, 0xD5A80000, 0xF613507F, 0xDF08507F, 0xD20E507F, 0xD758000F, 0xD8360000, 0xD9160000, 0xE5010C18,
    0x3B0C5060, 0x3E0B5050, 0x410A5040, 0x440A5030, 0x47095020, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF607507F,
    0xD226507F, 0xD77F0C08, 0xD83A0000, 0xD90F0000, 0xDD00007F, 0x3CFF647F, 0xE400FF30, 0xF3803C7F, 0xE400FF2A,
    0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF607507F, 0xD219507F, 0xD77F0C08, 0xD83A0000, 0xD90F0000, 0xDD00007F,
    0x45FF6440, 0xF3803C00, 0xFFFE0000, 0xD0FF0000, 0xD5800000, 0xF607507F, 0xD203507F, 0xD77F0F0A, 0xD8480000,
    0xD9160000, 0xD640FF40, 0xDF0BEC40, 0xED00EC40, 0xDD00EC40, 0x3B04017F, 0xDD001440, 0x38040170, 0xDD00EC40,
    0x36040160, 0xDD001440, 0x39040170, 0xDD00EC40, 0x3B04017F, 0xDD001440, 0x38040170, 0xDD00EC40, 0x36040160,
    0xDD001440, 0x39040170, 0xEE00EC40, 0xDF0AEC40, 0xEE00EC40, 0xDF09EC40, 0xEE00EC40, 0xD6F40040, 0xDF08EC40,
    0xEE00EC40, 0xDF07EC40, 0xEE00EC40, 0xDF06EC40, 0xEE00EC40, 0xDF05EC40, 0xEE00EC40, 0xDF04EC40, 0xEE00EC40,
    0xDF03EC40, 0xEE00EC40, 0xDF02EC40, 0xEE00EC40, 0xDF01EC40, 0xEE00EC40, 0xFFFE0000, 0xD0FF0000, 0xD5800000,
    0xF707507F, 0xDF0C507F, 0xD209507F, 0xD7600C0F, 0xD8440000, 0xD9120000, 0xED00017F, 0xE000017F, 0x3B040130,
    0xE00C2860, 0x3C0C2820, 0xE0060150, 0x3B040118, 0xE0122860, 0x3C0C2818, 0xE0062830, 0x3C0C2810, 0xEE04F400,
    0xD5700740, 0xEE040740, 0xD5600740, 0xEE040740, 0xD5400740, 0xEE040740, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF707507F, 0xD229507F, 0xD77F0F08, 0xD8000000, 0xD91F0000, 0x32020140, 0xD229507F, 0xD75E000F, 0xD8000000,
    0xD9120000, 0x2B0A0140, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF707507F, 0xD229507F, 0xD77F0F08, 0xD8000000,
    0xD91F0000, 0x33020140, 0xD22A507F, 0xD75E000F, 0xD8000000, 0xD9120000, 0x2D0A0140, 0xFFFE0000, 0xD0FF0000,
    0xD5FF0000, 0xF732507F, 0xD247507F, 0xD758000F, 0xD8000000, 0xD9130000, 0x21035050, 0x15065040, 0xD240507F,
    0xD77F000F, 0xD8000000, 0xD9130000, 0x14182830, 0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xF6800000, 0xD2270000,
    0xD77F0F08, 0xD8420000, 0xD9110000, 0x1A12507F, 0x1A125060, 0x1A125030, 0x1A125018, 0x1A12500C, 0x1A125006,
    0xFFFE0000, 0xD0800000, 0xD5FF0000, 0xF6800000, 0xD2270000, 0xD77F000F, 0xD8420000, 0xD9110000, 0x24105060,
    0xD2490000, 0xD77F0F08, 0xD8420000, 0xD9110000, 0x2D0C507F, 0x2D0A5020, 0x2D185010, 0xFFFE0000, 0xD0800000,
    0xD5FF0000, 0xF6800000, 0xD2160000, 0xD77F0F08, 0xD8420000, 0xD9110000, 0xDD00F120, 0x47060410, 0x440C040C,
    0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF613507F, 0xD216507F, 0xD77F000F, 0xD8360000, 0xD9180000, 0xDD000F7F,
    0x3C091E10, 0xD77F0F0B, 0xD8420000, 0xD9120000, 0x3C405018, 0xFFFE0000, 0xD0C00100, 0xD5C00000, 0xF6390130,
    0xD23A0130, 0xD754000F, 0xD8001430, 0xD9121430, 0xE5001805, 0x1730507F, 0x17305040, 0x17305020, 0x17305018,
    0x1730500C, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF705507F, 0xD20A507F, 0xD77F000F, 0xD83E0000, 0xD91C0000,
    0xDD000018, 0x2F0F4612, 0x2F23460C, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF605507F, 0xD204507F, 0xD77F0F0A,
    0xD8000000, 0xD91C0000, 0xDD000020, 0x3901640A, 0x2D016410, 0x32016418, 0xE7016420, 0xED016410, 0x39016420,
    0x2D016420, 0x32016420, 0xEE05FFF8, 0xE80400F8, 0xE7000000, 0xEE000000, 0xE805FEF8, 0xFFFE0000, 0xD0FF0000,
    0xD5A80000, 0xF700507F, 0xD213507F, 0xD77F000F, 0xD8000000, 0xD9140000, 0xE7066430, 0xE0006418, 0x2A016418,
    0xE0106410, 0x29016412, 0xE8080000, 0xE7066430, 0xE0006418, 0x2A016418, 0xE0106410, 0x29016412, 0xE808FEF8,
    0x2A020100, 0xFFFE0000, 0xD0AA507F, 0xD5C8507F, 0xF745507F, 0xD232000F, 0xD77F000F, 0xD8000000, 0xD9110000,
    0x1108506E, 0xD754000F, 0x1D40506E, 0xE418181C, 0xFFFE0000, 0xD0AA507F, 0xD5C8507F, 0xF745507F, 0xD23F000F,
    0xD77F000F, 0xD8000000, 0xD9120000, 0xF2040A50, 0xC480A50,  0xFFFE0000, 0xD0800000, 0xD5AA0000, 0xF704507F,
    0xD24A507F, 0xD764000F, 0xD8000000, 0xD9120000, 0x30063218, 0x2F063216, 0x30063218, 0x2F073216, 0xFFFE0000,
    0xD0800000, 0xD5AA0000, 0xF704507F, 0xD24B507F, 0xD768000F, 0xD8000000, 0xD9120000, 0x1C303230, 0xFFFE0000,
    0xD0800000, 0xD5FF0000, 0xF642507F, 0xD242507F, 0xD77F000F, 0xD8400000, 0xD9120000, 0x1C030A40, 0x24180A40,
    0xFFFE0000, 0xD0FF0100, 0xD5C00000, 0xF6330000, 0xD2110000, 0xD77F0F06, 0xD8400000, 0xD9100000, 0x34400A50,
    0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF607507F, 0xF218507F, 0xD232507F, 0xD750000F, 0xD8000000, 0xD9100000,
    0xE5000803, 0x12153240, 0x18303C28, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000, 0xF607507F, 0xD203507F, 0xD74A0F08,
    0xD83C0000, 0xD9100000, 0x1F601E40, 0xE4005E0C, 0xFFFE0000, 0xD0FF0100, 0xD5A00000, 0xD204507F, 0xD75B000F,
    0xD8000000, 0xD9150000, 0x23060A30, 0x280C1420, 0xD2450000, 0xD75D0808, 0xD8400000, 0xD9100000, 0x18061E20,
    0x18061E10, 0xFFFE0000, 0xD0FF0100, 0xD5A00000, 0xD204507F, 0xD75B000F, 0xD8000000, 0xD9150000, 0x23060A30,
    0x1F0C1420, 0xD2450000, 0xD75D0808, 0xD8400000, 0xD9100000, 0x18061E20, 0x18061E10, 0xFFFE0000, 0xD0FF0000,
    0xD5FF0000, 0xF642507F, 0xD245507F, 0xD77F000F, 0xD8000000, 0xD9140000, 0x24090A30, 0xD201507F, 0xD77F0F0A,
    0xD8440000, 0xD9130000, 0x30120A40, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6040000, 0xD24C0000, 0xD7500F0F,
    0xD8000000, 0xD9110000, 0x1C482830, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF7040000, 0xD23F0000, 0xD77F000F,
    0xD8000000, 0xD9130000, 0x10093260, 0xD77F000F, 0xD8005A64, 0xD9105A64, 0x24485050, 0xE4002C00, 0xFFFE0000,
    0xD0FF0100, 0xD5780000, 0xF6040000, 0xF2030000, 0xE0100000, 0xD2130000, 0xD77F0F08, 0xD8000000, 0xD9120000,
    0xDD00F630, 0x39050130, 0x36050138, 0x38050140, 0x35050148, 0x3B050150, 0x38050158, 0x3A050160, 0x37050158,
    0x3A050150, 0x37050148, 0x39050140, 0x36050148, 0x3C050150, 0x39050158, 0x3B050160, 0x38050158, 0x3B050150,
    0x38050148, 0x3A050140, 0x37050138, 0x3D050130, 0x3A050128, 0x3C050120, 0x39050118, 0x3B050110, 0x3805010C,
    0x3A050108, 0x37050105, 0xFFFE0000, 0xD0FF0100, 0xD5780000, 0xF6040000, 0xD2130000, 0xD77F0F08, 0xD8000000,
    0xD9120000, 0xDD000A30, 0x3A050130, 0x37050138, 0x39050140, 0x36050148, 0x3C050150, 0x39050158, 0x3B050160,
    0x38050158, 0x39050150, 0x36050148, 0x38050140, 0x35050148, 0x3B050150, 0x38050158, 0x3A050160, 0x37050158,
    0x3B050150, 0x38050148, 0x3A050140, 0x37050138, 0x3D050130, 0x3A050128, 0x3C050120, 0x39050118, 0x3B050110,
    0x3805010C, 0x3A050108, 0x37050105, 0xFFFE0000, 0xD0C00100, 0xD5DF0000, 0xF6390130, 0xD23A0130, 0xD77F000F,
    0xD8001430, 0xD9121430, 0xE50B06FD, 0xDD000060, 0x132A5070, 0x132A5038, 0x132A501C, 0x132A500E, 0xFFFE0000,
    0xD0FF0000, 0xD5800000, 0xF7066430, 0xD24B507F, 0xD768000F, 0xD8000000, 0xD9130000, 0xDFF03210, 0x45303210,
    0xE4181842, 0xFFFE0000, 0xD0540000, 0xD5FF0000, 0xF6185A0A, 0xD2185A0A, 0xD77F0F05, 0xD8005A0A, 0xD90E5A0A,
    0xDD00000C, 0x33045A60, 0x39045A70, 0x3F045A7F, 0x450C5A70, 0x33045A0C, 0x39045A0E, 0x3F045A10, 0x45245A0E,
    0xFFFE0000, 0xD0540000, 0xD5FF0000, 0xF60C5A0A, 0xF20C5A0A, 0xD2185A0A, 0xD77F0F05, 0xD8005A0A, 0xD90E5A0A,
    0xDD00000C, 0x33045A18, 0x39045A1C, 0x3F045A20, 0x450C5A1C, 0x33045A06, 0x39045A07, 0x3F045A08, 0x450C5A07,
    0xFFFE0000, 0xD0400000, 0xD5FF0000, 0xF6175A0A, 0xD2365A0A, 0xD744060A, 0xD83C5A0A, 0xD9105A0A, 0xDD00FA0C,
    0x3FA84620, 0xFFFE0000, 0xD0400000, 0xD5FF0000, 0xF6365A0A, 0xD2365A0A, 0xD744060A, 0xD83C5A0A, 0xD9105A0A,
    0xDD00060C, 0x3CA84620, 0xFFFE0000, 0xD0400000, 0xD5FF0000, 0xF6365A0A, 0xD2175A0A, 0xD744060A, 0xD83C5A0A,
    0xD9105A0A, 0xDD00000C, 0x39A84610, 0xFFFE0000, 0xD0400000, 0xD5FF0000, 0xF6175A0A, 0xD2365A0A, 0xD77F0806,
    0xD8385A0A, 0xD90F5A0A, 0xDD00000C, 0x39903C50, 0xFFFE0000, 0xD0400000, 0xD5FF0000, 0xF6175A0A, 0xD2365A0A,
    0xD77F0806, 0xD8385A0A, 0xD90F5A0A, 0xDD00000C, 0x38903C50, 0xFFFE0000, 0xD0400000, 0xD5FF0000, 0xF6175A0A,
    0xF2180A40, 0xD2355A0A, 0xD754080A, 0xD8385A0A, 0xD90F5A0A, 0xDD00000C, 0x22183C40, 0x21483230, 0xFFFE0000,
    0xD0FF0000, 0xD5FF0000, 0xF607507F, 0xD206507F, 0xD77F0F06, 0xD8000000, 0xD9120000, 0xDD000018, 0x46182860,
    0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6390130, 0xDD01F660, 0xD2040130, 0xD758000F, 0xD8001430, 0xD9121430,
    0x300C0A60, 0x240C0A60, 0x18180560, 0xD2480130, 0xD752000F, 0xD8001430, 0xD9121430, 0x1D095028, 0x1A095028,
    0x1C203C20, 0xE4002010, 0xFFFE0000, 0xD0FF0000, 0xD5C80000, 0xF6800000, 0xD2420000, 0xD7600F08, 0xD844647F,
    0xD91C647F, 0xDD00007F, 0x37180A7F, 0x2B180A20, 0x34180A40, 0x2B180A20, 0xFFFE0000, 0xD0FF0000, 0xD5FF0000,
    0xF607507F, 0xD207507F, 0xD77F000F, 0xD8000000, 0xD9180000, 0xDD000018, 0x47062818, 0x470C2818, 0xFFFE0000,
    0xD0FF0000, 0xD57F0000, 0xF604507F, 0xD204507F, 0xDD000F7F, 0xD77F000F, 0xD8001430, 0xD91C1430, 0x240C5014,
    0xD754000F, 0xD8001430, 0xD91C1430, 0x3030630E, 0xFFFE0000, 0xD0FF0000, 0xD57F0000, 0xF604507F, 0xD20A507F,
    0xDD000F7F, 0xD754000F, 0xD8001430, 0xD91C1430, 0x30406318, 0xE40C0637, 0xFFFE0000, 0xD0FF0100, 0xD5A00000,
    0xD204507F, 0xD759000F, 0xD8000000, 0xD9140000, 0x17060A40, 0x1C0C1430, 0x100C3C18, 0xFFFE0000, 0xD0FF0100,
    0xD5A00000, 0xD204507F, 0xD759000F, 0xD8000000, 0xD9140000, 0x1C060A40, 0x170C1430, 0xB0C3C18,  0xFFFE0000,
    0xD0FC0000, 0xD5C00000, 0xF613507F, 0xD20E507F, 0xD7540605, 0xD8400000, 0xD9120000, 0x2F202830, 0xE4002047,
    0xFFFE0000, 0xD0FC0100, 0xD5780000, 0xF613507F, 0xD237507F, 0xD77F000F, 0xD8400000, 0xD9120000, 0x30302810,
    0xFFFE0000, 0xD0FC0100, 0xD5780000, 0xF613507F, 0xD213507F, 0xD77F000F, 0xD8400000, 0xD9120000, 0x3030280C,
    0xFFFE0000, 0xD0780000, 0xF7FF0000, 0xD5FF0000, 0xD2270000, 0xDF00000F, 0xD77F000F, 0xD8000000, 0xD91F0000,
    0xE5000303, 0x1E206350, 0xE4041C1B, 0xFFFE0000, 0xD0FF0000, 0xD5600000, 0xF604507F, 0xD204507F, 0xDD00F67F,
    0xD77F000F, 0xD8001430, 0xD91C1430, 0x30035018, 0x24095018, 0xE4000C47, 0xFFFE0000, 0xD0FF0000, 0xD5600000,
    0xF604507F, 0xD20A507F, 0xDD00F67F, 0xD77F0F08, 0xD8401430, 0xD9121430, 0x30186340, 0xE4001846, 0xFFFE0000,
    0xD080507F, 0xD5C8507F, 0xF204000F, 0xD227000F, 0xD77F000F, 0xD83F0000, 0xD9110000, 0xE50004FA, 0x10302820,
    0xFFFE0000, 0xD080507F, 0xD5C8507F, 0xD232000F, 0xD754000F, 0xD8460000, 0xD9110000, 0x1030637F, 0xFFFE0000,
    0xD0FC0000, 0xD5FF0000, 0xF604507F, 0xDD01007F, 0xD203507F, 0xD77F000F, 0xD8001430, 0xD91F1430, 0x241A6320,
    0xE4001A39, 0xD226507F, 0xD77F0905, 0xD8471430, 0xD9121430, 0x3C145060, 0x3C145028, 0x3C1B3C14, 0xD203507F,
    0xD75C000F, 0xD8001430, 0xD9121430, 0x30302810, 0xE4003000, 0xFF008D00, 0xFFFE0000, 0xD0FC0000, 0xD5FF0000,
    0xF604507F, 0xDD01007F, 0xF2286318, 0xD219507F, 0xD74E000F, 0xD8001430, 0xD9121430, 0x2148320C, 0xD237000F,
    0xD77F000F, 0xD8001430, 0xD9121430, 0x39302808, 0xFFFE0000, 0xD0FC0000, 0xD5C80000, 0xF6920000, 0xD24D0100,
    0xD748000F, 0xD8000000, 0xD9110000, 0x16186428, 0xE4001818, 0xE7C05A64, 0x180C642C, 0xE8000000, 0xF3601464,
    0xFFFE0000, 0xD0FC0000, 0xD5FF0000, 0xF607507F, 0xD2190F0C, 0xD7440308, 0xD8400000, 0xD9110000, 0x24FF4628,
    0xFFFE0000, 0xD0FC0000, 0xD5FF0000, 0xF607507F, 0xD2190F0C, 0xD7440308, 0xD8400000, 0xD9110000, 0x22FF4614,
    0xFFFE0000, 0xD0FC0000, 0xD5FF0000, 0xF607507F, 0xD2360F0C, 0xD7440308, 0xD8400000, 0xD9110000, 0x2BFF4614,
    0xFFFE0000, 0xD0FF0000, 0xD5C00000, 0xF613507F, 0xD213507F, 0xD77F0905, 0xD8000000, 0xD9110000, 0xDD000E60,
    0x39120160, 0xFFFE0000, 0xD0FF0100, 0xD5FF0000, 0xF6260000, 0xD21E0000, 0xD77F000F, 0xD8000000, 0xD9140000,
    0x15060A40, 0xD2240000, 0xD77F000F, 0xD8400000, 0xD9110000, 0x13241430, 0xD2250000, 0xD77F000F, 0xD8480000,
    0xD9140000, 0x18060118, 0xD2220000, 0xD77F000F, 0xD8480000, 0xD9130000, 0xC180130,  0xFFFE0000, 0xD0FF0100,
    0xD5FF0000, 0xF7260000, 0xD2320000, 0xD74E000F, 0xD8400000, 0xD9100000, 0x11405A7F, 0xD2320000, 0xD760000F,
    0xD8400000, 0xD9100000, 0x1060037F, 0xFFFE0000, 0xD0FC0100, 0xD5960000, 0xF6800000, 0xD2270100, 0xD77F000F,
    0xD8006366, 0xD9196366, 0x22010146, 0xD24E0100, 0xD77F000F, 0xD8006366, 0xD9126366, 0xE00E6356, 0x220A635A,
    0xD762000F, 0x240F6324, 0xFFFE0000, 0xFFFE0000};
char SECTION(".data") se_tbl_800A22C4[] = {1, 1, 1, 0};

// temporary
#define SE_START 0x8009FDB8
// 0xFFFE0000 as seen above
#define SE_END 0x800A22C0
// contains pointers to the data above
// SePlay_800888F8
VECTOR SECTION(".data") se_tbl2_800A22C8[128] = { // temporary type, make struct
    {SE_END, SE_END, SE_END, 0x10140},
    {0x800A067C, SE_END, SE_END, 0x10110},
    {SE_START, SE_END, SE_END, 0x10110},
    {0x8009FDD8, SE_END, SE_END, 0x10130},
    {0x800A0A48, SE_END, SE_END, 0x10120},
    {0x800A1EE0, SE_END, SE_END, 0x10120},
    {0x800A1F08, SE_END, SE_END, 0x10120},
    {0x800A0F14, SE_END, SE_END, 0x10120},
    {0x800A0F90, SE_END, SE_END, 0x10130},
    {0x800A0FD4, SE_END, SE_END, 0x130},
    {0x800A1004, SE_END, SE_END, 0x190},
    {0x800A1338, SE_END, SE_END, 0x1B0},
    {0x800A13CC, SE_END, SE_END, 0x190},
    {0x800A1390, SE_END, SE_END, 0x190},
    {0x800A16E8, SE_END, SE_END, 0x3F0},
    {0x800A1408, 0x800A143C, 0x800A1468, 0x120},
    {0x800A0410, SE_END, SE_END, 0x190},
    {0x800A0470, SE_END, SE_END, 0x10101A0},
    {0x800A1BBC, SE_END, SE_END, 0x10101A0},
    {0x800A06A4, SE_END, SE_END, 0x10190},
    {0x800A088C, SE_END, SE_END, 0x120},
    {0x800A04C0, SE_END, SE_END, 0x290},
    {0x800A04F8, 0x800A0528, SE_END, 0x110},
    {0x800A0580, SE_END, SE_END, 0x10101A0},
    {0x800A05D0, SE_END, SE_END, 0x10101A0},
    {0x800A05F8, SE_END, SE_END, 0x10001F0},
    {0x800A061C, SE_END, SE_END, 0x10140},
    {0x800A0650, SE_END, SE_END, 0x10120},
    {0x800A06C8, SE_END, SE_END, 0x10110},
    {0x800A0EB8, SE_END, SE_END, 0x10120},
    {0x800A0714, SE_END, SE_END, 0x190},
    {0x800A0738, SE_END, SE_END, 0x290},
    {0x800A07DC, 0x800A0804, SE_END, 0x390},
    {0x800A075C, 0x800A078C, 0x800A07B4, 0x290},
    {0x800A082C, 0x800A0864, SE_END, 0x10190},
    {0x800A0BE0, SE_END, SE_END, 0x220},
    {0x800A12D8, 0x800A1310, SE_END, 0x10160},
    {0x800A0A6C, SE_END, SE_END, 0x10160},
    {0x8009FDF8, SE_END, SE_END, 0x10110},
    {0x8009FE18, SE_END, SE_END, 0x10140},
    {0x800A0AA8, SE_END, SE_END, 0x10190},
    {0x800A0B18, SE_END, SE_END, 0x1A0},
    {0x800A0300, SE_END, SE_END, 0x10120},
    {0x8009FE90, SE_END, SE_END, 0x10130},
    {0x8009FED8, SE_END, SE_END, 0x10130},
    {0x800A0AEC, SE_END, SE_END, 0x10130},
    {0x8009FF14, SE_END, SE_END, 0x10130},
    {0x8009FF5C, SE_END, SE_END, 0x10140},
    {0x800A0498, SE_END, SE_END, 0x10140},
    {0x8009FF88, SE_END, SE_END, 0x10140},
    {0x8009FFAC, SE_END, SE_END, 0x10170},
    {0x800A1608, SE_END, SE_END, 0x10140},
    {0x800A1114, SE_END, SE_END, 0x10140},
    {0x800A10E0, SE_END, SE_END, 0x110},
    {0x800A21BC, SE_END, SE_END, 0x10130},
    {0x800A0B70, SE_END, SE_END, 0x10120},
    {0x800A1098, SE_END, SE_END, 0x10120},
    {0x800A10BC, SE_END, SE_END, 0x290},
    {0x800A1A8C, 0x800A1B28, SE_END, 0x10160},
    {0x800A0C04, SE_END, SE_END, 0x10140},
    {0x800A004C, SE_END, SE_END, 0x10130},
    {0x800A00B8, SE_END, SE_END, 0x10140},
    {0x800A1034, SE_END, SE_END, 0x10160},
    {0x800A1074, SE_END, SE_END, 0x10130},
    {0x800A0204, SE_END, SE_END, 0x10290},
    {0x800A0C74, 0x800A0CA4, SE_END, 0x10170},
    {0x800A1A54, SE_END, SE_END, 0x10130},
    {0x800A21E4, SE_END, SE_END, 0x10130},
    {0x800A2244, SE_END, SE_END, 1},
    {SE_END, SE_END, SE_END, 1},
    {SE_END, SE_END, SE_END, 1},
    {SE_END, SE_END, SE_END, 0x10130},
    {0x800A0174, SE_END, SE_END, 0x10140},
    {0x800A1FA0, SE_END, SE_END, 0x280},
    {0x800A1FD0, 0x800A2000, SE_END, 0x1FF},
    {0x800A2118, SE_END, SE_END, 0x10140},
    {0x800A05A4, SE_END, SE_END, 0x10140},
    {0x800A01A8, SE_END, SE_END, 0x10130},
    {0x800A0230, SE_END, SE_END, 0x130},
    {0x800A0254, SE_END, SE_END, 0x10130},
    {0x800A0280, SE_END, SE_END, 0x10160},
    {0x800A02A4, SE_END, SE_END, 0x10140},
    {0x800A02C8, SE_END, SE_END, 0x3A0},
    {0x800A033C, 0x800A0380, 0x800A03C8, 0x280},
    {0x800A1160, 0x800A1188, SE_END, 0x180},
    {0x800A09C4, SE_END, SE_END, 0x180},
    {0x800A09E8, SE_END, SE_END, 0x280},
    {0x800A11B0, 0x800A11EC, SE_END, 0x10130},
    {0x800A08B0, SE_END, SE_END, 0x10130},
    {0x800A08E4, SE_END, SE_END, 0x10130},
    {0x800A0918, SE_END, SE_END, 0x10130},
    {0x800A0940, SE_END, SE_END, 0x10130},
    {0x800A0978, SE_END, SE_END, 0x10130},
    {0x800A09A0, SE_END, SE_END, 0x10110},
    {0x800A1BF4, SE_END, SE_END, 0x10190},
    {0x800A0C50, SE_END, SE_END, 0x10120},
    {0x800A0CE8, SE_END, SE_END, 0x10120},
    {0x800A0D10, SE_END, SE_END, 0x10120},
    {0x800A0D48, SE_END, SE_END, 0x10110},
    {0x800A1138, SE_END, SE_END, 0x3FF},
    {0x800A0DB4, 0x800A0DF4, 0x800A0E6C, 0x10140},
    {0x800A227C, SE_END, SE_END, 0x2F0},
    {0x800A1644, 0x800A167C, SE_END, 0x120},
    {0x800A122C, SE_END, SE_END, 0x180},
    {0x800A1278, SE_END, SE_END, 0x180},
    {0x800A129C, SE_END, SE_END, 0x190},
    {0x800A16BC, SE_END, SE_END, 0x1000190},
    {0x800A1720, SE_END, SE_END, 0x280},
    {0x800A1758, 0x800A1784, SE_END, 0x10120},
    {0x800A17DC, SE_END, SE_END, 0x10240},
    {0x800A1830, 0x800A1860, SE_END, 0x10230},
    {0x800A1888, 0x800A18B8, SE_END, 0x10120},
    {0x800A1904, SE_END, SE_END, 0x10230},
    {0x800A1928, 0x800A1958, SE_END, 0x190},
    {0x800A1A30, SE_END, SE_END, 0x1B0},
    {0x800A19F8, SE_END, SE_END, 0x140},
    {0x800A1E50, SE_END, SE_END, 0x1B0},
    {0x800A1E1C, SE_END, SE_END, 0x180},
    {0x800A1DCC, SE_END, SE_END, 0x1B0},
    {0x800A1DA4, SE_END, SE_END, 0x290},
    {0x800A1E7C, 0x800A1EB4, SE_END, 0x2F0},
    {0x800A1C20, 0x800A1C64, SE_END, 0x3F0},
    {0x800A1CAC, 0x800A1CD4, 0x800A1CFC, 0x3F0},
    {0x800A2150, 0x800A2174, 0x800A2198, 0x10240},
    {0x800A202C, 0x800A2054, SE_END, 0x2F0},
    {0x800A2074, 0x800A20D8, SE_END, 0x3B0},
    {0x800A1F30, 0x800A1F58, 0x800A1F7C, 0x190},
    {0x800A18DC, SE_END, SE_END, 1}};

int SECTION(".data") spu_ch_tbl_800A2AC8[] = {
    1,      2,      4,      8,      0x10,    0x20,    0x40,    0x80,    0x100,    0x200,    0x400,    0x800,
    0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000};

unsigned char SECTION(".data") blank_data_800A2B28[512] = {
    12u, 6u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 3u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u};

unsigned SECTION(".data") char byte_800A2D28[4096] = {
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 12u, 2u,
    0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u, 0u,  0u};

unsigned char SECTION(".data") v800A3D28[64] = {
    196u, 61u, 1u, 128u, 192u, 61u, 1u, 128u, 184u, 61u, 1u, 128u, 176u, 61u, 1u, 128u,
    152u, 61u, 1u, 128u, 128u, 61u, 1u, 128u, 112u, 61u, 1u, 128u, 92u,  61u, 1u, 128u,
    76u,  61u, 1u, 128u, 56u,  61u, 1u, 128u, 44u,  61u, 1u, 128u, 36u,  61u, 1u, 128u,
    20u,  61u, 1u, 128u, 16u,  61u, 1u, 128u, 16u,  61u, 1u, 128u, 16u,  61u, 1u, 128u};

int         SECTION(".data") dword_800A3D68[] = {0, 0};
int         SECTION(".data") gMts_Event1_800A3D70 = 0;
void       *SECTION(".data") gControllerCallBack_800A3D74 = 0;
int         SECTION(".data") gMtsVSyncCount_800A3D78 = -1;
mts_msg     SECTION(".data") stru_800A3D7C = {NULL, 0, -1, 0, NULL};
int         SECTION(".data") gMts_Event2_800A3D90 = 0;
int         SECTION(".data") gStackSize_800A3D94 = 0;
const char *SECTION(".data") dword_800A3D98[] = {aSending, aReceiving, aReady, aSleeping, aWaitvbl, aPending};
int         SECTION(".data") dword_800A3DB0 = 1;
int         SECTION(".data") dword_800A3DB4 = 0;
int         SECTION(".data") dword_800A3DB8 = 0;
int         SECTION(".data") gMtsPadInited_800A3DBC = 0;
int         SECTION(".data") dword_800A3DC0[] = {0, 0};
int         SECTION(".data") dword_800A3DC8 = 1;
int         SECTION(".data") dword_800A3DCC = 0;
int         SECTION(".data") CD_cbread_800A3DD0 = 0;
int         SECTION(".data") CD_read_dma_mode_800A3DD4[] = {0, 0, 0};
int         SECTION(".data") dword_800A3DE0[] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,       0,
                                                 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0x47350, 0x440000};
int         SECTION(".data") CD_cbsync_800A3E68 = 0;
int         SECTION(".data") CD_cbready_800A3E6C = 0;
int         SECTION(".data") CD_debug_800A3E70 = 0;
int         SECTION(".data") CD_status_800A3E74 = 0;
int         SECTION(".data") CD_status1_800A3E78 = 0;
int         SECTION(".data") CD_nopen_800A3E7C = 0;
char        SECTION(".data") CD_pos_800A3E80[] = {2, 0, 0, 0};
char        SECTION(".data") CD_com_800A3E84[] = {0, 0, 0, 0, 0, 0, 0, 0};
int         SECTION(".data") CD_comstr_800A3E8C[] = {(int)aCdlsync,           (int)aCdlnop,
                                                     (int)aCdlsetloc,         (int)aCdlplay,
                                                     (int)aCdlforward,        (int)aCdlbackward,
                                                     (int)aCdlreadn,          (int)aCdlstandby,
                                                     (int)aCdlstop,           (int)aCdlpause,
                                                     (int)aCdlreset,          (int)aCdlmute,
                                                     (int)aCdldemute,         (int)dword_800141CC + 0x10,
                                                     (int)dword_800141CC + 4, (int)dword_800141CC,
                                                     (int)aCdlgetlocl,        (int)aCdlgetlocp,
                                                     (int)dword_800141CC,     (int)aCdlgettn,
                                                     (int)aCdlgettd,          (int)aCdlseekl,
                                                     (int)aCdlseekp,          (int)dword_800141CC,
                                                     (int)dword_800141CC,     (int)dword_800141CC,
                                                     (int)dword_800141CC,     (int)aCdlreads,
                                                     (int)dword_800141CC,     (int)dword_800141CC,
                                                     (int)dword_800141CC,     (int)dword_800141CC};
int         SECTION(".data") CD_intstr_800A3F0C[] = {(int)aNointr,        (int)aDataready,    (int)aComplete_0,
                                                     (int)aAcknowledge,   (int)aDataend,      (int)aDiskerror_0,
                                                     (int)dword_800141CC, (int)dword_800141CC};
int         SECTION(".data") dword_800A3F2C[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
                                                 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
int         SECTION(".data") dword_800A3FAC[] = {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0};
int         SECTION(".data") dword_800A402C[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int  SECTION(".data") dword_800A40AC[] = {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0};
int  SECTION(".data") dword_800A4110[] = {0, 0, 0, 0, 0, 0, 0};
int  SECTION(".data") dword_800A412C = 0x1F801800;
int  SECTION(".data") dword_800A4130 = 0x1F801801;
int  SECTION(".data") dword_800A4134 = 0x1F801802;
int  SECTION(".data") dword_800A4138 = 0x1F801803;
int  SECTION(".data") dword_800A413C = 0x1F801020;
int  SECTION(".data") dword_800A4140 = 0x1F801C00;
char SECTION(".data") byte_800A4144[] = {0, 0, 0, 0};

struct off_800A4148
{
    unsigned char *p1;
    short         *p2;
    unsigned char *p3;
    int           *p4;
    unsigned char *p5;
    const char    *p6;
};
struct off_800A4148 SECTION(".data") goff_800A4148 = {
    (unsigned char *)&byte_800A4144,      (short *)0x800C14F8,
    (unsigned char *)&CD_com_800A3E84[1], (int *)&CD_status_800A3E74,
    (unsigned char *)&CD_pos_800A3E80,    (const char *)aIdBiosCV186199};
int SECTION(".data") dword_800A4160 = 0x1F801018;
int SECTION(".data") dword_800A4164 = 0x1F8010F0;
int SECTION(".data") dword_800A4168 = 0x1F8010B0;
int SECTION(".data") dword_800A416C = 0x1F8010B4;
int SECTION(".data") dword_800A4170[] = {0x1F8010B8, 0, 0, 0};
int SECTION(".data") dword_800A4180 = 0;
int SECTION(".data") dword_800A4184 = 0;
int SECTION(".data") dword_800A4188[] = {0, 0, 0x27350, 0x440000, 0, 0};
int SECTION(".data") dword_800A41A0 = 0;
int SECTION(".data") dword_800A41A4[] = {
    0,          0,          0,          0x20202000, 0x20202020, 0x8082020,  0x20080808, 0x20202020, 0x20202020,
    0x20202020, 0x20202020, 0x10101820, 0x10101010, 0x10101010, 0x10101010, 0x4040410,  0x4040404,  0x10040404,
    0x10101010, 0x41411010, 0x41414141, 0x1010101,  0x1010101,  0x1010101,  0x1010101,  0x1010101,  0x10101010,
    0x42421010, 0x42424242, 0x2020202,  0x2020202,  0x2020202,  0x2020202,  0x2020202,  0x10101010, 0x20,
    0,          0,          0,          0x77350,    0x440000};
int SECTION(".data") off_800A4248[] = {(int)aIdSysCV1140199, 0x800915D8, 0x800915FC, 0x80090DFC, 0x800914E8, 0x80091520,
                                       0x80091560,           0x80091268, 0x8009102C, 0x800918AC, 0x8009150C, 0x80090D1C,
                                       0x800915A8,           0x80091B0C, 0x80090D04, 0x80091C5C};
int SECTION(".data") off_800A4288 = (int)off_800A4248;
int SECTION(".data") GPU_printf_800A428C = 0x8008BBA0;
char  SECTION(".data") GEnv_800A4290 = 0;
char  SECTION(".data") byte_800A4291 = 0;
char  SECTION(".data") byte_800A4292 = 0;
char  SECTION(".data") byte_800A4293 = 0;
short SECTION(".data") word_800A4294 = 0;
short SECTION(".data") word_800A4296 = 0;
int   SECTION(".data") dword_800A4298 = 0;
int   SECTION(".data") dword_800A429C = 0;
int   SECTION(".data") dword_800A42A0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
short SECTION(".data") word_800A42FC = 0;
short SECTION(".data") word_800A42FE = 0;
short SECTION(".data") word_800A4300 = 0;
short SECTION(".data") word_800A4302 = 0;
short SECTION(".data") word_800A4304 = 0;
short SECTION(".data") word_800A4306 = 0;
short SECTION(".data") word_800A4308 = 0;
short SECTION(".data") word_800A430A = 0;
int   SECTION(".data") dword_800A430C = 0;
int   SECTION(".data") dword_800A4310[] = {0x400, 0x400, 0x400};
int   SECTION(".data") dword_800A431C[] = {0x200, 0x200, 0x400};
int   SECTION(".data") dword_800A4328[] = {0x4FFFFFF, 0x80000000};
int   SECTION(".data") dword_800A4330 = 0;
int   SECTION(".data") dword_800A4334 = 0;
int   SECTION(".data") dword_800A4338 = 0;
int   SECTION(".data") dword_800A433C[] = {0x4FFFFFF, 0, 0, 0, 0};
int   SECTION(".data") dword_800A4350[] = {0, 0x80000000, 0, 0, 0x10002};
int   SECTION(".data") dword_800A4364[] = {0xC4E024E, 0xC580258, 0xC9B021B, 0xC670267, 0xC6C026C,
                                           0xC620262, 0xC700270, 0xCB00230, 0xC7B027B, 0xC800280};
char  SECTION(".data") byte_800A438C[] = {0xA, 8, 7, 5, 4};
int   SECTION(".data") dword_800A4394 = 0x1F801810;
int   SECTION(".data") dword_800A4398 = 0x1F801814;
int   SECTION(".data") dword_800A439C = 0x1F8010A0;
int   SECTION(".data") dword_800A43A0 = 0x1F8010A4;
int   SECTION(".data") dword_800A43A4 = 0x1F8010A8;
int   SECTION(".data") dword_800A43A8 = 0x1F8010E0;
int   SECTION(".data") dword_800A43AC = 0x1F8010E4;
int   SECTION(".data") dword_800A43B0 = 0x1F8010E8;
int   SECTION(".data") dword_800A43B4 = 0x1F8010F0;
int   SECTION(".data") qin_800A43B8 = 0;
int   SECTION(".data") qout_800A43BC = 0;
int   SECTION(".data") dword_800A43C0 = 0;
int   SECTION(".data") dword_800A43C4 = 0;
int   SECTION(".data") dword_800A43C8 = 0;
int   SECTION(".data") dword_800A43CC = 0;
int   SECTION(".data") dword_800A43D0[] = {0, 0, 0, 0};
int   SECTION(".data") rsin_tbl_800A43E0[] = {
      0x60000,    0x13000D,   0x1F0019,  0x2C0026,  0x390032,  0x45003F,  0x52004B,  0x5E0058,   0x6B0065,   0x770071,
      0x84007E,   0x90008A,   0x9D0097,  0xAA00A3,  0xB600B0,  0xC300BC,  0xCF00C9,  0xDC00D6,   0xE800E2,   0xF500EF,
      0x10100FB,  0x10E0108,  0x11B0114, 0x1270121, 0x134012D, 0x140013A, 0x14D0146, 0x1590153,  0x166015F,  0x172016C,
      0x17F0178,  0x18B0185,  0x1980191, 0x1A4019E, 0x1B101AA, 0x1BD01B7, 0x1CA01C3, 0x1D601D0,  0x1E301DC,  0x1EF01E9,
      0x1FC01F5,  0x2080202,  0x215020E, 0x221021B, 0x22D0227, 0x23A0234, 0x2460240, 0x253024D,  0x25F0259,  0x26C0265,
      0x2780272,  0x284027E,  0x291028B, 0x29D0297, 0x2AA02A3, 0x2B602B0, 0x2C202BC, 0x2CF02C9,  0x2DB02D5,  0x2E802E1,
      0x2F402EE,  0x30002FA,  0x30D0306, 0x3190313, 0x325031F, 0x332032B, 0x33E0338, 0x34A0344,  0x3560350,  0x363035D,
      0x36F0369,  0x37B0375,  0x3880381, 0x394038E, 0x3A0039A, 0x3AC03A6, 0x3B903B2, 0x3C503BF,  0x3D103CB,  0x3DD03D7,
      0x3E903E3,  0x3F603EF,  0x40203FC, 0x40E0408, 0x41A0414, 0x4260420, 0x432042C, 0x43E0438,  0x44B0444,  0x4570451,
      0x463045D,  0x46F0469,  0x47B0475, 0x4870481, 0x493048D, 0x49F0499, 0x4AB04A5, 0x4B704B1,  0x4C304BD,  0x4CF04C9,
      0x4DB04D5,  0x4E704E1,  0x4F304ED, 0x4FF04F9, 0x50B0505, 0x5170511, 0x523051D, 0x52F0529,  0x53A0534,  0x5460540,
      0x552054C,  0x55E0558,  0x56A0564, 0x5760570, 0x581057C, 0x58D0587, 0x5990593, 0x5A5059F,  0x5B105AB,  0x5BC05B6,
      0x5C805C2,  0x5D405CE,  0x5DF05DA, 0x5EB05E5, 0x5F705F1, 0x60205FD, 0x60E0608, 0x61A0614,  0x625061F,  0x631062B,
      0x63C0637,  0x6480642,  0x654064E, 0x65F0659, 0x66B0665, 0x6760670, 0x682067C, 0x68D0687,  0x6990693,  0x6A4069E,
      0x6AF06AA,  0x6BB06B5,  0x6C606C1, 0x6D206CC, 0x6DD06D7, 0x6E806E3, 0x6F406EE, 0x6FF06F9,  0x70A0705,  0x7150710,
      0x721071B,  0x72C0726,  0x7370732, 0x742073D, 0x74E0748, 0x7590753, 0x764075E, 0x76F076A,  0x77A0775,  0x7850780,
      0x790078B,  0x79B0796,  0x7A607A1, 0x7B207AC, 0x7BD07B7, 0x7C807C2, 0x7D207CD, 0x7DD07D8,  0x7E807E3,  0x7F307EE,
      0x7FE07F9,  0x8090804,  0x814080E, 0x81F0819, 0x82A0824, 0x834082F, 0x83F083A, 0x84A0845,  0x855084F,  0x85F085A,
      0x86A0865,  0x875086F,  0x87F087A, 0x88A0885, 0x895088F, 0x89F089A, 0x8AA08A5, 0x8B408AF,  0x8BF08BA,  0x8C908C4,
      0x8D408CF,  0x8DE08D9,  0x8E908E4, 0x8F308EE, 0x8FE08F8, 0x9080903, 0x912090D, 0x91D0918,  0x9270922,  0x931092C,
      0x93C0937,  0x9460941,  0x950094B, 0x95A0955, 0x965095F, 0x96F096A, 0x9790974, 0x983097E,  0x98D0988,  0x9970992,
      0x9A1099C,  0x9AB09A6,  0x9B509B0, 0x9BF09BA, 0x9C909C4, 0x9D309CE, 0x9DD09D8, 0x9E709E2,  0x9F109EC,  0x9FB09F6,
      0xA0409FF,  0xA0E0A09,  0xA180A13, 0xA220A1D, 0xA2B0A26, 0xA350A30, 0xA3F0A3A, 0xA480A44,  0xA520A4D,  0xA5C0A57,
      0xA650A60,  0xA6F0A6A,  0xA780A73, 0xA820A7D, 0xA8B0A86, 0xA950A90, 0xA9E0A99, 0xAA70AA3,  0xAB10AAC,  0xABA0AB5,
      0xAC30ABF,  0xACD0AC8,  0xAD60AD1, 0xADF0ADB, 0xAE80AE4, 0xAF20AED, 0xAFB0AF6, 0xB040AFF,  0xB0D0B08,  0xB160B11,
      0xB1F0B1B,  0xB280B24,  0xB310B2D, 0xB3A0B36, 0xB430B3E, 0xB4C0B47, 0xB550B50, 0xB5E0B59,  0xB660B62,  0xB6F0B6B,
      0xB780B74,  0xB810B7C,  0xB890B85, 0xB920B8E, 0xB9B0B97, 0xBA30B9F, 0xBAC0BA8, 0xBB50BB0,  0xBBD0BB9,  0xBC60BC1,
      0xBCE0BCA,  0xBD70BD2,  0xBDF0BDB, 0xBE80BE3, 0xBF00BEC, 0xBF80BF4, 0xC010BFC, 0xC090C05,  0xC110C0D,  0xC190C15,
      0xC220C1E,  0xC2A0C26,  0xC320C2E, 0xC3A0C36, 0xC420C3E, 0xC4A0C46, 0xC520C4E, 0xC5A0C56,  0xC620C5E,  0xC6A0C66,
      0xC720C6E,  0xC7A0C76,  0xC820C7E, 0xC8A0C86, 0xC910C8E, 0xC990C95, 0xCA10C9D, 0xCA90CA5,  0xCB00CAC,  0xCB80CB4,
      0xCC00CBC,  0xCC70CC3,  0xCCF0CCB, 0xCD60CD2, 0xCDE0CDA, 0xCE50CE1, 0xCED0CE9, 0xCF40CF0,  0xCFB0CF8,  0xD030CFF,
      0xD0A0D06,  0xD110D0E,  0xD180D15, 0xD200D1C, 0xD270D23, 0xD2E0D2A, 0xD350D32, 0xD3C0D39,  0xD430D40,  0xD4A0D47,
      0xD510D4E,  0xD580D55,  0xD5F0D5C, 0xD660D62, 0xD6D0D69, 0xD740D70, 0xD7A0D77, 0xD810D7E,  0xD880D85,  0xD8F0D8B,
      0xD950D92,  0xD9C0D99,  0xDA20D9F, 0xDA90DA6, 0xDB00DAC, 0xDB60DB3, 0xDBC0DB9, 0xDC30DC0,  0xDC90DC6,  0xDD00DCC,
      0xDD60DD3,  0xDDC0DD9,  0xDE30DDF, 0xDE90DE6, 0xDEF0DEC, 0xDF50DF2, 0xDFB0DF8, 0xE010DFE,  0xE070E04,  0xE0D0E0A,
      0xE130E10,  0xE190E16,  0xE1F0E1C, 0xE250E22, 0xE2B0E28, 0xE310E2E, 0xE370E34, 0xE3C0E3A,  0xE420E3F,  0xE480E45,
      0xE4D0E4B,  0xE530E50,  0xE590E56, 0xE5E0E5B, 0xE640E61, 0xE690E66, 0xE6F0E6C, 0xE740E71,  0xE790E77,  0xE7F0E7C,
      0xE840E81,  0xE890E87,  0xE8F0E8C, 0xE940E91, 0xE990E96, 0xE9E0E9B, 0xEA30EA1, 0xEA80EA6,  0xEAD0EAB,  0xEB20EB0,
      0xEB70EB5,  0xEBC0EBA,  0xEC10EBF, 0xEC60EC3, 0xECB0EC8, 0xECF0ECD, 0xED40ED2, 0xED90ED6,  0xEDD0EDB,  0xEE20EE0,
      0xEE70EE4,  0xEEB0EE9,  0xEF00EEE, 0xEF40EF2, 0xEF90EF7, 0xEFD0EFB, 0xF020EFF, 0xF060F04,  0xF0A0F08,  0xF0E0F0C,
      0xF130F11,  0xF170F15,  0xF1B0F19, 0xF1F0F1D, 0xF230F21, 0xF270F25, 0xF2B0F29, 0xF2F0F2D,  0xF330F31,  0xF370F35,
      0xF3B0F39,  0xF3F0F3D,  0xF430F41, 0xF460F45, 0xF4A0F48, 0xF4E0F4C, 0xF510F50, 0xF550F53,  0xF590F57,  0xF5C0F5A,
      0xF600F5E,  0xF630F61,  0xF670F65, 0xF6A0F68, 0xF6D0F6C, 0xF710F6F, 0xF740F72, 0xF770F76,  0xF7A0F79,  0xF7D0F7C,
      0xF810F7F,  0xF840F82,  0xF870F85, 0xF8A0F88, 0xF8D0F8B, 0xF900F8E, 0xF930F91, 0xF950F94,  0xF980F97,  0xF9B0F9A,
      0xF9E0F9C,  0xFA10F9F,  0xFA30FA2, 0xFA60FA5, 0xFA80FA7, 0xFAB0FAA, 0xFAE0FAC, 0xFB00FAF,  0xFB30FB1,  0xFB50FB4,
      0xFB70FB6,  0xFBA0FB8,  0xFBC0FBB, 0xFBE0FBD, 0xFC00FBF, 0xFC30FC2, 0xFC50FC4, 0xFC70FC6,  0xFC90FC8,  0xFCB0FCA,
      0xFCD0FCC,  0xFCF0FCE,  0xFD10FD0, 0xFD30FD2, 0xFD50FD4, 0xFD60FD5, 0xFD80FD7, 0xFDA0FD9,  0xFDC0FDB,  0xFDD0FDC,
      0xFDF0FDE,  0xFE00FE0,  0xFE20FE1, 0xFE30FE3, 0xFE50FE4, 0xFE60FE6, 0xFE80FE7, 0xFE90FE8,  0xFEA0FEA,  0xFEC0FEB,
      0xFED0FEC,  0xFEE0FED,  0xFEF0FEF, 0xFF00FF0, 0xFF10FF1, 0xFF20FF2, 0xFF30FF3, 0xFF40FF4,  0xFF50FF5,  0xFF60FF6,
      0xFF70FF7,  0xFF80FF8,  0xFF90FF8, 0xFF90FF9, 0xFFA0FFA, 0xFFB0FFA, 0xFFB0FFB, 0xFFC0FFC,  0xFFC0FFC,  0xFFD0FFD,
      0xFFD0FFD,  0xFFE0FFE,  0xFFE0FFE, 0xFFF0FFE, 0xFFF0FFF, 0xFFF0FFF, 0xFFF0FFF, 0x10001000, 0x10001000, 0x10001000,
      0x10001000, 0x10001000, 0x1000,    0,         0,         0};
int SECTION(".data") dword_800A4BF0[] = {0, 0, 0, 0};
int SECTION(".data") SQRT_800A4C00[] = {
    0x101F1000, 0x105E103F, 0x109C107E, 0x10DA10BB, 0x111610F8, 0x11521134, 0x118C116F, 0x11C611A9, 0x120011E3,
    0x1238121C, 0x12701254, 0x12A7128C, 0x12DE12C2, 0x131412F9, 0x1349132E, 0x137E1364, 0x13B21398, 0x13E613CC,
    0x14191400, 0x144C1432, 0x147E1465, 0x14B01497, 0x14E114C8, 0x151214F9, 0x1542152A, 0x1572155A, 0x15A2158A,
    0x15D115B9, 0x160015E8, 0x162E1617, 0x165C1645, 0x16891673, 0x16B716A0, 0x16E416CD, 0x171016FA, 0x173C1726,
    0x17681752, 0x1794177E, 0x17BF17AA, 0x17EA17D5, 0x18151800, 0x183F182A, 0x18691854, 0x1893187E, 0x18BD18A8,
    0x18E618D1, 0x190F18FA, 0x19381923, 0x1960194C, 0x19881974, 0x19B0199C, 0x19D819C4, 0x1A0019EC, 0x1A271A13,
    0x1A4E1A3A, 0x1A751A61, 0x1A9B1A88, 0x1AC21AAE, 0x1AE81AD5, 0x1B0E1AFB, 0x1B331B21, 0x1B591B46, 0x1B7E1B6C,
    0x1BA31B91, 0x1BC81BB6, 0x1BED1BDB, 0x1C121C00, 0x1C361C24, 0x1C5A1C48, 0x1C7E1C6C, 0x1CA21C90, 0x1CC61CB4,
    0x1CE91CD8, 0x1D0D1CFB, 0x1D301D1E, 0x1D531D41, 0x1D761D64, 0x1D981D87, 0x1DBB1DAA, 0x1DDD1DCC, 0x1E001DEE,
    0x1E221E11, 0x1E431E33, 0x1E651E54, 0x1E871E76, 0x1EA81E98, 0x1ECA1EB9, 0x1EEB1EDA, 0x1F0C1EFB, 0x1F2D1F1C,
    0x1F4E1F3D, 0x1F6E1F5E, 0x1F8F1F7E, 0x1FAF1F9F, 0x1FCF1FBF, 0x1FEF1FDF, 0,          0,          0,
    0,          0};
int SECTION(".data") dword_800A4D94[] = {
    0xFE01000, 0xFA30FC1, 0xF680F85, 0xF300F4C, 0xEFB0F15, 0xEC70EE1, 0xE960EAE, 0xE660E7E, 0xE380E4F, 0xE0C0E22,
    0xDE20DF7, 0xDB90DCD, 0xD910DA5, 0xD6B0D7E, 0xD450D58, 0xD210D33, 0xCFF0D10, 0xCDD0CEE, 0xCBC0CCC, 0xC9C0CAC,
    0xC7D0C8D, 0xC5F0C6E, 0xC420C51, 0xC260C34, 0xC0A0C18, 0xBEF0BFD, 0xBD50BE2, 0xBBB0BC8, 0xBA20BAF, 0xB8A0B96,
    0xB720B7E, 0xB5B0B67, 0xB450B50, 0xB2E0B39, 0xB190B24, 0xB040B0E, 0xAEF0AF9, 0xADB0AE5, 0xAC70AD1, 0xAB40ABD,
    0xAA10AAA, 0xA8E0A97, 0xA7C0A85, 0xA6A0A73, 0xA590A61, 0xA470A50, 0xA370A3F, 0xA260A2E, 0xA160A1E, 0xA060A0E,
    0x9F609FE, 0x9E709EF, 0x9D809E0, 0x9C909D1, 0x9BB09C2, 0x9AD09B4, 0x99E09A5, 0x9910998, 0x983098A, 0x976097C,
    0x969096F, 0x95C0962, 0x94F0955, 0x9430949, 0x936093C, 0x92A0930, 0x91E0924, 0x9120918, 0x907090D, 0x8FB0901,
    0x8F008F6, 0x8E508EB, 0x8DA08E0, 0x8CF08D5, 0x8C508CA, 0x8BA08BF, 0x8B008B5, 0x8A608AB, 0x89C08A1, 0x8920897,
    0x888088D, 0x87E0883, 0x875087A, 0x86B0870, 0x8620867, 0x859085E, 0x8500855, 0x847084C, 0x83E0843, 0x836083A,
    0x82D0831, 0x8240829, 0x81C0820, 0x8140818, 0x80C0810, 0x8040808, 0,         0,         0};
int SECTION(".data") rcossin_tbl_800A4F20[] = {
    0x10000000, 0x10000006, 0x1000000D, 0x10000013, 0x10000019, 0x1000001F, 0x10000026, 0x1000002C, 0x10000032,
    0x10000039, 0x1000003F, 0xFFF0045,  0xFFF004B,  0xFFF0052,  0xFFF0058,  0xFFF005E,  0xFFF0065,  0xFFF006B,
    0xFFE0071,  0xFFE0077,  0xFFE007E,  0xFFE0084,  0xFFE008A,  0xFFD0090,  0xFFD0097,  0xFFD009D,  0xFFD00A3,
    0xFFC00AA,  0xFFC00B0,  0xFFC00B6,  0xFFC00BC,  0xFFB00C3,  0xFFB00C9,  0xFFB00CF,  0xFFA00D6,  0xFFA00DC,
    0xFFA00E2,  0xFF900E8,  0xFF900EF,  0xFF900F5,  0xFF800FB,  0xFF80101,  0xFF80108,  0xFF7010E,  0xFF70114,
    0xFF6011B,  0xFF60121,  0xFF50127,  0xFF5012D,  0xFF40134,  0xFF4013A,  0xFF30140,  0xFF30146,  0xFF2014D,
    0xFF20153,  0xFF10159,  0xFF1015F,  0xFF00166,  0xFF0016C,  0xFEF0172,  0xFEF0178,  0xFEE017F,  0xFED0185,
    0xFED018B,  0xFEC0191,  0xFEC0198,  0xFEB019E,  0xFEA01A4,  0xFEA01AA,  0xFE901B1,  0xFE801B7,  0xFE801BD,
    0xFE701C3,  0xFE601CA,  0xFE601D0,  0xFE501D6,  0xFE401DC,  0xFE301E3,  0xFE301E9,  0xFE201EF,  0xFE101F5,
    0xFE001FC,  0xFE00202,  0xFDF0208,  0xFDE020E,  0xFDD0215,  0xFDC021B,  0xFDC0221,  0xFDB0227,  0xFDA022D,
    0xFD90234,  0xFD8023A,  0xFD70240,  0xFD60246,  0xFD5024D,  0xFD50253,  0xFD40259,  0xFD3025F,  0xFD20265,
    0xFD1026C,  0xFD00272,  0xFCF0278,  0xFCE027E,  0xFCD0284,  0xFCC028B,  0xFCB0291,  0xFCA0297,  0xFC9029D,
    0xFC802A3,  0xFC702AA,  0xFC602B0,  0xFC502B6,  0xFC402BC,  0xFC302C2,  0xFC202C9,  0xFC002CF,  0xFBF02D5,
    0xFBE02DB,  0xFBD02E1,  0xFBC02E8,  0xFBB02EE,  0xFBA02F4,  0xFB802FA,  0xFB70300,  0xFB60306,  0xFB5030D,
    0xFB40313,  0xFB30319,  0xFB1031F,  0xFB00325,  0xFAF032B,  0xFAE0332,  0xFAC0338,  0xFAB033E,  0xFAA0344,
    0xFA8034A,  0xFA70350,  0xFA60356,  0xFA5035D,  0xFA30363,  0xFA20369,  0xFA1036F,  0xF9F0375,  0xF9E037B,
    0xF9C0381,  0xF9B0388,  0xF9A038E,  0xF980394,  0xF97039A,  0xF9503A0,  0xF9403A6,  0xF9303AC,  0xF9103B2,
    0xF9003B9,  0xF8E03BF,  0xF8D03C5,  0xF8B03CB,  0xF8A03D1,  0xF8803D7,  0xF8703DD,  0xF8503E3,  0xF8403E9,
    0xF8203EF,  0xF8103F6,  0xF7F03FC,  0xF7D0402,  0xF7C0408,  0xF7A040E,  0xF790414,  0xF77041A,  0xF760420,
    0xF740426,  0xF72042C,  0xF710432,  0xF6F0438,  0xF6D043E,  0xF6C0444,  0xF6A044B,  0xF680451,  0xF670457,
    0xF65045D,  0xF630463,  0xF610469,  0xF60046F,  0xF5E0475,  0xF5C047B,  0xF5A0481,  0xF590487,  0xF57048D,
    0xF550493,  0xF530499,  0xF51049F,  0xF5004A5,  0xF4E04AB,  0xF4C04B1,  0xF4A04B7,  0xF4804BD,  0xF4604C3,
    0xF4504C9,  0xF4304CF,  0xF4104D5,  0xF3F04DB,  0xF3D04E1,  0xF3B04E7,  0xF3904ED,  0xF3704F3,  0xF3504F9,
    0xF3304FF,  0xF310505,  0xF2F050B,  0xF2D0511,  0xF2B0517,  0xF29051D,  0xF270523,  0xF250529,  0xF23052F,
    0xF210534,  0xF1F053A,  0xF1D0540,  0xF1B0546,  0xF19054C,  0xF170552,  0xF150558,  0xF13055E,  0xF110564,
    0xF0E056A,  0xF0C0570,  0xF0A0576,  0xF08057C,  0xF060581,  0xF040587,  0xF02058D,  0xEFF0593,  0xEFD0599,
    0xEFB059F,  0xEF905A5,  0xEF705AB,  0xEF405B1,  0xEF205B6,  0xEF005BC,  0xEEE05C2,  0xEEB05C8,  0xEE905CE,
    0xEE705D4,  0xEE405DA,  0xEE205DF,  0xEE005E5,  0xEDD05EB,  0xEDB05F1,  0xED905F7,  0xED605FD,  0xED40602,
    0xED20608,  0xECF060E,  0xECD0614,  0xECB061A,  0xEC8061F,  0xEC60625,  0xEC3062B,  0xEC10631,  0xEBF0637,
    0xEBC063C,  0xEBA0642,  0xEB70648,  0xEB5064E,  0xEB20654,  0xEB00659,  0xEAD065F,  0xEAB0665,  0xEA8066B,
    0xEA60670,  0xEA30676,  0xEA1067C,  0xE9E0682,  0xE9B0687,  0xE99068D,  0xE960693,  0xE940699,  0xE91069E,
    0xE8F06A4,  0xE8C06AA,  0xE8906AF,  0xE8706B5,  0xE8406BB,  0xE8106C1,  0xE7F06C6,  0xE7C06CC,  0xE7906D2,
    0xE7706D7,  0xE7406DD,  0xE7106E3,  0xE6F06E8,  0xE6C06EE,  0xE6906F4,  0xE6606F9,  0xE6406FF,  0xE610705,
    0xE5E070A,  0xE5B0710,  0xE590715,  0xE56071B,  0xE530721,  0xE500726,  0xE4D072C,  0xE4B0732,  0xE480737,
    0xE45073D,  0xE420742,  0xE3F0748,  0xE3C074E,  0xE3A0753,  0xE370759,  0xE34075E,  0xE310764,  0xE2E076A,
    0xE2B076F,  0xE280775,  0xE25077A,  0xE220780,  0xE1F0785,  0xE1C078B,  0xE190790,  0xE160796,  0xE13079B,
    0xE1007A1,  0xE0D07A6,  0xE0A07AC,  0xE0707B2,  0xE0407B7,  0xE0107BD,  0xDFE07C2,  0xDFB07C8,  0xDF807CD,
    0xDF507D2,  0xDF207D8,  0xDEF07DD,  0xDEC07E3,  0xDE907E8,  0xDE607EE,  0xDE307F3,  0xDDF07F9,  0xDDC07FE,
    0xDD90804,  0xDD60809,  0xDD3080E,  0xDD00814,  0xDCC0819,  0xDC9081F,  0xDC60824,  0xDC3082A,  0xDC0082F,
    0xDBC0834,  0xDB9083A,  0xDB6083F,  0xDB30845,  0xDB0084A,  0xDAC084F,  0xDA90855,  0xDA6085A,  0xDA2085F,
    0xD9F0865,  0xD9C086A,  0xD99086F,  0xD950875,  0xD92087A,  0xD8F087F,  0xD8B0885,  0xD88088A,  0xD85088F,
    0xD810895,  0xD7E089A,  0xD7A089F,  0xD7708A5,  0xD7408AA,  0xD7008AF,  0xD6D08B4,  0xD6908BA,  0xD6608BF,
    0xD6208C4,  0xD5F08C9,  0xD5C08CF,  0xD5808D4,  0xD5508D9,  0xD5108DE,  0xD4E08E4,  0xD4A08E9,  0xD4708EE,
    0xD4308F3,  0xD4008F8,  0xD3C08FE,  0xD390903,  0xD350908,  0xD32090D,  0xD2E0912,  0xD2A0918,  0xD27091D,
    0xD230922,  0xD200927,  0xD1C092C,  0xD180931,  0xD150937,  0xD11093C,  0xD0E0941,  0xD0A0946,  0xD06094B,
    0xD030950,  0xCFF0955,  0xCFB095A,  0xCF8095F,  0xCF40965,  0xCF0096A,  0xCED096F,  0xCE90974,  0xCE50979,
    0xCE1097E,  0xCDE0983,  0xCDA0988,  0xCD6098D,  0xCD20992,  0xCCF0997,  0xCCB099C,  0xCC709A1,  0xCC309A6,
    0xCC009AB,  0xCBC09B0,  0xCB809B5,  0xCB409BA,  0xCB009BF,  0xCAC09C4,  0xCA909C9,  0xCA509CE,  0xCA109D3,
    0xC9D09D8,  0xC9909DD,  0xC9509E2,  0xC9109E7,  0xC8E09EC,  0xC8A09F1,  0xC8609F6,  0xC8209FB,  0xC7E09FF,
    0xC7A0A04,  0xC760A09,  0xC720A0E,  0xC6E0A13,  0xC6A0A18,  0xC660A1D,  0xC620A22,  0xC5E0A26,  0xC5A0A2B,
    0xC560A30,  0xC520A35,  0xC4E0A3A,  0xC4A0A3F,  0xC460A44,  0xC420A48,  0xC3E0A4D,  0xC3A0A52,  0xC360A57,
    0xC320A5C,  0xC2E0A60,  0xC2A0A65,  0xC260A6A,  0xC220A6F,  0xC1E0A73,  0xC190A78,  0xC150A7D,  0xC110A82,
    0xC0D0A86,  0xC090A8B,  0xC050A90,  0xC010A95,  0xBFC0A99,  0xBF80A9E,  0xBF40AA3,  0xBF00AA7,  0xBEC0AAC,
    0xBE80AB1,  0xBE30AB5,  0xBDF0ABA,  0xBDB0ABF,  0xBD70AC3,  0xBD20AC8,  0xBCE0ACD,  0xBCA0AD1,  0xBC60AD6,
    0xBC10ADB,  0xBBD0ADF,  0xBB90AE4,  0xBB50AE8,  0xBB00AED,  0xBAC0AF2,  0xBA80AF6,  0xBA30AFB,  0xB9F0AFF,
    0xB9B0B04,  0xB970B08,  0xB920B0D,  0xB8E0B11,  0xB890B16,  0xB850B1B,  0xB810B1F,  0xB7C0B24,  0xB780B28,
    0xB740B2D,  0xB6F0B31,  0xB6B0B36,  0xB660B3A,  0xB620B3E,  0xB5E0B43,  0xB590B47,  0xB550B4C,  0xB500B50,
    0xB4C0B55,  0xB470B59,  0xB430B5E,  0xB3E0B62,  0xB3A0B66,  0xB360B6B,  0xB310B6F,  0xB2D0B74,  0xB280B78,
    0xB240B7C,  0xB1F0B81,  0xB1B0B85,  0xB160B89,  0xB110B8E,  0xB0D0B92,  0xB080B97,  0xB040B9B,  0xAFF0B9F,
    0xAFB0BA3,  0xAF60BA8,  0xAF20BAC,  0xAED0BB0,  0xAE80BB5,  0xAE40BB9,  0xADF0BBD,  0xADB0BC1,  0xAD60BC6,
    0xAD10BCA,  0xACD0BCE,  0xAC80BD2,  0xAC30BD7,  0xABF0BDB,  0xABA0BDF,  0xAB50BE3,  0xAB10BE8,  0xAAC0BEC,
    0xAA70BF0,  0xAA30BF4,  0xA9E0BF8,  0xA990BFC,  0xA950C01,  0xA900C05,  0xA8B0C09,  0xA860C0D,  0xA820C11,
    0xA7D0C15,  0xA780C19,  0xA730C1E,  0xA6F0C22,  0xA6A0C26,  0xA650C2A,  0xA600C2E,  0xA5C0C32,  0xA570C36,
    0xA520C3A,  0xA4D0C3E,  0xA480C42,  0xA440C46,  0xA3F0C4A,  0xA3A0C4E,  0xA350C52,  0xA300C56,  0xA2B0C5A,
    0xA260C5E,  0xA220C62,  0xA1D0C66,  0xA180C6A,  0xA130C6E,  0xA0E0C72,  0xA090C76,  0xA040C7A,  0x9FF0C7E,
    0x9FB0C82,  0x9F60C86,  0x9F10C8A,  0x9EC0C8E,  0x9E70C91,  0x9E20C95,  0x9DD0C99,  0x9D80C9D,  0x9D30CA1,
    0x9CE0CA5,  0x9C90CA9,  0x9C40CAC,  0x9BF0CB0,  0x9BA0CB4,  0x9B50CB8,  0x9B00CBC,  0x9AB0CC0,  0x9A60CC3,
    0x9A10CC7,  0x99C0CCB,  0x9970CCF,  0x9920CD2,  0x98D0CD6,  0x9880CDA,  0x9830CDE,  0x97E0CE1,  0x9790CE5,
    0x9740CE9,  0x96F0CED,  0x96A0CF0,  0x9650CF4,  0x95F0CF8,  0x95A0CFB,  0x9550CFF,  0x9500D03,  0x94B0D06,
    0x9460D0A,  0x9410D0E,  0x93C0D11,  0x9370D15,  0x9310D18,  0x92C0D1C,  0x9270D20,  0x9220D23,  0x91D0D27,
    0x9180D2A,  0x9120D2E,  0x90D0D32,  0x9080D35,  0x9030D39,  0x8FE0D3C,  0x8F80D40,  0x8F30D43,  0x8EE0D47,
    0x8E90D4A,  0x8E40D4E,  0x8DE0D51,  0x8D90D55,  0x8D40D58,  0x8CF0D5C,  0x8C90D5F,  0x8C40D62,  0x8BF0D66,
    0x8BA0D69,  0x8B40D6D,  0x8AF0D70,  0x8AA0D74,  0x8A50D77,  0x89F0D7A,  0x89A0D7E,  0x8950D81,  0x88F0D85,
    0x88A0D88,  0x8850D8B,  0x87F0D8F,  0x87A0D92,  0x8750D95,  0x86F0D99,  0x86A0D9C,  0x8650D9F,  0x85F0DA2,
    0x85A0DA6,  0x8550DA9,  0x84F0DAC,  0x84A0DB0,  0x8450DB3,  0x83F0DB6,  0x83A0DB9,  0x8340DBC,  0x82F0DC0,
    0x82A0DC3,  0x8240DC6,  0x81F0DC9,  0x8190DCC,  0x8140DD0,  0x80E0DD3,  0x8090DD6,  0x8040DD9,  0x7FE0DDC,
    0x7F90DDF,  0x7F30DE3,  0x7EE0DE6,  0x7E80DE9,  0x7E30DEC,  0x7DD0DEF,  0x7D80DF2,  0x7D20DF5,  0x7CD0DF8,
    0x7C80DFB,  0x7C20DFE,  0x7BD0E01,  0x7B70E04,  0x7B20E07,  0x7AC0E0A,  0x7A60E0D,  0x7A10E10,  0x79B0E13,
    0x7960E16,  0x7900E19,  0x78B0E1C,  0x7850E1F,  0x7800E22,  0x77A0E25,  0x7750E28,  0x76F0E2B,  0x76A0E2E,
    0x7640E31,  0x75E0E34,  0x7590E37,  0x7530E3A,  0x74E0E3C,  0x7480E3F,  0x7420E42,  0x73D0E45,  0x7370E48,
    0x7320E4B,  0x72C0E4D,  0x7260E50,  0x7210E53,  0x71B0E56,  0x7150E59,  0x7100E5B,  0x70A0E5E,  0x7050E61,
    0x6FF0E64,  0x6F90E66,  0x6F40E69,  0x6EE0E6C,  0x6E80E6F,  0x6E30E71,  0x6DD0E74,  0x6D70E77,  0x6D20E79,
    0x6CC0E7C,  0x6C60E7F,  0x6C10E81,  0x6BB0E84,  0x6B50E87,  0x6AF0E89,  0x6AA0E8C,  0x6A40E8F,  0x69E0E91,
    0x6990E94,  0x6930E96,  0x68D0E99,  0x6870E9B,  0x6820E9E,  0x67C0EA1,  0x6760EA3,  0x6700EA6,  0x66B0EA8,
    0x6650EAB,  0x65F0EAD,  0x6590EB0,  0x6540EB2,  0x64E0EB5,  0x6480EB7,  0x6420EBA,  0x63C0EBC,  0x6370EBF,
    0x6310EC1,  0x62B0EC3,  0x6250EC6,  0x61F0EC8,  0x61A0ECB,  0x6140ECD,  0x60E0ECF,  0x6080ED2,  0x6020ED4,
    0x5FD0ED6,  0x5F70ED9,  0x5F10EDB,  0x5EB0EDD,  0x5E50EE0,  0x5DF0EE2,  0x5DA0EE4,  0x5D40EE7,  0x5CE0EE9,
    0x5C80EEB,  0x5C20EEE,  0x5BC0EF0,  0x5B60EF2,  0x5B10EF4,  0x5AB0EF7,  0x5A50EF9,  0x59F0EFB,  0x5990EFD,
    0x5930EFF,  0x58D0F02,  0x5870F04,  0x5810F06,  0x57C0F08,  0x5760F0A,  0x5700F0C,  0x56A0F0E,  0x5640F11,
    0x55E0F13,  0x5580F15,  0x5520F17,  0x54C0F19,  0x5460F1B,  0x5400F1D,  0x53A0F1F,  0x5340F21,  0x52F0F23,
    0x5290F25,  0x5230F27,  0x51D0F29,  0x5170F2B,  0x5110F2D,  0x50B0F2F,  0x5050F31,  0x4FF0F33,  0x4F90F35,
    0x4F30F37,  0x4ED0F39,  0x4E70F3B,  0x4E10F3D,  0x4DB0F3F,  0x4D50F41,  0x4CF0F43,  0x4C90F45,  0x4C30F46,
    0x4BD0F48,  0x4B70F4A,  0x4B10F4C,  0x4AB0F4E,  0x4A50F50,  0x49F0F51,  0x4990F53,  0x4930F55,  0x48D0F57,
    0x4870F59,  0x4810F5A,  0x47B0F5C,  0x4750F5E,  0x46F0F60,  0x4690F61,  0x4630F63,  0x45D0F65,  0x4570F67,
    0x4510F68,  0x44B0F6A,  0x4440F6C,  0x43E0F6D,  0x4380F6F,  0x4320F71,  0x42C0F72,  0x4260F74,  0x4200F76,
    0x41A0F77,  0x4140F79,  0x40E0F7A,  0x4080F7C,  0x4020F7D,  0x3FC0F7F,  0x3F60F81,  0x3EF0F82,  0x3E90F84,
    0x3E30F85,  0x3DD0F87,  0x3D70F88,  0x3D10F8A,  0x3CB0F8B,  0x3C50F8D,  0x3BF0F8E,  0x3B90F90,  0x3B20F91,
    0x3AC0F93,  0x3A60F94,  0x3A00F95,  0x39A0F97,  0x3940F98,  0x38E0F9A,  0x3880F9B,  0x3810F9C,  0x37B0F9E,
    0x3750F9F,  0x36F0FA1,  0x3690FA2,  0x3630FA3,  0x35D0FA5,  0x3560FA6,  0x3500FA7,  0x34A0FA8,  0x3440FAA,
    0x33E0FAB,  0x3380FAC,  0x3320FAE,  0x32B0FAF,  0x3250FB0,  0x31F0FB1,  0x3190FB3,  0x3130FB4,  0x30D0FB5,
    0x3060FB6,  0x3000FB7,  0x2FA0FB8,  0x2F40FBA,  0x2EE0FBB,  0x2E80FBC,  0x2E10FBD,  0x2DB0FBE,  0x2D50FBF,
    0x2CF0FC0,  0x2C90FC2,  0x2C20FC3,  0x2BC0FC4,  0x2B60FC5,  0x2B00FC6,  0x2AA0FC7,  0x2A30FC8,  0x29D0FC9,
    0x2970FCA,  0x2910FCB,  0x28B0FCC,  0x2840FCD,  0x27E0FCE,  0x2780FCF,  0x2720FD0,  0x26C0FD1,  0x2650FD2,
    0x25F0FD3,  0x2590FD4,  0x2530FD5,  0x24D0FD5,  0x2460FD6,  0x2400FD7,  0x23A0FD8,  0x2340FD9,  0x22D0FDA,
    0x2270FDB,  0x2210FDC,  0x21B0FDC,  0x2150FDD,  0x20E0FDE,  0x2080FDF,  0x2020FE0,  0x1FC0FE0,  0x1F50FE1,
    0x1EF0FE2,  0x1E90FE3,  0x1E30FE3,  0x1DC0FE4,  0x1D60FE5,  0x1D00FE6,  0x1CA0FE6,  0x1C30FE7,  0x1BD0FE8,
    0x1B70FE8,  0x1B10FE9,  0x1AA0FEA,  0x1A40FEA,  0x19E0FEB,  0x1980FEC,  0x1910FEC,  0x18B0FED,  0x1850FED,
    0x17F0FEE,  0x1780FEF,  0x1720FEF,  0x16C0FF0,  0x1660FF0,  0x15F0FF1,  0x1590FF1,  0x1530FF2,  0x14D0FF2,
    0x1460FF3,  0x1400FF3,  0x13A0FF4,  0x1340FF4,  0x12D0FF5,  0x1270FF5,  0x1210FF6,  0x11B0FF6,  0x1140FF7,
    0x10E0FF7,  0x1080FF8,  0x1010FF8,  0xFB0FF8,   0xF50FF9,   0xEF0FF9,   0xE80FF9,   0xE20FFA,   0xDC0FFA,
    0xD60FFA,   0xCF0FFB,   0xC90FFB,   0xC30FFB,   0xBC0FFC,   0xB60FFC,   0xB00FFC,   0xAA0FFC,   0xA30FFD,
    0x9D0FFD,   0x970FFD,   0x900FFD,   0x8A0FFE,   0x840FFE,   0x7E0FFE,   0x770FFE,   0x710FFE,   0x6B0FFF,
    0x650FFF,   0x5E0FFF,   0x580FFF,   0x520FFF,   0x4B0FFF,   0x450FFF,   0x3F1000,   0x391000,   0x321000,
    0x2C1000,   0x261000,   0x1F1000,   0x191000,   0x131000,   0xD1000,    0x61000,    0x1000,     0xFFFA1000,
    0xFFF31000, 0xFFED1000, 0xFFE71000, 0xFFE11000, 0xFFDA1000, 0xFFD41000, 0xFFCE1000, 0xFFC71000, 0xFFC11000,
    0xFFBB0FFF, 0xFFB50FFF, 0xFFAE0FFF, 0xFFA80FFF, 0xFFA20FFF, 0xFF9B0FFF, 0xFF950FFF, 0xFF8F0FFE, 0xFF890FFE,
    0xFF820FFE, 0xFF7C0FFE, 0xFF760FFE, 0xFF700FFD, 0xFF690FFD, 0xFF630FFD, 0xFF5D0FFD, 0xFF560FFC, 0xFF500FFC,
    0xFF4A0FFC, 0xFF440FFC, 0xFF3D0FFB, 0xFF370FFB, 0xFF310FFB, 0xFF2A0FFA, 0xFF240FFA, 0xFF1E0FFA, 0xFF180FF9,
    0xFF110FF9, 0xFF0B0FF9, 0xFF050FF8, 0xFEFF0FF8, 0xFEF80FF8, 0xFEF20FF7, 0xFEEC0FF7, 0xFEE50FF6, 0xFEDF0FF6,
    0xFED90FF5, 0xFED30FF5, 0xFECC0FF4, 0xFEC60FF4, 0xFEC00FF3, 0xFEBA0FF3, 0xFEB30FF2, 0xFEAD0FF2, 0xFEA70FF1,
    0xFEA10FF1, 0xFE9A0FF0, 0xFE940FF0, 0xFE8E0FEF, 0xFE880FEF, 0xFE810FEE, 0xFE7B0FED, 0xFE750FED, 0xFE6F0FEC,
    0xFE680FEC, 0xFE620FEB, 0xFE5C0FEA, 0xFE560FEA, 0xFE4F0FE9, 0xFE490FE8, 0xFE430FE8, 0xFE3D0FE7, 0xFE360FE6,
    0xFE300FE6, 0xFE2A0FE5, 0xFE240FE4, 0xFE1D0FE3, 0xFE170FE3, 0xFE110FE2, 0xFE0B0FE1, 0xFE040FE0, 0xFDFE0FE0,
    0xFDF80FDF, 0xFDF20FDE, 0xFDEB0FDD, 0xFDE50FDC, 0xFDDF0FDC, 0xFDD90FDB, 0xFDD30FDA, 0xFDCC0FD9, 0xFDC60FD8,
    0xFDC00FD7, 0xFDBA0FD6, 0xFDB30FD5, 0xFDAD0FD5, 0xFDA70FD4, 0xFDA10FD3, 0xFD9B0FD2, 0xFD940FD1, 0xFD8E0FD0,
    0xFD880FCF, 0xFD820FCE, 0xFD7C0FCD, 0xFD750FCC, 0xFD6F0FCB, 0xFD690FCA, 0xFD630FC9, 0xFD5D0FC8, 0xFD560FC7,
    0xFD500FC6, 0xFD4A0FC5, 0xFD440FC4, 0xFD3E0FC3, 0xFD370FC2, 0xFD310FC0, 0xFD2B0FBF, 0xFD250FBE, 0xFD1F0FBD,
    0xFD180FBC, 0xFD120FBB, 0xFD0C0FBA, 0xFD060FB8, 0xFD000FB7, 0xFCFA0FB6, 0xFCF30FB5, 0xFCED0FB4, 0xFCE70FB3,
    0xFCE10FB1, 0xFCDB0FB0, 0xFCD50FAF, 0xFCCE0FAE, 0xFCC80FAC, 0xFCC20FAB, 0xFCBC0FAA, 0xFCB60FA8, 0xFCB00FA7,
    0xFCAA0FA6, 0xFCA30FA5, 0xFC9D0FA3, 0xFC970FA2, 0xFC910FA1, 0xFC8B0F9F, 0xFC850F9E, 0xFC7F0F9C, 0xFC780F9B,
    0xFC720F9A, 0xFC6C0F98, 0xFC660F97, 0xFC600F95, 0xFC5A0F94, 0xFC540F93, 0xFC4E0F91, 0xFC470F90, 0xFC410F8E,
    0xFC3B0F8D, 0xFC350F8B, 0xFC2F0F8A, 0xFC290F88, 0xFC230F87, 0xFC1D0F85, 0xFC170F84, 0xFC110F82, 0xFC0A0F81,
    0xFC040F7F, 0xFBFE0F7D, 0xFBF80F7C, 0xFBF20F7A, 0xFBEC0F79, 0xFBE60F77, 0xFBE00F76, 0xFBDA0F74, 0xFBD40F72,
    0xFBCE0F71, 0xFBC80F6F, 0xFBC20F6D, 0xFBBC0F6C, 0xFBB50F6A, 0xFBAF0F68, 0xFBA90F67, 0xFBA30F65, 0xFB9D0F63,
    0xFB970F61, 0xFB910F60, 0xFB8B0F5E, 0xFB850F5C, 0xFB7F0F5A, 0xFB790F59, 0xFB730F57, 0xFB6D0F55, 0xFB670F53,
    0xFB610F51, 0xFB5B0F50, 0xFB550F4E, 0xFB4F0F4C, 0xFB490F4A, 0xFB430F48, 0xFB3D0F46, 0xFB370F45, 0xFB310F43,
    0xFB2B0F41, 0xFB250F3F, 0xFB1F0F3D, 0xFB190F3B, 0xFB130F39, 0xFB0D0F37, 0xFB070F35, 0xFB010F33, 0xFAFB0F31,
    0xFAF50F2F, 0xFAEF0F2D, 0xFAE90F2B, 0xFAE30F29, 0xFADD0F27, 0xFAD70F25, 0xFAD10F23, 0xFACC0F21, 0xFAC60F1F,
    0xFAC00F1D, 0xFABA0F1B, 0xFAB40F19, 0xFAAE0F17, 0xFAA80F15, 0xFAA20F13, 0xFA9C0F11, 0xFA960F0E, 0xFA900F0C,
    0xFA8A0F0A, 0xFA840F08, 0xFA7F0F06, 0xFA790F04, 0xFA730F02, 0xFA6D0EFF, 0xFA670EFD, 0xFA610EFB, 0xFA5B0EF9,
    0xFA550EF7, 0xFA4F0EF4, 0xFA4A0EF2, 0xFA440EF0, 0xFA3E0EEE, 0xFA380EEB, 0xFA320EE9, 0xFA2C0EE7, 0xFA260EE4,
    0xFA210EE2, 0xFA1B0EE0, 0xFA150EDD, 0xFA0F0EDB, 0xFA090ED9, 0xFA030ED6, 0xF9FE0ED4, 0xF9F80ED2, 0xF9F20ECF,
    0xF9EC0ECD, 0xF9E60ECB, 0xF9E10EC8, 0xF9DB0EC6, 0xF9D50EC3, 0xF9CF0EC1, 0xF9C90EBF, 0xF9C40EBC, 0xF9BE0EBA,
    0xF9B80EB7, 0xF9B20EB5, 0xF9AC0EB2, 0xF9A70EB0, 0xF9A10EAD, 0xF99B0EAB, 0xF9950EA8, 0xF9900EA6, 0xF98A0EA3,
    0xF9840EA1, 0xF97E0E9E, 0xF9790E9B, 0xF9730E99, 0xF96D0E96, 0xF9670E94, 0xF9620E91, 0xF95C0E8F, 0xF9560E8C,
    0xF9510E89, 0xF94B0E87, 0xF9450E84, 0xF93F0E81, 0xF93A0E7F, 0xF9340E7C, 0xF92E0E79, 0xF9290E77, 0xF9230E74,
    0xF91D0E71, 0xF9180E6F, 0xF9120E6C, 0xF90C0E69, 0xF9070E66, 0xF9010E64, 0xF8FB0E61, 0xF8F60E5E, 0xF8F00E5B,
    0xF8EB0E59, 0xF8E50E56, 0xF8DF0E53, 0xF8DA0E50, 0xF8D40E4D, 0xF8CE0E4B, 0xF8C90E48, 0xF8C30E45, 0xF8BE0E42,
    0xF8B80E3F, 0xF8B20E3C, 0xF8AD0E3A, 0xF8A70E37, 0xF8A20E34, 0xF89C0E31, 0xF8960E2E, 0xF8910E2B, 0xF88B0E28,
    0xF8860E25, 0xF8800E22, 0xF87B0E1F, 0xF8750E1C, 0xF8700E19, 0xF86A0E16, 0xF8650E13, 0xF85F0E10, 0xF85A0E0D,
    0xF8540E0A, 0xF84E0E07, 0xF8490E04, 0xF8430E01, 0xF83E0DFE, 0xF8380DFB, 0xF8330DF8, 0xF82E0DF5, 0xF8280DF2,
    0xF8230DEF, 0xF81D0DEC, 0xF8180DE9, 0xF8120DE6, 0xF80D0DE3, 0xF8070DDF, 0xF8020DDC, 0xF7FC0DD9, 0xF7F70DD6,
    0xF7F20DD3, 0xF7EC0DD0, 0xF7E70DCC, 0xF7E10DC9, 0xF7DC0DC6, 0xF7D60DC3, 0xF7D10DC0, 0xF7CC0DBC, 0xF7C60DB9,
    0xF7C10DB6, 0xF7BB0DB3, 0xF7B60DB0, 0xF7B10DAC, 0xF7AB0DA9, 0xF7A60DA6, 0xF7A10DA2, 0xF79B0D9F, 0xF7960D9C,
    0xF7910D99, 0xF78B0D95, 0xF7860D92, 0xF7810D8F, 0xF77B0D8B, 0xF7760D88, 0xF7710D85, 0xF76B0D81, 0xF7660D7E,
    0xF7610D7A, 0xF75B0D77, 0xF7560D74, 0xF7510D70, 0xF74C0D6D, 0xF7460D69, 0xF7410D66, 0xF73C0D62, 0xF7370D5F,
    0xF7310D5C, 0xF72C0D58, 0xF7270D55, 0xF7220D51, 0xF71C0D4E, 0xF7170D4A, 0xF7120D47, 0xF70D0D43, 0xF7080D40,
    0xF7020D3C, 0xF6FD0D39, 0xF6F80D35, 0xF6F30D32, 0xF6EE0D2E, 0xF6E80D2A, 0xF6E30D27, 0xF6DE0D23, 0xF6D90D20,
    0xF6D40D1C, 0xF6CF0D18, 0xF6C90D15, 0xF6C40D11, 0xF6BF0D0E, 0xF6BA0D0A, 0xF6B50D06, 0xF6B00D03, 0xF6AB0CFF,
    0xF6A60CFB, 0xF6A10CF8, 0xF69B0CF4, 0xF6960CF0, 0xF6910CED, 0xF68C0CE9, 0xF6870CE5, 0xF6820CE1, 0xF67D0CDE,
    0xF6780CDA, 0xF6730CD6, 0xF66E0CD2, 0xF6690CCF, 0xF6640CCB, 0xF65F0CC7, 0xF65A0CC3, 0xF6550CC0, 0xF6500CBC,
    0xF64B0CB8, 0xF6460CB4, 0xF6410CB0, 0xF63C0CAC, 0xF6370CA9, 0xF6320CA5, 0xF62D0CA1, 0xF6280C9D, 0xF6230C99,
    0xF61E0C95, 0xF6190C91, 0xF6140C8E, 0xF60F0C8A, 0xF60A0C86, 0xF6050C82, 0xF6010C7E, 0xF5FC0C7A, 0xF5F70C76,
    0xF5F20C72, 0xF5ED0C6E, 0xF5E80C6A, 0xF5E30C66, 0xF5DE0C62, 0xF5DA0C5E, 0xF5D50C5A, 0xF5D00C56, 0xF5CB0C52,
    0xF5C60C4E, 0xF5C10C4A, 0xF5BC0C46, 0xF5B80C42, 0xF5B30C3E, 0xF5AE0C3A, 0xF5A90C36, 0xF5A40C32, 0xF5A00C2E,
    0xF59B0C2A, 0xF5960C26, 0xF5910C22, 0xF58D0C1E, 0xF5880C19, 0xF5830C15, 0xF57E0C11, 0xF57A0C0D, 0xF5750C09,
    0xF5700C05, 0xF56B0C01, 0xF5670BFC, 0xF5620BF8, 0xF55D0BF4, 0xF5590BF0, 0xF5540BEC, 0xF54F0BE8, 0xF54B0BE3,
    0xF5460BDF, 0xF5410BDB, 0xF53D0BD7, 0xF5380BD2, 0xF5330BCE, 0xF52F0BCA, 0xF52A0BC6, 0xF5250BC1, 0xF5210BBD,
    0xF51C0BB9, 0xF5180BB5, 0xF5130BB0, 0xF50E0BAC, 0xF50A0BA8, 0xF5050BA3, 0xF5010B9F, 0xF4FC0B9B, 0xF4F80B97,
    0xF4F30B92, 0xF4EF0B8E, 0xF4EA0B89, 0xF4E50B85, 0xF4E10B81, 0xF4DC0B7C, 0xF4D80B78, 0xF4D30B74, 0xF4CF0B6F,
    0xF4CA0B6B, 0xF4C60B66, 0xF4C20B62, 0xF4BD0B5E, 0xF4B90B59, 0xF4B40B55, 0xF4B00B50, 0xF4AB0B4C, 0xF4A70B47,
    0xF4A20B43, 0xF49E0B3E, 0xF49A0B3A, 0xF4950B36, 0xF4910B31, 0xF48C0B2D, 0xF4880B28, 0xF4840B24, 0xF47F0B1F,
    0xF47B0B1B, 0xF4770B16, 0xF4720B11, 0xF46E0B0D, 0xF4690B08, 0xF4650B04, 0xF4610AFF, 0xF45D0AFB, 0xF4580AF6,
    0xF4540AF2, 0xF4500AED, 0xF44B0AE8, 0xF4470AE4, 0xF4430ADF, 0xF43F0ADB, 0xF43A0AD6, 0xF4360AD1, 0xF4320ACD,
    0xF42E0AC8, 0xF4290AC3, 0xF4250ABF, 0xF4210ABA, 0xF41D0AB5, 0xF4180AB1, 0xF4140AAC, 0xF4100AA7, 0xF40C0AA3,
    0xF4080A9E, 0xF4040A99, 0xF3FF0A95, 0xF3FB0A90, 0xF3F70A8B, 0xF3F30A86, 0xF3EF0A82, 0xF3EB0A7D, 0xF3E70A78,
    0xF3E20A73, 0xF3DE0A6F, 0xF3DA0A6A, 0xF3D60A65, 0xF3D20A60, 0xF3CE0A5C, 0xF3CA0A57, 0xF3C60A52, 0xF3C20A4D,
    0xF3BE0A48, 0xF3BA0A44, 0xF3B60A3F, 0xF3B20A3A, 0xF3AE0A35, 0xF3AA0A30, 0xF3A60A2B, 0xF3A20A26, 0xF39E0A22,
    0xF39A0A1D, 0xF3960A18, 0xF3920A13, 0xF38E0A0E, 0xF38A0A09, 0xF3860A04, 0xF38209FF, 0xF37E09FB, 0xF37A09F6,
    0xF37609F1, 0xF37209EC, 0xF36F09E7, 0xF36B09E2, 0xF36709DD, 0xF36309D8, 0xF35F09D3, 0xF35B09CE, 0xF35709C9,
    0xF35409C4, 0xF35009BF, 0xF34C09BA, 0xF34809B5, 0xF34409B0, 0xF34009AB, 0xF33D09A6, 0xF33909A1, 0xF335099C,
    0xF3310997, 0xF32E0992, 0xF32A098D, 0xF3260988, 0xF3220983, 0xF31F097E, 0xF31B0979, 0xF3170974, 0xF313096F,
    0xF310096A, 0xF30C0965, 0xF308095F, 0xF305095A, 0xF3010955, 0xF2FD0950, 0xF2FA094B, 0xF2F60946, 0xF2F20941,
    0xF2EF093C, 0xF2EB0937, 0xF2E80931, 0xF2E4092C, 0xF2E00927, 0xF2DD0922, 0xF2D9091D, 0xF2D60918, 0xF2D20912,
    0xF2CE090D, 0xF2CB0908, 0xF2C70903, 0xF2C408FE, 0xF2C008F8, 0xF2BD08F3, 0xF2B908EE, 0xF2B608E9, 0xF2B208E4,
    0xF2AF08DE, 0xF2AB08D9, 0xF2A808D4, 0xF2A408CF, 0xF2A108C9, 0xF29E08C4, 0xF29A08BF, 0xF29708BA, 0xF29308B4,
    0xF29008AF, 0xF28C08AA, 0xF28908A5, 0xF286089F, 0xF282089A, 0xF27F0895, 0xF27B088F, 0xF278088A, 0xF2750885,
    0xF271087F, 0xF26E087A, 0xF26B0875, 0xF267086F, 0xF264086A, 0xF2610865, 0xF25E085F, 0xF25A085A, 0xF2570855,
    0xF254084F, 0xF250084A, 0xF24D0845, 0xF24A083F, 0xF247083A, 0xF2440834, 0xF240082F, 0xF23D082A, 0xF23A0824,
    0xF237081F, 0xF2340819, 0xF2300814, 0xF22D080E, 0xF22A0809, 0xF2270804, 0xF22407FE, 0xF22107F9, 0xF21D07F3,
    0xF21A07EE, 0xF21707E8, 0xF21407E3, 0xF21107DD, 0xF20E07D8, 0xF20B07D2, 0xF20807CD, 0xF20507C8, 0xF20207C2,
    0xF1FF07BD, 0xF1FC07B7, 0xF1F907B2, 0xF1F607AC, 0xF1F307A6, 0xF1F007A1, 0xF1ED079B, 0xF1EA0796, 0xF1E70790,
    0xF1E4078B, 0xF1E10785, 0xF1DE0780, 0xF1DB077A, 0xF1D80775, 0xF1D5076F, 0xF1D2076A, 0xF1CF0764, 0xF1CC075E,
    0xF1C90759, 0xF1C60753, 0xF1C4074E, 0xF1C10748, 0xF1BE0742, 0xF1BB073D, 0xF1B80737, 0xF1B50732, 0xF1B3072C,
    0xF1B00726, 0xF1AD0721, 0xF1AA071B, 0xF1A70715, 0xF1A50710, 0xF1A2070A, 0xF19F0705, 0xF19C06FF, 0xF19A06F9,
    0xF19706F4, 0xF19406EE, 0xF19106E8, 0xF18F06E3, 0xF18C06DD, 0xF18906D7, 0xF18706D2, 0xF18406CC, 0xF18106C6,
    0xF17F06C1, 0xF17C06BB, 0xF17906B5, 0xF17706AF, 0xF17406AA, 0xF17106A4, 0xF16F069E, 0xF16C0699, 0xF16A0693,
    0xF167068D, 0xF1650687, 0xF1620682, 0xF15F067C, 0xF15D0676, 0xF15A0670, 0xF158066B, 0xF1550665, 0xF153065F,
    0xF1500659, 0xF14E0654, 0xF14B064E, 0xF1490648, 0xF1460642, 0xF144063C, 0xF1410637, 0xF13F0631, 0xF13D062B,
    0xF13A0625, 0xF138061F, 0xF135061A, 0xF1330614, 0xF131060E, 0xF12E0608, 0xF12C0602, 0xF12A05FD, 0xF12705F7,
    0xF12505F1, 0xF12305EB, 0xF12005E5, 0xF11E05DF, 0xF11C05DA, 0xF11905D4, 0xF11705CE, 0xF11505C8, 0xF11205C2,
    0xF11005BC, 0xF10E05B6, 0xF10C05B1, 0xF10905AB, 0xF10705A5, 0xF105059F, 0xF1030599, 0xF1010593, 0xF0FE058D,
    0xF0FC0587, 0xF0FA0581, 0xF0F8057C, 0xF0F60576, 0xF0F40570, 0xF0F2056A, 0xF0EF0564, 0xF0ED055E, 0xF0EB0558,
    0xF0E90552, 0xF0E7054C, 0xF0E50546, 0xF0E30540, 0xF0E1053A, 0xF0DF0534, 0xF0DD052F, 0xF0DB0529, 0xF0D90523,
    0xF0D7051D, 0xF0D50517, 0xF0D30511, 0xF0D1050B, 0xF0CF0505, 0xF0CD04FF, 0xF0CB04F9, 0xF0C904F3, 0xF0C704ED,
    0xF0C504E7, 0xF0C304E1, 0xF0C104DB, 0xF0BF04D5, 0xF0BD04CF, 0xF0BB04C9, 0xF0BA04C3, 0xF0B804BD, 0xF0B604B7,
    0xF0B404B1, 0xF0B204AB, 0xF0B004A5, 0xF0AF049F, 0xF0AD0499, 0xF0AB0493, 0xF0A9048D, 0xF0A70487, 0xF0A60481,
    0xF0A4047B, 0xF0A20475, 0xF0A0046F, 0xF09F0469, 0xF09D0463, 0xF09B045D, 0xF0990457, 0xF0980451, 0xF096044B,
    0xF0940444, 0xF093043E, 0xF0910438, 0xF08F0432, 0xF08E042C, 0xF08C0426, 0xF08A0420, 0xF089041A, 0xF0870414,
    0xF086040E, 0xF0840408, 0xF0830402, 0xF08103FC, 0xF07F03F6, 0xF07E03EF, 0xF07C03E9, 0xF07B03E3, 0xF07903DD,
    0xF07803D7, 0xF07603D1, 0xF07503CB, 0xF07303C5, 0xF07203BF, 0xF07003B9, 0xF06F03B2, 0xF06D03AC, 0xF06C03A6,
    0xF06B03A0, 0xF069039A, 0xF0680394, 0xF066038E, 0xF0650388, 0xF0640381, 0xF062037B, 0xF0610375, 0xF05F036F,
    0xF05E0369, 0xF05D0363, 0xF05B035D, 0xF05A0356, 0xF0590350, 0xF058034A, 0xF0560344, 0xF055033E, 0xF0540338,
    0xF0520332, 0xF051032B, 0xF0500325, 0xF04F031F, 0xF04D0319, 0xF04C0313, 0xF04B030D, 0xF04A0306, 0xF0490300,
    0xF04802FA, 0xF04602F4, 0xF04502EE, 0xF04402E8, 0xF04302E1, 0xF04202DB, 0xF04102D5, 0xF04002CF, 0xF03E02C9,
    0xF03D02C2, 0xF03C02BC, 0xF03B02B6, 0xF03A02B0, 0xF03902AA, 0xF03802A3, 0xF037029D, 0xF0360297, 0xF0350291,
    0xF034028B, 0xF0330284, 0xF032027E, 0xF0310278, 0xF0300272, 0xF02F026C, 0xF02E0265, 0xF02D025F, 0xF02C0259,
    0xF02B0253, 0xF02B024D, 0xF02A0246, 0xF0290240, 0xF028023A, 0xF0270234, 0xF026022D, 0xF0250227, 0xF0240221,
    0xF024021B, 0xF0230215, 0xF022020E, 0xF0210208, 0xF0200202, 0xF02001FC, 0xF01F01F5, 0xF01E01EF, 0xF01D01E9,
    0xF01D01E3, 0xF01C01DC, 0xF01B01D6, 0xF01A01D0, 0xF01A01CA, 0xF01901C3, 0xF01801BD, 0xF01801B7, 0xF01701B1,
    0xF01601AA, 0xF01601A4, 0xF015019E, 0xF0140198, 0xF0140191, 0xF013018B, 0xF0130185, 0xF012017F, 0xF0110178,
    0xF0110172, 0xF010016C, 0xF0100166, 0xF00F015F, 0xF00F0159, 0xF00E0153, 0xF00E014D, 0xF00D0146, 0xF00D0140,
    0xF00C013A, 0xF00C0134, 0xF00B012D, 0xF00B0127, 0xF00A0121, 0xF00A011B, 0xF0090114, 0xF009010E, 0xF0080108,
    0xF0080101, 0xF00800FB, 0xF00700F5, 0xF00700EF, 0xF00700E8, 0xF00600E2, 0xF00600DC, 0xF00600D6, 0xF00500CF,
    0xF00500C9, 0xF00500C3, 0xF00400BC, 0xF00400B6, 0xF00400B0, 0xF00400AA, 0xF00300A3, 0xF003009D, 0xF0030097,
    0xF0030090, 0xF002008A, 0xF0020084, 0xF002007E, 0xF0020077, 0xF0020071, 0xF001006B, 0xF0010065, 0xF001005E,
    0xF0010058, 0xF0010052, 0xF001004B, 0xF0010045, 0xF000003F, 0xF0000039, 0xF0000032, 0xF000002C, 0xF0000026,
    0xF000001F, 0xF0000019, 0xF0000013, 0xF000000D, 0xF0000006, 0xF0000000, 0xF000FFFA, 0xF000FFF3, 0xF000FFED,
    0xF000FFE7, 0xF000FFE1, 0xF000FFDA, 0xF000FFD4, 0xF000FFCE, 0xF000FFC7, 0xF000FFC1, 0xF001FFBB, 0xF001FFB5,
    0xF001FFAE, 0xF001FFA8, 0xF001FFA2, 0xF001FF9B, 0xF001FF95, 0xF002FF8F, 0xF002FF89, 0xF002FF82, 0xF002FF7C,
    0xF002FF76, 0xF003FF70, 0xF003FF69, 0xF003FF63, 0xF003FF5D, 0xF004FF56, 0xF004FF50, 0xF004FF4A, 0xF004FF44,
    0xF005FF3D, 0xF005FF37, 0xF005FF31, 0xF006FF2A, 0xF006FF24, 0xF006FF1E, 0xF007FF18, 0xF007FF11, 0xF007FF0B,
    0xF008FF05, 0xF008FEFF, 0xF008FEF8, 0xF009FEF2, 0xF009FEEC, 0xF00AFEE5, 0xF00AFEDF, 0xF00BFED9, 0xF00BFED3,
    0xF00CFECC, 0xF00CFEC6, 0xF00DFEC0, 0xF00DFEBA, 0xF00EFEB3, 0xF00EFEAD, 0xF00FFEA7, 0xF00FFEA1, 0xF010FE9A,
    0xF010FE94, 0xF011FE8E, 0xF011FE88, 0xF012FE81, 0xF013FE7B, 0xF013FE75, 0xF014FE6F, 0xF014FE68, 0xF015FE62,
    0xF016FE5C, 0xF016FE56, 0xF017FE4F, 0xF018FE49, 0xF018FE43, 0xF019FE3D, 0xF01AFE36, 0xF01AFE30, 0xF01BFE2A,
    0xF01CFE24, 0xF01DFE1D, 0xF01DFE17, 0xF01EFE11, 0xF01FFE0B, 0xF020FE04, 0xF020FDFE, 0xF021FDF8, 0xF022FDF2,
    0xF023FDEB, 0xF024FDE5, 0xF024FDDF, 0xF025FDD9, 0xF026FDD3, 0xF027FDCC, 0xF028FDC6, 0xF029FDC0, 0xF02AFDBA,
    0xF02BFDB3, 0xF02BFDAD, 0xF02CFDA7, 0xF02DFDA1, 0xF02EFD9B, 0xF02FFD94, 0xF030FD8E, 0xF031FD88, 0xF032FD82,
    0xF033FD7C, 0xF034FD75, 0xF035FD6F, 0xF036FD69, 0xF037FD63, 0xF038FD5D, 0xF039FD56, 0xF03AFD50, 0xF03BFD4A,
    0xF03CFD44, 0xF03DFD3E, 0xF03EFD37, 0xF040FD31, 0xF041FD2B, 0xF042FD25, 0xF043FD1F, 0xF044FD18, 0xF045FD12,
    0xF046FD0C, 0xF048FD06, 0xF049FD00, 0xF04AFCFA, 0xF04BFCF3, 0xF04CFCED, 0xF04DFCE7, 0xF04FFCE1, 0xF050FCDB,
    0xF051FCD5, 0xF052FCCE, 0xF054FCC8, 0xF055FCC2, 0xF056FCBC, 0xF058FCB6, 0xF059FCB0, 0xF05AFCAA, 0xF05BFCA3,
    0xF05DFC9D, 0xF05EFC97, 0xF05FFC91, 0xF061FC8B, 0xF062FC85, 0xF064FC7F, 0xF065FC78, 0xF066FC72, 0xF068FC6C,
    0xF069FC66, 0xF06BFC60, 0xF06CFC5A, 0xF06DFC54, 0xF06FFC4E, 0xF070FC47, 0xF072FC41, 0xF073FC3B, 0xF075FC35,
    0xF076FC2F, 0xF078FC29, 0xF079FC23, 0xF07BFC1D, 0xF07CFC17, 0xF07EFC11, 0xF07FFC0A, 0xF081FC04, 0xF083FBFE,
    0xF084FBF8, 0xF086FBF2, 0xF087FBEC, 0xF089FBE6, 0xF08AFBE0, 0xF08CFBDA, 0xF08EFBD4, 0xF08FFBCE, 0xF091FBC8,
    0xF093FBC2, 0xF094FBBC, 0xF096FBB5, 0xF098FBAF, 0xF099FBA9, 0xF09BFBA3, 0xF09DFB9D, 0xF09FFB97, 0xF0A0FB91,
    0xF0A2FB8B, 0xF0A4FB85, 0xF0A6FB7F, 0xF0A7FB79, 0xF0A9FB73, 0xF0ABFB6D, 0xF0ADFB67, 0xF0AFFB61, 0xF0B0FB5B,
    0xF0B2FB55, 0xF0B4FB4F, 0xF0B6FB49, 0xF0B8FB43, 0xF0BAFB3D, 0xF0BBFB37, 0xF0BDFB31, 0xF0BFFB2B, 0xF0C1FB25,
    0xF0C3FB1F, 0xF0C5FB19, 0xF0C7FB13, 0xF0C9FB0D, 0xF0CBFB07, 0xF0CDFB01, 0xF0CFFAFB, 0xF0D1FAF5, 0xF0D3FAEF,
    0xF0D5FAE9, 0xF0D7FAE3, 0xF0D9FADD, 0xF0DBFAD7, 0xF0DDFAD1, 0xF0DFFACC, 0xF0E1FAC6, 0xF0E3FAC0, 0xF0E5FABA,
    0xF0E7FAB4, 0xF0E9FAAE, 0xF0EBFAA8, 0xF0EDFAA2, 0xF0EFFA9C, 0xF0F2FA96, 0xF0F4FA90, 0xF0F6FA8A, 0xF0F8FA84,
    0xF0FAFA7F, 0xF0FCFA79, 0xF0FEFA73, 0xF101FA6D, 0xF103FA67, 0xF105FA61, 0xF107FA5B, 0xF109FA55, 0xF10CFA4F,
    0xF10EFA4A, 0xF110FA44, 0xF112FA3E, 0xF115FA38, 0xF117FA32, 0xF119FA2C, 0xF11CFA26, 0xF11EFA21, 0xF120FA1B,
    0xF123FA15, 0xF125FA0F, 0xF127FA09, 0xF12AFA03, 0xF12CF9FE, 0xF12EF9F8, 0xF131F9F2, 0xF133F9EC, 0xF135F9E6,
    0xF138F9E1, 0xF13AF9DB, 0xF13DF9D5, 0xF13FF9CF, 0xF141F9C9, 0xF144F9C4, 0xF146F9BE, 0xF149F9B8, 0xF14BF9B2,
    0xF14EF9AC, 0xF150F9A7, 0xF153F9A1, 0xF155F99B, 0xF158F995, 0xF15AF990, 0xF15DF98A, 0xF15FF984, 0xF162F97E,
    0xF165F979, 0xF167F973, 0xF16AF96D, 0xF16CF967, 0xF16FF962, 0xF171F95C, 0xF174F956, 0xF177F951, 0xF179F94B,
    0xF17CF945, 0xF17FF93F, 0xF181F93A, 0xF184F934, 0xF187F92E, 0xF189F929, 0xF18CF923, 0xF18FF91D, 0xF191F918,
    0xF194F912, 0xF197F90C, 0xF19AF907, 0xF19CF901, 0xF19FF8FB, 0xF1A2F8F6, 0xF1A5F8F0, 0xF1A7F8EB, 0xF1AAF8E5,
    0xF1ADF8DF, 0xF1B0F8DA, 0xF1B3F8D4, 0xF1B5F8CE, 0xF1B8F8C9, 0xF1BBF8C3, 0xF1BEF8BE, 0xF1C1F8B8, 0xF1C4F8B2,
    0xF1C6F8AD, 0xF1C9F8A7, 0xF1CCF8A2, 0xF1CFF89C, 0xF1D2F896, 0xF1D5F891, 0xF1D8F88B, 0xF1DBF886, 0xF1DEF880,
    0xF1E1F87B, 0xF1E4F875, 0xF1E7F870, 0xF1EAF86A, 0xF1EDF865, 0xF1F0F85F, 0xF1F3F85A, 0xF1F6F854, 0xF1F9F84E,
    0xF1FCF849, 0xF1FFF843, 0xF202F83E, 0xF205F838, 0xF208F833, 0xF20BF82E, 0xF20EF828, 0xF211F823, 0xF214F81D,
    0xF217F818, 0xF21AF812, 0xF21DF80D, 0xF221F807, 0xF224F802, 0xF227F7FC, 0xF22AF7F7, 0xF22DF7F2, 0xF230F7EC,
    0xF234F7E7, 0xF237F7E1, 0xF23AF7DC, 0xF23DF7D6, 0xF240F7D1, 0xF244F7CC, 0xF247F7C6, 0xF24AF7C1, 0xF24DF7BB,
    0xF250F7B6, 0xF254F7B1, 0xF257F7AB, 0xF25AF7A6, 0xF25EF7A1, 0xF261F79B, 0xF264F796, 0xF267F791, 0xF26BF78B,
    0xF26EF786, 0xF271F781, 0xF275F77B, 0xF278F776, 0xF27BF771, 0xF27FF76B, 0xF282F766, 0xF286F761, 0xF289F75B,
    0xF28CF756, 0xF290F751, 0xF293F74C, 0xF297F746, 0xF29AF741, 0xF29EF73C, 0xF2A1F737, 0xF2A4F731, 0xF2A8F72C,
    0xF2ABF727, 0xF2AFF722, 0xF2B2F71C, 0xF2B6F717, 0xF2B9F712, 0xF2BDF70D, 0xF2C0F708, 0xF2C4F702, 0xF2C7F6FD,
    0xF2CBF6F8, 0xF2CEF6F3, 0xF2D2F6EE, 0xF2D6F6E8, 0xF2D9F6E3, 0xF2DDF6DE, 0xF2E0F6D9, 0xF2E4F6D4, 0xF2E8F6CF,
    0xF2EBF6C9, 0xF2EFF6C4, 0xF2F2F6BF, 0xF2F6F6BA, 0xF2FAF6B5, 0xF2FDF6B0, 0xF301F6AB, 0xF305F6A6, 0xF308F6A1,
    0xF30CF69B, 0xF310F696, 0xF313F691, 0xF317F68C, 0xF31BF687, 0xF31FF682, 0xF322F67D, 0xF326F678, 0xF32AF673,
    0xF32EF66E, 0xF331F669, 0xF335F664, 0xF339F65F, 0xF33DF65A, 0xF340F655, 0xF344F650, 0xF348F64B, 0xF34CF646,
    0xF350F641, 0xF354F63C, 0xF357F637, 0xF35BF632, 0xF35FF62D, 0xF363F628, 0xF367F623, 0xF36BF61E, 0xF36FF619,
    0xF372F614, 0xF376F60F, 0xF37AF60A, 0xF37EF605, 0xF382F601, 0xF386F5FC, 0xF38AF5F7, 0xF38EF5F2, 0xF392F5ED,
    0xF396F5E8, 0xF39AF5E3, 0xF39EF5DE, 0xF3A2F5DA, 0xF3A6F5D5, 0xF3AAF5D0, 0xF3AEF5CB, 0xF3B2F5C6, 0xF3B6F5C1,
    0xF3BAF5BC, 0xF3BEF5B8, 0xF3C2F5B3, 0xF3C6F5AE, 0xF3CAF5A9, 0xF3CEF5A4, 0xF3D2F5A0, 0xF3D6F59B, 0xF3DAF596,
    0xF3DEF591, 0xF3E2F58D, 0xF3E7F588, 0xF3EBF583, 0xF3EFF57E, 0xF3F3F57A, 0xF3F7F575, 0xF3FBF570, 0xF3FFF56B,
    0xF404F567, 0xF408F562, 0xF40CF55D, 0xF410F559, 0xF414F554, 0xF418F54F, 0xF41DF54B, 0xF421F546, 0xF425F541,
    0xF429F53D, 0xF42EF538, 0xF432F533, 0xF436F52F, 0xF43AF52A, 0xF43FF525, 0xF443F521, 0xF447F51C, 0xF44BF518,
    0xF450F513, 0xF454F50E, 0xF458F50A, 0xF45DF505, 0xF461F501, 0xF465F4FC, 0xF469F4F8, 0xF46EF4F3, 0xF472F4EF,
    0xF477F4EA, 0xF47BF4E5, 0xF47FF4E1, 0xF484F4DC, 0xF488F4D8, 0xF48CF4D3, 0xF491F4CF, 0xF495F4CA, 0xF49AF4C6,
    0xF49EF4C2, 0xF4A2F4BD, 0xF4A7F4B9, 0xF4ABF4B4, 0xF4B0F4B0, 0xF4B4F4AB, 0xF4B9F4A7, 0xF4BDF4A2, 0xF4C2F49E,
    0xF4C6F49A, 0xF4CAF495, 0xF4CFF491, 0xF4D3F48C, 0xF4D8F488, 0xF4DCF484, 0xF4E1F47F, 0xF4E5F47B, 0xF4EAF477,
    0xF4EFF472, 0xF4F3F46E, 0xF4F8F469, 0xF4FCF465, 0xF501F461, 0xF505F45D, 0xF50AF458, 0xF50EF454, 0xF513F450,
    0xF518F44B, 0xF51CF447, 0xF521F443, 0xF525F43F, 0xF52AF43A, 0xF52FF436, 0xF533F432, 0xF538F42E, 0xF53DF429,
    0xF541F425, 0xF546F421, 0xF54BF41D, 0xF54FF418, 0xF554F414, 0xF559F410, 0xF55DF40C, 0xF562F408, 0xF567F404,
    0xF56BF3FF, 0xF570F3FB, 0xF575F3F7, 0xF57AF3F3, 0xF57EF3EF, 0xF583F3EB, 0xF588F3E7, 0xF58DF3E2, 0xF591F3DE,
    0xF596F3DA, 0xF59BF3D6, 0xF5A0F3D2, 0xF5A4F3CE, 0xF5A9F3CA, 0xF5AEF3C6, 0xF5B3F3C2, 0xF5B8F3BE, 0xF5BCF3BA,
    0xF5C1F3B6, 0xF5C6F3B2, 0xF5CBF3AE, 0xF5D0F3AA, 0xF5D5F3A6, 0xF5DAF3A2, 0xF5DEF39E, 0xF5E3F39A, 0xF5E8F396,
    0xF5EDF392, 0xF5F2F38E, 0xF5F7F38A, 0xF5FCF386, 0xF601F382, 0xF605F37E, 0xF60AF37A, 0xF60FF376, 0xF614F372,
    0xF619F36F, 0xF61EF36B, 0xF623F367, 0xF628F363, 0xF62DF35F, 0xF632F35B, 0xF637F357, 0xF63CF354, 0xF641F350,
    0xF646F34C, 0xF64BF348, 0xF650F344, 0xF655F340, 0xF65AF33D, 0xF65FF339, 0xF664F335, 0xF669F331, 0xF66EF32E,
    0xF673F32A, 0xF678F326, 0xF67DF322, 0xF682F31F, 0xF687F31B, 0xF68CF317, 0xF691F313, 0xF696F310, 0xF69BF30C,
    0xF6A1F308, 0xF6A6F305, 0xF6ABF301, 0xF6B0F2FD, 0xF6B5F2FA, 0xF6BAF2F6, 0xF6BFF2F2, 0xF6C4F2EF, 0xF6C9F2EB,
    0xF6CFF2E8, 0xF6D4F2E4, 0xF6D9F2E0, 0xF6DEF2DD, 0xF6E3F2D9, 0xF6E8F2D6, 0xF6EEF2D2, 0xF6F3F2CE, 0xF6F8F2CB,
    0xF6FDF2C7, 0xF702F2C4, 0xF708F2C0, 0xF70DF2BD, 0xF712F2B9, 0xF717F2B6, 0xF71CF2B2, 0xF722F2AF, 0xF727F2AB,
    0xF72CF2A8, 0xF731F2A4, 0xF737F2A1, 0xF73CF29E, 0xF741F29A, 0xF746F297, 0xF74CF293, 0xF751F290, 0xF756F28C,
    0xF75BF289, 0xF761F286, 0xF766F282, 0xF76BF27F, 0xF771F27B, 0xF776F278, 0xF77BF275, 0xF781F271, 0xF786F26E,
    0xF78BF26B, 0xF791F267, 0xF796F264, 0xF79BF261, 0xF7A1F25E, 0xF7A6F25A, 0xF7ABF257, 0xF7B1F254, 0xF7B6F250,
    0xF7BBF24D, 0xF7C1F24A, 0xF7C6F247, 0xF7CCF244, 0xF7D1F240, 0xF7D6F23D, 0xF7DCF23A, 0xF7E1F237, 0xF7E7F234,
    0xF7ECF230, 0xF7F2F22D, 0xF7F7F22A, 0xF7FCF227, 0xF802F224, 0xF807F221, 0xF80DF21D, 0xF812F21A, 0xF818F217,
    0xF81DF214, 0xF823F211, 0xF828F20E, 0xF82EF20B, 0xF833F208, 0xF838F205, 0xF83EF202, 0xF843F1FF, 0xF849F1FC,
    0xF84EF1F9, 0xF854F1F6, 0xF85AF1F3, 0xF85FF1F0, 0xF865F1ED, 0xF86AF1EA, 0xF870F1E7, 0xF875F1E4, 0xF87BF1E1,
    0xF880F1DE, 0xF886F1DB, 0xF88BF1D8, 0xF891F1D5, 0xF896F1D2, 0xF89CF1CF, 0xF8A2F1CC, 0xF8A7F1C9, 0xF8ADF1C6,
    0xF8B2F1C4, 0xF8B8F1C1, 0xF8BEF1BE, 0xF8C3F1BB, 0xF8C9F1B8, 0xF8CEF1B5, 0xF8D4F1B3, 0xF8DAF1B0, 0xF8DFF1AD,
    0xF8E5F1AA, 0xF8EBF1A7, 0xF8F0F1A5, 0xF8F6F1A2, 0xF8FBF19F, 0xF901F19C, 0xF907F19A, 0xF90CF197, 0xF912F194,
    0xF918F191, 0xF91DF18F, 0xF923F18C, 0xF929F189, 0xF92EF187, 0xF934F184, 0xF93AF181, 0xF93FF17F, 0xF945F17C,
    0xF94BF179, 0xF951F177, 0xF956F174, 0xF95CF171, 0xF962F16F, 0xF967F16C, 0xF96DF16A, 0xF973F167, 0xF979F165,
    0xF97EF162, 0xF984F15F, 0xF98AF15D, 0xF990F15A, 0xF995F158, 0xF99BF155, 0xF9A1F153, 0xF9A7F150, 0xF9ACF14E,
    0xF9B2F14B, 0xF9B8F149, 0xF9BEF146, 0xF9C4F144, 0xF9C9F141, 0xF9CFF13F, 0xF9D5F13D, 0xF9DBF13A, 0xF9E1F138,
    0xF9E6F135, 0xF9ECF133, 0xF9F2F131, 0xF9F8F12E, 0xF9FEF12C, 0xFA03F12A, 0xFA09F127, 0xFA0FF125, 0xFA15F123,
    0xFA1BF120, 0xFA21F11E, 0xFA26F11C, 0xFA2CF119, 0xFA32F117, 0xFA38F115, 0xFA3EF112, 0xFA44F110, 0xFA4AF10E,
    0xFA4FF10C, 0xFA55F109, 0xFA5BF107, 0xFA61F105, 0xFA67F103, 0xFA6DF101, 0xFA73F0FE, 0xFA79F0FC, 0xFA7FF0FA,
    0xFA84F0F8, 0xFA8AF0F6, 0xFA90F0F4, 0xFA96F0F2, 0xFA9CF0EF, 0xFAA2F0ED, 0xFAA8F0EB, 0xFAAEF0E9, 0xFAB4F0E7,
    0xFABAF0E5, 0xFAC0F0E3, 0xFAC6F0E1, 0xFACCF0DF, 0xFAD1F0DD, 0xFAD7F0DB, 0xFADDF0D9, 0xFAE3F0D7, 0xFAE9F0D5,
    0xFAEFF0D3, 0xFAF5F0D1, 0xFAFBF0CF, 0xFB01F0CD, 0xFB07F0CB, 0xFB0DF0C9, 0xFB13F0C7, 0xFB19F0C5, 0xFB1FF0C3,
    0xFB25F0C1, 0xFB2BF0BF, 0xFB31F0BD, 0xFB37F0BB, 0xFB3DF0BA, 0xFB43F0B8, 0xFB49F0B6, 0xFB4FF0B4, 0xFB55F0B2,
    0xFB5BF0B0, 0xFB61F0AF, 0xFB67F0AD, 0xFB6DF0AB, 0xFB73F0A9, 0xFB79F0A7, 0xFB7FF0A6, 0xFB85F0A4, 0xFB8BF0A2,
    0xFB91F0A0, 0xFB97F09F, 0xFB9DF09D, 0xFBA3F09B, 0xFBA9F099, 0xFBAFF098, 0xFBB5F096, 0xFBBCF094, 0xFBC2F093,
    0xFBC8F091, 0xFBCEF08F, 0xFBD4F08E, 0xFBDAF08C, 0xFBE0F08A, 0xFBE6F089, 0xFBECF087, 0xFBF2F086, 0xFBF8F084,
    0xFBFEF083, 0xFC04F081, 0xFC0AF07F, 0xFC11F07E, 0xFC17F07C, 0xFC1DF07B, 0xFC23F079, 0xFC29F078, 0xFC2FF076,
    0xFC35F075, 0xFC3BF073, 0xFC41F072, 0xFC47F070, 0xFC4EF06F, 0xFC54F06D, 0xFC5AF06C, 0xFC60F06B, 0xFC66F069,
    0xFC6CF068, 0xFC72F066, 0xFC78F065, 0xFC7FF064, 0xFC85F062, 0xFC8BF061, 0xFC91F05F, 0xFC97F05E, 0xFC9DF05D,
    0xFCA3F05B, 0xFCAAF05A, 0xFCB0F059, 0xFCB6F058, 0xFCBCF056, 0xFCC2F055, 0xFCC8F054, 0xFCCEF052, 0xFCD5F051,
    0xFCDBF050, 0xFCE1F04F, 0xFCE7F04D, 0xFCEDF04C, 0xFCF3F04B, 0xFCFAF04A, 0xFD00F049, 0xFD06F048, 0xFD0CF046,
    0xFD12F045, 0xFD18F044, 0xFD1FF043, 0xFD25F042, 0xFD2BF041, 0xFD31F040, 0xFD37F03E, 0xFD3EF03D, 0xFD44F03C,
    0xFD4AF03B, 0xFD50F03A, 0xFD56F039, 0xFD5DF038, 0xFD63F037, 0xFD69F036, 0xFD6FF035, 0xFD75F034, 0xFD7CF033,
    0xFD82F032, 0xFD88F031, 0xFD8EF030, 0xFD94F02F, 0xFD9BF02E, 0xFDA1F02D, 0xFDA7F02C, 0xFDADF02B, 0xFDB3F02B,
    0xFDBAF02A, 0xFDC0F029, 0xFDC6F028, 0xFDCCF027, 0xFDD3F026, 0xFDD9F025, 0xFDDFF024, 0xFDE5F024, 0xFDEBF023,
    0xFDF2F022, 0xFDF8F021, 0xFDFEF020, 0xFE04F020, 0xFE0BF01F, 0xFE11F01E, 0xFE17F01D, 0xFE1DF01D, 0xFE24F01C,
    0xFE2AF01B, 0xFE30F01A, 0xFE36F01A, 0xFE3DF019, 0xFE43F018, 0xFE49F018, 0xFE4FF017, 0xFE56F016, 0xFE5CF016,
    0xFE62F015, 0xFE68F014, 0xFE6FF014, 0xFE75F013, 0xFE7BF013, 0xFE81F012, 0xFE88F011, 0xFE8EF011, 0xFE94F010,
    0xFE9AF010, 0xFEA1F00F, 0xFEA7F00F, 0xFEADF00E, 0xFEB3F00E, 0xFEBAF00D, 0xFEC0F00D, 0xFEC6F00C, 0xFECCF00C,
    0xFED3F00B, 0xFED9F00B, 0xFEDFF00A, 0xFEE5F00A, 0xFEECF009, 0xFEF2F009, 0xFEF8F008, 0xFEFFF008, 0xFF05F008,
    0xFF0BF007, 0xFF11F007, 0xFF18F007, 0xFF1EF006, 0xFF24F006, 0xFF2AF006, 0xFF31F005, 0xFF37F005, 0xFF3DF005,
    0xFF44F004, 0xFF4AF004, 0xFF50F004, 0xFF56F004, 0xFF5DF003, 0xFF63F003, 0xFF69F003, 0xFF70F003, 0xFF76F002,
    0xFF7CF002, 0xFF82F002, 0xFF89F002, 0xFF8FF002, 0xFF95F001, 0xFF9BF001, 0xFFA2F001, 0xFFA8F001, 0xFFAEF001,
    0xFFB5F001, 0xFFBBF001, 0xFFC1F000, 0xFFC7F000, 0xFFCEF000, 0xFFD4F000, 0xFFDAF000, 0xFFE1F000, 0xFFE7F000,
    0xFFEDF000, 0xFFF3F000, 0xFFFAF000, 0xF000,     0x6F000,    0xDF000,    0x13F000,   0x19F000,   0x1FF000,
    0x26F000,   0x2CF000,   0x32F000,   0x39F000,   0x3FF000,   0x45F001,   0x4BF001,   0x52F001,   0x58F001,
    0x5EF001,   0x65F001,   0x6BF001,   0x71F002,   0x77F002,   0x7EF002,   0x84F002,   0x8AF002,   0x90F003,
    0x97F003,   0x9DF003,   0xA3F003,   0xAAF004,   0xB0F004,   0xB6F004,   0xBCF004,   0xC3F005,   0xC9F005,
    0xCFF005,   0xD6F006,   0xDCF006,   0xE2F006,   0xE8F007,   0xEFF007,   0xF5F007,   0xFBF008,   0x101F008,
    0x108F008,  0x10EF009,  0x114F009,  0x11BF00A,  0x121F00A,  0x127F00B,  0x12DF00B,  0x134F00C,  0x13AF00C,
    0x140F00D,  0x146F00D,  0x14DF00E,  0x153F00E,  0x159F00F,  0x15FF00F,  0x166F010,  0x16CF010,  0x172F011,
    0x178F011,  0x17FF012,  0x185F013,  0x18BF013,  0x191F014,  0x198F014,  0x19EF015,  0x1A4F016,  0x1AAF016,
    0x1B1F017,  0x1B7F018,  0x1BDF018,  0x1C3F019,  0x1CAF01A,  0x1D0F01A,  0x1D6F01B,  0x1DCF01C,  0x1E3F01D,
    0x1E9F01D,  0x1EFF01E,  0x1F5F01F,  0x1FCF020,  0x202F020,  0x208F021,  0x20EF022,  0x215F023,  0x21BF024,
    0x221F024,  0x227F025,  0x22DF026,  0x234F027,  0x23AF028,  0x240F029,  0x246F02A,  0x24DF02B,  0x253F02B,
    0x259F02C,  0x25FF02D,  0x265F02E,  0x26CF02F,  0x272F030,  0x278F031,  0x27EF032,  0x284F033,  0x28BF034,
    0x291F035,  0x297F036,  0x29DF037,  0x2A3F038,  0x2AAF039,  0x2B0F03A,  0x2B6F03B,  0x2BCF03C,  0x2C2F03D,
    0x2C9F03E,  0x2CFF040,  0x2D5F041,  0x2DBF042,  0x2E1F043,  0x2E8F044,  0x2EEF045,  0x2F4F046,  0x2FAF048,
    0x300F049,  0x306F04A,  0x30DF04B,  0x313F04C,  0x319F04D,  0x31FF04F,  0x325F050,  0x32BF051,  0x332F052,
    0x338F054,  0x33EF055,  0x344F056,  0x34AF058,  0x350F059,  0x356F05A,  0x35DF05B,  0x363F05D,  0x369F05E,
    0x36FF05F,  0x375F061,  0x37BF062,  0x381F064,  0x388F065,  0x38EF066,  0x394F068,  0x39AF069,  0x3A0F06B,
    0x3A6F06C,  0x3ACF06D,  0x3B2F06F,  0x3B9F070,  0x3BFF072,  0x3C5F073,  0x3CBF075,  0x3D1F076,  0x3D7F078,
    0x3DDF079,  0x3E3F07B,  0x3E9F07C,  0x3EFF07E,  0x3F6F07F,  0x3FCF081,  0x402F083,  0x408F084,  0x40EF086,
    0x414F087,  0x41AF089,  0x420F08A,  0x426F08C,  0x42CF08E,  0x432F08F,  0x438F091,  0x43EF093,  0x444F094,
    0x44BF096,  0x451F098,  0x457F099,  0x45DF09B,  0x463F09D,  0x469F09F,  0x46FF0A0,  0x475F0A2,  0x47BF0A4,
    0x481F0A6,  0x487F0A7,  0x48DF0A9,  0x493F0AB,  0x499F0AD,  0x49FF0AF,  0x4A5F0B0,  0x4ABF0B2,  0x4B1F0B4,
    0x4B7F0B6,  0x4BDF0B8,  0x4C3F0BA,  0x4C9F0BB,  0x4CFF0BD,  0x4D5F0BF,  0x4DBF0C1,  0x4E1F0C3,  0x4E7F0C5,
    0x4EDF0C7,  0x4F3F0C9,  0x4F9F0CB,  0x4FFF0CD,  0x505F0CF,  0x50BF0D1,  0x511F0D3,  0x517F0D5,  0x51DF0D7,
    0x523F0D9,  0x529F0DB,  0x52FF0DD,  0x534F0DF,  0x53AF0E1,  0x540F0E3,  0x546F0E5,  0x54CF0E7,  0x552F0E9,
    0x558F0EB,  0x55EF0ED,  0x564F0EF,  0x56AF0F2,  0x570F0F4,  0x576F0F6,  0x57CF0F8,  0x581F0FA,  0x587F0FC,
    0x58DF0FE,  0x593F101,  0x599F103,  0x59FF105,  0x5A5F107,  0x5ABF109,  0x5B1F10C,  0x5B6F10E,  0x5BCF110,
    0x5C2F112,  0x5C8F115,  0x5CEF117,  0x5D4F119,  0x5DAF11C,  0x5DFF11E,  0x5E5F120,  0x5EBF123,  0x5F1F125,
    0x5F7F127,  0x5FDF12A,  0x602F12C,  0x608F12E,  0x60EF131,  0x614F133,  0x61AF135,  0x61FF138,  0x625F13A,
    0x62BF13D,  0x631F13F,  0x637F141,  0x63CF144,  0x642F146,  0x648F149,  0x64EF14B,  0x654F14E,  0x659F150,
    0x65FF153,  0x665F155,  0x66BF158,  0x670F15A,  0x676F15D,  0x67CF15F,  0x682F162,  0x687F165,  0x68DF167,
    0x693F16A,  0x699F16C,  0x69EF16F,  0x6A4F171,  0x6AAF174,  0x6AFF177,  0x6B5F179,  0x6BBF17C,  0x6C1F17F,
    0x6C6F181,  0x6CCF184,  0x6D2F187,  0x6D7F189,  0x6DDF18C,  0x6E3F18F,  0x6E8F191,  0x6EEF194,  0x6F4F197,
    0x6F9F19A,  0x6FFF19C,  0x705F19F,  0x70AF1A2,  0x710F1A5,  0x715F1A7,  0x71BF1AA,  0x721F1AD,  0x726F1B0,
    0x72CF1B3,  0x732F1B5,  0x737F1B8,  0x73DF1BB,  0x742F1BE,  0x748F1C1,  0x74EF1C4,  0x753F1C6,  0x759F1C9,
    0x75EF1CC,  0x764F1CF,  0x76AF1D2,  0x76FF1D5,  0x775F1D8,  0x77AF1DB,  0x780F1DE,  0x785F1E1,  0x78BF1E4,
    0x790F1E7,  0x796F1EA,  0x79BF1ED,  0x7A1F1F0,  0x7A6F1F3,  0x7ACF1F6,  0x7B2F1F9,  0x7B7F1FC,  0x7BDF1FF,
    0x7C2F202,  0x7C8F205,  0x7CDF208,  0x7D2F20B,  0x7D8F20E,  0x7DDF211,  0x7E3F214,  0x7E8F217,  0x7EEF21A,
    0x7F3F21D,  0x7F9F221,  0x7FEF224,  0x804F227,  0x809F22A,  0x80EF22D,  0x814F230,  0x819F234,  0x81FF237,
    0x824F23A,  0x82AF23D,  0x82FF240,  0x834F244,  0x83AF247,  0x83FF24A,  0x845F24D,  0x84AF250,  0x84FF254,
    0x855F257,  0x85AF25A,  0x85FF25E,  0x865F261,  0x86AF264,  0x86FF267,  0x875F26B,  0x87AF26E,  0x87FF271,
    0x885F275,  0x88AF278,  0x88FF27B,  0x895F27F,  0x89AF282,  0x89FF286,  0x8A5F289,  0x8AAF28C,  0x8AFF290,
    0x8B4F293,  0x8BAF297,  0x8BFF29A,  0x8C4F29E,  0x8C9F2A1,  0x8CFF2A4,  0x8D4F2A8,  0x8D9F2AB,  0x8DEF2AF,
    0x8E4F2B2,  0x8E9F2B6,  0x8EEF2B9,  0x8F3F2BD,  0x8F8F2C0,  0x8FEF2C4,  0x903F2C7,  0x908F2CB,  0x90DF2CE,
    0x912F2D2,  0x918F2D6,  0x91DF2D9,  0x922F2DD,  0x927F2E0,  0x92CF2E4,  0x931F2E8,  0x937F2EB,  0x93CF2EF,
    0x941F2F2,  0x946F2F6,  0x94BF2FA,  0x950F2FD,  0x955F301,  0x95AF305,  0x95FF308,  0x965F30C,  0x96AF310,
    0x96FF313,  0x974F317,  0x979F31B,  0x97EF31F,  0x983F322,  0x988F326,  0x98DF32A,  0x992F32E,  0x997F331,
    0x99CF335,  0x9A1F339,  0x9A6F33D,  0x9ABF340,  0x9B0F344,  0x9B5F348,  0x9BAF34C,  0x9BFF350,  0x9C4F354,
    0x9C9F357,  0x9CEF35B,  0x9D3F35F,  0x9D8F363,  0x9DDF367,  0x9E2F36B,  0x9E7F36F,  0x9ECF372,  0x9F1F376,
    0x9F6F37A,  0x9FBF37E,  0x9FFF382,  0xA04F386,  0xA09F38A,  0xA0EF38E,  0xA13F392,  0xA18F396,  0xA1DF39A,
    0xA22F39E,  0xA26F3A2,  0xA2BF3A6,  0xA30F3AA,  0xA35F3AE,  0xA3AF3B2,  0xA3FF3B6,  0xA44F3BA,  0xA48F3BE,
    0xA4DF3C2,  0xA52F3C6,  0xA57F3CA,  0xA5CF3CE,  0xA60F3D2,  0xA65F3D6,  0xA6AF3DA,  0xA6FF3DE,  0xA73F3E2,
    0xA78F3E7,  0xA7DF3EB,  0xA82F3EF,  0xA86F3F3,  0xA8BF3F7,  0xA90F3FB,  0xA95F3FF,  0xA99F404,  0xA9EF408,
    0xAA3F40C,  0xAA7F410,  0xAACF414,  0xAB1F418,  0xAB5F41D,  0xABAF421,  0xABFF425,  0xAC3F429,  0xAC8F42E,
    0xACDF432,  0xAD1F436,  0xAD6F43A,  0xADBF43F,  0xADFF443,  0xAE4F447,  0xAE8F44B,  0xAEDF450,  0xAF2F454,
    0xAF6F458,  0xAFBF45D,  0xAFFF461,  0xB04F465,  0xB08F469,  0xB0DF46E,  0xB11F472,  0xB16F477,  0xB1BF47B,
    0xB1FF47F,  0xB24F484,  0xB28F488,  0xB2DF48C,  0xB31F491,  0xB36F495,  0xB3AF49A,  0xB3EF49E,  0xB43F4A2,
    0xB47F4A7,  0xB4CF4AB,  0xB50F4B0,  0xB55F4B4,  0xB59F4B9,  0xB5EF4BD,  0xB62F4C2,  0xB66F4C6,  0xB6BF4CA,
    0xB6FF4CF,  0xB74F4D3,  0xB78F4D8,  0xB7CF4DC,  0xB81F4E1,  0xB85F4E5,  0xB89F4EA,  0xB8EF4EF,  0xB92F4F3,
    0xB97F4F8,  0xB9BF4FC,  0xB9FF501,  0xBA3F505,  0xBA8F50A,  0xBACF50E,  0xBB0F513,  0xBB5F518,  0xBB9F51C,
    0xBBDF521,  0xBC1F525,  0xBC6F52A,  0xBCAF52F,  0xBCEF533,  0xBD2F538,  0xBD7F53D,  0xBDBF541,  0xBDFF546,
    0xBE3F54B,  0xBE8F54F,  0xBECF554,  0xBF0F559,  0xBF4F55D,  0xBF8F562,  0xBFCF567,  0xC01F56B,  0xC05F570,
    0xC09F575,  0xC0DF57A,  0xC11F57E,  0xC15F583,  0xC19F588,  0xC1EF58D,  0xC22F591,  0xC26F596,  0xC2AF59B,
    0xC2EF5A0,  0xC32F5A4,  0xC36F5A9,  0xC3AF5AE,  0xC3EF5B3,  0xC42F5B8,  0xC46F5BC,  0xC4AF5C1,  0xC4EF5C6,
    0xC52F5CB,  0xC56F5D0,  0xC5AF5D5,  0xC5EF5DA,  0xC62F5DE,  0xC66F5E3,  0xC6AF5E8,  0xC6EF5ED,  0xC72F5F2,
    0xC76F5F7,  0xC7AF5FC,  0xC7EF601,  0xC82F605,  0xC86F60A,  0xC8AF60F,  0xC8EF614,  0xC91F619,  0xC95F61E,
    0xC99F623,  0xC9DF628,  0xCA1F62D,  0xCA5F632,  0xCA9F637,  0xCACF63C,  0xCB0F641,  0xCB4F646,  0xCB8F64B,
    0xCBCF650,  0xCC0F655,  0xCC3F65A,  0xCC7F65F,  0xCCBF664,  0xCCFF669,  0xCD2F66E,  0xCD6F673,  0xCDAF678,
    0xCDEF67D,  0xCE1F682,  0xCE5F687,  0xCE9F68C,  0xCEDF691,  0xCF0F696,  0xCF4F69B,  0xCF8F6A1,  0xCFBF6A6,
    0xCFFF6AB,  0xD03F6B0,  0xD06F6B5,  0xD0AF6BA,  0xD0EF6BF,  0xD11F6C4,  0xD15F6C9,  0xD18F6CF,  0xD1CF6D4,
    0xD20F6D9,  0xD23F6DE,  0xD27F6E3,  0xD2AF6E8,  0xD2EF6EE,  0xD32F6F3,  0xD35F6F8,  0xD39F6FD,  0xD3CF702,
    0xD40F708,  0xD43F70D,  0xD47F712,  0xD4AF717,  0xD4EF71C,  0xD51F722,  0xD55F727,  0xD58F72C,  0xD5CF731,
    0xD5FF737,  0xD62F73C,  0xD66F741,  0xD69F746,  0xD6DF74C,  0xD70F751,  0xD74F756,  0xD77F75B,  0xD7AF761,
    0xD7EF766,  0xD81F76B,  0xD85F771,  0xD88F776,  0xD8BF77B,  0xD8FF781,  0xD92F786,  0xD95F78B,  0xD99F791,
    0xD9CF796,  0xD9FF79B,  0xDA2F7A1,  0xDA6F7A6,  0xDA9F7AB,  0xDACF7B1,  0xDB0F7B6,  0xDB3F7BB,  0xDB6F7C1,
    0xDB9F7C6,  0xDBCF7CC,  0xDC0F7D1,  0xDC3F7D6,  0xDC6F7DC,  0xDC9F7E1,  0xDCCF7E7,  0xDD0F7EC,  0xDD3F7F2,
    0xDD6F7F7,  0xDD9F7FC,  0xDDCF802,  0xDDFF807,  0xDE3F80D,  0xDE6F812,  0xDE9F818,  0xDECF81D,  0xDEFF823,
    0xDF2F828,  0xDF5F82E,  0xDF8F833,  0xDFBF838,  0xDFEF83E,  0xE01F843,  0xE04F849,  0xE07F84E,  0xE0AF854,
    0xE0DF85A,  0xE10F85F,  0xE13F865,  0xE16F86A,  0xE19F870,  0xE1CF875,  0xE1FF87B,  0xE22F880,  0xE25F886,
    0xE28F88B,  0xE2BF891,  0xE2EF896,  0xE31F89C,  0xE34F8A2,  0xE37F8A7,  0xE3AF8AD,  0xE3CF8B2,  0xE3FF8B8,
    0xE42F8BE,  0xE45F8C3,  0xE48F8C9,  0xE4BF8CE,  0xE4DF8D4,  0xE50F8DA,  0xE53F8DF,  0xE56F8E5,  0xE59F8EB,
    0xE5BF8F0,  0xE5EF8F6,  0xE61F8FB,  0xE64F901,  0xE66F907,  0xE69F90C,  0xE6CF912,  0xE6FF918,  0xE71F91D,
    0xE74F923,  0xE77F929,  0xE79F92E,  0xE7CF934,  0xE7FF93A,  0xE81F93F,  0xE84F945,  0xE87F94B,  0xE89F951,
    0xE8CF956,  0xE8FF95C,  0xE91F962,  0xE94F967,  0xE96F96D,  0xE99F973,  0xE9BF979,  0xE9EF97E,  0xEA1F984,
    0xEA3F98A,  0xEA6F990,  0xEA8F995,  0xEABF99B,  0xEADF9A1,  0xEB0F9A7,  0xEB2F9AC,  0xEB5F9B2,  0xEB7F9B8,
    0xEBAF9BE,  0xEBCF9C4,  0xEBFF9C9,  0xEC1F9CF,  0xEC3F9D5,  0xEC6F9DB,  0xEC8F9E1,  0xECBF9E6,  0xECDF9EC,
    0xECFF9F2,  0xED2F9F8,  0xED4F9FE,  0xED6FA03,  0xED9FA09,  0xEDBFA0F,  0xEDDFA15,  0xEE0FA1B,  0xEE2FA21,
    0xEE4FA26,  0xEE7FA2C,  0xEE9FA32,  0xEEBFA38,  0xEEEFA3E,  0xEF0FA44,  0xEF2FA4A,  0xEF4FA4F,  0xEF7FA55,
    0xEF9FA5B,  0xEFBFA61,  0xEFDFA67,  0xEFFFA6D,  0xF02FA73,  0xF04FA79,  0xF06FA7F,  0xF08FA84,  0xF0AFA8A,
    0xF0CFA90,  0xF0EFA96,  0xF11FA9C,  0xF13FAA2,  0xF15FAA8,  0xF17FAAE,  0xF19FAB4,  0xF1BFABA,  0xF1DFAC0,
    0xF1FFAC6,  0xF21FACC,  0xF23FAD1,  0xF25FAD7,  0xF27FADD,  0xF29FAE3,  0xF2BFAE9,  0xF2DFAEF,  0xF2FFAF5,
    0xF31FAFB,  0xF33FB01,  0xF35FB07,  0xF37FB0D,  0xF39FB13,  0xF3BFB19,  0xF3DFB1F,  0xF3FFB25,  0xF41FB2B,
    0xF43FB31,  0xF45FB37,  0xF46FB3D,  0xF48FB43,  0xF4AFB49,  0xF4CFB4F,  0xF4EFB55,  0xF50FB5B,  0xF51FB61,
    0xF53FB67,  0xF55FB6D,  0xF57FB73,  0xF59FB79,  0xF5AFB7F,  0xF5CFB85,  0xF5EFB8B,  0xF60FB91,  0xF61FB97,
    0xF63FB9D,  0xF65FBA3,  0xF67FBA9,  0xF68FBAF,  0xF6AFBB5,  0xF6CFBBC,  0xF6DFBC2,  0xF6FFBC8,  0xF71FBCE,
    0xF72FBD4,  0xF74FBDA,  0xF76FBE0,  0xF77FBE6,  0xF79FBEC,  0xF7AFBF2,  0xF7CFBF8,  0xF7DFBFE,  0xF7FFC04,
    0xF81FC0A,  0xF82FC11,  0xF84FC17,  0xF85FC1D,  0xF87FC23,  0xF88FC29,  0xF8AFC2F,  0xF8BFC35,  0xF8DFC3B,
    0xF8EFC41,  0xF90FC47,  0xF91FC4E,  0xF93FC54,  0xF94FC5A,  0xF95FC60,  0xF97FC66,  0xF98FC6C,  0xF9AFC72,
    0xF9BFC78,  0xF9CFC7F,  0xF9EFC85,  0xF9FFC8B,  0xFA1FC91,  0xFA2FC97,  0xFA3FC9D,  0xFA5FCA3,  0xFA6FCAA,
    0xFA7FCB0,  0xFA8FCB6,  0xFAAFCBC,  0xFABFCC2,  0xFACFCC8,  0xFAEFCCE,  0xFAFFCD5,  0xFB0FCDB,  0xFB1FCE1,
    0xFB3FCE7,  0xFB4FCED,  0xFB5FCF3,  0xFB6FCFA,  0xFB7FD00,  0xFB8FD06,  0xFBAFD0C,  0xFBBFD12,  0xFBCFD18,
    0xFBDFD1F,  0xFBEFD25,  0xFBFFD2B,  0xFC0FD31,  0xFC2FD37,  0xFC3FD3E,  0xFC4FD44,  0xFC5FD4A,  0xFC6FD50,
    0xFC7FD56,  0xFC8FD5D,  0xFC9FD63,  0xFCAFD69,  0xFCBFD6F,  0xFCCFD75,  0xFCDFD7C,  0xFCEFD82,  0xFCFFD88,
    0xFD0FD8E,  0xFD1FD94,  0xFD2FD9B,  0xFD3FDA1,  0xFD4FDA7,  0xFD5FDAD,  0xFD5FDB3,  0xFD6FDBA,  0xFD7FDC0,
    0xFD8FDC6,  0xFD9FDCC,  0xFDAFDD3,  0xFDBFDD9,  0xFDCFDDF,  0xFDCFDE5,  0xFDDFDEB,  0xFDEFDF2,  0xFDFFDF8,
    0xFE0FDFE,  0xFE0FE04,  0xFE1FE0B,  0xFE2FE11,  0xFE3FE17,  0xFE3FE1D,  0xFE4FE24,  0xFE5FE2A,  0xFE6FE30,
    0xFE6FE36,  0xFE7FE3D,  0xFE8FE43,  0xFE8FE49,  0xFE9FE4F,  0xFEAFE56,  0xFEAFE5C,  0xFEBFE62,  0xFECFE68,
    0xFECFE6F,  0xFEDFE75,  0xFEDFE7B,  0xFEEFE81,  0xFEFFE88,  0xFEFFE8E,  0xFF0FE94,  0xFF0FE9A,  0xFF1FEA1,
    0xFF1FEA7,  0xFF2FEAD,  0xFF2FEB3,  0xFF3FEBA,  0xFF3FEC0,  0xFF4FEC6,  0xFF4FECC,  0xFF5FED3,  0xFF5FED9,
    0xFF6FEDF,  0xFF6FEE5,  0xFF7FEEC,  0xFF7FEF2,  0xFF8FEF8,  0xFF8FEFF,  0xFF8FF05,  0xFF9FF0B,  0xFF9FF11,
    0xFF9FF18,  0xFFAFF1E,  0xFFAFF24,  0xFFAFF2A,  0xFFBFF31,  0xFFBFF37,  0xFFBFF3D,  0xFFCFF44,  0xFFCFF4A,
    0xFFCFF50,  0xFFCFF56,  0xFFDFF5D,  0xFFDFF63,  0xFFDFF69,  0xFFDFF70,  0xFFEFF76,  0xFFEFF7C,  0xFFEFF82,
    0xFFEFF89,  0xFFEFF8F,  0xFFFFF95,  0xFFFFF9B,  0xFFFFFA2,  0xFFFFFA8,  0xFFFFFAE,  0xFFFFFB5,  0xFFFFFBB,
    0x1000FFC1, 0x1000FFC7, 0x1000FFCE, 0x1000FFD4, 0x1000FFDA, 0x1000FFE1, 0x1000FFE7, 0x1000FFED, 0x1000FFF3,
    0x1000FFFA};
int SECTION(".data") ratan_tbl_800A8F20[] = {
    0x10000,   0x20002,   0x30003,   0x50004,   0x60005,   0x70007,   0x90008,   0xA0009,   0xB000A,   0xC000C,
    0xE000D,   0xF000E,   0x100010,  0x110011,  0x130012,  0x140013,  0x150015,  0x170016,  0x180017,  0x190018,
    0x1A001A,  0x1C001B,  0x1D001C,  0x1E001E,  0x1F001F,  0x210020,  0x220021,  0x230023,  0x240024,  0x260025,
    0x270026,  0x280028,  0x2A0029,  0x2B002A,  0x2C002B,  0x2D002D,  0x2F002E,  0x30002F,  0x310031,  0x320032,
    0x340033,  0x350034,  0x360036,  0x370037,  0x390038,  0x3A0039,  0x3B003B,  0x3D003C,  0x3E003D,  0x3F003E,
    0x400040,  0x420041,  0x430042,  0x440043,  0x450045,  0x470046,  0x480047,  0x490049,  0x4A004A,  0x4C004B,
    0x4D004C,  0x4E004E,  0x4F004F,  0x510050,  0x520051,  0x530053,  0x540054,  0x560055,  0x570056,  0x580058,
    0x590059,  0x5B005A,  0x5C005B,  0x5D005D,  0x5E005E,  0x60005F,  0x610060,  0x620062,  0x630063,  0x650064,
    0x660065,  0x670067,  0x680068,  0x6A0069,  0x6B006A,  0x6C006B,  0x6D006D,  0x6F006E,  0x70006F,  0x710070,
    0x720072,  0x740073,  0x750074,  0x760075,  0x770077,  0x780078,  0x7A0079,  0x7B007A,  0x7C007C,  0x7D007D,
    0x7F007E,  0x80007F,  0x810080,  0x820082,  0x830083,  0x850084,  0x860085,  0x870087,  0x880088,  0x8A0089,
    0x8B008A,  0x8C008B,  0x8D008D,  0x8E008E,  0x90008F,  0x910090,  0x920091,  0x930093,  0x940094,  0x960095,
    0x970096,  0x980098,  0x990099,  0x9B009A,  0x9C009B,  0x9D009C,  0x9E009E,  0x9F009F,  0xA100A0,  0xA200A1,
    0xA300A2,  0xA400A4,  0xA500A5,  0xA600A6,  0xA800A7,  0xA900A8,  0xAA00A9,  0xAB00AB,  0xAC00AC,  0xAE00AD,
    0xAF00AE,  0xB000AF,  0xB100B1,  0xB200B2,  0xB400B3,  0xB500B4,  0xB600B5,  0xB700B6,  0xB800B8,  0xB900B9,
    0xBB00BA,  0xBC00BB,  0xBD00BC,  0xBE00BE,  0xBF00BF,  0xC000C0,  0xC200C1,  0xC300C2,  0xC400C3,  0xC500C5,
    0xC600C6,  0xC700C7,  0xC900C8,  0xCA00C9,  0xCB00CA,  0xCC00CB,  0xCD00CD,  0xCE00CE,  0xCF00CF,  0xD100D0,
    0xD200D1,  0xD300D2,  0xD400D3,  0xD500D5,  0xD600D6,  0xD700D7,  0xD900D8,  0xDA00D9,  0xDB00DA,  0xDC00DB,
    0xDD00DD,  0xDE00DE,  0xDF00DF,  0xE100E0,  0xE200E1,  0xE300E2,  0xE400E3,  0xE500E4,  0xE600E6,  0xE700E7,
    0xE800E8,  0xEA00E9,  0xEB00EA,  0xEC00EB,  0xED00EC,  0xEE00ED,  0xEF00EF,  0xF000F0,  0xF100F1,  0xF200F2,
    0xF400F3,  0xF500F4,  0xF600F5,  0xF700F6,  0xF800F7,  0xF900F8,  0xFA00FA,  0xFB00FB,  0xFC00FC,  0xFD00FD,
    0xFE00FE,  0x10000FF, 0x1010100, 0x1020101, 0x1030102, 0x1040103, 0x1050104, 0x1060106, 0x1070107, 0x1080108,
    0x1090109, 0x10A010A, 0x10B010B, 0x10D010C, 0x10E010D, 0x10F010E, 0x110010F, 0x1110110, 0x1120111, 0x1130112,
    0x1140113, 0x1150114, 0x1160116, 0x1170117, 0x1180118, 0x1190119, 0x11A011A, 0x11B011B, 0x11C011C, 0x11D011D,
    0x11E011E, 0x120011F, 0x1210120, 0x1220121, 0x1230122, 0x1240123, 0x1250124, 0x1260125, 0x1270126, 0x1280127,
    0x1290128, 0x12A0129, 0x12B012A, 0x12C012B, 0x12D012C, 0x12E012D, 0x12F012E, 0x130012F, 0x1310130, 0x1320131,
    0x1330133, 0x1340134, 0x1350135, 0x1360136, 0x1370137, 0x1380138, 0x1390139, 0x13A013A, 0x13B013B, 0x13C013C,
    0x13D013D, 0x13E013E, 0x13F013F, 0x1400140, 0x1410141, 0x1420142, 0x1430142, 0x1440143, 0x1450144, 0x1460145,
    0x1470146, 0x1480147, 0x1490148, 0x14A0149, 0x14B014A, 0x14C014B, 0x14D014C, 0x14E014D, 0x14F014E, 0x150014F,
    0x1510150, 0x1520151, 0x1530152, 0x1540153, 0x1540154, 0x1550155, 0x1560156, 0x1570157, 0x1580158, 0x1590159,
    0x15A015A, 0x15B015B, 0x15C015C, 0x15D015D, 0x15E015D, 0x15F015E, 0x160015F, 0x1610160, 0x1620161, 0x1630162,
    0x1640163, 0x1640164, 0x1650165, 0x1660166, 0x1670167, 0x1680168, 0x1690169, 0x16A016A, 0x16B016A, 0x16C016B,
    0x16D016C, 0x16E016D, 0x16F016E, 0x170016F, 0x1700170, 0x1710171, 0x1720172, 0x1730173, 0x1740174, 0x1750174,
    0x1760175, 0x1770176, 0x1780177, 0x1790178, 0x1790179, 0x17A017A, 0x17B017B, 0x17C017C, 0x17D017D, 0x17E017D,
    0x17F017E, 0x180017F, 0x1810180, 0x1810181, 0x1820182, 0x1830183, 0x1840184, 0x1850184, 0x1860185, 0x1870186,
    0x1870187, 0x1880188, 0x1890189, 0x18A018A, 0x18B018B, 0x18C018B, 0x18D018C, 0x18E018D, 0x18E018E, 0x18F018F,
    0x1900190, 0x1910191, 0x1920191, 0x1930192, 0x1930193, 0x1940194, 0x1950195, 0x1960196, 0x1970196, 0x1980197,
    0x1990198, 0x1990199, 0x19A019A, 0x19B019B, 0x19C019B, 0x19D019C, 0x19D019D, 0x19E019E, 0x19F019F, 0x1A001A0,
    0x1A101A0, 0x1A201A1, 0x1A201A2, 0x1A301A3, 0x1A401A4, 0x1A501A4, 0x1A601A5, 0x1A601A6, 0x1A701A7, 0x1A801A8,
    0x1A901A9, 0x1AA01A9, 0x1AB01AA, 0x1AB01AB, 0x1AC01AC, 0x1AD01AD, 0x1AE01AD, 0x1AF01AE, 0x1AF01AF, 0x1B001B0,
    0x1B101B0, 0x1B201B1, 0x1B201B2, 0x1B301B3, 0x1B401B4, 0x1B501B4, 0x1B601B5, 0x1B601B6, 0x1B701B7, 0x1B801B8,
    0x1B901B8, 0x1B901B9, 0x1BA01BA, 0x1BB01BB, 0x1BC01BB, 0x1BD01BC, 0x1BD01BD, 0x1BE01BE, 0x1BF01BE, 0x1C001BF,
    0x1C001C0, 0x1C101C1, 0x1C201C2, 0x1C301C2, 0x1C301C3, 0x1C401C4, 0x1C501C5, 0x1C601C5, 0x1C601C6, 0x1C701C7,
    0x1C801C8, 0x1C901C8, 0x1C901C9, 0x1CA01CA, 0x1CB01CB, 0x1CC01CB, 0x1CC01CC, 0x1CD01CD, 0x1CE01CD, 0x1CF01CE,
    0x1CF01CF, 0x1D001D0, 0x1D101D0, 0x1D101D1, 0x1D201D2, 0x1D301D3, 0x1D401D3, 0x1D401D4, 0x1D501D5, 0x1D601D5,
    0x1D701D6, 0x1D701D7, 0x1D801D8, 0x1D901D8, 0x1D901D9, 0x1DA01DA, 0x1DB01DA, 0x1DC01DB, 0x1DC01DC, 0x1DD01DD,
    0x1DE01DD, 0x1DE01DE, 0x1DF01DF, 0x1E001DF, 0x1E001E0, 0x1E101E1, 0x1E201E1, 0x1E301E2, 0x1E301E3, 0x1E401E4,
    0x1E501E4, 0x1E501E5, 0x1E601E6, 0x1E701E6, 0x1E701E7, 0x1E801E8, 0x1E901E8, 0x1E901E9, 0x1EA01EA, 0x1EB01EA,
    0x1EB01EB, 0x1EC01EC, 0x1ED01EC, 0x1ED01ED, 0x1EE01EE, 0x1EF01EE, 0x1EF01EF, 0x1F001F0, 0x1F101F0, 0x1F101F1,
    0x1F201F2, 0x1F301F2, 0x1F301F3, 0x1F401F4, 0x1F501F4, 0x1F501F5, 0x1F601F6, 0x1F701F6, 0x1F701F7, 0x1F801F8,
    0x1F901F8, 0x1F901F9, 0x1FA01FA, 0x1FB01FA, 0x1FB01FB, 0x1FC01FC, 0x1FD01FC, 0x1FD01FD, 0x1FE01FE, 0x1FF01FE,
    0x1FF01FF, 0x20001FF, 0x200,     0,         0,         0,         0x117350,  0x440000};
int   SECTION(".data") spu_EVdma_800A9738 = 0;
int   SECTION(".data") spu_keystat_800A973C = 0;
int   SECTION(".data") spu_trans_mode_800A9740 = 0;
int   SECTION(".data") spu_rev_flag_800A9744 = 0;
int   SECTION(".data") spu_rev_reserve_wa_800A9748 = 0;
int   SECTION(".data") spu_rev_offsetaddr_800A974C[] = {0, 0};
int   SECTION(".data") dword_800A9754 = 0;
short SECTION(".data") word_800A9758 = 0;
short SECTION(".data") word_800A975A = 0;
int   SECTION(".data") dword_800A975C = 0;
int   SECTION(".data") dword_800A9760 = 0;
int   SECTION(".data") spu_RQvoice_800A9764 = 0;
int   SECTION(".data") spu_RQmask_800A9768 = 0;
int   SECTION(".data") spu_voice_centerNote_800A976C[] = {0xC000C000, 0xC000C000, 0xC000C000, 0xC000C000,
                                                          0xC000C000, 0xC000C000, 0xC000C000, 0xC000C000,
                                                          0xC000C000, 0xC000C000, 0xC000C000};
char  SECTION(".data") byte_crap2[] = {0, 0xC0};
short SECTION(".data") word_800A979A = 0xC000;
int   SECTION(".data") spu_env_800A979C = 0;
int   SECTION(".data") spu_isCalled_800A97A0[] = {0, 0, 0, 0};
int   SECTION(".data") spu_RXX_800A97B0 = 0x1F801C00;
int   SECTION(".data") dword_800A97B4 = 0x1F8010C0;
int   SECTION(".data") dword_800A97B8 = 0x1F8010C4;
int   SECTION(".data") dword_800A97BC = 0x1F8010C8;
int   SECTION(".data") dword_800A97C0 = 0x1F8010F0;
int   SECTION(".data") dword_800A97C4 = 0x1F801014;
short SECTION(".data") spu_tsa_800A97C8 = 0;
int   SECTION(".data") spu_transMode_800A97CC = 0;
int   SECTION(".data") spu_addrMode_800A97D0 = 0;
int   SECTION(".data") spu_mem_mode_800A97D4 = 2;
int   SECTION(".data") spu_mem_mode_plus_800A97D8 = 3;
int   SECTION(".data") spu_mem_mode_unit_800A97DC = 8;
int   SECTION(".data") spu_mem_mode_unitM_800A97E0 = 7;
int   SECTION(".data") spu_inTransfer_800A97E4 = 1;
int   SECTION(".data") spu_transferCallback_800A97E8 = 0;
int   SECTION(".data") spu_IRQCallback_800A97EC = 0;
int   SECTION(".data") dword_800A97F0[] = {0x7070707, 0x7070707, 0x7070707, 0x7070707};
int   SECTION(".data") dword_800A9800 = 0;
int   SECTION(".data") dword_800A9804 = 0;
int   SECTION(".data") dword_800A9808[] = {0, 0};
int   SECTION(".data") spu_AllocBlockNum_800A9810 = 0;
int   SECTION(".data") spu_AllocLastNum_800A9814 = 0;
int   SECTION(".data") spu_memList_800A9818[] = {0, 0};
int   SECTION(".data") spu_zerobuf_800A9820[] = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
short SECTION(".data") word_800A9C20[] = {0x8000, 0x879C, 0x8FAC, 0x9837, 0xA145, 0xAADC,
                                          0xB504, 0xBFC8, 0xCB2F, 0xD744, 0xE411};
short SECTION(".data") word_800A9C36 = 0xF1A1;
int   SECTION(".data") dword_800A9C38[] = {
      0x800E8000, 0x802C801D, 0x804A803B, 0x80678058, 0x80858076, 0x80A38094, 0x80C080B1, 0x80DE80CF, 0x80FC80ED,
      0x811A810B, 0x81388129, 0x81558146, 0x81738164, 0x81918182, 0x81AF81A0, 0x81CD81BE, 0x81EB81DC, 0x820981FA,
      0x82278218, 0x82458236, 0x82638254, 0x82828272, 0x82A08291, 0x82BE82AF, 0x82DC82CD, 0x82FA82EB, 0x8319830A,
      0x83378328, 0x83558346, 0x83748364, 0x83928383, 0x83B083A1, 0x83CF83C0, 0x83ED83DE, 0x840C83FD, 0x842A841B,
      0x8449843A, 0x84688458, 0x84868477, 0x84A58495, 0x84C384B4, 0x84E284D3, 0x850184F1, 0x85208510, 0x853E852F,
      0x855D854E, 0x857C856D, 0x859B858B, 0x85BA85AA, 0x85D985C9, 0x85F885E8, 0x86178607, 0x86368626, 0x86558645,
      0x86748664, 0x86938683, 0x86B286A2, 0x86D186C1, 0x86F086E0, 0x870F8700, 0x872E871F, 0x874E873E, 0x876D875D};
short SECTION(".data") word_800A9D34[] = {0x877D, 0x878C, 0, 0, 0, 0};
int   SECTION(".data") spu_rev_startaddr_800A9D40[] = {0xFFFE, 0xFB28, 0xFC18, 0xF6F8, 0xF204, 0xEA44,
                                                       0xE128, 0xCFF8, 0xCFF8, 0xF880, 0,      0};
int   SECTION(".data") spu_rev_param_800A9D70[] = {
      0,          0,          0,          0,          0,          0,          0,          0,          0,
      0,          0,          0,          0,          0,          0,          0,          0,          0,
      0x5B007D,   0x54B86D80, 0xBED0,     0xBA800000, 0x53005800, 0x33304D6,  0x22703F0,  0x1EF0374,  0x1B50334,
      0,          0,          0,          0,          0x13601B4,  0x5C00B8,   0x80008000, 0,          0x250033,
      0x4FA870F0, 0x4410BCE0, 0x9C00C0F0, 0x4EC05280, 0x31B03E4,  0x2AF03A4,  0x2660372,  0x25D031C,  0x18E025C,
      0x135022F,  0xB701D2,   0xB5018F,   0x8000B4,   0x26004C,   0x80008000, 0,          0x7F00B1,   0x4FA870F0,
      0x4510BCE0, 0xB4C0BEF0, 0x4EC05280, 0x76B0904,  0x65F0824,  0x61607A2,  0x5ED076C,  0x42E05EC,  0x305050F,
      0x2B70462,  0x265042F,  0x1B20264,  0x800100,   0x80008000, 0,          0xA900E3,   0x4FA86F60, 0x4510BCE0,
      0xA680BEF0, 0x52C05680, 0xB580DFB,  0xA3C0D09,  0x9730BD9,  0x8DA0B59,  0x5E908D9,  0x4B007EC,  0x3D206EF,
      0x31D05EA,  0x238031C,  0xAA0154,   0x80008000, 0,          0x13901A5,  0x50006000, 0xB8004C00, 0xC000BC00,
      0x5C006000, 0x11BB15BA, 0x10BD14C2, 0xDC111BC,  0xDC311C0,  0x9C10DC0,  0x7C10BC4,  0x6CD0A00,  0x5C109C2,
      0x41A05C0,  0x13A0274,  0x80008000, 0,          0x231033D,  0x50007E00, 0xB000B400, 0xB0004C00, 0x54006000,
      0x1A311ED6, 0x183B1D14, 0x16B21BC2, 0x15EF1A32, 0x105515EE, 0xF2D1334,  0xC5D11F6,  0xAE11056,  0x7A20AE0,
      0x2320464,  0x80008000, 0,          0x10001,    0x7FFF7FFF, 0,          0x81000000, 0,          0xFFF1FFF,
      0x51005,    0,          0x51005,    0,          0,          0,          0,          0x10021004, 0x20004,
      0x80008000, 0,          0x10001,    0x7FFF7FFF, 0,          0,          0,          0xFFF1FFF,  0x51005,
      0,          0x51005,    0,          0,          0,          0,          0x10021004, 0x20004,    0x80008000,
      0,          0x130017,   0x4FA870F0, 0x4510BCE0, 0x8500BEF0, 0x54C05F80, 0x2AF0371,  0x1DF02E5,  0x1D702B0,
      0x26A0358,  0x11E01D6,  0xB1012D,   0x59011F,   0xE301A0,   0x400058,   0x140028,   0x80008000, 0,
      0,          0x67350,    0x440000};
int  SECTION(".data") dword_800AA028 = 0x1F801814;
int  SECTION(".data") dword_800AA02C = 0x1F801110;
int  SECTION(".data") Hcount_800AA030 = 0;
int  SECTION(".data") dword_800AA034[] = {0, 0, 0};
char SECTION(".data")
    aLibraryProgram[] = "Library Programs (c) 1993-1997 Sony Computer Entertainment Inc., All Rights Reserved.";
short SECTION(".data") word_800AA096 = 0;
short SECTION(".data") word_800AA098 = 0;
int   SECTION(".data") dword_800AA09C[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
short SECTION(".data") word_800AA0C8 = 0;
short SECTION(".data") word_800AA0CA = 0;
int   SECTION(".data") dword_800AA0CC = 0;
int   SECTION(".data") dword_800AA0D0 = 0;
int   SECTION(".data") dword_800AA0D4[] = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int SECTION(".data") dword_800AB0B0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int SECTION(".data") off_800AB100[] = {(int)aIdIntrCV175199, 0, 0x80098754, 0x800984AC,
                                       0x8009889C,           0, 0x8009893C, (int)&word_800AA096 + 2};
int SECTION(".data") off_800AB120 = (int)off_800AB100;
int SECTION(".data") dword_800AB124 = 0x1F801070;
int SECTION(".data") dword_800AB128 = 0x1F801074;
int SECTION(".data") dword_800AB12C = 0x1F8010F0;
int SECTION(".data") dword_800AB130[] = {0, 0, 0, 0};
int SECTION(".data") dword_800AB140[] = {0, 0, 0, 0, 0, 0, 0, 0};
int SECTION(".data") Vcount_800AB160 = 0;
int SECTION(".data") dword_800AB164[] = {0x1F801114, 0, 0};
int SECTION(".data") dword_800AB170 = 0x1F8010F4;
int SECTION(".data") dword_800AB174[] = {0, 0, 0, 0, 0, 0, 0, 0};
int SECTION(".data") dword_800AB194[] = {0x1F801080, 0, 0};
int SECTION(".data") dword_800AB1A0[] = {0, 0, 0, 0};
int SECTION(".data") dword_800AB1B0 = 0;
int SECTION(".data") _heapbase_800AB1B4 = 0;
int SECTION(".data") _heapsize_800AB1B8[] = {0,       0x800148B8, 0x88A24,  0x8009D2DC, 0xE008, 0x800ABBF0,
                                             0x17618, 0x37350,    0x440000, 0,          0};
int SECTION(".data") dword_800AB1E4 = 0x1F801070;
int SECTION(".data") dword_800AB1E8 = 0x1F801100;
int SECTION(".data") dword_800AB1EC[] = {0x10, 0x20, 0x40, 1, 0, 0};
int SECTION(".data") dword_800AB204[] = {0x100, 0, 0, 0};
int SECTION(".data") dword_800AB214 = 0;
int SECTION(".data") dword_800AB218 = 0x1F801040;
int SECTION(".data") dword_800AB21C[] = {0x1F801070, 0, 0xC7350, 0x440000};
int SECTION(".data") padFuncNextPort_800AB22C = 0;
int SECTION(".data") padFuncClrInfo_800AB230 = 0;
int SECTION(".data") padFuncGetTxd_800AB234 = 0;
int SECTION(".data") padFuncCurrLimit_800AB238 = 0;
int SECTION(".data") padFuncPtr2Port_800AB23C = 0;
int SECTION(".data") padFuncPort2Info_800AB240 = 0;
int SECTION(".data") padFuncSendAuto_800AB244 = 0;
int SECTION(".data") padFuncChkEng_800AB248 = 0;
int SECTION(".data") padFuncRecvAuto_800AB24C = 0;
int SECTION(".data") padFuncClrCmdNo_800AB250 = 0;
int SECTION(".data") padFuncIntGun_800AB254 = 0;
int SECTION(".data") padFuncSetGunPort_800AB258 = 0;
int SECTION(".data") padFuncGetGunPos_800AB25C = 0;
int SECTION(".data") padInfoDir_800AB260 = 0;
int SECTION(".data") padIntExec_800AB264 = 0;
int SECTION(".data") padGunExec_800AB268 = 0;
int SECTION(".data") padSioChan_800AB26C = 0;
int SECTION(".data") padSioState_800AB270 = 0;
int SECTION(".data") padTotalCurr_800AB274 = 0;
int SECTION(".data") padModeMtap_800AB278 = 0;
int SECTION(".data") padChanStart_800AB27C = 0;
int SECTION(".data") padChanStop_800AB280 = 1;
int SECTION(".data") padFixResult_800AB284[] = {0xFFFFFFFF, 0xFFFFFFFF};
int SECTION(".data") dword_800AB28C = 0x1F801070;
int SECTION(".data") dword_800AB290 = 0x1F801040;
int SECTION(".data") dword_800AB294[] = {0, 0, 0, 0};
int SECTION(".data") dword_800AB2A4 = 0;
int SECTION(".data") dword_800AB2A8 = 0x1F801040;
int SECTION(".data") dword_800AB2AC = 0;
int SECTION(".data") dword_800AB2B0 = 0;
int SECTION(".data") padIntFunc_800AB2B4[] = {0x8009C09C, 0x8009C0E4, 0x8009C1BC, 0x8009C268, 0x8009C32C, 0, 0, 0};
int SECTION(".data") dword_800AB2D4[] = {0x1F801040, 0, 0, 0};
