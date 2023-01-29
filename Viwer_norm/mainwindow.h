#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "s21_3DViewer.h"
#include <myopengl.h>
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

  void on_scale_slider_sliderMoved(int position);

private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
