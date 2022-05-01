#ifndef EGOLINGO__SETTINGS_WINDOW_H_
#define EGOLINGO__SETTINGS_WINDOW_H_

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class SettingsWindow : public QWidget {
  Q_OBJECT
 public:
  SettingsWindow();
  void ManageLayouts();

 private:

  QLabel* difficulty_label_;
  QComboBox* difficulty_;

  QLabel* sound_label_;
  QComboBox* sound_;

  QLabel* reset_label_;
  QPushButton* reset_settings_;

  QGridLayout* layout_;
};

#endif //EGOLINGO__SETTINGS_WINDOW_H_
