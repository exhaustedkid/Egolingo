#include "exit_context_menu.h"
#include <QApplication>

ExitContextMenu::ExitContextMenu() {

  setWindowIcon(QIcon("../resourses/cross.png"));
  setWindowTitle("exit");

  text_ = new QLabel("Are you sure?",this);
  QFont font( "Times", 15, QFont::ExtraLight, true);
  text_->setFont(font);
  no_ = new QPushButton("no",this);
  yes_ = new QPushButton("yes",this);
  yes_->setGeometry(0,70,100,30);
  no_->setGeometry(100,70,100,30);
  text_->setGeometry(40,00,200,70);

  setFixedSize(200,100);
  ConnectButtons();
}

void ExitContextMenu::ConnectButtons() {
  connect(yes_, &QPushButton::pressed, this, [&]{
    return QApplication::quit();
  });
  connect(no_, &QPushButton::pressed, this, [&]{
    this->close();
  });

}
