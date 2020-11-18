#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int caesar(int k, string msg); //function to cipher a message

int main(int argc, string argv[])
{
    if (argc != 2)
    { // if number of arguments is not equal to 2.
        printf("Enter one Key Value!!\n");
        return 1;
    }
    string s = argv[1];
    for (int i = 0, n = strlen(s); i < n; i++) // checking if key is numeric or not. If not numeric, exit.
    {
     if (!isdigit(s[i]))
     {
         printf("KEY MUST BE NUMERIC!\n"); // Alpanumeric is also not accepted.
         return 1;
     }
    }
    int key = atoi(s) % 26; // convert string to numeric
    string input;
    if (key == 0 || key == 26)
    {
        input = get_string("input: ");
        printf("ciphertext: %s\n", input);
        return 0;
    }
    else if (key < 0)
    {
        printf("Key should be between 0-26\n");
        return 1;
    }
    do
    {
        input = get_string("input: ");
    }
    while (strlen(input) < 1);
    caesar(key, input); // sends it to the caesar function
}

int caesar(int k, string msg) //this is where ciphering is happening.
{
    int c = 0;
    printf("ciphertext: ");
    while (msg[c] != '\0')
    {
        int j = 0;
        if (isalpha(msg[c]))
        { // Is the letter alphabet
            j = msg[c] + k;
            if (isupper(msg[c]))
            { // Is it in upper case.
                if (j>90)
                { //check if alphabet plus key is greater than 90 which is Z.
                    j=j%90;
                    printf("%c",j+64);
                }
                else
                {
                    printf("%c",j);
                }
            }
            else // check if lowercase.
            {
                if (j>122)
                {
                    j = j%122;
                    printf("%c",j+96);
                }
                else
                {
                    printf("%c",j);
                }
            }
        }
        else
        { //If the letter is not an alphabet.
            printf("%c", msg[c]);
        }
        c++;
    }
    printf("\n");
    return 0;
}