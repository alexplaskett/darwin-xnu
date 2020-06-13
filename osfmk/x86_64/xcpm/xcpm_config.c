#include <x86_64/xcpm/xcpm_internal.h>

// Taken from https://github.com/knightsc/darwin-xnu/commit/3c33ed11358e8de767a370edcdb17b7a98cb91f7
// Credit to Scott Knight for the fix. 

static boolean_t xcpm_hwp_enabled;
static uint32_t __xcpm_reg[64] = {};

boolean_t
xcpm_is_hwp_enabled(void)
{
    return xcpm_hwp_enabled;
}

void
xcpm_mbox_lock(void)
{

}

void
xcpm_mbox_unlock(void)
{

}

uint32_t xcpm_bios_mbox_cmd_read(uint32_t a)
{
    return __xcpm_reg[a%64];
}

uint32_t xcpm_bios_mbox_cmd_unsafe_read(uint32_t a)
{
    return __xcpm_reg[a%64];
}

void xcpm_bios_mbox_cmd_write(uint32_t a, uint32_t b)
{
    __xcpm_reg[a%64] = b;
}
