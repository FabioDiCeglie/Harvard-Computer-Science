import csv
import sys


def main():

    # TODO: Check for command-line usage
    # Print all command-line arguments
    # print("Arguments passed:", sys.argv[1])

    # Access individual arguments
    if len(sys.argv) > 3:
        print("Error you can use just two command-line arguments")
    
    if not (contains_substring(sys.argv[1], ".csv")):
        print("You need to add a CSV file argument as first command-line argument")
    
    if not (contains_substring(sys.argv[2], ".txt")):
        print("You need to add a txt file argument as second command-line argument")

    # TODO: Read database file into a variable
    peoples = []
    strs = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        strs = reader.fieldnames
        for row in reader:
            peoples.append(row)
    
    # TODO: Read DNA sequence file into a variable
    sequence = []
    with open(sys.argv[2], "r") as file:
        reader = csv.DictReader(file)
        sequence = reader.fieldnames

    # TODO: Find longest match of each STR in DNA sequence
    matched_dna = {}
    keys_to_check = []
    for s in strs:
        if(s == 'name'):
            continue
        keys_to_check.append(s)
        match = longest_match(sequence[0], s)
        matched_dna.update({s: match})

    # TODO: Check database for matching profiles  
    profile_matches = {}
    for profile in peoples:
        for key in keys_to_check:
            if profile[key] == str(matched_dna[key]):
                # Check if profile['name'] exists as a key in profile_matches
                if profile['name'] in profile_matches:
                    profile_matches[profile['name']] += 1
                else:
                    profile_matches[profile['name']] = 1

    highest_number = max(profile_matches.values()) == len(keys_to_check)
    if highest_number:
        best_profile = max(profile_matches, key=profile_matches.get)
        print(best_profile)
    else:
        print('No match')
    
    return 0

def contains_substring(s, substring):
    return substring in s

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
