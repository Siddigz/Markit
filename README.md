# Assignment 1 - Autograder

**Name:** Siddig Ahmed  
COMP 2404 A1

## File Structure

### Header Files
- **`Assignment.h`** - Defines the Assignment class for managing multiple Submissions
- **`Submission.h`** - Defines the Submission class representing a student's submission with the time and mark
- **`DateTime.h`** - Defines a date/time class for everything else to use
- **`Mark.h`** - Defines the Mark class for grades (x out of y)
- **`Autograder.h`** - Defines the Autograder class for grading each student's output
- **`SubmissionServer.h`** - Defines the SubmissionServer class for managing multiple assignments
- **`Tester.h`** - Defines the Tester class for testing cases of the other classes
- **`defs.h`** - Contains global constant for MAX_ARRAY

### Implementation Files
- **`Assignment.cc`** - Implements Assignment class methods
- **`Submission.cc`** - Implements Submission class methods
- **`DateTime.cc`** - Implements DateTime class methods
- **`Mark.cc`** - Implements Mark class methods
- **`Autograder.cc`** - Implements Autograder class methods
- **`SubmissionServer.cc`** - Implements SubmissionServer class methods
- **`Tester.cc`** - Implements Tester class methods
- **`main.cc`** - The main function being run by the executable

### Build Files
- **`Makefile`** - Build configuration for compiling the project

## Compilation Instructions

```bash
make clean   
make         
```

### Executing Instructions
```bash
./a1
```

## Note
- I had to create an empty Submission() constructor due to SubmissionServer::SubmissionServer() being very problematic without it


