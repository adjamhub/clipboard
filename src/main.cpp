/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * Clipboard Project
 *
 * @license GPL-3.0 <https://www.gnu.org/licenses/gpl-3.0.txt>
 */


#include "config.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    
    app.setApplicationName(PROJECT_NAME);
    app.setApplicationVersion(PROJECT_VER);
    app.setOrganizationName("adjam");
    app.setOrganizationDomain("adjam.org");
    
    return app.exec();
}
