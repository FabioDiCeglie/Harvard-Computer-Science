from cs50 import get_int

card = get_int("Number: ")

number_of_digits = len(str(card))
first_two_digits = int(str(card)[0] + str(card)[1])

total_index_of_digits = len(str(card)) - 1

index_odd_numbers = total_index_of_digits - 2
index_even_numbers = total_index_of_digits

total_odd_numbers = 0
total_even_numbers = 0

for i in range(number_of_digits):
        # Calculate number not even
        if index_odd_numbers >= 0:
            calculate_number_not_even = int(str(card)[index_odd_numbers]) * 2
            if calculate_number_not_even > 9:
                 last_digit = int(str(calculate_number_not_even)[1])
                 first_digit = int(str(calculate_number_not_even)[0])
                 calculate_number_not_even = last_digit + first_digit
            total_odd_numbers += calculate_number_not_even
        # Calculate number even
        if index_even_numbers >= 0:
            total_even_numbers += int(str(card)[index_even_numbers])
        index_even_numbers -= 2
        index_odd_numbers -= 2

# Calculate total of numbers 
total = total_odd_numbers + total_even_numbers

if total > 10 and total % 10 == 0:
    if (first_two_digits // 10) == 4 and (number_of_digits == 13 or number_of_digits == 16):
        print("VISA")
    elif (first_two_digits == 34 or first_two_digits == 37) and number_of_digits == 15:
        print("AMEX")
    elif (first_two_digits == 51 or first_two_digits == 52 or first_two_digits == 53 or first_two_digits == 54 or first_two_digits == 55) and number_of_digits == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")