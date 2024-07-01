# Workshop #10: Function Templates

Version 1.0

In this workshop, you are to code a `standard-layout` class template (previously called `P`lain `O`ld `D`ata) and two function templates. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- code a very simple `struct` as template
- code function templates
- code calls to function template
- describe what you have learned while completing this workshop


## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (`LAB`): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is `not to be started in your first session of the week`. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a `penalty of max 40% of the whole workshop's mark` if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace `??` with your subject code (`00 or 44`)
- Replace `X` with Workshop number: [`1 to 10`]
- Replace `Y` with the part number: [`1 or 2`]
- Replace `sss` with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
`your name`, `your Seneca email`, `Seneca Student ID` and the `date` when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), `write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.`  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the `seneca` namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.


> Note: All the code written in workshops and the project must be implemented in the `seneca` namespace.

# Part 1 - LAB (100%)

Study and understand the code provided in `Student` module (`Student.h` and `Student.cpp`), `Book` module (`Book.h` and `Book.cpp`), and the tester `main` module (`main.cpp`). 

## Supplied Modules:
- Book (`Book.h` and `Book.cpp`)
- Student (`Student` and `Student.cpp`)
- main (`main.cpp`)


`Do not modify Book and Student modules!` Look at the code and make sure you understand them. Also, read the main module and understand it.

## MatchPair module
Create a header file called `MatchPair.h`. Do not create an implementation file for this module, since it is a `template` module.  

### `Pair` (templated struct)
In the MatchPair module, create a class template (struct) called `Pair` using two different type parameters with the following attributes:
- a public member called `first` of type, first type-parameter
- a public member called `second` of type, second type-parameter

#### `addDynamicPairElement`

Add the following function template to the `MatchPair` module.  This function template is used to add a Pair element to a dynamic array of Pairs and adding one to its provided size reference. 

```c++
template<typename T, typename U>
void addDynamicPairElement(Pair<T, U>*& pArray,const T& first, const U& second, int& size) {
   Pair<T, U>* temp = new Pair<T, U>[size + 1];
   for (int k = 0; pArray && k < size; k++) {
      temp[k] = pArray[k];
   }
   temp[size].first = first;
   temp[size].second = second;
   delete[] pArray;
   pArray = temp;
   size++;
}
```

>The function `addDynamicPairElement`is designed to add a new element (a **Pair**) to a dynamic array of Pairs (**pArray**). It takes three parameters: the array itself (**pArray**), the **first** element of the **Pair**, the **second** element of the **Pair**, and a reference to an integer **size** which represents the current size of the array.<br />
 The function dynamically allocates memory for a new temporary array (temp) with a size one greater than the current size. It then copies the elements from the original array into the temporary array using a loop. After that, it assigns the provided first and second values to the newly added element in the temporary array.<br />
  Next, it deallocates the memory occupied by the original array using delete[] to avoid memory leaks. Finally, it updates the pointer pArray to point to the newly created array and increments the size reference by one.

###  matches (templated function)
Finds pairs of element matches in two arrays, where the two arrays may carry elements of different types. 

Create a function template called `matches` with two different type parameters that accepts five arguments:
- an array called `arr1` with elements of type, first type-parameter
- an array called `arr2` with elements of type, second type-parameter
- the size of the array received in the first parameter
- the size of the array received in the second parameter
- a reference parameter to be used to return the size of the new dynamic array created inside the function.

First, function `matches` creates a pointer called `pt` for pointing to an object of `Pair` type instantiated for the two type parameters; initializes `pt` to `nullptr`. This pointer is to be used for pointing to a dynamic memory space to hold an array of `Pair` type objects. 

Second, function `matches` initializes the fifth reference parameter to zero. This parameter is to keep track of the number of elements in the `pt`-pointed array.

Third, in its core logic, function `matches` iterates through all the elements of the first array `arr1`, and in each of these iterations it runs a nested loop to iterate, or sub-iterate, through all the elements of the second array `arr2`. Each sub-iteration is to compare the current element of `arr1` with the current element of `arr2` for equality (using `==` operator). 

If the compared elements are equal, it calls `addDynamicPairElement` function to add the matched  `Pair` as a new elemet to the `pt` dynamic array. 


Finally, function `matches` returns the address of the first element of the new dynamic array; remember that its size is returned through the fifth function parameter. NOTE: The return type of `matches` is to be set to the type of the returned data.  

### releaseMem (templated function)
This function is for releasing the dynamic memory allocated by `matches` function. 

Create a function template called `releaseMem`, which  
- accepts addresses of the first element of an array as argument; types of the array elements are to be of the type, type parameter.
- releases the dynamic memory if the received address is valid, i.e., not `nullptr`.

## Tester Program (main module)
> In this workshop you will be making some changes in the main module. Make sure you add to the comment at the top of the main module including your information.

[main.cpp](./lab/main.cpp)

## Execution Sample

[correct_output.txt](./lab/correct_output.txt)

## PART 1 Submission (lab)


### Files to submit:  

```Text
Book.cpp
Book.h
Student.cpp
Student.h
MatchPair.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# Part 2: Reflection

Study your final solutions for each deliverable of the workshop `and the most recent milestones of the project`, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  `This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.`

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and `the project milestones` and mention any issues that caused you difficulty.


### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace `??` with your subject code (`00 or 44`)
- Replace `X` with Workshop number: [`1 to 10`]
- Replace `Y` with the part number: [`1 or 2`]
- Replace `sss` with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

> `⚠️Important:` Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
