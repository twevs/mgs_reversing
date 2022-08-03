#include "linker.h"
#include "mts_new.h"

int SECTION(".int_800B5298") fs_stream_ref_count_800B5298;

void* SECTION(".fs_stream_heap_800B52A4") fs_stream_heap_800B52A4;
void* SECTION(".fs_stream_heap_800B52A4") fs_stream_heap_end_800B52A8;
int SECTION(".fs_stream_heap_800B52A4") fs_stream_heapSize_800B52AC;

void mts_lock_sem_8008A6CC(int taskNr);
void mts_unlock_sem_8008A85C(int taskNum);
void CDBIOS_ForceStop_80022864(void);

extern const char aStreamInitXX[];

extern int fs_stream_is_force_stop_8009D518;
extern int fs_stream_end_flag_8009D51C;
extern int fs_stream_task_state_800B52C0;

int FS_StreamInit_80023FD4(void* pHeap, int heapSize)
{
    fs_stream_heap_800B52A4 = pHeap;
    fs_stream_heapSize_800B52AC = heapSize;
    fs_stream_heap_end_800B52A8 = pHeap + heapSize;
    mts_printf_8008BBA0(aStreamInitXX, pHeap, heapSize);
    fs_stream_ref_count_800B5298 = 0;
    return 1;
}

void FS_StreamStop_80024028()
{
    fs_stream_is_force_stop_8009D518 = 1;
    fs_stream_end_flag_8009D51C = 1;
    fs_stream_task_state_800B52C0 = 0;
    CDBIOS_ForceStop_80022864();
}

void FS_StreamOpen_80024060()
{
    mts_lock_sem_8008A6CC(1);
    ++fs_stream_ref_count_800B5298;
    mts_unlock_sem_8008A85C(1);
}

void FS_StreamClose_80024098()
{
    mts_lock_sem_8008A6CC(1);
    --fs_stream_ref_count_800B5298;
    mts_unlock_sem_8008A85C(1);
}

int FS_StreamIsEnd_800240D0(void)
{
    return fs_stream_ref_count_800B5298 == 0;
}
