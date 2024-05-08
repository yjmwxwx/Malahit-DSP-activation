/* Simple linker script for the STM32 ARM Cortex M3.  Link the text
   of the program into on-board flash and use on-board RAM for data and stack.
*/

SECTIONS
{
        /* interrupt vectors start at zero */
        . = 0x0;  /* start of flash */

        .text :  {  *(.text)   }

        /* constant data follows code but still in flash */
        .data :
        {
          *(.data)
          *(.rom)
        }

        /* internal RAM starts at 0x20000000 */
        . = 0x20000000;
        .ram : { *(.ram) }

        .bss :
        {
          *(.bss)
          *(.ram)
        }
}
