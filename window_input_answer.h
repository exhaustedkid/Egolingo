#ifndef EGOLINGO__WINDOW_INPUT_ANSWER_H_
#define EGOLINGO__WINDOW_INPUT_ANSWER_H_

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

#include "abstract_view.h"

class WindowInputAnswer : public AbstractWindow{
 public:
  WindowInputAnswer();

  void ConnectWidgets();
  void ManageLayout();

  QString actual_answer_;
  QString real_answer_;
 private:

  QGridLayout* layout_;
  QLineEdit* input_line;
};

#endif //EGOLINGO__WINDOW_INPUT_ANSWER_H_
