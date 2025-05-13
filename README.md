# Devbhasha: The Divine Programming Language

## Project Description
Devbhasha ("Language of the Gods" in Sanskrit) is a programming language inspired by Indian mythology, culture, and history. This language aims to make programming more accessible while celebrating India's rich heritage through its syntax and structure. Devbhasha blends modern programming concepts with traditional Indian philosophical and mythological elements.

The language follows principles derived from ancient Indian texts:
- Clarity (Spashta): Code should be clear and understandable
- Purpose (Lakshya): Every element should serve a defined purpose
- Harmony (Sanyoga): Different parts of the program should work together seamlessly
- Elegance (Soundarya): The language should be aesthetically pleasing to write and read

## Student Information
- Student Name: Vaidik Patel
- Enrollment ID: 22000842

## Project Components
1. `devbhasha_keywords.pdf` - Comprehensive reference of all Devbhasha keywords
2. `devbhasha_manual.pdf` - Language specification and user manual

## Running Devbhasha Programs

### Compilation Instructions
To compile and run Devbhasha programs, use the following commands:

#### Generate parser from YACC file
bison -d devbhasha.y

#### Generate lexer from Flex file
flex devbhasha.l

#### Compile the generated files
gcc lex.yy.c devbhasha.tab.c -o devbhasha

#### Run a program
devbhasha.exe Sample/hello_world.db

### Example Program
Here's a simple "Hello World" program in Devbhasha:

dharma HelloWorld {
    lekha("Namaste, World!");
}
samapti

### System Requirements
- GCC compiler
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)

## Features
- Sanskrit/Hindi derived keywords for all programming constructs
- Support for variables, constants, loops, conditionals, and functions
- Object-oriented programming with classes and inheritance
- Standard library with mathematical, string, and system operations
- Error handling capabilities
- Cultural authenticity maintained through thoughtful keyword selection

## Acknowledgments
- Special thanks to my faculty, Prof. Vaibhavi Patel for her guidance and support throughout this project
- Thanks to my team member Om Pandit for his contributions and collaboration
