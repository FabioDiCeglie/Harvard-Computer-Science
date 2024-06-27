def coleman_liau_index(text):
    letters = 0
    words = 1
    sentences = 0

    # Count letters, words, and sentences
    for char in text:
        if char.isalpha():
            letters += 1
        if char == ' ':
            words += 1
        if char in ['.', '!', '?']:
            sentences += 1

    # Compute the Coleman-Liau index
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Print the grade level
    if index < 1:
        return "Before Grade 1"
    elif index >= 16:
        return "Grade 16+"
    else:
        return f"Grade {index}"

# Prompt the user for some text
text = input("Text: ")
grade = coleman_liau_index(text)
print(grade)