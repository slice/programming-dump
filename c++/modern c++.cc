#include <string>
#include <memory>
#include <iostream>
#include <Windows.h>
#include <Commctrl.h>

struct Song {
  std::wstring artist;
  std::wstring title;

  Song(const std::wstring& artist, const std::wstring& title)
    : artist(artist), title(title) {
  }
};

int main() {
  auto song = std::make_unique<Song>(L"Diana Krall", L"The Look of Love");
  std::wcout << song->artist << " - " << song->title << '\n';
  auto ptr = std::move(song);
  if (song == nullptr) {
    std::wcout << L"The song was deallocated!\n";
  }
  if (ptr == nullptr) {
    std::cout << L"Uh...what?\n";
  }
  std::wcout << ptr->title << '\n';
  const std::wstring ole = L"olé Hecker v1.0001";
  std::wcout << ole << '\n';
  MessageBox(nullptr, ole.c_str(), L"Hello! Your system is hecked.", MB_OK);
  int* result = new int;
  TaskDialog(nullptr, nullptr,
    ole.c_str(), // title
    L"Oh uh", // main instruction
    L"You're hecked. Might as well heck yourself now", //content
    TDCBF_OK_BUTTON,
    TD_SHIELD_ICON,
    result);
  std::wcout << L"The result was: " << result << '\n';
  delete result;
  std::system("pause"); // blargh windows
}