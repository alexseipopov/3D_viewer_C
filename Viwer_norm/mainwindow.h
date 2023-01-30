#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>

#include "s21_3DViewer.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 public slots:
  void get_position(int x, int y);

 private slots:
  void on_OpenobjFile_clicked();

  void on_EditFile_clicked();

  void on_Draw_clicked();

  void on_scale_but_minus_clicked();

  void on_scale_scale_plus_clicked();

  void on_scale_line_edit_returnPressed();

  void on_x_rotate_returnPressed();

  void on_y_rotate_returnPressed();

  void on_z_rotate_returnPressed();

  void on_x_move_returnPressed();

  void on_y_move_returnPressed();

  void on_z_move_returnPressed();

  void on_backgroundcolor_clicked();

  void on_horizontalSlider_2_sliderReleased();

  void on_comboBox_3_activated(int index);

  void on_x_move_slider_sliderMoved(int position);

  void on_x_rotate_slider_sliderMoved(int position);

  void on_scale_slider_sliderMoved(int position);

 private:
  Ui::MainWindow *ui;
  int previous_value_slider_x;

  int previous_value_rotate_x;

  double previous_scale;
};
#endif  // MAINWINDOW_H
