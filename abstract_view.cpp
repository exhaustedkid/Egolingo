#include "abstract_view.h"

AbstractWindow::AbstractWindow() {
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

  progress_bar_ = new QProgressBar(this);
  progress_bar_->setMaximum(500);
  progress_bar_->setValue(0);

  empty_label_ = new QLabel(this);

  task_number_ = new QLabel(this);
  task_number_->setFont(font);

  statement_ = new QLabel(this);
  QFont statement_font( "Times", 30, QFont::ExtraLight);
  statement_->setFont(statement_font);

  sentence_ = new QLabel(this);
  QFont font_sentence( "Times", 30, QFont::ExtraLight);
  sentence_->setFont(font_sentence);

}

//void AbstractWindow::LoadNextLevel() {
//
//}
