#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for the user's name and store it in a variable
    string name = get_string("What's your name?\n");

    // Print out hello + the name of the user from the "hello" variable
    printf("hello, %s\n", name);
}