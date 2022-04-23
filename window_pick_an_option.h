#include "abstract_view.h"

#ifndef EGOLINGO__WINDOW_PICK_AN_OPTION_H_
#define EGOLINGO__WINDOW_PICK_AN_OPTION_H_

class PickAnOptionWindow : public AbstractWindow {
 Q_OBJECT
 public:
  PickAnOptionWindow();

  void ManageLayout();
  void LoadNextLevel();
  void LoadVictoryScreen();
  void CreateWindow();
  void ConnectLevelFeatures();

  int GetTotalScore();

  signals:
//  void ScoreChanged();

 private:
  QGridLayout* layout_;

  int correct_answer_;
  int chosen_answer_; // 0,1,2,3

  bool gray_first_ = false;
  bool gray_second_ = false;
  bool gray_third_ = false;
  bool gray_fourth_ = false;

  QPushButton* first_answer_;
  QPushButton* second_answer_;
  QPushButton* third_answer_;
  QPushButton* fourth_answer_;
//  QPushButton* check_answer_;
//  QPushButton* skip_level_;

//  QPushButton* next_level_;
//  QLabel* task_number_;
//  QLabel* statement_;
//  QLabel* sentence_;
//  QLabel* empty_label_;

  int tasks_solved_ = 0;
  int tasks_count = 5;
  int total_score = 0;
};

#endif //EGOLINGO__WINDOW_PICK_AN_OPTION_H_
