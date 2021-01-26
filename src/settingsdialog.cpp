/*
 * Copyright (C) Andrea Diamantini 2021 <adjam@protonmail.com>
 *
 * Clipboard project
 *
 * @license GPL-3.0 <https://www.gnu.org/licenses/gpl-3.0.txt>
 */


#include "settingsdialog.h"
#include "ui_settings.h"


SettingsDialog::SettingsDialog(QWidget *parent) 
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Clipboard Manager Settings");

    loadSettings();
}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::loadSettings()
{
}


void SettingsDialog::saveSettings()
{
}
