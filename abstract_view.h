#pragma once

#include <QWidget>
#include <QPushButton>
#include <QProgressBar>

class AbstractWindow : public QWidget {
  Q_OBJECT

 public:
  AbstractWindow();

//  virtual void LoadNextLevel();

  QProgressBar* progress_bar_;

 private:

//  QPushButton* skip_button_;
//  QPushButton* check_button_;


  int score_ = 0;
};

