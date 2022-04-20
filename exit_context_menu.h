#ifndef EGOLINGO__EXIT_CONTEXT_MENU_H_
#define EGOLINGO__EXIT_CONTEXT_MENU_H_

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class ExitContextMenu : public QWidget {
 public:
    ExitContextMenu();
    void ConnectButtons();
 private:
  QLabel* text_;
  QPushButton* no_;
  QPushButton* yes_;
};

#endif //EGOLINGO__EXIT_CONTEXT_MENU_H_
