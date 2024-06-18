/* linker script CortexM3
Auther: Ahmed Khaled Khalaf
*/

MEMORY
{
    FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 128K
    SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}


SECTIONS
{
    .text : {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = . ;
    }>FLASH

    .data : {
        _S_DATA = .;
        *(.data)
        . = ALIGN(4);
        _E_DATA = .;

    }>SRAM AT>FLASH

    .bss : {
        _S_bss = .;
        *(.bss*)
        _E_bss = .;
        . = ALIGN(4);
        . = . + 0x1000;
        Stack_top = .;

    }>SRAM
}