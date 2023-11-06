//
// Created by saintedlittle on 05.11.2023.
//

#pragma once

#ifndef TOKENIZER_MAINWINDOW_H
#define TOKENIZER_MAINWINDOW_H

#include <string>
#include <vector>

using namespace std;

namespace ui {



    class MainWindow {
    public:
        MainWindow(const string &title, const pair<int, int> &resolution);

        bool setIcon(const string &path);

        void show();
    private:
        string title;
        pair<int, int> resolution;

        int initialize();
    };

} // ui

#endif //TOKENIZER_MAINWINDOW_H
