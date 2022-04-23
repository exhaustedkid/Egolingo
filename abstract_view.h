#pragma once

#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QGridLayout>

class AbstractWindow : public QWidget {
  Q_OBJECT

 public:
  AbstractWindow();

  QProgressBar* progress_bar_;
  QPushButton* check_answer_;
  QPushButton* skip_level_;
  QPushButton* next_level_;
  QLabel* task_number_;
  QLabel* statement_;
  QLabel* sentence_;
  QLabel* empty_label_;


 private:

//  QPushButton* skip_button_;
//  QPushButton* check_button_;


  int score_ = 0;
};

