#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>
#include <map>
#include <stdexcept>

class CSV;
class Row
{
public:
    std::vector<std::string> row;
    CSV *csv;

    Row(CSV *csv, std::vector<std::string> row) : csv(csv), row(row) {}

    std::string operator[](const std::string &columnName);
    std::string operator[](const int &columnIndex);
};

class CSV
{
public:
    std::vector<std::string> columns;
    std::vector<Row> rows;
    std::string path;

    int getColumnIndex(const std::string &columnName);
    int getRowIndex(const std::string &rowName);

    int writeCSV();
};

class CSVHandler
{
public:
    CSV readCSV(std::string CSVPath);
    int mergeCSVs(std::string inputFolder, std::string outputFolder, std::vector<std::pair<std::string, std::vector<std::string>>> CSVPaths);

private:
    int splitText(std::vector<std::string> &ptr, std::string text, char delimiter);
    std::vector<std::string> getColumns(std::string CSVPath);
    std::vector<std::vector<std::string>> getRows(std::string CSVPath);
};

#endif
