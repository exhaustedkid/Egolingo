#include "settings_window.h"

SettingsWindow::SettingsWindow() {

  setWindowIcon(QIcon("../resourses/shesterny.png"));
  setWindowTitle("Settings");
  setFixedSize(230, 150);

  setStyleSheet("background-color: lightblue;");

  layout_ = new QGridLayout();

  difficulty_label_ = new QLabel("Choose difficulty:", this);
  difficulty_ = new QComboBox(this);
  difficulty_->addItem("easy");
  difficulty_->addItem("medium");
  difficulty_->addItem("hard");

  reset_label_ = new QLabel("Reset score:");
  reset_settings_ = new QPushButton("Be careful please", this);

  sound_label_ = new QLabel("Sound:", this);
  sound_ = new QComboBox(this);
  sound_->addItem("on");
  sound_->addItem("off");


  ManageLayouts();
  setLayout(layout_);
}

void SettingsWindow::ManageLayouts() {
  layout_->addWidget(difficulty_label_, 0, 0);
  layout_->addWidget(difficulty_, 0, 1);
  layout_->addWidget(sound_label_, 1, 0);
  layout_->addWidget(sound_, 1, 1);
  layout_->addWidget(reset_label_, 2, 0);
  layout_->addWidget(reset_settings_, 2, 1);
}
