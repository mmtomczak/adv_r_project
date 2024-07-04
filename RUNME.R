
# Run code below before running the main app
# It will ensure that all required packages and dependencies are installed


#### IMPORTANT ####
# Remember to set the below variable to the path in which folder with "tfmodel" package is stored
path_to_package <- "path_to_tfmodel_package_folder"



# Instaling all required packages
required_packages = c("shiny", "shinyjs", "bslib", "tidyverse", "keras", "Rcpp", "DT", "paletteer", "ggplot2", "devtools", "gridExtra")
for(i in required_packages){if(!require(i,character.only = TRUE)) install.packages(i)}


# Installation of Python enviroment for R and Keras (TensorFlow)
install.packages("reticulate")
install.packages("keras")
library(reticulate)
reticulate::install_python()
library(keras)
install_keras()


# Check and install the tfmodel package
library(devtools)

devtools::check(path_to_package)
devtools::install(pkg = path_to_package, reload = TRUE)
