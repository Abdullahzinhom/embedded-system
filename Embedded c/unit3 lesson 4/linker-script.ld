/*learn-in-depth
unit3lesson3
Abdallah Zinhom */

MEMORY
{
    flash (RX) : ORIGIN = 0x00000000, LENGTH = 512M
    sram (RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
    .text :
    {
        *(.vectors*)       /* Vector table */
        *(.text*)          /* Code section */
        *(.rodata*)        /* Read-only data */
        _E_text = .;       /* End of text section */
    } > flash

    .data :
    {
        _S_data = .;       /* Start of data section */
        . = ALIGN(4);     /* Align to 4 bytes */
        *(.data*)          /* Initialized data */
        _E_data = .;       /* End of data section */
    } > sram AT> flash      /* Load data section into flash but copy to SRAM */

    .bss :
    {
        _S_bss = .;        /* Start of BSS section */
        *(.bss*)           /* Uninitialized data */
        _E_bss = .;        /* End of BSS section */
           
    } > sram
}
