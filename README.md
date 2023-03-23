# Divisible Text

## The Problem

Given a slug of text like "bellkittyforhill" and a dictionary of words, print "true" if it is possible to break that slug into a space separated string of words using only the words provided by the dictionary. You may use any language to write the solution.  Assume that input will come on standard input, and your results should be printed on standard output.

### Examples

| Slug             | Dictionary                      | Result |
| ---------------- | ------------------------------- | ------ |
| bellkittyforhill | "bell", "kittle", "for", "hill" | true   |
| theonlyones      | "cat", "apple", "ones"          | false  |

### The Input

The [samples](samples/) folder contains sample generated input, from the program `generate` provided in this repository.

The first line of input is the text slug. Each subsequent line is a single word which is available as part of the dictionary. All text should be lower case letters used in English writing.  The slug will be less than 100 characters. The dictionary will be under 200 words.

The source text is the text of Pride and Prejudice, from Project Gutenberg. People who wish to use other texts are free to do so.

## The Tools

If you wish to generate your own inputs, the tool `cleantext` takes a source text file and outputs it as lower case text stripped of punctuation. Because Project Gutenberg indicates such things as illustrations by putting things in square brackets, it attempts to omit all text that appears in square brackets, including nested brackets.  Using the `--unique` flag, it will output a list of the unique words that appear in the source text.

The `generate` tool, given a `text.txt` and `words.txt` file (which should be generated from the `cleantext` tool), will generate a problem input file.

Assuming that you have a modern C++ compiler installed, and the *make* build tool, you can generate samples with:

    make samples