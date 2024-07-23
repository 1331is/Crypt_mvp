#include "MarketDataDownloader.h"

void MarketDataDownloader::parse(){
    std::ifstream file("/home/nagibator/Documents/For_QT/Crypto_mvp/quotes/TONUSDT-trades-2024-07-01.csv");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string id, price, qty, quote_qty, time, is_buyer_maker;

        std::getline(ss, id, ',');
        std::getline(ss, price, ',');
        std::getline(ss, qty, ',');
        std::getline(ss, quote_qty, ',');
        std::getline(ss, time, ',');
        std::getline(ss, is_buyer_maker, '\n');
        for_y.push_back(std::stod(price));
        for_x.push_back(std::stod(time));
        long long unix_time = std::stoll(time);
        time_t unix_time_second = unix_time / 1000;
        struct tm *local_time;
        local_time = localtime(&unix_time_second);
        // std::cout << "Price: " << price << ", day : month " << local_time->tm_mday << " : " << local_time->tm_mon + 1 << std::endl;
    }
    file.close();
}

void MarketDataDownloader::let_me_see(){
    for(int i = 0; i < for_x.size()-1;i++){
        std::cout << "price " << for_y[i] << " time " << for_x[i] << "  ||  ";
    }
}
