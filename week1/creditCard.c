#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long int card = get_long("Number: ");

    long int anotherCard = card;

    // Remove last card number for numbers not even
    long int secondCardWithoutLastDigit = card;
    secondCardWithoutLastDigit /= 10;

    int calculateNumberPerTwo = 0;
    int calculateNumberNotEven = 0;
    int numberOfDigits = 0;
    int firstTwoDigits = 0;

    // calculate odd numbers and even numbers
    while(card > 0)
    {
        int lastDigit = card % 10;
        card /= 10;
        calculateNumberPerTwo += lastDigit;
        card /= 10;
        int last = secondCardWithoutLastDigit % 10;
        secondCardWithoutLastDigit /= 10;
        last *= 2;
        if(last > 9)
        {
            int lastDig = last % 10;
            int firstDig = (last - lastDig) / 10;
            int totalNumber = lastDig + firstDig;
            calculateNumberNotEven += totalNumber;
        }
        else
        {
          calculateNumberNotEven += last;
        }
        secondCardWithoutLastDigit /= 10;
    }

    // calculate first two digits and number of digits
    while(anotherCard > 0)
    {
        anotherCard /= 10;
        numberOfDigits += 1;
        if(anotherCard > 10 && anotherCard < 100)
        {
            firstTwoDigits += anotherCard;
        }
    }

    int total = calculateNumberNotEven + calculateNumberPerTwo;
    if(total > 10 && (total % 10) == 0)
    {
        if((firstTwoDigits / 10) == 4 && (numberOfDigits == 13 || numberOfDigits == 16))
        {
            printf("VISA\n");
        }else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && numberOfDigits == 15)
        {
            printf("AMEX\n");
        } else if ((firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55) && numberOfDigits == 16)
        {
            printf("MASTERCARD\n");
        } else
        {
            printf("INVALID\n");
        }
    }else {
        printf("INVALID\n");
    }
}