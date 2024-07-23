#ifndef MARKETDATADOWNLOADER_H
#define MARKETDATADOWNLOADER_H
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <QMainWindow>
class MarketDataDownloader{
public:
    std::vector<double> for_y;
    std::vector<double> for_x;
    void let_me_see();
    void parse();
};
#endif // MARKETDATADOWNLOADER_H

