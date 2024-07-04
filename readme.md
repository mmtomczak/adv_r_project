# Neural Network App - Advanced Programming in R project

## Authors

**Marcin Miszkiel** (432418)  
**Katarzyna Mocio** (429956)  
**Mateusz Tomczak** (432561)

---

Project folder inside .zip package contains:

1. **App** folder:
    - `app.R` - Shiny app file
    - `stats.cpp` - File containing C++ code used to calculate data descriptive statistics
2. `RUNME.R` - File that should be run before running the Shiny application. It ensures that all required packages are installed
3. *glass.csv* - sample classification dataset number 1
4. *page_block_classification.csv* - sample classification dataset number 2
5. **readme.md** - this file
6. **tfmodel** folder - contains `tfmodel` package files

---

## IMPORTANT

In the `RUNME.R` file you should set the variable `path_to_package` to contain the absolute path to the `tfmodel` folder contents before running the code.  
This is needed to correctly install the `tfmodel` package on your computer.  
You set this variable correctly if the `devtools::check(path_to_package)` code block runs correctly and no errors and warnings are found in the package.
