//
// Created by saintedlittle on 05.11.2023.
//

#include "MainWindow.h"

namespace ui {

    MainWindow::MainWindow(const string &title, const pair<int, int> &resolution) {
        this->title = title;
        this->resolution = resolution;
    }

    int MainWindow::initialize() {
        /*
         * TODO: USE RAYLIB.
         */
    }

    void MainWindow::show() {
        /*
         * USE INITIALIZE METHOD.
         */
    }

    bool MainWindow::setIcon(const string &path) {
        return false;
    }

} // ui