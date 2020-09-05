#include <stdio.h>
#include <cs50.h>

// Define our two helper functions: print_spaces and print_hashes
void print_spaces(int height, int current_height);
void print_hashes(int current_height);

int main(void)
{
    int height = 0;

    // Keep asking for height value until we get an int in between 1 and 8 (inclusive)
    while (height < 1 | height > 8)
    {
        height = get_int("Height: ");
    }

    int current_height;

    // Go into a loop, starting at height 1, until we are at the desired height
    for (current_height = 1; current_height <= height; current_height++)
    {
        // Call our functions print_spaces and print_hashes to handle the printing of spaces and hashes
        print_spaces(height, current_height);
        print_hashes(current_height);
        printf("\n"); // Add a new line at the end of the hashes to move on to the next "floor"
    }
}

void print_spaces(int height, int current_height)
{
    int spaces;
    for (spaces = 0; spaces < height - current_height; spaces++)
    {
        printf(" ");
    }
    return;
}

void print_hashes(int current_height)
{
    int hashes;

    for (hashes = 0; hashes < current_height; hashes++)
    {
        printf("#");
    }

    printf("  ");

    for (hashes = 0; hashes < current_height; hashes++)
    {
        printf("#");
    }
    return;
}