// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// edit_file_specific_line.cpp
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#include <QtWidgets>

/// 指定されたファイルの指定された行を指定された内容に置き換える
/// 戻り値: bool (失敗時false)
bool EditFileSpecificLine(int line_, QString content_, QString path_) {
  QFile file(path_);
  if(!file.open(QIODevice::ReadOnly)) return false;
  QTextStream stream(&file);
  QString out;
  int i=1;
  bool edited = false;

  // Read from file
  while (!stream.atEnd()) {
    // 変更が要求されている行に達したら、変更内容を適用する
    if (i == line_) {
      out += content_;
      stream.readLine();
    } else out += stream.readLine();
    out += '\n';
    i++;
  }
  file.close();

  // Write to file
  if (!file.open(QIODevice::WriteOnly)) return false;
  QTextStream outstream(&file);
  outstream<<out;
  file.close();
  return true;
}