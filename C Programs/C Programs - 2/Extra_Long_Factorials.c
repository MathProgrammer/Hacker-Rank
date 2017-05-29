#include <stdio.h>

#define size_of_number 160
#define base 10

//Function Prototypes
int sum_of_digits(int[]);
void factorial(int[],int);

int main()
{
    int number[size_of_number] = {0}, question;
    scanf("%d", &question);

    factorial(number, question);
    return 0;
}

//Finding the factorial by multiplying the digits
void factorial(int number[], int num)
{
    int i, first_digit;
    int carry, replace, product;

    //First digit keeps track of the position of the 'most significant digit' in the array - where the trailing zeroes end.
    first_digit = 0;
    number[first_digit] = 1; //If we don't do this, the answer will be 0.

    //This while loop calculates num! and stores it in number[]
    while(num != 1)
    {
        //This block performs multiplication of number[] with the current value of num and stores the result in num
        //The multiplication is done like how we normally do it by hand.
        carry = 0;
        for(i = 0; i <= first_digit; i++)
        {
            product = num*number[i] + carry;
            replace = product%base; //Replace is what should be rewritten in the ith digit
            carry = product/base; //Carry needs to be added when num is multiplied with the next most significant digit

            //The ith digit of number is rewritten now as the product%base we're working in. This case - 10
            number[i] = replace;

            //If there is a carry in the MSB, then the number of digits will increase. For example, 112x10 = 1120. There is a carry in the MSB.
            if( (i == first_digit) && (carry > 0) )
            {
                first_digit++;
            }
        }

        num--;
    }

    for(i = first_digit; i >= 0; printf("%d",number[i--]));
}
