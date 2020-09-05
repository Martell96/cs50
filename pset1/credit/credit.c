#include <stdio.h>
#include <math.h>
#include <cs50.h>

string check_type(long credit_card);

int main(void)
{
    long credit_card = get_long("Number: ");
    // Splitting actual checking logic into other function
    printf("%s\n", check_type(credit_card));
}

string check_type(long credit_card)
{
    string cc_type;
    int digit;
    int even_sum = 0;
    int odd_sum = 0;

    int first_digit;
    int second_digit;

    for (digit = 0; credit_card > 0; digit++)
    {
        int current_digit = (credit_card % 10);
        if ((digit + 1) % 2 == 0) // Checks every 2 digits (counting from the back)
        {
            int doubled_digit = current_digit * 2; // Double current digit and store in this credential
            if (doubled_digit >= 10) // If the doubled number is bigger than 10, split into 2 digits
            {
                even_sum += doubled_digit % 10 + doubled_digit / 10; // Add first and second digit separately into even_sum
            }
            else
            {
                even_sum += doubled_digit; // If doubled number is a single digit, just add to even_sum
            }
        }
        else
        {
            odd_sum += (credit_card % 10); // If this is the 1, 3, 5, etc, digit, just add to odd_sum
        }

        if (credit_card < 100 && credit_card > 10)
        {
            first_digit = credit_card / 10;
            second_digit = credit_card % 10;
        }

        credit_card = credit_card / 10;
    }

    if ((even_sum + odd_sum) % 10 == 0)
    {
        if (first_digit == 4 && (digit == 13 | digit == 16))
        {
            cc_type = "VISA";
        }
        else if (first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4
                                      || second_digit == 5) && digit == 16)
        {
            cc_type = "MASTERCARD";
        }
        else if (first_digit == 3 && (second_digit == 4 || second_digit == 7) && digit == 15)
        {
            cc_type = "AMEX";
        }
        else
        {
            cc_type = "INVALID";
        }
    }
    else
    {
        cc_type = "INVALID";
    }

    return cc_type;
}