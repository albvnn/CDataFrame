# CDataFrame Project - README

Welcome to the CDataFrame project!

This project aims to implement a data structure in C called CDataFrame. This structure allows you to manipulate datasets organized into columns, offering various data interaction and analysis functionalities.

## Project Description
In this project, we have developed a library in C to create and manipulate DataFrames, similar to what is offered in high-level languages like Python. The CDataFrame is a flexible data structure for storing tabular data with features for adding, deleting, modifying, and analyzing data.

## How to Use the Library
### Prerequisites
- Operating System: Any system compatible with GCC or another C compiler
- C Compiler: GCC recommended

### Steps to Use the Library
1. Clone or download the project repository to your local machine:
```bash
git clone https://github.com/Akes-exe/CDataFrame.git
```
2. Navigate to the project directory:
```bash
cd projet-cdataframe
```
3. Compile the source files using your C compiler:
```bash
gcc main.c column.c cdataframe.c sort.c double-linked-list.c -o CDataFrame
```
4. Run the generated executable:
```bash
./CDataFrame
```

Then follow the on-screen instructions to interact with the library and use its features.

## Features

### 1. Creation and Filling
- **Create an Empty CDataframe**: Start with a blank slate by creating an empty CDataframe, ready to be filled with your data.
- **Fill the CDataframe with User Input**: Manually enter data to populate your CDataframe through an intuitive user input interface.
- **Hard Fill the CDataframe**: Pre-populate the CDataframe with predefined data, ideal for testing or demonstration purposes.
- **Import a CSV File into a CDataframe**: Easily import data from CSV files into your CDataframe, allowing for quick and seamless data integration.

### 2. Display
- **Display the Entire CDataframe**: View all the data in your CDataframe in one comprehensive display.
- **Display a Part of the Rows**: Specify a limit to view a subset of rows from your CDataframe, making it easier to analyze large datasets.
- **Display a Part of the Columns**: Specify a limit to view a subset of columns, allowing for focused analysis on specific data attributes.
- **Export the CDataframe to CSV**: Export your CDataframe data to a CSV file for sharing, reporting, or further processing in other tools.

### 3. Usual Operations
- **Add a Row of Values**: Insert a new row of data into your CDataframe, expanding your dataset as needed.
- **Delete a Row of Values**: Remove unwanted or incorrect data by deleting rows from your CDataframe.
- **Add a Column**: Introduce new attributes to your data by adding columns to your CDataframe.
- **Delete a Column**: Clean up your dataset by removing unnecessary or obsolete columns.
- **Rename a Column Title**: Update the titles of your columns for better clarity and understanding of the data.
- **Check for Existence of a Value**: Search your CDataframe to see if a particular value exists, aiding in quick data validation.
- **Access/Replace Cell Value**: Directly access or update the value in a specific cell using its row and column number for precise data manipulation.

### 4. Analysis and Statistics
- **Display Number of Rows**: Quickly determine the size of your dataset by viewing the total number of rows.
- **Display Number of Columns**: Understand the breadth of your data by seeing the total number of columns.
- **Count Cells Equal to a Value**: Find out how many cells contain a specific value for quick statistical insights.
- **Count Cells Greater Than a Value**: Identify cells with values greater than a specified number to assess data distributions.
- **Count Cells Less Than a Value**: Identify cells with values less than a specified number to assess data distributions.

### 5. Operations on Columns
- **Create a Column**: Add new columns to your CDataframe to expand your data structure.
- **Insert Value in a Column**: Populate specific columns with values, enhancing the detail and depth of your data.
- **Insert Value at a Position in a Column**: Insert values at specific positions within a column for precise data entry.
- **Free Memory of a Column**: Optimize memory usage by releasing memory allocated to unused columns.
- **Display Column Content**: View all values within a column to analyze and understand data trends.
- **Sort a Column**: Organize data by sorting column values in ascending or descending order.
- **Display Sorted Column Content**: View the contents of a sorted column to easily spot patterns and anomalies.
- **Delete Column Index**: Remove the index of a column when it is no longer needed.
- **Check Column Index**: Verify if a column has an index to ensure data integrity.
- **Update Column Index**: Modify the index of a column to reflect changes in data structure.

### 6. Search
- **Count Occurrences of a Value**: Determine how frequently a specific value appears in your CDataframe.
- **Return Value at Position**: Retrieve the value located at a specific position in your CDataframe.
- **Count Values Greater Than a Given Value**: Find out how many values exceed a specified threshold.
- **Count Values Less Than a Given Value**: Find out how many values fall below a specified threshold.
- **Count Values Equal to a Given Value**: Get the total count of cells matching a particular value.
- **Perform Binary Search**: Efficiently search for values using binary search algorithms for quick data retrieval.

### Additional Features
- **Manage Multiple CDataframes and Columns**: Create and manage multiple CDataframes and Columns simultaneously. Select the CDataframe or Column you wish to modify, providing flexibility and control over your data management tasks.

## Contributions and Remarks
This project was developed by Alban Pascal and Maxime Colin. We welcome contributions, improvement suggestions, and remarks. If you wish to contribute to the project or report an issue, please open a new issue on GitHub.

Note: This library is intended for educational and development purposes and is not affiliated with any real data manipulation projects.

---
