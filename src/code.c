// Macy Seaholm 
// CSCI 112 Fall 2026
// Programming Assignment #8
// I declare that I am the author of this work, take full responsibility for it, and have disclosed any material external assistance.

// code.c — student implementation only
/* * code.c - Implementation file for Lab 8  */


#include "code.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

/*
 * code.c - Assignment 8: File Access and Math Functions
 *
 * TODO: Include <stdio.h> (file functions), <stdlib.h> (abs),
 *       <math.h> (all other math functions) and your own "code.h".
 *
 * GENERAL RULES (apply to EVERY function below):
 *   - Check the arguments FIRST. If they are invalid, return false
 *     immediately, BEFORE calling fopen(), so the file is never touched.
 *   - Always check whether fopen() succeeded. If it did not, return false
 *     (or -1 for the functions that return int / long).
 *   - Always close every file you open, including on error paths
 *     that happen AFTER a successful fopen().
 *   - Text files: doubles are written as "%.2f\n", integers as "%d\n",
 *     one value per line.
 *   - Binary files: raw bytes only, no separators, no extra data.
 *   - Return true only if the write/read AND the close succeeded.
 *
 * OPTIONAL TIP: Many functions differ only in the math function and the
 * file mode. You may write small `static` helper functions (for example
 * "write one double as a text line using a given mode" and
 * "write an array of doubles as raw bytes using a given mode")
 * and reuse them. Helpers are not tested, and they do not go into code.h.
 */


/* ========================= PART A: Text mode ========================= */

/*
 * 1. create_abs_txt (returns bool; parameters: filename, int value)
 *    - Open the file for writing (it is created or overwritten).
 *    - Compute the absolute value of the integer with abs().
 *    - Write it as an integer followed by a newline.
 *    - Close the file and report success only if writing and closing worked.
 */
// TODO
bool create_abs_txt(const char *filename, int value)
{
    if (filename == NULL)
        return false;
    FILE *file = fopen (filename, "w");

    if (file == NULL)
        return false;
 
    int result = abs (value);

    int write_result = fprintf (file, "%d\n", result);
    int close_result = fclose(file);

    return write_result >= 0 && close_result == 0;
}
/*
 * 2. create_fabs_txt (returns bool; parameters: filename, double value)
 *    - Same idea as the previous function, but for a double:
 *      use fabs() and write with exactly two digits after the decimal point.
 *    - Open mode: write (create / overwrite).
 */
// TODO
bool create_fabs_txt(const char *filename, double value)
{
    if (filename == NULL || value < 0)
        return false;

    FILE *file = fopen (filename, "w");

    if (file == NULL)
        return false;
    
    double result = fabs(value);

    int write_result = fprintf (file, "%.2f\n", result);
    int close_result = fclose(file);

    return write_result >= 0 && close_result == 0;
    
}
/*
 * 3. append_sqrt_txt (returns bool; parameters: filename, double value)
 *    - Invalid input: negative value -> return false, do not touch the file.
 *    - Open the file in APPEND mode, so older content stays.
 *    - Write sqrt(value) as a new line with two decimal digits.
 *    - Close and report success.
 */
// TODO
bool append_sqrt_txt(const char *filename, double value)
{
    if (filename == NULL || value < 0)
        return false;

    FILE *file = fopen (filename, "w");

    if (file == NULL)
        return false;
    
    double result = sqrt(value);

    int write_result = fprintf (file, "%.2f\n", result);
    int close_result = fclose(file); 

    return write_result >= 0 && close_result == 0;
}

/*
 * 4. append_pow_txt (returns bool; parameters: filename, double base, double exponent)
 *    - Invalid input: base equal to zero AND exponent negative
 *      (division by zero) -> return false, do not touch the file.
 *    - Open in APPEND mode, write pow(base, exponent) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_pow_txt(const char *filename, double base, double exponent)
{
    if (filename == NULL)
        return false;
    
    if (base == 0 && exponent < 0)
        return false;

    FILE *file = fopen (filename, "a");

    if (file == NULL)
        return false;
    
    double result = pow(base, exponent);

    int write_result = fprintf (file, "%.2f\n", result);
    int close_result = fclose(file); 

    return write_result >= 0 && close_result == 0; 
}
/*
 * 5. create_ceil_floor_txt (returns bool; parameters: filename, double value)
 *    - Open in WRITE mode (create / overwrite).
 *    - Write TWO lines: first ceil(value), then floor(value),
 *      both with two decimal digits.
 *    - Success requires that both writes AND the close worked.
 */
// TODO
bool create_ceil_floor_txt(const char *filename, double value)
{
     if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "w");

    if (file == NULL)
        return false;
    
    double ceil_value = ceil(value);
    double floor_value = floor(value);

    int write1 = fprintf (file, "%.2f\n", ceil_value);
    int write2 = fprintf (file, "%.2f\n", floor_value);

    int close_result = fclose(file); 

    return  write1 >= 0 && write2 >= 0 && close_result == 0;

}
/*
 * 6. append_round_txt (returns bool; parameters: filename, double value)
 *    - Open in APPEND mode, write round(value) as a new line
 *      with two decimal digits, close, report success.
 *    - No invalid input exists for this function.
 */
// TODO
bool append_round_txt(const char *filename, double value)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "a");

    if (file == NULL)
        return false;
    
    double result = round(value);

    int write_result = fprintf (file, "%.2f\n", result);
    int close_result = fclose(file);

    return write_result >= 0 && close_result == 0;

}
/*
 * 7. append_fmod_txt (returns bool; parameters: filename, double x, double y)
 *    - Invalid input: y equal to zero -> return false, do not touch the file.
 *    - Open in APPEND mode, write fmod(x, y) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_fmod_txt(const char *filename, double x, double y)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "a");

    if (file == NULL)
        return false;

    double result = fmod(x,y);

    int write_result = fprintf (file, "%.2f\n", result);
    int close_result = fclose(file);

    return write_result >= 0 && close_result == 0;
    
}
/*
 * 8. load_txt_values (returns int; parameters: filename, double array, int max_count)
 *    - Open the file for reading. If it cannot be opened, return -1.
 *    - Keep a counter of values read, starting at 0.
 *    - Repeat while the counter is below max_count: read one number
 *      with the formatted-input function. Remember that a double needs
 *      the "long float" conversion specifier. The input function returns
 *      the number of items it successfully read; stop the loop when
 *      that is not exactly 1 (end of file or bad data).
 *    - Store each value into the next slot of the array and increase the counter.
 *    - Close the file and return the counter.
 */
// TODO
int load_txt_values(const char *filename, double *arr, int max_count)
{
    if (filename == NULL || arr == NULL || max_count<0)
        return -1;

    FILE *file = fopen (filename, "r");

    if (file == NULL)
        return -1;
    
    int count = 0;
    
    while (count < max_count)
    {
        if (fscanf (file, "lf", &arr[count])!=1)
            break;
        count++;
    }
    if (fclose(file) != 0)

    return count;
}

/*
 * 9. clear_file (returns bool; parameters: filename)
 *    - Think: which open mode removes all existing content
 *      and creates the file when it does not exist?
 *    - You do not need to write anything. Just open and close.
 *    - Report success only if both the open and the close worked.
 */
// TODO
bool clear_file(const char *filename)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "r");

    if (file == NULL)
        return false;
    
    return fclose(file) == 0;
}


/* ========================= PART B: Binary mode ========================= */

/*
 * 10. create_abs_bin (returns bool; parameters: filename, int value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Compute abs(value) and keep it in an int variable
 *       (you need its address to write it).
 *     - Write exactly ONE element whose size is the size of an int.
 *     - Success: fwrite reported 1 element written AND the close worked.
 */
// TODO
bool create_abs_bin(const char *filename, int value)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "wb");

    if (file == NULL)
        return false;
    
    int result = abs(value);

    size_t write_result = fwrite(&result, sizeof(int), 1, file);
    int close_result = fclose (file);

    return write_result == 1 && close_result == 0;
}
/*
 * 11. create_fabs_bin (returns bool; parameters: filename, double value)
 *     - Same idea as above, but the stored value is a double (fabs of the input).
 *     - Open in BINARY WRITE mode.
 *     - Keep the result in a double variable and write ONE element
 *       of size sizeof(double).
 */
// TODO
bool create_fabs_bin(const char *filename, double value)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "wb");

    if (file == NULL)
        return false;
    
    double result = fabs(value);

    size_t write_result = fwrite(&result, sizeof(double), 1, file);
    int close_result = fclose (file);

    return write_result == 1 && close_result == 0;
}

/*
 * 12. append_sqrt_bin (returns bool; parameters: filename, double value)
 *     - Invalid input: negative value -> return false BEFORE opening the file.
 *     - Open in BINARY APPEND mode, so older content stays.
 *     - Store sqrt(value) in a double variable and write ONE double.
 *     - Close and report success.
 */
// TODO
bool append_sqrt_bin(const char *filename, double value)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "ab");

    if (file == NULL)
        return false;
    
    double result = sqrt(value);

    size_t write_result = fwrite(&result, sizeof(double), 1, file);
    int close_result = fclose (file);

    return write_result == 1 && close_result == 0;
}

/*
 * 13. append_pow_bin (returns bool; parameters: filename, double base, double exponent)
 *     - Invalid input: base equal to zero AND exponent negative
 *       -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write pow(base, exponent) as ONE double,
 *       close, report success.
 */
// TODO
bool append_pow_bin(const char *filename, double base, double exponent)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "ab");

    if (file == NULL)
        return false;
    
    double result = pow(base, exponent);

    size_t write_result = fwrite(&result, sizeof(double), 1, file);
    int close_result = fclose (file);

    return write_result == 1 && close_result == 0;
}
/*
 * 14. create_ceil_floor_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Write TWO doubles: first ceil(value), then floor(value).
 *     - Hint: put both results in a small double array of size 2
 *       and write both elements with a SINGLE write call
 *       (count = 2), or use two separate calls.
 *     - Success requires that all writes AND the close worked.
 */
// TODO
bool create_ceil_floor_bin(const char *filename, double value)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "wb");

    if (file == NULL)
        return false;
    
    double values [2];

    values [0] = ceil(value);
    values [1] = floor(value);

    size_t write_result = fwrite(values, sizeof(double), 2, file);
    int close_result = fclose (file);

    return write_result == 2 && close_result == 0;    
}
/*
 * 15. append_round_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY APPEND mode, write round(value) as ONE double,
 *       close, report success.
 *     - No invalid input exists for this function.
 */
// TODO
bool append_round_bin(const char *filename, double value)
 {
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "ab");

    if (file == NULL)
        return false;

    double result = round(value);

    size_t write_result = fwrite(&result, sizeof(double), 1, file);
    int close_result = fclose (file);

    return write_result == 1 && close_result == 0;    
 }
/*
 * 16. append_fmod_bin (returns bool; parameters: filename, double x, double y)
 *     - Invalid input: y equal to zero -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write fmod(x, y) as ONE double,
 *       close, report success.
 */
// TODO
bool append_fmod_bin(const char *filename, double x, double y)
{
    if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "ab");

    if (file == NULL)
        return false;

    double result = fmod (x,y);

    size_t write_result = fwrite(&result, sizeof(double), 1, file);
    int close_result = fclose (file);

    return write_result == 1 && close_result == 0; 
}
/*
 * 17. load_abs_bin (returns bool; parameters: filename, int pointer out)
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Read ONE element of size sizeof(int) directly into *out
 *       (the pointer already holds the address, so do not use & here).
 *     - Close the file (always, also when the read failed).
 *     - Return true only if exactly 1 element was read.
 *       A file that is too short makes the read function return 0.
 */
// TODO
bool load_abs_bin(const char *filename, int *out)
{
      if (filename == NULL)
        return false;

    FILE *file = fopen (filename, "rb");

    if (file == NULL)
        return false;
    
    size_t read_result = fread(out, sizeof(int), 1, file);
    int close_result = fclose(file);

    return read_result == 1 && close_result == 0; 

}
/*
 * 18. load_bin_values (returns int; parameters: filename, double array, int max_count)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Keep a counter starting at 0.
 *     - Repeat while the counter is below max_count: read ONE double
 *       into the next array slot. Stop the loop when the read function
 *       does not return 1 (end of file).
 *     - Increase the counter after every successful read.
 *     - Close the file and return the counter.
 */
// TODO
int load_bin_values(const char *filename, double *arr, int max_count)
{
    if (filename == NULL || arr == NULL || max_count < 0)
        return -1;

    FILE *file = fopen (filename, "rb");

    if (file == NULL)
        return -1;
    
    int count = 0;

    while (count < max_count)
    {
        if (fread (&arr[count], sizeof(double), 1, file)!=1)
            break;
        count ++;
    }
    if (fclose(file) !=0)
        return -1;
    
    return count;
}
/*
 * 19. load_bin_value_at (returns bool; parameters: filename, int index, double pointer out)
 *     - Invalid input: negative index -> return false BEFORE opening the file.
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Calculate the byte offset: index multiplied by the size of a double.
 *       Convert it to long to match the type expected by the seek function.
 *     - Jump there from the BEGINNING of the file.
 *       If the seek fails, close the file and return false.
 *     - Read ONE double into *out. Close the file.
 *     - Return true only if exactly 1 element was read
 *       (a file that is too short gives 0).
 */
// TODO
bool load_bin_value_at(const char *filename, int index, double *out)
{
    if (filename == NULL || out == NULL || index < 0)
        return false;

    FILE *file = fopen (filename, "rb");

    if (file == NULL)
        return false;
    
    long offset = (long)index* sizeof (double);

    if (fseek(file,offset, SEEK_SET)!=0)
    {
        fclose(file);
        return false;
    }

    size_t read_result = fread(out, sizeof(double), 1, file);
    int close_result = fclose(file);

    return read_result == 1 && close_result == 0; 
}
/*
 * 20. get_file_size (returns long; parameters: filename)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Jump to the END of the file (offset 0, origin = end).
 *       If the seek fails, close the file and return -1.
 *     - Ask for the current position: at the end of the file it equals
 *       the size in bytes. Store it in a long variable.
 *     - Close the file and return the stored size.
 */
// TODO
long get_file_size(const char *filename)

{
    if (filename == NULL)
        return -1;

    FILE *file = fopen (filename, "rb");

    if (file == NULL)
        return -1;
    
    if (fseek(file, 0, SEEK_END)!=0)
     {
        fclose(file);
        return -1;
    }

    long size = ftell(file);

    if (fclose(file) != 0)
        return -1;

    return size;

}
