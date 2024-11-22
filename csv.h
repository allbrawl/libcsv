#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>
#include <map>
#include "mod.h"

struct CSV
{
    std::vector<std::string> columns;
    std::vector<std::vector<std::string>> rows;
};

class CSVHandler
{
public:
    std::vector<std::string> getColumns(std::string CSVPath);
    std::vector<std::vector<std::string>> getRows(std::string CSVPath);
    CSV readCSV(std::string CSVPath);
    int writeCSV(std::string CSVPath, CSV csv);
    int mergeCSVs(std::string inputFolder, std::string outputFolder, std::vector<std::pair<std::string, std::vector<std::string>>> CSVPaths);
    int getColumnIndex(std::vector<std::string> columns, std::string columnName);
    int getRowIndex(std::vector<std::vector<std::string>> rows, std::string rowName);
    int removeColumn(CSV csv, int index);
    int removeRow(CSV csv, int index);

private:
    int splitText(std::vector<std::string> &ptr, std::string text, char delimiter);
};

#endif
