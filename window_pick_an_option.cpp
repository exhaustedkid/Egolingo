#include "window_pick_an_option.h"
#include <QFile>
#include <QPainter>
#include <iostream>

void PickAnOptionWindow::CreateWindow() {

  resize(1800, 800);
  layout_ = new QGridLayout(this);

  progress_bar_ = new QProgressBar(this);
  progress_bar_->setMaximum(500);
  progress_bar_->setValue(0);

  empty_label_ = new QLabel(this);

  QFont font( "Times", 20, QFont::ExtraLight);
  next_level_ = new QPushButton(this);
  next_level_->setText("NEXT");
  next_level_->setFont(font);
  next_level_->hide();
  check_answer_= new QPushButton(this);
  check_answer_->setText("CHECK");
  check_answer_->setFont(font);
  skip_level_= new QPushButton(this);
  skip_level_->setText("SKIP");
  skip_level_->setFont(font);

  QFile fileIn(":resourses/pick_an_option_tasks.txt");
  fileIn.open(QIODevice::ReadOnly);
  QTextStream easy_input_input(&fileIn);

  task_number_ = new QLabel(this);
  task_number_->setText(easy_input_input.readLine());
  QFont task_font( "Times", 20, QFont::ExtraLight);
  task_number_->setFont(font);

  statement_ = new QLabel(this);
  statement_->setText(easy_input_input.readLine());
  QFont statement_font( "Times", 30, QFont::ExtraLight);
  statement_->setFont(statement_font);

  sentence_ = new QLabel(this);
  sentence_->setText(easy_input_input.readLine());
  QFont font_sentence( "Times", 30, QFont::ExtraLight);
  sentence_->setFont(font_sentence);

  first_answer_ = new QPushButton(this);
  first_answer_->setText(easy_input_input.readLine());
  second_answer_ = new QPushButton(this);
  second_answer_->setText(easy_input_input.readLine());
  third_answer_ = new QPushButton(this);
  third_answer_->setText(easy_input_input.readLine());
  fourth_answer_ = new QPushButton(this);
  fourth_answer_->setText(easy_input_input.readLine());
  QFont font_answer( "Times", 20, QFont::ExtraLight);
  first_answer_->setFont(font_answer);
  second_answer_->setFont(font_answer);
  third_answer_->setFont(font_answer);
  fourth_answer_->setFont(font_answer);

  QString string =  easy_input_input.readLine();
  if (string == "0") {
    correct_answer_ = 0;
  }
  if (string == "1") {
    correct_answer_ = 1;
  }
  if (string == "2") {
    correct_answer_ = 2;
  }
  if (string == "3") {
    correct_answer_ = 3;
  }


  ConnectLevelFeatures();
  ManageLayout();
  setLayout(layout_);
}

PickAnOptionWindow::PickAnOptionWindow() {
  CreateWindow();
}

void PickAnOptionWindow::LoadNextLevel() {

  QFile fileIn(":resourses/pick_an_option_tasks.txt");
  fileIn.open(QIODevice::ReadOnly);
  QTextStream easy_input_input(&fileIn);

  for (auto i = 0; i < 8 * tasks_solved_; ++i) {
    easy_input_input.readLine();
  }

  task_number_->setText(easy_input_input.readLine());
  statement_->setText(easy_input_input.readLine());
  sentence_->setText(easy_input_input.readLine());
  first_answer_->setText(easy_input_input.readLine());
  second_answer_->setText(easy_input_input.readLine());
  third_answer_->setText(easy_input_input.readLine());
  fourth_answer_->setText(easy_input_input.readLine());
  QString string =  easy_input_input.readLine();
  if (string == "0") {
    correct_answer_ = 0;
  }
  if (string == "1") {
    correct_answer_ = 1;
  }
  if (string == "2") {
    correct_answer_ = 2;
  }
  if (string == "3") {
    correct_answer_ = 3;
  }
}

void PickAnOptionWindow::ManageLayout() {

//  QPainter painter;
//  painter.drawLine(QPoint(100,100), QPoint(10000,10000));

  layout_->addWidget(progress_bar_, 0, 2, 1, 6);
  layout_->addWidget(task_number_, 0, 0, 1, 1);
  layout_->addWidget(statement_, 1, 2, 1, 2);
//  layout_->addWidget(sentence_, 1, 5,1,2);
  layout_->addWidget(sentence_, 2, 2,1,4);
  layout_->addWidget(first_answer_, 2, 3,2,1);
  layout_->addWidget(second_answer_, 2, 4,2,1);
  layout_->addWidget(third_answer_, 2, 5,2,1);
  layout_->addWidget(fourth_answer_, 2, 6,2,1);
  layout_->addWidget(skip_level_, 4, 2,1,1);
  layout_->addWidget(check_answer_, 4, 7,1,1);
  layout_->addWidget(empty_label_, 0,8,1,2);
  layout_->addWidget(next_level_, 4,9,1,1);
}

void PickAnOptionWindow::ConnectLevelFeatures() {
  connect(first_answer_, &QPushButton::pressed, this, [&]{
    chosen_answer_ = 0;
    first_answer_->setStyleSheet("background-color: gray;");
    gray_first_ = true;
    if (gray_second_) {
      gray_second_ = false;
      second_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_third_) {
      gray_third_ = false;
      third_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_fourth_) {
      gray_fourth_ = false;
      fourth_answer_->setStyleSheet("background-color: white;");
    }
  });

  connect(second_answer_, &QPushButton::pressed, this, [&]{
    chosen_answer_ = 1;
    second_answer_->setStyleSheet("background-color: gray;");
    gray_second_ = true;
    if (gray_first_) {
      gray_first_ = false;
      first_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_third_) {
      gray_third_ = false;
      third_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_fourth_) {
      gray_fourth_ = false;
      fourth_answer_->setStyleSheet("background-color: white;");
    }
  });

  connect(third_answer_, &QPushButton::pressed, this, [&]{
    chosen_answer_ = 2;
    third_answer_->setStyleSheet("background-color: gray;");
    gray_third_ = true;
    if (gray_first_) {
      gray_first_ = false;
      first_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_second_) {
      gray_second_ = false;
      second_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_fourth_) {
      gray_fourth_ = false;
      fourth_answer_->setStyleSheet("background-color: white;");
    }
  });

  connect(fourth_answer_, &QPushButton::pressed, this, [&]{
    chosen_answer_ = 3;
    fourth_answer_->setStyleSheet("background-color: gray;");
    gray_fourth_ = true;
    if (gray_first_) {
      gray_first_ = false;
      first_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_second_) {
      gray_second_ = false;
      second_answer_->setStyleSheet("background-color: white;");
    }
    if (gray_third_) {
      gray_third_ = false;
      third_answer_->setStyleSheet("background-color: white;");
    }
  });

  connect(check_answer_, &QPushButton::pressed, this, [&]{
    if (chosen_answer_ == correct_answer_) {
      if (chosen_answer_ == 0) {
        first_answer_->setStyleSheet("background-color: lightgreen;");
        total_score += 10;
        progress_bar_->setValue(progress_bar_->value() + 100);
        gray_first_ = false;
        next_level_->show();
      }
      if (chosen_answer_ == 1) {
        second_answer_->setStyleSheet("background-color: lightgreen;");
        total_score += 10;
        progress_bar_->setValue(progress_bar_->value() + 100);
        gray_second_ = false;
        next_level_->show();
      }
      if (chosen_answer_ == 2) {
        third_answer_->setStyleSheet("background-color: lightgreen;");
        total_score += 10;
        progress_bar_->setValue(progress_bar_->value() + 100);
        gray_third_ = false;
        next_level_->show();
      }
      if (chosen_answer_ == 3) {
        fourth_answer_->setStyleSheet("background-color: lightgreen;");
        total_score += 10;
        progress_bar_->setValue(progress_bar_->value() + 100);
        gray_fourth_ = false;
        next_level_->show();
      }
    } else {
      if (chosen_answer_ == 0) {
        first_answer_->setStyleSheet("background-color: red;");
        total_score -= 4;
        gray_first_ = false;
      }
      if (chosen_answer_ == 1) {
        second_answer_->setStyleSheet("background-color: red;");
        total_score -= 4;
        gray_second_ = false;
      }
      if (chosen_answer_ == 2) {
        third_answer_->setStyleSheet("background-color: red;");
        total_score -= 4;
        gray_third_ = false;
      }
      if (chosen_answer_ == 3) {
        fourth_answer_->setStyleSheet("background-color: red;");
        total_score -= 4;
        gray_fourth_ = false;
      }
    }
  });

  connect(next_level_, &QPushButton::pressed, this, [&]{
    next_level_->hide();
    gray_first_ = false;
    gray_second_ = false;
    gray_third_ = false;
    gray_fourth_ = false;
    first_answer_->setStyleSheet("background-color: white;");
    second_answer_->setStyleSheet("background-color: white;");
    third_answer_->setStyleSheet("background-color: white;");
    fourth_answer_->setStyleSheet("background-color: white;");
    ++tasks_solved_;
    if (tasks_solved_ != tasks_count) {
      LoadNextLevel();
    } else {
      LoadVictoryScreen();
    }
  });
}

void PickAnOptionWindow::LoadVictoryScreen() {
  next_level_->hide();
  gray_first_ = false;
  gray_second_ = false;
  gray_third_ = false;
  gray_fourth_ = false;
  first_answer_->hide();
  second_answer_->hide();
  third_answer_->hide();
  fourth_answer_->hide();
  check_answer_->hide();
  skip_level_->hide();
  task_number_->hide();
  statement_->hide();
  sentence_->hide();
  progress_bar_->hide();
  QLabel* victory_label = new QLabel(this);
  victory_label->setText("Hooray!!! Come tomorrow to practice again");
  QFont font( "Times", 40, QFont::ExtraLight);
  victory_label->setFont(font);
  layout_->addWidget(victory_label, 1, 1, 1, 1);

}

int PickAnOptionWindow::GetTotalScore() {
  return total_score;
}

//void PickAnOptionWindow::ScoreChanged() {
//  emit
//}
