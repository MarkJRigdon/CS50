# Questions

## What's `stdint.h`?

- stdint.h is a header file in the C library that provides a set of typedefs for programmers.
- These typedefs specify exact-width integer types, along with defined min and max values for each type.
- The typedefs are presented as Macros the programmer can insert into code after including the stdint.h file.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

- intN_t naming convention is for signed int's.
- uintN-t naming convention is used for unsighed int's.
- "signed" values are the normal size of data the processor deals with (word size).
- "unsigned" values are can store integers from 0 to higher but no negatives.
- We are using uint8_t, uint32_t, etc to declare our size of our int's to be used for the various Aliases.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
- In our bmp.h file:
    - A BYTE is 8 bytes
    - A DWORD is 32 bytes
    - A LONG is 32 bytes
    - A WORD is 16 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP must be the character "B" then the character "M"
- In Hexadecimal B is 42
- In hexadecimal M is 4D
- Thus our first two bytes would need to be:  424D
- In binary it would then be:  01000010 01001101
These first two bytes are of course in the BITMAPFILEHEADER and allows applications to ensure that the file is actually a BMP file and that it is not damaged.

## What's the difference between `bfSize` and `biSize`?

- biSize is the number of bytes required by the structure of the BITMAPINFOHEADER:  fixed at 40 bytes
- bfSize is the total size of the entire BMP file
    - BITMAPFILEHEADER (14 bytes) +
    - BITMAPINFOHEADER (40 bytes) +
    - biSizeImage (the bytes of however many RGB triples the BMP file uses)

## What does it mean if `biHeight` is negative?

If biHeight is negative this indicates that the bitmap is a top-down type bitmap where it's origin starts in the upper-left corner.  

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

- The biBitCount field handles the color depth / bits-per-pixel file specification.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The file, as named, does not exist.
Teh file, as named, exists but you do not have permissions.
The file could already be open in a mode that doesn't allow other access.
File exists but there is a path/directory confusion. 

## Why is the third argument to `fread` always `1` in our code?

The third argument of fread denotes how many elements of the data are read in.
In our case since the second fread argument is the size of the element to read in, and the size is set to the full sizeof what we are reading (BITMAPINFOHEADER, RGBTRIPLE, etc), we are thus reading in 1 element of data each use of fread...which grabs the entire data set we are currently interested in since size is set to the sizeof the entire data set.
 

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

It assigns 1 since 1 module 4 = 1

## What does `fseek` do?

fseek is allowing us to immediately change the offset of the file pointer.  IE where the pointer is indexing to.  In this case we are using it to move the file pointer over the padding and point to the next real data value.

## What is `SEEK_CUR`?

SEEK_CUR is used to specify that the count of padding starts FROM the CURRENT file possition of the pointer.


## Whodunit?

***It was Professor Plum with the candlestick in the library.***
