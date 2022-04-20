#include <iostream>
#include <QFile>
#include "main_window.h"

MainWindow::MainWindow(QWidget* parent) {

  layout_ = new QGridLayout();
  central_widget = new QWidget(this);

  resize(1000, 500);

  settings_window_ = new SettingsWindow();
  exit_context_menu_ = new ExitContextMenu();
  pick_an_option_window_ = new PickAnOptionWindow();

  flag_ = new QLabel(central_widget);
  owl_ = new QLabel(central_widget);
  shesternya_ = new QLabel(central_widget);
  exit_ = new QLabel(central_widget);

  settings_button_ = new QPushButton(central_widget);
  exit_button_ = new QPushButton(central_widget);

  time_to_practice_label_ = new QLabel("Let's practice", central_widget);
  QFont serifFont( "Times", 35, QFont::ExtraLight, true);
  time_to_practice_label_->setFont(serifFont);

  pick_an_option_button_ = new QPushButton("Pick-an-option", central_widget);
  pick_an_option_button_->setStyleSheet("background-color: lightgreen;");
  input_answer_button_ = new QPushButton("Input answer", central_widget);
  input_answer_button_->setStyleSheet("background-color: lightgreen;");
  audio_button_ = new QPushButton("Audio", central_widget);
  audio_button_->setStyleSheet("background-color: lightgreen;");
  mixed_button_ = new QPushButton("Mixed", central_widget);
  mixed_button_->setStyleSheet("background-color: lightgreen;");

  score_ = new QLabel(central_widget);
  QFont font( "Times", 20, QFont::ExtraLight);
  score_->setFont(font);
  score_->setText("Score 0");

  setStyleSheet("background-color: white;");
  central_widget->setLayout(layout_);
  setCentralWidget(central_widget);
  ConnectWidgets();
  CreateWidgets();

}


void MainWindow::ConnectWidgets() {
  connect(pick_an_option_button_, &QPushButton::pressed, this, [&]{
    pick_an_option_window_->show();
  });
  connect(settings_button_, &QPushButton::pressed, this, [&]{
    settings_window_->show();
  });
  connect(exit_button_, &QPushButton::pressed, this, [&]{
    exit_context_menu_->show();
  });
  connect(pick_an_option_window_->next_level_, &QPushButton::pressed, this, [&]{
    SetScore();
  });
}

void MainWindow::CreateWidgets() {

  QPixmap pix( "../resourses/flag.jpg");
  flag_->setPixmap(pix);
  QPixmap owl("../resourses/duolingo-bird.png");
  owl_->setPixmap(owl);
  QPixmap shesternya("../resourses/shesterny.png");
  shesternya_->setPixmap(shesternya);
  QPixmap exit("../resourses/exit.png");
  exit_->setPixmap(exit);

  layout_->addWidget(settings_button_, 0,0,1,1);
  settings_button_->setFlat(true);
  layout_->addWidget(exit_button_, 5,4,1,1);
  exit_button_->setFlat(true);

  connect(settings_button_, &QPushButton::clicked, this, []{std::cout << 1;});

  layout_->addWidget(flag_, 0, 4);
  layout_->addWidget(owl_, 2, 0, 3, 2);
  layout_->addWidget(time_to_practice_label_, 0, 2, 1, 1);
  layout_->addWidget(shesternya_, 0, 0, 1, 1);
  layout_->addWidget(exit_, 5, 4, 1, 1);
  layout_->addWidget(score_, 1, 4, 1, 1);

  layout_->addWidget(pick_an_option_button_, 2, 2, 1, 3);
  layout_->addWidget(input_answer_button_, 3, 2, 1, 3);
  layout_->addWidget(audio_button_, 4,2,1,3);
  layout_->addWidget(mixed_button_, 5, 2,1,3);

  audio_button_->setFixedSize(450, 70);
  input_answer_button_->setFixedSize(450, 70);
  pick_an_option_button_->setFixedSize(450, 70);
  mixed_button_->setFixedSize(450, 70);

  settings_button_->setFixedSize(70, 70);
  exit_button_->setFixedSize(70,70);

  owl_->setFixedSize(210, 280); // 1024 x 768
  owl_->setScaledContents(true);
  flag_->setFixedSize(70, 70);
  flag_->setScaledContents(true);
  shesternya_->setFixedSize(70, 70);
  shesternya_->setScaledContents(true);
  exit_->setFixedSize(70, 70);
  exit_->setScaledContents(true);

  QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  pick_an_option_button_->setSizePolicy(policy);
  input_answer_button_->setSizePolicy(policy);
  audio_button_->setSizePolicy(policy);
  mixed_button_->setSizePolicy(policy);

}

void MainWindow::SetScore() {
  QString str;
  str.setNum(pick_an_option_window_->GetTotalScore());
  score_->setText("Score " + str);
}

