#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "s21_3DViewer.h"
#include <QColorDialog>
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


 private slots:
  void on_OpenobjFile_clicked();

  void on_EditFile_clicked();

  void on_Draw_clicked();

 // void on_scale_slider_sliderMoved(int position);

  void on_scale_slider_sliderReleased();

  void on_scale_but_minus_clicked();

  void on_scale_scale_plus_clicked();

  void on_scale_slider_valueChanged(int value);

  void on_scale_line_edit_returnPressed();

  void on_x_rotate_returnPressed();

  void on_y_rotate_returnPressed();

  void on_z_rotate_returnPressed();

  void on_x_move_returnPressed();

  void on_y_move_returnPressed();

  void on_z_move_returnPressed();

  void on_backgroundcolor_clicked();

private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
