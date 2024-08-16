/*learn-in-depth
unit3lesson3
Abdallah Zinhom */

MEMORY
{
    flash (RX) : ORIGIN = 0x08000000, LENGTH = 128k
    sram (RWX) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
    .text :
    {
        *(.vectors*)       /* Vector table */
        *(.text*)          /* Code section */
        *(.rodata*)        /* Read-only data */
             /* End of text section */
    } > flash

    .data :
    {
              /* Start of data section */
        . = ALIGN(4);     /* Align to 4 bytes */
        *(.data*)          /* Initialized data */
        /* End of data section */
    } > flash      /* Load data section into flash but copy to SRAM */

    .bss :
    {
                /* Start of BSS section */
        *(.bss*)           /* Uninitialized data */
        _E_bss = .;        /* End of BSS section */
            /* Define stack top address */
    } > sram
}
