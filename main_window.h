#ifndef EGOLINGO__MAIN_WINDOW_H_
#define EGOLINGO__MAIN_WINDOW_H_

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QLabel>

#include "window_pick_an_option.h"
//#include "controller.h"
#include "settings_window.h"
#include "exit_context_menu.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);

  void ConnectWidgets();
  void CreateWidgets();

  void SetScore();

 private:
  QGridLayout* layout_;
  QWidget* central_widget;

  SettingsWindow* settings_window_;
  ExitContextMenu* exit_context_menu_;
  PickAnOptionWindow* pick_an_option_window_;

  QLabel* flag_;
  QLabel* owl_;
  QLabel* time_to_practice_label_;
  QLabel* shesternya_;
  QLabel* exit_;
  QLabel* score_;

  QPushButton* settings_button_;
  QPushButton* exit_button_;

  QPushButton* pick_an_option_button_;
  QPushButton* input_answer_button_;
  QPushButton* audio_button_;
  QPushButton* mixed_button_;

};

#endif //EGOLINGO__MAIN_WINDOW_H_
