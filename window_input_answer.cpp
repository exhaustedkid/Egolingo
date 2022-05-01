#include <QFile>
#include "window_input_answer.h"


WindowInputAnswer::WindowInputAnswer() {
  resize(1500, 1000);
  input_line = new QLineEdit(this);
  layout_ = new QGridLayout();
  empty_label_ = new QLabel(this);

  QFile fileIn(":resourses/pick_an_option_tasks.txt");
  fileIn.open(QIODevice::ReadOnly);
  QTextStream easy_input_input(&fileIn);

  task_number_->setText(easy_input_input.readLine());
  statement_->setText(easy_input_input.readLine());
  sentence_->setText(easy_input_input.readLine());
  real_answer_ = easy_input_input.readLine();

  ConnectWidgets();
  ManageLayout();
  setLayout(layout_);
}

void WindowInputAnswer::ManageLayout() {
  layout_->addWidget(progress_bar_, 0, 2, 1, 6);
  layout_->addWidget(task_number_, 0, 0, 1, 1);
  layout_->addWidget(statement_, 1, 2, 1, 2);
  layout_->addWidget(sentence_, 2, 2,1,4);
  layout_->addWidget(skip_level_, 4, 2,1,1);
  layout_->addWidget(check_answer_, 4, 7,1,1);
  layout_->addWidget(empty_label_, 0,8,1,2);
  layout_->addWidget(next_level_, 4,9,1,1);
  layout_->addWidget(input_line, 2, 2,1,4);
}

void WindowInputAnswer::ConnectWidgets() {
  connect(input_line, &QLineEdit::returnPressed, this, [&] {
    actual_answer_ = input_line->text();
  });
  connect(input_line, &QLineEdit::editingFinished, this, [&] {
    actual_answer_ = input_line->text();
  });
  connect(check_answer_, &QPushButton::pressed, this, [&]{
    if (actual_answer_ == real_answer_) {
      input_line->setStyleSheet("background-color: lightgreen;");
    } else {
      input_line->setStyleSheet("background-color: red;");
    }
  });
}
